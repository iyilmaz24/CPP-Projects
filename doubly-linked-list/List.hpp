
#include <iostream>

using namespace std;


template <typename T>
cop4530::List<T>::List() {
    this->init();
};

template <typename T> 
cop4530::List<T>::List(const_iterator start, const_iterator end) {
    this->init();
    while(start.current != end.current) {
        this->push_back(start.current->data);
        start++;
    }
    this->push_back(end.current->data);
};

template <typename T> 
cop4530::List<T>::List(std::initializer_list<T> iList) {
    this->init();
    int length = iList.size();
    auto curr = iList.begin();

    for(int i = 0; i < length; i++) {
        this->push_back(*curr);
        curr++;
    }
};

template <typename T> 
cop4530::List<T>& cop4530::List<T>::operator=(std::initializer_list<T> iList) {
    this->clear();
    delete this->head;
    delete this->tail;

    this->init();
    int length = iList.size();
    auto curr = iList.begin();
    for(int i = 0; i < length; i++) {
        this->push_back(*curr);
        curr++;
    }
    return *this;
};

template <typename T>
cop4530::List<T>::List(int num, const T& val) {
    this->init();
    for(int i = 0; i < num; i++) {
        this->push_front(val);
    }
};

template <typename T>
cop4530::List<T>::List(const List& rhs) {
    this->init();
    auto iter = rhs.begin();

    for(int i = 0; i < rhs.theSize; i++) {
        this->push_back(*iter);
        iter++; 
    }
};

template <typename T>
cop4530::List<T>::List(List &&rhs) : theSize{rhs.theSize}, head{rhs.head}, tail{rhs.tail} {
    rhs.theSize = 0;
    rhs.head = nullptr;
    rhs.tail = nullptr;
};

template <typename T>
const cop4530::List<T>& cop4530::List<T>::operator=(const List &rhs) {
    List copy = rhs;
    std::swap(*this, copy);
    return *this;
};

template <typename T>
cop4530::List<T>& cop4530::List<T>::operator=(List &&rhs) {
    std::swap(theSize, rhs.theSize);
    std::swap(head, rhs.head);
    std::swap(tail, rhs.tail);
    return *this;
};

template <typename T>
cop4530::List<T>::~List() {
    if(this->theSize > 0) {
        this->clear();
    }
    delete this->head;         
    delete this->tail;  
};

template <typename T>
void cop4530::List<T>::init() {
    this->theSize = 0;
    this->head = new Node();         
    this->tail = new Node();    
};



