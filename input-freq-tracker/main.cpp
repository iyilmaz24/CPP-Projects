

#include <string>
#include <iostream>
#include "freq_tracker.cpp"

using namespace std;


int main() {

//    freopen("./tests6/test5", "r" ,stdin);


    FreqTracker freqTracker;
    string curr; char ch; int iter = 0;

    while(!cin.eof()) {

        cin.get(ch); iter++;
        if(!cin.fail()) {
            freqTracker.addChr(make_pair(ch, make_pair(1, iter)));
        }

        if(ch != ' ') {
            if(cin.fail()) {
                if(isdigit(curr.back()) && curr.length() > 1) {
                    freqTracker.addNum(make_pair(curr, make_pair(1, iter)));
                }
                else if(isalpha(curr.back()) && curr.length() > 1) {
                    freqTracker.addStr(make_pair(curr, make_pair(1, iter)));
                }
            }
            else if(isdigit(ch)) { // add currently saved num and reset buffer with char
                if(isalpha(curr.back())) {
                    if(curr.length() > 1) {
                        freqTracker.addStr(make_pair(curr, make_pair(1, iter)));
                    }
                    curr = "";
                }
                curr += ch;
            }
            else if(isalpha(ch)) { // add currently saved string / char and reset buffer with digit
                if(isdigit(curr.back())) {
                    freqTracker.addNum(make_pair(curr, make_pair(1, iter)));
                    curr = "";
                }
                curr +=  tolower(ch);
            }
        }
        else {
            if(isdigit(curr.back())) {
                freqTracker.addNum(make_pair(curr, make_pair(1, iter)));
            }
            else if (isalpha(curr.back()) && curr.length() > 1) {
                freqTracker.addStr(make_pair(curr, make_pair(1, iter)));
            }
            curr = "";
        }

    };


    freqTracker.printChrs(); cout << endl;
    freqTracker.printStrs(); cout << endl;
    freqTracker.printNums();

    return 0;
}

//    ./main.x < ./tests6/test4
//    g++ -std=c++17 main.cpp -o main.x
//    valgrind --leak-check=full --track-origins=yes -v ./main.x