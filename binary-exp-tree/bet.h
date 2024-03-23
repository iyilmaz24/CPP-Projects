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


    private:
    

};

#include "bet.hpp"

#endif