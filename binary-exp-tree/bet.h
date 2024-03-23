#ifndef BE_TREE_H
#define BE_TREE_H


using namespace std;

class BET {

    struct BinaryNode { // public by default

        string element; // the data being stored internally
        BinaryNode* left; // pointer to left child
        BinaryNode* right; // pointer to right child

        BinaryNode(const string& e = string{}, BinaryNode *l = nullptr, BinaryNode *r = nullptr) 
            : element{e}, left{l}, right{r} {} // initialize BinaryNode data members
    };
        
    public:
        BET(); // default zero-parameter constructor
        BET(const string& postfix); // 1 param constructor -- build tree from the postfix expression 
        BET(const BET&); // copy constructor -- makes deep copy
        ~BET(); // destructor -- cleans up all dynamic space

        bool buildFromPostfix(const string& postfix); // build tree from the postfix expression 
                                                // return true if successful, false otherwise 
        const BET& operator= (const BET&); // assignment operator = -- makes deep copy
        void printInfixExpression(); // print infix exp
        void printPostfixExpression(); // print postfix exp
        size_t size(); // return number of nodes in tree
        size_t leaf_nodes(); // return number of leaf nodes in tree
        bool empty(); // return true if tree is empty, false otherwise

    private:
        void printInfixExpression(BinaryNode* n);
        void makeEmpty(BinaryNode*& t); // delete all nodes in subtree pointed to by "t"
        BinaryNode* clone(BinaryNode* t); // clone all nodes in subtree pointed to by "t"
        void printPostfixExpression(BinaryNode* n);
        size_t size(BinaryNode* t);
        size_t leaf_nodes(BinaryNode* t);

};

#include "bet.hpp"

#endif