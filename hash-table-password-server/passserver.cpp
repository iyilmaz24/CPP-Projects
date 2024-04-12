

#include "passserver.h"
#include "hashtable.h"
#include<string.h>



PassServer::PassServer(size_t size) : password_server(size) {	// use HashTable's implemented member functions to do heavy lifting

}

PassServer::~PassServer() {
    password_server.clear();
}

bool PassServer::load(const char* filename) {
    return password_server.load(filename);
}

bool PassServer::addUser(std::pair<string, string>& kv) {
    if(password_server.contains(kv.first) == true) {
        return false;
    }
    return password_server.insert(make_pair(kv.first, encrypt(kv.second)));
}

bool PassServer::addUser(std::pair<string, string>&& kv) {
    if(password_server.contains(kv.first) == true) {
        return false;
    }
    return password_server.insert(std::move(make_pair(kv.first, encrypt(kv.second))));
}

bool PassServer::removeUser(const string& k) {
    return password_server.remove(k);
}

bool PassServer::changePassword(const pair<string, string>& p, const string& newpassword) {
    if(password_server.match(make_pair(p.first, encrypt(p.second))) == true) {		// if encrypted kv is found in HashTable object
        if (encrypt(newpassword) != encrypt(p.second)) {		// if newpassword is not duplicate of current password
            pair new_encry_kv = std::make_pair(p.first, encrypt(newpassword));		// create new encrypted kv pair
            password_server.insert(new_encry_kv);			// insert()'s implementation takes care of upserting
            return true;
        }
    }
    return false;
}

bool PassServer::find(const string& user) {
    return password_server.contains(user);
}

void PassServer::dump() {
    password_server.dump();
}

size_t PassServer::size() {
    return password_server.size();
}

bool PassServer::write_to_file(const char* filename) {
    return password_server.write_to_file(filename);
}

string PassServer::encrypt(const string& str) {
    char* p = new char[34]; strcpy(p, str.c_str());			// put plaintext password 'str' in char array p
    char s[] = "$1$########";		// salt for encryption

    string encrypted_pass = crypt(p, s);
    return encrypted_pass.substr(12);		// remove salt before returning encrypted password
}

