#ifndef BE_TREE_H
#define BE_TREE_H


class BET {

    struct BinaryNode {

        string element;
        BinaryNode* left;
        BinaryNode* right;

        BinaryNode(const string& e = string{}, BinaryNode *l = nullptr, BinaryNode *r = nullptr) 
            : element{e}, left{l}, right{r} {}
    };
        
    public:
        BET();
        BET(const string& postfix);
        BET(const BET&);
        ~BET();
        bool buildFromPostfix(const string& postfix);
        const BET& operator= (const BET&);
        void printInfixExpression();
        void printPostfixExpression();
        size_t size();
        size_t leaf_nodes();
        bool empty();

    private:
        void printInfixExpression(BinaryNode* n);
        void makeEmpty(BinaryNode*& t);
        BinaryNode * clone(BinaryNode* t);
        void printPostfixExpression(BinaryNode* n);
        size_t size(BinaryNode* t);
        size_t leaf_nodes(BinaryNode* t);

};

#include "bet.hpp"

#endif