
#ifndef FREQ_TRACKER
#define FREQ_TRACKER

#include<fstream>
#include <string>
#include <iostream>
#include <map>

using namespace std;


class FreqTracker {

    public:

//        void insert_file(const char* filename);
        void printHello();


    private:

//        bool read_file(const char* filename);
        // return True if successful, False otherwise


        map<string, int> word_map;
        map<string, int> char_map;
        map<string, int> number_map;

};

#include "freq_tracker.hpp"
#endif
