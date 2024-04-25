


void FreqTracker::addNum(std::pair<string, std::pair<int, int> > num_pair) {
    auto itr = number_map.find(num_pair.first);
    if(itr == number_map.end()) {
        number_map.insert(num_pair); // if not in our hash map, insert it and return
        return;
    }
    itr->second.first += 1; // if in our hash map, increment int representing frequency
}

void FreqTracker::addChr(std::pair<string, std::pair<int, int> > chr_pair) {
    auto itr = char_map.find(chr_pair.first);
    if(itr == char_map.end()) {
        char_map.insert(chr_pair); // if not in our hash map, insert it and return
        return;
    }
    itr->second.first += 1; // if in our hash map, increment int representing frequency
}

void FreqTracker::addStr(std::pair<string, std::pair<int, int> > str_pair) {
    auto itr = string_map.find(str_pair.first);
    if(itr == string_map.end()) {
        string_map.insert(str_pair); // if not in our hash map, insert it and return
        return;
    }
    itr->second.first += 1; // if in our hash map, increment int representing frequency
}



void FreqTracker::printNums() {
    cout << "PRINTNUMS()" << endl;
    // std::map<string, pair<int, int> >::iterator
    for(auto itr = number_map.begin(); itr != number_map.end(); ++itr){
        cout << "key: " << itr->first << " | value: (" << itr->second.first << "," << itr->second.second << ")" << endl;
    }
}

void FreqTracker::printChrs() {
    cout << "PRINTCHRS()" << endl;
    for(auto itr = char_map.begin(); itr != char_map.end(); ++itr){
        cout << "key: " << itr->first << " | value: (" << itr->second.first << "," << itr->second.second << ")" <<  endl;
    }
}

void FreqTracker::printStrs() {
    cout << "PRINTSTRS()" << endl;
    for(auto itr = string_map.begin(); itr != string_map.end(); ++itr){
        cout << "key: " << itr->first << " | value: (" << itr->second.first << "," << itr->second.second << ")" <<  endl;
    }
}