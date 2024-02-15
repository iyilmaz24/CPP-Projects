
#include <iostream>

using namespace std;


template <typename T>
cop4530 :: List<T> :: List() {
    cout << "Default Constructor Called" << endl;
    this->init();
    cout << "size: " << this->theSize << endl;
    cout << "head: " << this->head->data << endl;
};

template <typename T>
cop4530 :: List<T> :: List(int num, const T& val) {
    cout << "Constructing List of 'num' elements initialized with value 'val' (num, val)" << endl;
    this->init();
    for(int i = 0; i < num; i++) {
        if(i == 0) {
            this->head->next = new Node(val);
            this->tail->next = this->head->next;
            continue;
        }
        Node* temp = this->head->next;
        this->head->next = new Node(val, nullptr, temp);
        temp->prev = this->head->next;
        this->theSize += 1;
    }
};

template <typename T>
cop4530 :: List<T> :: List(const List &rhs) {
    cout << "Copy Constructor Called" << endl;
};

template <typename T>
cop4530 :: List<T> :: List(List &&rhs) {
    cout << "Move Constructor Called" << endl;
};

template <typename T>
const cop4530::List<T>& cop4530::List<T>::operator=(const List &rhs) {
    cout << "Copy Assignment Operator Overload Called" << endl;
};

template <typename T>
cop4530::List<T>& cop4530::List<T>::operator=(List &&rhs) {
    cout << "Move Assignment Operator Called" << end;
};

template <typename T>
cop4530 :: List<T> :: ~List() {
    cout << "Destructor Called" << endl;
};

template <typename T>
void cop4530 :: List<T> :: init() {
    this->theSize = 0;
    this->head = new Node();         
    this->tail = new Node();    
    cout << "init done" << endl;   
}

template<class T> 
int cop4530::List<T>::size() const {
    return this->theSize;
};

template<class T> 
bool cop4530::List<T>::empty() const {
    return this->theSize == 0 ? true : false;
};

template<class T> 
void cop4530::List<T>::push_front(const T &val) {
    
};

template<class T> 
void cop4530::List<T>::push_front(T &&val) {

};

template<class T> 
void cop4530::List<T>::push_back(const T &val) {

    // cout << "p1" << endl;
    Node* currentTail = this->tail->next;
    // cout << "currentTail: " << currentTail->data << endl;

    // cout << (currentTail == nullptr ? "true" : "false") << endl;

    // cout << "p2" << endl;
    Node* newNode = new Node(val, currentTail, nullptr);

    // cout << "p3" << endl;
    currentTail->next = newNode;

    // cout << "p4" << endl;
    this->tail->next = newNode;

    this->theSize += 1;
    // cout << "complete" << endl;

    cout << val << " pushed to the back (COPY)" << endl;
};

template<class T> 
void cop4530::List<T>::push_back(T&& val) {
    // cout << "p1" << endl;
    Node* currentTail = this->tail->next;
    // cout << "currentTail: " << currentTail->data << endl;

    // cout << (currentTail == nullptr ? "true" : "false") << endl;

    // cout << "p2" << endl;
    Node* newNode = new Node(val, currentTail, nullptr);

    // cout << "p3" << endl;
    currentTail->next = newNode;

    // cout << "p4" << endl;
    this->tail->next = newNode;
    
    this->theSize += 1;
    // cout << "complete" << endl;

    cout << val << " pushed to the back (MOVE)" << endl;
};

template<class T> 
void cop4530::List<T>::print(std::ostream &os, char ofc) const {
    Node* curr = this->head->next;

    while(curr != nullptr) {
        cout << curr->data << ofc;
        curr = curr->next;
    }

};

// template<class T> 
// cop4530::List<T>::iterator cop4530::List<T>::begin() {

// };

// template<class T> 
// std::ostream &cop4530::operator<<(std::ostream &os, const cop4530::List<T> &l) {
//     cout << "OPERATOR<<" << endl;
//     return os << l.print();
// };