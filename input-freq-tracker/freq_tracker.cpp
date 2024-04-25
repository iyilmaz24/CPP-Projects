
#ifndef FREQ_TRACKER
#define FREQ_TRACKER

#include<fstream>
#include <string>
#include <iostream>
#include <map>

using namespace std;

class FreqTracker {

    public:

        void addNum(std::pair<string, std::pair<int, int> > num_pair);
        void addChr(std::pair<string, std::pair<int, int> > chr_pair);
        void addStr(std::pair<string, std::pair<int, int> > str_pair);

        void printNums();
        void printChrs();
        void printStrs();

    private:

        map<string, std::pair<int, int> > string_map;
        map<string, std::pair<int, int> > char_map;
        map<string, std::pair<int, int> > number_map;

};

#include "freq_tracker.hpp"
#endif
