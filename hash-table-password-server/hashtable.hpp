

template <typename K, typename V>
cop4530::HashTable<K, V>::HashTable(size_t size) {
    ht_entries = 0;
    hash_table.resize(prime_below(size));
}

template <typename K, typename V>
cop4530::HashTable<K, V>::~HashTable() {
    clear();
}

template <typename K, typename V>
size_t cop4530::HashTable<K, V>::size() {
    return ht_entries;
}

template <typename K, typename V>
bool cop4530::HashTable<K, V>::contains(const K& k) {
    auto& selected_list = hash_table[myhash(k)];
    for(auto& kv : selected_list) {
        if(kv.first == k) {
            return true;
        }
    }
    return false;
}

template <typename K, typename V>
bool cop4530::HashTable<K, V>::match(const std::pair<K, V>& kv) {
    auto& selected_list = hash_table[myhash(kv.first)];
    if(find(begin(selected_list), end(selected_list), kv) != end(selected_list)) { // key value exists
        return true;
    }
    return false;
}

template <typename K, typename V>
bool cop4530::HashTable<K, V>::insert(const std::pair<K, V>& kv) {
    auto& selected_list = hash_table[myhash(kv.first)];
    if(find(begin(selected_list), end(selected_list), kv) != end(selected_list)) { // key value exists
        return false;
    }
    if(contains(kv.first) == false) { // key doesnt exist
        ht_entries += 1;
        selected_list.push_back(kv);
    }
    else { // key exists, with different value
        remove(kv.first);
        ht_entries += 1;
        selected_list.push_back(kv);
    }

    int curr_size = ht_entries;
    if(++curr_size > hash_table.size()) {
        rehash();
    }
    return true;
}

template <typename K, typename V>
bool cop4530::HashTable<K, V>::insert(std::pair<K, V>&& kv) {
    auto& selected_list = hash_table[myhash(kv.first)];
    if(find(begin(selected_list), end(selected_list), kv) != end(selected_list)) { // key value exists
        return false;
    }
    if(contains(kv.first) == false) { // key doesnt exist
        ht_entries += 1;
        selected_list.push_back(kv);
    }
    else { // key exists, with different value
        remove(kv.first);
        ht_entries += 1;
        selected_list.push_back(kv);
    }

    int curr_size = ht_entries;
    if(++curr_size > hash_table.size()) {
        rehash();
    }
    return true;
}

template <typename K, typename V>
bool cop4530::HashTable<K, V>::remove(const K& k) {
    auto& selected_list = hash_table[myhash(k)];

    for(auto itr = selected_list.begin(); itr != selected_list.end(); itr++) {
        if(itr->first == k) {
            selected_list.erase(itr);
            --ht_entries;
            return true;
        }
    }
    return false;
}

template <typename K, typename V>
void cop4530::HashTable<K, V>::clear() {
    makeEmpty();
}

template <typename K, typename V>
bool cop4530::HashTable<K, V>::load(const char* filename) {
    K key; V value;
    ifstream input_stream; input_stream.clear();
    input_stream.open(filename);

    if(!input_stream) {
        return false;
    }
    while(input_stream.eof() == false) {
        input_stream >> key >> value;
        insert(std::make_pair(key, value));
    }
    input_stream.close();
    return true;
}

template <typename K, typename V>
void cop4530::HashTable<K, V>::dump() {
    int temp = 0;
    for(auto& currList : hash_table) {
        cout << "v[" << temp << "]: ";

        if(currList.size() == 1) {
            cout << currList.begin()->first << " " << currList.begin()->second;
        }
        else {
            for(auto& kv : currList) {
                cout << kv.first << " " << kv.second; cout << ":";
            }
        }
        cout << endl; ++temp;
    }
}

template <typename K, typename V>
bool cop4530::HashTable<K, V>::write_to_file(const char* filename) {
    ofstream output_stream;
    output_stream.open(filename);

    if(!output_stream) {
        return false;
    }
    for(auto& currList : hash_table) {

        if(currList.size() == 1) {
            output_stream << currList.begin()->first << " " << currList.begin()->second << endl;
        }
        else {
            for(auto& kv : currList) {
                output_stream << kv.first << " " << kv.second << endl;
            }
        }
    }

    output_stream.close();
    return true;
}

template <typename K, typename V>
void cop4530::HashTable<K, V>::makeEmpty() {
    for(auto& currList : hash_table) {
        currList.clear();       // uses std::list<T>.clear()
    }
}

template <typename K, typename V>
void cop4530::HashTable<K, V>::rehash() {
    auto old_data = hash_table;
    makeEmpty();
    hash_table.resize(prime_below(2 * hash_table.size()));

    for(auto& currList : old_data) {
        for(auto& kv : currList) {
            insert(std::move(kv));
        }
    }
}

template <typename K, typename V>
size_t cop4530::HashTable<K, V>::myhash(const K& k) {
    hash<K> hash_generator;
    return hash_generator(k) % hash_table.size();
}

// returns largest prime number <= n or zero if input is too large
template<typename K, typename V>
unsigned long cop4530::HashTable<K, V>::prime_below(unsigned long n) {     // this is likely more efficient than prime_above(), because it only needs vector of size n

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
template<typename K, typename V>
void cop4530::HashTable<K, V>::setPrimes(std::vector<unsigned long>& vprimes) {

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

