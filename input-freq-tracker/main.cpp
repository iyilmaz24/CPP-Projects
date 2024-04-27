
#include <string>
#include <iostream>
#include "freq_tracker.cpp"

using namespace std;

int main() {

    FreqTracker freqTracker;
    string curr; char ch; int iter = 0;

    while(!cin.eof()) {

        cin.get(ch); iter++;
        if(!cin.fail()) { // if at the end of the file, cin will fail
            freqTracker.addChr(make_pair(ch, make_pair(1, iter)));
        }

        if(ch != ' ') {
            if(cin.fail() || ispunct(ch) || ch == '\n') {
                if(!curr.empty() && isdigit(curr.back())) {
                    freqTracker.addNum(make_pair(curr, make_pair(1, iter)));
                }
                else if(!curr.empty() && isalpha(curr.back())) {
                    freqTracker.addStr(make_pair(curr, make_pair(1, iter)));
                }
                if(ispunct(ch) || ch == '\n') {
                    curr = "";
                }
            }
            else if(isdigit(ch)) {
                if(!curr.empty() && isalpha(curr.back())) { // add currently saved str and reset buffer
                    freqTracker.addStr(make_pair(curr, make_pair(1, iter)));
                    curr = "";
                }
                curr += ch;
            }
            else if(isalpha(ch)) {
                if(!curr.empty() && isdigit(curr.back())) { // add currently saved num and reset buffer
                    freqTracker.addNum(make_pair(curr, make_pair(1, iter)));
                    curr = "";
                }
                curr +=  tolower(ch);
            }
        }
        else {
            if(!curr.empty() && isdigit(curr.back())) {
                freqTracker.addNum(make_pair(curr, make_pair(1, iter)));
            }
            else if (!curr.empty() && isalpha(curr.back())) {
                freqTracker.addStr(make_pair(curr, make_pair(1, iter)));
            }
            curr = "";
        }
    };

    freqTracker.printChrs(); cout << '\n';
    freqTracker.printStrs(); cout << '\n';
    freqTracker.printNums();

    return 0;
}

//    ./main.x < ./tests6/test4
//    g++ -std=c++17 main.cpp -o main.x
//    valgrind --leak-check=full --track-origins=yes -v ./main.x