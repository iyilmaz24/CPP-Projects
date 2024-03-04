#include "stack.h"
#include <iostream>
#include <string.h>

using namespace std;
using namespace cop4530;

int opPrec(string c);
vector<string> splitTokens(string userInput);
void printVector(vector<string> V);
vector<string> turnPostFix(vector<string> tokens);
string evalExp(vector<string> pFixExp);


int main() {

    string userInput = "";
    while (userInput != "exit") {
        cout << "Enter infix expression ('exit' to quit):" << endl;
        userInput.clear();
        getline(cin, userInput);

        vector<string> tokens = splitTokens(userInput);
        printVector(tokens);
        vector<string> postFix = turnPostFix(tokens);
    

        cout << "Postfix expression: ";
        printVector(postFix);
        cout << endl;

        if(postFix.back() == "false") {
            cout << "Postfix evaluation: "; printVector(postFix);
            cout << " = "; printVector(postFix); cout << endl;
        } else {
            cout << "Postfix evaluation: "; printVector(postFix);
            cout << " = " << evalExp(postFix) << endl;
        }

    };

    return 0;
}


vector<string> splitTokens(string userInput) { 
    vector<string> returnTokens;
    vector<string> falseVector{"false"};
    string word;
    word += userInput[0];

    if(opPrec(word) != 0 && word != "(") {
        // if first token is not a ( or operand, return false
        cout << "first token is not a ( or operand" << endl;
        return falseVector;
    }

    word = "";
    int openPs = 0; // check for parantheses balance

    for(int i = 0; i < userInput.length(); i++) {
        if(userInput[i] == ' ') {
            if(opPrec(word) == 4) {
                (word == "(") ? openPs += 1 : openPs -= 1;
            }
            returnTokens.push_back(word);
            word = "";  
        }
        else if(userInput[i] != ' ') {
            word += userInput[i];
            // if(userInput[i] == '(' || userInput[i] == ')') {
            //     if(word.length() != 0) {
            //         returnTokens.push_back(word);
            //         word = "";
            //     }
            //     word += userInput[i];
            //     returnTokens.push_back(word);
            //     word = "";
            // }
            // else {
            //     word += userInput[i];
            //     if(i == userInput.length() - 1) {
            //         returnTokens.push_back(word);      
            //     }
            // }   
        }
        // else if(i == userInput.length() - 1) {
        //     word += userInput[i];
        //     returnTokens.push_back(word);      
        // }
    }
    if(opPrec(word) == 4) {
        (word == "(") ? openPs += 1 : openPs -= 1;
        if(openPs != 0) { // if parantheses not balanced, return false
            cout << "parantheses not balanced" << endl;
            return falseVector; 
        }
    }
    if(word != ")" || opPrec(word) != 0) {
        // if last char is not operand or ), return same input
            cout << "last char is not operand or )" << endl;
        return falseVector;
    }
    returnTokens.push_back(word);

    return returnTokens;
}

void printVector(vector<string> V) {
    for(int i = 0; i < V.size(); i++) {
        if(V[i] == "false") {
            continue;
        }
        cout << V[i] << " ";
    }
}

int opPrec(string c) {
    if(c == "(" || c == ")") {
        return 4;
    }
    if(c == "^") {
        return 3;
    }
    if(c == "/" || c == "*") {
        return 2;
    }
    if(c == "/" || c == "*") {
        return 2;
    }
    if (c == "+" || c == "-") {
        return 1;
    }
    return 0;
}

vector<string> turnPostFix(vector<string> tokens) {
    vector<string> pFixExp;
    bool evalFlag = true;

    for(string token : tokens) {
        cout << opPrec(token) << endl;

        // if two tokens are back to back operands or operators, return tokens
        // if token is a ) and previous is an operator, return tokens
        // no weird parantheses " )( ", return tokens


        if( !(isalnum(token[0])) ) {
            evalFlag = false; // if variable present, trigger no evaluation flag
        }
    }

    if(evalFlag == false) {
        pFixExp.push_back("false");
    }
    return pFixExp;
}

string evalExp(vector<string> pFixExp) {
    return "evalExp";
}


// g++ -g in2post.cpp -o stack.x