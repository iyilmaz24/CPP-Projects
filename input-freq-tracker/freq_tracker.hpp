


void FreqTracker::addNum(std::pair<string, std::pair<int, int> > num_pair) {
    auto itr = number_map.find(num_pair.first);
    if(itr == number_map.end()) {
        number_map.insert(num_pair); // if not in our hash map, insert it and return
        return;
    }
    itr->second.first += 1; // if in our hash map, increment int representing frequency
}

void FreqTracker::addChr(std::pair<char, std::pair<int, int> > chr_pair) {
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
    vector<pair<string, int> > numbersTop10 = getTop10Nums();
    cout << "Total "<< string_map.size() << " different numbers, " << numbersTop10.size() << " most used words:" << endl;
    int count = 0;

    for(auto itr = numbersTop10.begin(); itr != numbersTop10.end(); ++itr){
        cout << "No. " << count << ": " << itr->first << "\t\t" << itr->second << "\n"; count++;
    }

}

void FreqTracker::printChrs() {
    vector<pair<char, int> > charsTop10 = getTop10Chrs();
    cout << "Total "<< char_map.size() << " different characters, " << charsTop10.size() << " most used words:" << endl;
    int count = 0;

    for(auto itr = charsTop10.begin(); itr != charsTop10.end(); ++itr){
        cout << "No. " << count << ": " << itr->first << "\t\t" << itr->second << "\n"; count++;
    }

}

void FreqTracker::printStrs() {
    vector<pair<string, int> > stringsTop10 = getTop10Strs();
    cout << "Total "<< string_map.size() << " different words, " << stringsTop10.size() << " most used words:" << endl;
    int count = 0;

    for(auto itr = stringsTop10.begin(); itr != stringsTop10.end(); ++itr){
        cout << "No. " << count << ": " << itr->first << "\t\t" << itr->second << "\n"; count++;
    }

}


vector<pair<char, int> > FreqTracker::getTop10Chrs() {
    vector<pair<char, int> > results;
    std::priority_queue<pair<int, pair<char, int> > > pq; // <pair<freq, pair<char, read_index> > >

    if(char_map.size() <= 10) {
        for(auto itr = char_map.begin(); itr != char_map.end(); ++itr) {
            pq.push(make_pair(itr->second.first, make_pair(itr->first, itr->second.second)));
        }
        while(!pq.empty()) {
            results.push_back(make_pair(pq.top().second.first, pq.top().first)); pq.pop();
        }
    }
    else {
        cout << "not implemented yet";
    }

    return results;
}


vector<pair<string, int> > FreqTracker::getTop10Strs() {
    vector<pair<string, int> > results;
    std::priority_queue<pair<int, pair<string, int> > > pq; // <pair<freq, pair<str, read_index> > >

    if(string_map.size() <= 10) {
        for(auto itr = string_map.begin(); itr != string_map.end(); ++itr) {
            pq.push(make_pair(itr->second.first, make_pair(itr->first, itr->second.second)));
        }
        while(!pq.empty()) {
            results.push_back(make_pair(pq.top().second.first, pq.top().first)); pq.pop();
        }
    }
    else {
        cout << "not implemented yet";
    }

    return results;
}


vector<pair<string, int> > FreqTracker::getTop10Nums() {
    vector<pair<string, int> > results;
    std::priority_queue<pair<int, pair<string, int> > > pq; // <pair<freq, pair<num, read_index> > >

    if(number_map.size() <= 10) {
        for(auto itr = number_map.begin(); itr != number_map.end(); ++itr) {
            pq.push(make_pair(itr->second.first, make_pair(itr->first, itr->second.second)));
        }
        while(!pq.empty()) {
            results.push_back(make_pair(pq.top().second.first, pq.top().first)); pq.pop();
        }
    }
    else {
        cout << "not implemented yet";
    }

    return results;
}