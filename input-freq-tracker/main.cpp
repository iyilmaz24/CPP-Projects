

#include <string>
#include <iostream>
#include "freq_tracker.cpp"

using namespace std;


int main() {

    FreqTracker freqTracker;

    string curr; char ch; int iter = 0;

    while(!cin.eof()) {

        cin.get(ch); iter++;

        if(ch != ' ') {
            if(cin.fail()) {
                isdigit(curr.back()) ? freqTracker.addNum(make_pair(curr, make_pair(1, iter))) :
                    curr.length() == 1 ? freqTracker.addChr(make_pair(curr, make_pair(1, iter))) :
                    freqTracker.addStr(make_pair(curr, make_pair(1, iter)));

                isdigit(curr.back()) ? cout << "freqTracker.addNum(curr):" + curr << endl :
                curr.length() == 1 ? cout << "freqTracker.addChar(curr):" + curr << endl : cout << "freqTracker.addStr(curr):" + curr << endl;
            }
            else if(isdigit(ch)) { // add currently saved num and reset buffer with char
                if(isalpha(curr.back())) {
                    curr.length() == 1 ? freqTracker.addChr(make_pair(curr, make_pair(1, iter))) : freqTracker.addStr(make_pair(curr, make_pair(1, iter)));
                    curr.length() == 1 ? cout << "freqTracker.addChar(curr):" + curr << endl : cout << "freqTracker.addStr(curr):" + curr << endl;
                    curr = "";
                }
                 curr += ch;
            }
            else if(isalpha(ch)) { // add currently saved string / char and reset buffer with digit
                ch = std::tolower(ch);
                if(isdigit(curr.back())) {
                    freqTracker.addNum(make_pair(curr, make_pair(1, iter)));
                    cout << "freqTracker.addNum(curr):" + curr << endl;
                    curr = "";
                }
                curr += ch;
            }
        }
        else {
            if(isdigit(curr.back())) {
                freqTracker.addNum(make_pair(curr, make_pair(1, iter)));
                cout << "freqTracker.addNum(curr):" + curr << endl;
            }
            else if (isalpha(curr.back())) {
                curr.length() == 1 ? freqTracker.addChr(make_pair(curr, make_pair(1, iter))) : freqTracker.addStr(make_pair(curr, make_pair(1, iter)));
                curr.length() == 1 ? cout << "freqTracker.addChar(curr):" + curr << endl : cout << "freqTracker.addStr(curr):" + curr << endl;
            }
            curr = "";
        }

    };

    freqTracker.printNums();
    freqTracker.printChrs();
    freqTracker.printStrs();

    //    ./main.x < ./tests6/test4
    //    g++ -std=c++17 main.cpp -o main.x
    return 0;
}

