

#include "hashtable.h"
#include<crypt.h>

using namespace std;
using namespace cop4530;


class PassServer {

public:

    PassServer(size_t size = 101);          // pass through constructor, internally calls HashTable constructor
    ~PassServer();
    bool load(const char* filename);        // load password file into HashTable object
    bool addUser(std::pair<string, string>& kv);       // add new username + password (password is plaintext, encrypted before insertion)
    bool addUser(std::pair<string, string>&& kv);      // move version of addUser
    bool removeUser(const string& k);          // delete existing user with username k
    bool changePassword(const pair<string, string>& p, const string& newpassword);         // change existing user's password, parameters are plaintext
    bool find(const string& user);         // check if user exists
    void dump();        // show structure and contents of HashTable object
    size_t size();          // return number of username/password pairs
    bool write_to_file(const char* filename);       // save all username and password combinations to file


private:

    HashTable<string, string> password_server;
    string encrypt(const string& str);         // encrypt parameter 'str' and return result

};

