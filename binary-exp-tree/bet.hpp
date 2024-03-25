

// ------------ PUBLIC METHODS ------------ //

BET :: BET() {
    t_root = new BinaryNode;
};
BET :: BET(const string& postfix) {
    t_root = new BinaryNode;
    buildFromPostfix(postfix);
};
BET :: BET(const BET&) {
    makeEmpty(t_root); // first clear existing tree
};
BET :: ~BET() {

};
bool BET :: buildFromPostfix(const string& postfix) {
    stack<BinaryNode*> localStack;
    for(auto s : postfix) {
        if(opPrec(s) > 0) { // if char is an operator

        }
        else if (isOperand(s)) { // if char is an operand

        }
        else { // return false if char is not an operator, or operand
            return false;
        }
    }

    if(localStack.size() == 0) {
        t_root = localStack.top(); // set t_root equal to BinaryNode* in stack
        return true;
    }
    else { // invalid postfix exp provided, if more than one BinaryNode* is left
        return false;
    }

};
const BET& BET :: operator= (const BET&) {

};
void BET :: printInfixExpression() {

};
void BET :: printPostfixExpression() {

};
size_t BET :: size() {
    
};
size_t BET :: leaf_nodes() {

};
bool BET :: empty() {

};


// ------------ PRIVATE METHODS ------------ //

void BET :: printInfixExpression(BinaryNode* n) {

};
void BET :: makeEmpty(BinaryNode*& t) {

};
BET::BinaryNode* BET :: clone(BinaryNode* t) {

};
void BET :: printPostfixExpression(BinaryNode* n) {

};
size_t BET :: size(BinaryNode* t) {

};
size_t BET :: leaf_nodes(BinaryNode* t) {

};


// ------------ HELPER METHODS ------------ //

bool isOperand(char s) {

}
int opPrec(char s) {

}