template <typename T> 
int cop4530::List<T>::size() const {
    return this->theSize;
};
template <typename T> 
bool cop4530::List<T>::empty() const {
    return this->theSize == 0 ? true : false;
};
template <typename T>
void cop4530::List<T>::clear() { 
    Node* curr = this->head->next;
    while(curr != nullptr) {
        Node* prev = curr;
        curr = curr->next;
        delete prev;
        prev = nullptr;
        this->theSize -= 1;
    }
};
template <typename T>
void cop4530::List<T>::reverse() { 
    if(this->head->next == nullptr) {
        return;
    }
    Node* temp = this->head->next;
    this->head->next = this->tail->prev;
    this->tail->prev = temp;

    Node* curr = this->head->next;
    while(curr != nullptr) {
        Node* prev = curr;
        Node* prevNext = prev->next;
        prev->next = prev->prev;
        prev->prev = prevNext;
        curr = curr->next;
    }
};
template <typename T>
T& cop4530::List<T>::front() {
    return this->head->next->data;
};
template <typename T>
const T& cop4530::List<T>::front() const {
    return &(this->head->next->data);
};
template <typename T>
T& cop4530::List<T>::back() {
    return this->tail->prev->data;
};
template <typename T>
const T& cop4530::List<T>::back() const {
    return &(this->tail->prev->data);
};
template <typename T> 
void cop4530::List<T>::push_front(const T& val) {
    if(this->theSize == 0) {
        this->head->next = new Node(val);
        this->tail->prev = this->head->next;
        this->theSize += 1;
        return;
    }
    Node* currentHead = this->head->next;
    Node* newNode = new Node(val, nullptr, currentHead);

    currentHead->prev = newNode;
    this->head->next = newNode;
    this->theSize += 1;
};
template <typename T> 
void cop4530::List<T>::push_front(T&& val) {
    if(this->theSize == 0) {
        this->head->next = new Node(val);
        this->tail->prev = this->head->next;
        this->theSize += 1;
        return;
    }
    Node* currentHead = this->head->next;
    Node* newNode = new Node(val, nullptr, currentHead);

    currentHead->prev = newNode;
    this->head->next = newNode;
    this->theSize += 1;
};
template <typename T> 
void cop4530::List<T>::push_back(const T& val) {
    if(this->theSize == 0) {
        this->head->next = new Node(val);
        this->tail->prev = this->head->next;
        this->theSize += 1;
        return;
    }
    Node* currentTail = this->tail->prev;
    Node* newNode = new Node(val, currentTail, nullptr);

    currentTail->next = newNode;
    this->tail->prev = newNode;
    this->theSize += 1;
};
template <typename T> 
void cop4530::List<T>::push_back(T&& val) {
    if(this->theSize == 0) {
        this->head->next = new Node(val);
        this->tail->prev = this->head->next;
        this->theSize += 1;
        return;
    }
    Node* currentTail = this->tail->prev;
    Node* newNode = new Node(val, currentTail, nullptr);

    currentTail->next = newNode;
    this->tail->prev = newNode;
    this->theSize += 1;
};
template <typename T>
void cop4530::List<T>::pop_front() {
    Node* currentHead = this->head->next;
    if(this->theSize == 1) {
        this->tail->prev = nullptr;
        this->head->next = nullptr;
    }
    if(this->head->next != nullptr) {
        this->head->next = this->head->next->next;
        this->head->next->prev = nullptr;
    }
    delete currentHead;
    currentHead = nullptr;
    this->theSize -= 1;
};
template <typename T>
void cop4530::List<T>::pop_back() {
    Node* currentTail = this->tail->prev;
    if(this->theSize == 1) {
        this->tail->prev = nullptr;
        this->head->next = nullptr;
    }
    else if(this->tail->prev != nullptr) {
        this->tail->prev = this->tail->prev->prev;
        this->tail->prev->next = nullptr;
    }
    delete currentTail;
    currentTail = nullptr;
    this->theSize -= 1;
};
template <typename T>
void cop4530::List<T>::remove(const T& val) {
    auto itr = this->begin();
    while(itr.current != (this->end()).current) {
        if(itr.current->data == val) {
            itr = this->erase(itr);
        }
        else {
            itr++;
        }
    }
    if((this->end()).current->data == val) {
        this->pop_back();
    }
};
template <typename T> 
template <typename PREDICATE> 
void cop4530::List<T>::remove_if(PREDICATE pred) {
    auto itr = this->begin();
    while(itr.current != (this->end()).current)
    if(pred(itr.current->data) == true) {
        itr = this->erase(itr);
    }
    else {
        itr++;
    }
    if(pred((this->end()).current->data) == true) {
        this->pop_back();
    }
};
template <typename T> 
void cop4530::List<T>::print(std::ostream &os, char ofc) const {
    if(this->theSize == 0) {
        return;
    }
    Node* curr = this->head->next;
    while(curr != nullptr) {
        cout << curr->data << ofc;
        curr = curr->next;
    }
};



template <typename T>
typename cop4530::List<T>::iterator cop4530::List<T>::end() {
    iterator newIter;
    if(this->theSize != 0) {
        newIter.current = this->tail->prev;
    }
    return newIter;
};
template <typename T>
typename cop4530::List<T>::const_iterator cop4530::List<T>::end() const {
    const_iterator newIter;
    if(this->theSize != 0) {
        newIter.current = this->tail->prev;
    }
    return newIter;
};
template <typename T>
typename cop4530::List<T>::iterator cop4530::List<T>::insert(iterator itr, const T& val) {
    if(itr.current == this->end().current) {
        this->push_back(val);
        return itr;
    }
    Node* newNode = new Node(val, itr.current, itr.current->next);
    itr.current->next->prev = newNode;
    itr.current->next = newNode;
    this->theSize += 1;
    return itr;
};
template <typename T>
typename cop4530::List<T>::iterator cop4530::List<T>::insert(iterator itr, T && val) {
    if(itr.current == this->end().current) {
        this->push_back(val);
        return itr;
    }
    Node* newNode = new Node(val, itr.current, itr.current->next);
    itr.current->next->prev = newNode;
    itr.current->next = newNode;
    this->theSize += 1;
    return itr;
};
template <typename T>
typename cop4530::List<T>::iterator cop4530::List<T>::erase(iterator itr) {
    if(itr.current == this->tail->prev) {
        auto nextItr = this->end();
        (this->theSize == 1 ? nextItr : nextItr--);
        this->pop_back();
        return nextItr;
    }
    else if(itr.current == this->head->next) {
        auto nextItr = this->begin();
        (this->theSize == 1 ? nextItr : nextItr++);
        this->pop_front();
        return nextItr;
    }
    iterator nextItr;
    nextItr.current = itr.current->next;
    itr.current->prev->next = nextItr.current;
    nextItr.current->prev = itr.current->prev;
    
    delete itr.current;
    this->theSize -= 1;
    return nextItr;
};
template <typename T>
typename cop4530::List<T>::iterator cop4530::List<T>::erase(iterator start, iterator end) {
    iterator curr;
    curr.current = start.current;
    while(curr.current != end.current) {
        curr = this->erase(curr);
    }
    return end;
};


