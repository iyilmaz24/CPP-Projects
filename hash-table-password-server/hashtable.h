#ifndef HASHTABLE_H
#define HASHTABLE_H


#include<iostream>
#include<vector>
#include<list>
#include<fstream>
#include<algorithm>


using namespace std;

static const unsigned int max_prime = 1301081;      // max_prime is used internally
static const unsigned int default_capacity = 11;    // default_capacity is used if initial capacity of underlying vector in hash table is zero


namespace cop4530 {

    template<typename K, typename V>
    class HashTable {

    public:

        HashTable(size_t size = 101);       // create hash table, where size of vector is set to 'prime_below(size)' (default size is 101)
        ~HashTable();       // delete all elements/entries in hash table

        size_t size();      // return size of the hash table (i.e. number of entries stored)
        bool contains(const K& k);      // check if key k is in the hash table
        bool match(const std::pair<K, V>& kv);      // check if key-value pair is in the hash table

        // insert: add key-value pair kv into hash table if kv not already included, else if the key is in hash table, update value to new one from kv
        bool insert(const std::pair<K, V>& kv);     // return true if kv or value is inserted, return false otherwise (i.e., if kv is a duplicate key:value)
        bool insert(std::pair<K, V>&& kv);      // move version of insert

        bool remove(const K& k);        // delete key k, and it's value if in hash table, return true if k is deleted, return false otherwise (i.e., if key k is not in the hash table)
        void clear();       // delete all elements in the hash table

        bool load(const char* filename);        // load content of file (filename) into hash table. In file, each line contains single pair of key and value, separated by a white space
        void dump();        // display all entries in hash table. If entry contains multiple key-value pairs, separate them by semicolon character ':'
        bool write_to_file(const char* filename);        // write all entries from hash table into file with name filename
        // similar to line format in load function, each line = 'pair of key and value, separated by a white space'

    private:

        int ht_entries;         // total number of entries in hash table
        vector<list<pair<K, V>>> hash_table;        // hash table internal storage, vector consisting of lists

        void makeEmpty();       // delete all elements in hash table, public 'void clear()' will call this function
        void rehash();      // rehash function, called when number of elements in hash table is greater than size of vector
        size_t myhash(const K& k);      // return index of vector entry where k should be stored

        // two helpful functions that determine proper prime numbers used in setting up vector size
        unsigned long prime_below(unsigned long);       // whenever setting hash table to a new size "sz", call prime_below(sz) to determine new proper internal vector size
        void setPrimes(std::vector <unsigned long>&);

    };


#include "hashtable.hpp"

}


#endif
