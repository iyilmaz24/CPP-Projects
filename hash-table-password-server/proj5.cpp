

#include "passserver.h"
#include "hashtable.h"

using namespace std;
using namespace cop4530;


unsigned long prime_below(unsigned long n);     // implementation below
void setPrimes(std::vector<unsigned long>& vprimes);      // implementation below


void Menu() {

    cout << "\n\n";
    cout << "l - Load From File" << endl;
    cout << "a - Add User" << endl;
    cout << "r - Remove User" << endl;
    cout << "c - Change User Password" << endl;
    cout << "f - Find User" << endl;
    cout << "d - Dump HashTable" << endl;
    cout << "s - HashTable Size" << endl;
    cout << "w - Write to Password File" << endl;
    cout << "x - Exit program" << endl;
    cout << "\nEnter choice : ";

};

int main() {

    int input_size = 0; string selection;     // used to store user inputs
    string username; string password; string filename;

    cout << "Enter preferred hash table capacity: "; cin >> input_size;

    if(input_size < 2) {
        cout << "** input too small" << endl;
        cout << "prime_below gives: 0" << endl;
        cout << "set to default capacity" << endl;
        input_size = 11;
    }
    else {
        cout << "prime_below gives: " << prime_below(input_size) << endl;
    }
    cout << prime_below(input_size) << endl;

    PassServer password_server(input_size);

    do {

        Menu(); cin >> selection; // cout << "selection is: " << selection << endl;

        if(selection == "l") {
            cout << "Enter password file name to load from: "; cin >> filename;
            if(!(password_server.load(filename.c_str()))) {
                cout << "Error: Cannot open file " << filename << endl;
            }
        }
        else if(selection == "a") {
            cout << "Enter username: "; cin >> username;
            cout << "Enter password: "; cin >> password;
            pair kv = make_pair(username, password);

            if(password_server.addUser(kv) == true) {
                cout << endl << "User " << username << " added." << endl;
            }
            else {
                cout << endl << "*****Error: User already exists. Could not add user." << endl;
            }
        }
        else if(selection == "r") {
            cout << "Enter username: "; cin >> username;
            if(password_server.removeUser(username)) {
                cout << "User " << username << " deleted.";
            }
            else {
                cout << endl << "*****Error: User not found.  Could not delete user";
            }
            cout << endl;
        }
        else if(selection == "c") {
            cout << "Enter username: "; cin >> username;
            cout << "Enter password: "; cin >> password;
            pair old_kv = make_pair(username, password);

            string temp = ""; cout << endl << "Enter new password: ";
            cin >> temp; cout << endl;

            if(password_server.changePassword(old_kv, temp) == true) {
                cout << "Password changed for user " << username;
            }
            else {
                cout << "*****Error: Could not change user password";
            }
            cout << endl;
        }
        else if(selection == "f") {
            cout << "Enter username: "; cin >> username;
            cout << endl;

            if(password_server.find(username)) {
                cout << "User '" << username << "' found.";
            }
            else {
                cout << "User '" << username << "' not found.";
            }
            cout << endl;
        }
        else if(selection == "d") {
            password_server.dump();
        }
        else if(selection == "s") {
            cout << "Size of hashtable: " << password_server.size() << endl;
        }
        else if(selection == "w") {
            cout << "Enter password file name to write to: "; cin >> filename;
            if(!password_server.write_to_file(filename.c_str())) {
                cout << "FILE WRITE ERROR!" << endl;
            }
        }
        else if (selection == "x") {
            exit(0);
        }
        else {
            cout << "*****Error: Invalid entry.  Try again.";
            selection = "";     // reset selection input string
        }

    } while(selection != "x");

    return 0;

    // valgrind --leak-check=full --track-origins=yes -v ./test.x
    // g++ -g passserver.cpp proj5.cpp -lcrypt -o test.x

};

// returns largest prime number <= n or zero if input is too large
unsigned long prime_below(unsigned long n) {     // this is likely more efficient than prime_above(), because it only needs vector of size n

    if(n > max_prime) {
        std::cerr << "** input too large for prime_below()\n";
        return 0;
    }
    if(n == max_prime) {
        return max_prime;
    }
    if(n <= 1) {
        std::cerr << "** input too small \n";
        return 0;
    }

    // now: 2 <= n < max_prime
    std::vector<unsigned long> v(n + 1);
    setPrimes(v);
    while(n > 2) {
        if(v[n] == 1) {
            return n;
        }
        --n;
    }
    return 2;
};

// sets all prime number indexes to 1, called by method 'prime_below(n)'
void setPrimes(std::vector<unsigned long>& vprimes) {

    int i = 0;
    int j = 0;

    vprimes[0] = 0;
    vprimes[1] = 0;
    int n = vprimes.capacity();

    for(i = 2; i < n; ++i) {
        vprimes[i] = 1;
    }

    for(i = 2; i*i < n; ++i) {
        if(vprimes[i] == 1) {
            for(j = i+i; j < n; j += i) {
                vprimes[j] = 0;
            }
        }
    }

};

