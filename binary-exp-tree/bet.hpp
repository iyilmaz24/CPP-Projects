
bool isOperand(string s);
int opPrec(string s);

// ------------ PUBLIC METHODS ------------ //

BET :: BET() {
    t_root = new BinaryNode;
};
BET :: BET(const string& postfix) {
    t_root = new BinaryNode;
    buildFromPostfix(postfix);
};
BET :: BET(const BET& BET) {
    t_root = clone(BET.t_root);
};
BET :: ~BET() {
    makeEmpty(t_root);
};
bool BET :: buildFromPostfix(const string& postfix) {
    if(postfix[0] == ' ' || postfix.length() == 0) {
        cout << "Invalid Postfix Exp Provided, Leading Whitespace OR Blank" << endl;
        return false;
    }
    if (size(t_root) != 0) {
        makeEmpty(t_root);
    }

    stack<BinaryNode*> localStack{};
    string currToken = "";
    for(int i = 0; i < postfix.length(); i++) { // if current char is not a space or last char, add onto currToken

        if(postfix[i] != ' ') { 
            currToken += postfix[i];
            if(i != postfix.length() - 1) {
                continue;
            }
        }
        if(opPrec(currToken) != 0) { // if currToken is an operator
            if(localStack.size() < 2) { 
                cout << "Invalid Postfix Exp Provided, Too Many Operators OR Incorrect Input Sequence" << endl;
                return false; // if less than 2 nodes in our stack
            }
            BinaryNode* newNode = new BinaryNode(currToken);
            BinaryNode* l_node = localStack.top(); localStack.pop();
            BinaryNode* r_node = localStack.top(); localStack.pop();

            newNode->left = l_node; newNode->right = r_node;
            localStack.push(newNode);
            currToken = "";
        }
        else if (isOperand(currToken) == true) { // if currToken is an operand
            BinaryNode* newNode = new BinaryNode(currToken);
            localStack.push(newNode);
            currToken = "";
        }
    }
    
    if(localStack.size() == 1) { // set t_root equal to last BinaryNode in stack
        t_root = localStack.top(); localStack.pop(); 
        return true;
    }
    else { // if more than one BinaryNode is left
        cout << "Invalid Postfix Exp Provided, Not Enough Operators Provided For Operands" << endl;
        return false;
    }
};
const BET& BET :: operator= (const BET& BET) {
    if (size(t_root) != 0) {
        makeEmpty(t_root);
    }
    t_root = clone(BET.t_root);
    return *this;
};
void BET :: printInfixExpression() {
    printInfixExpression(t_root); cout << endl;
};
void BET :: printPostfixExpression() {
    printPostfixExpression(t_root); cout << endl;
};
size_t BET :: size() {
    return size(t_root);
};
size_t BET :: leaf_nodes() {
    return leaf_nodes(t_root);
};
bool BET :: empty() {
    return (t_root == nullptr);
};


// ------------ PRIVATE METHODS ------------ //

void BET :: printInfixExpression(BinaryNode* n) {
    if(n->left == nullptr && n->right == nullptr) {
        cout << n->element << " ";
        return;
    }

    int unclosedPar = 0;
    if(n != nullptr) { 
        if(opPrec(n->right->element) <= opPrec(n->element) && opPrec(n->right->element) != 0 && opPrec(n->element) != 0) {
            if(opPrec(n->element) > 1) {
            cout << "( ";
            unclosedPar += 1;
        }}
        printInfixExpression(n->right); // traverse right child

        if(unclosedPar != 0) {
            cout << ") "; unclosedPar -= 1;
        }

        cout << n->element << " "; // print parent/origin node

        if(opPrec(n->left->element) <= opPrec(n->element) && opPrec(n->left->element) != 0 && opPrec(n->element) != 0) {
            if(opPrec(n->element) > 1) {
                cout << "( ";
                unclosedPar += 1;
        }}
        printInfixExpression(n->left); // traverse left child

        if(unclosedPar != 0) {
            cout << ") "; unclosedPar -= 1;
        }
    }
};
void BET :: makeEmpty(BinaryNode*& t) {
    if(t != nullptr) { 
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }    
};
BET::BinaryNode* BET :: clone(BinaryNode* t) {
    if(t == nullptr) {
        return nullptr;
    }
    return new BinaryNode(t->element, clone(t->left), clone(t->right));
};
void BET :: printPostfixExpression(BinaryNode* n) {
    if(n != nullptr) {
        printPostfixExpression(n->right);
        printPostfixExpression(n->left);
        cout << n->element << " ";
    }
};
size_t BET :: size(BinaryNode* t) {
    if(t == nullptr) {
        return 0;
    }

    long total = 0L;
    if(t != nullptr) {
        total += size(t->left);
        total += size(t->right);
    }
    return total + 1;
};
size_t BET :: leaf_nodes(BinaryNode* t) {
    if(t->left == nullptr && t->right == nullptr) {
        return 1;
    }

    long total = 0L;
    if(t != nullptr) {
        total += leaf_nodes(t->left);
        total += leaf_nodes(t->right);
    }
    return total;
};


// ------------ HELPER METHODS ------------ //

bool isOperand(string s) {
    if(s == "" || s == " ") {
        return false;
    }
    for(auto c : s)
        if(isalnum(c) == false) {
            return false;
        }
    return true;
}
int opPrec(string s) {
    if(s == "(" || s == ")" ) {
        return 3;
    }
    else if(s == "/" || s == "*" ) {
        return 2;
    }
    else if(s == "-" || s == "+" ) {
        return 1;
    }
    return 0;
}