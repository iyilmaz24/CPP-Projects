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
        if(userInput == "exit") { break; }

        vector<string> tokens = splitTokens(userInput);
        if(tokens[0] == "false") {
            cout << "please provide valid infix expression!" << endl;
            continue;
        }

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
        }
    }

    if(opPrec(word) == 4) {
        (word == "(") ? openPs += 1 : openPs -= 1;
        if(openPs != 0) { // if parantheses not balanced, return false
            cout << "parantheses not balanced" << endl;
            return falseVector; 
        }
    }
    if(word != ")" && opPrec(word) != 0) {
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
    Stack<string> stack;
    bool evalFlag = true;

    for(int i = 0; i < tokens.size(); i++) {
        if(opPrec(tokens[i]) == 0) {
            pFixExp.push_back(tokens[i]); 
            if(isalpha(tokens[i][0])) {
                evalFlag = false;  // if variable present, trigger no evaluation flag
            }
            continue;
        }

        if(tokens[i] == "(") {
            stack.push(tokens[i]); // if '(', push onto stack
            continue;
        }

        if(tokens[i] == ")") {
            if(opPrec(tokens[i - 1]) != 0 && tokens[i - 1] != ")") {
                cout << "invalid operator or '(' found directly before ')'" << endl;
                return tokens; // if token is a ) and previous is an operator, return tokens
            }

            while(stack.top() != "(" && stack.empty() == false) {
                pFixExp.push_back(stack.top());
                stack.pop();
            }
            if(stack.empty() == true) {
                cout << "parantheses not in correct order" << endl;
                return tokens; // ex. "( ) ) ("      
            }
            stack.pop(); // pop the '('
            continue;
        }

        if(opPrec(tokens[i]) != 0) { // if token is an operator
            if(stack.empty() == true) {
                stack.push(tokens[i]);
                continue;
            }
            while(stack.top() != "(" && opPrec(stack.top()) > opPrec(tokens[i]) && stack.empty() == false) {
                pFixExp.push_back(stack.top()); // pop stack until empty or higher precedence operator seen
                stack.pop();
            }
            stack.push(tokens[i]);
            continue;
        }

// if two tokens are back to back operands or operators, return tokens

    }

    while(stack.empty() == false) {
        if(stack.top() != "(") {
            pFixExp.push_back(stack.top());
        }
        stack.pop(); // empty stack of operators after reading entire token stream
    }
    if(evalFlag == false) {
        pFixExp.push_back("false");
    }
    return pFixExp;
}

string evalExp(vector<string> pFixExp) {
    return "evalExp";
}


// valgrind --leak-check=full --track-origins=yes -v ./stack.x
// g++ -g in2post.cpp -o stack.x