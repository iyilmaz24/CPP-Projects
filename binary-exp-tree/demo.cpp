#include "bet.h"
#include <string>
#include <iostream>

using namespace std;

int main() { 

    // string postfix;
    // cout << "Enter the first postfix expression: ";
    // getline(cin, postfix);


    BET myTree = BET();
    std::string myStr {"10 + 10 + 5"};
    myTree.buildFromPostfix(myStr);




    return 0;
}

