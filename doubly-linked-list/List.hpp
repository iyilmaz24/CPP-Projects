
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

// template <typename T>
// cop4530 :: List<T> :: List(const List &rhs) {
//     cout << "Copy Constructor Called" << endl;
//     this->init();
//     this->theSize = rhs.theSize;

//     iter = rhs.begin();
//     while(iter != nullptr) {
//         this->push_back((*iter)->data);
//         iter++;
//     }
//     iter--;
//     this->tail->next = (*iter);    
// };

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

template<typename T> 
int cop4530::List<T>::size() const {
    return this->theSize;
};

template<typename T> 
bool cop4530::List<T>::empty() const {
    return this->theSize == 0 ? true : false;
};

template<typename T> 
void cop4530::List<T>::push_front(const T &val) {
    
};

template<typename T> 
void cop4530::List<T>::push_front(T &&val) {

};

template<typename T> 
void cop4530::List<T>::push_back(const T &val) {
    Node* currentTail = this->tail->next;
    Node* newNode = new Node(val, currentTail, nullptr);

    currentTail->next = newNode;
    this->tail->next = newNode;
    this->theSize += 1;
    // cout << val << " pushed to the back (COPY)" << endl;
};

template<typename T> 
void cop4530::List<T>::push_back(T&& val) {
    Node* currentTail = this->tail->next;
    Node* newNode = new Node(val, currentTail, nullptr);

    currentTail->next = newNode;
    this->tail->next = newNode;
    this->theSize += 1;
    // cout << val << " pushed to the back (MOVE)" << endl;
};

template<typename T> 
void cop4530::List<T>::print(std::ostream &os, char ofc) const {
    Node* curr = this->head->next;

    while(curr != nullptr) {
        cout << curr->data << ofc;
        curr = curr->next;
    }
};


// template<typename T> 
// std::ostream &cop4530::operator<<(std::ostream &os, const cop4530::List<T> &l) {

//     for(int i = 0; i < l.theSize; i ++) {
//         GET ITERATOR
//         os << ITERATOR RETURNS DATA HERE << " ";
//         ITERATOR MOVES FORWARD;
//     }
//     return os;
// };


template<typename T> 
typename cop4530::List<T>::const_iterator cop4530::List<T>::begin() const {
    cout << "begin() for const_iterator" << endl;
    const_iterator newIter;
    if(this->theSize != 0) {
        newIter.current = this->head->next;
    }
    return newIter;
};
template <typename T>
cop4530 :: List<T> :: const_iterator :: const_iterator() {
    Node* current = nullptr;
}
template <typename T>
cop4530 :: List<T> :: const_iterator :: const_iterator(Node* p) {
    Node* current = p;
}
template <typename T>
T& cop4530 :: List<T> :: const_iterator :: retrieve() const {
    return current->data;
}
template <typename T>
const T& cop4530 :: List<T> :: const_iterator :: operator*() const {
    return this->retrieve();
}



template<typename T> 
typename cop4530::List<T>::iterator cop4530::List<T>::begin() {
    cout << "begin() for iterator" << endl;
    iterator newIter;
    if(this->theSize != 0) {
        newIter.current = this->head->next;
    }
    return newIter;
};
template <typename T>
cop4530 :: List<T> :: iterator :: iterator() {
    Node* current = nullptr;
}
template <typename T>
cop4530 :: List<T> :: iterator :: iterator(Node* p) {
    Node* current = p;
}
template <typename T>
T& cop4530 :: List<T> :: iterator :: operator*() {
    return cop4530 :: List<T> :: const_iterator :: retrieve();
}
template <typename T>
const T& cop4530 :: List<T> :: iterator :: operator*() const {
    return cop4530 :: List<T> :: const_iterator :: operator*();
}

