#include "bet.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main() { 

    // string postfix;
    // cout << "Enter the postfix expression: ";
    // getline(cin, postfix);

    vector<string> testInputs = {"4 50 6 + +", "4 50 + 6 +", "4 50 + 6 2 * +",
    "4 50 6 + + 2 *", "a b + c d e + * *", "", " ", "abc" };


    // vector<string> testInputs = {"4 50 6 + +"};

    BET myTree = BET();

    for(auto postF : testInputs) {
        myTree.buildFromPostfix(postF);
        cout << "my postF: " << postF << endl;
        cout << "infix: "; myTree.printInfixExpression();
        cout << "postfix: "; myTree.printPostfixExpression();
        cout << "node count (size): " << myTree.size(); cout << endl;
        cout << "leaf count (leaf_nodes): " << myTree.leaf_nodes(); cout << endl;
        cout << " -- -- -- -- -- " << endl;
    }

    return 0;
}