template <typename T> 
typename cop4530::List<T>::const_iterator cop4530::List<T>::begin() const {
    const_iterator newIter;
    newIter.current = this->head->next;
    return newIter;
};
template <typename T>
cop4530::List<T>::const_iterator::const_iterator() {
    Node* current = nullptr;
};
template <typename T>
cop4530::List<T>::const_iterator::const_iterator(Node* p) {
    Node* current = p;
};
template <typename T>
T& cop4530::List<T>::const_iterator::retrieve() const {
    return current->data;
};
template <typename T>
const T& cop4530::List<T>::const_iterator::operator*() const {
    return retrieve();
};
template <typename T>
typename cop4530::List<T>::const_iterator& cop4530::List<T>::const_iterator::operator++() {
    this->current = this->current->next;
    return *this;
};
template <typename T>
typename cop4530::List<T>::const_iterator cop4530::List<T>::const_iterator::operator++(int) {
    cop4530::List<T>::const_iterator iter = *this;
    ++(*this);
    return iter;
};
template <typename T>
typename cop4530::List<T>::const_iterator& cop4530::List<T>::const_iterator::operator--() {
    if(this->current->prev != nullptr) {
        this->current = this->current->prev;
    }
    return *this;
};
template <typename T>
typename cop4530::List<T>::const_iterator cop4530::List<T>::const_iterator::operator--(int) {
    cop4530::List<T>::const_iterator iter = *this;
    if(this->current->prev != nullptr) {
        --(*this);
        return iter;
    }
    return iter;
};
template <typename T>
bool cop4530::List<T>::const_iterator::operator==(const const_iterator& rhs) const {
    return (this->current == rhs.current);
};
template <typename T>
bool cop4530::List<T>::const_iterator::operator!=(const const_iterator& rhs) const {
    return !(*this == rhs);
};



template<typename T> 
typename cop4530::List<T>::iterator cop4530::List<T>::begin() {
    iterator newIter(head->next);
    newIter.current = head->next;
    return newIter;
};
template <typename T>
cop4530::List<T>::iterator::iterator() {
    this->current = nullptr;
};
template <typename T>
cop4530::List<T>::iterator::iterator(Node* p) : cop4530::List<T>::const_iterator::const_iterator(p) {
};
template <typename T>
T& cop4530::List<T>::iterator::operator*() {
    return cop4530::List<T>::const_iterator::retrieve();
};
template <typename T>
const T& cop4530::List<T>::iterator::operator*() const {
    return cop4530::List<T>::const_iterator::operator*();
};
template <typename T>
typename cop4530::List<T>::iterator& cop4530::List<T>::iterator::operator++() {
    this->current = this->current->next;
    return *this;
};
template <typename T>
typename cop4530::List<T>::iterator cop4530::List<T>::iterator::operator++(int) {
    cop4530::List<T>::iterator iter = *this;
    ++(*this);
    return iter;
};
template <typename T>
typename cop4530::List<T>::iterator& cop4530::List<T>::iterator::operator--() {
    if(this->current->prev != nullptr) {
        this->current = this->current->prev;
    }
    return *this;
};
template <typename T>
typename cop4530::List<T>::iterator cop4530::List<T>::iterator::operator--(int) {
    cop4530::List<T>::iterator iter = *this;
    if(this->current->prev != nullptr) {
        --(*this);
        return iter;
    }
    return iter;
};


template <typename T>
bool cop4530::operator==(const List<T>& lhs, const List<T>& rhs) {
    if(lhs.size() != rhs.size()) {
        return false;
    }
    auto l_itr = lhs.begin();
    auto r_itr = rhs.begin();
    for(int i = 0; i < rhs.size(); i++) {
        if(*l_itr != *r_itr) {
            return false;
        }
        l_itr++;
        r_itr++;
    }
    return true;
};
template<typename T>
bool cop4530::operator!=(const List<T>& lhs, const List<T>& rhs) {
    return (!(lhs == rhs));
};
template<typename T> 
std::ostream& cop4530::operator<<(std::ostream &os, const cop4530::List<T> &l) {
    l.print(os);
    return os;
};

