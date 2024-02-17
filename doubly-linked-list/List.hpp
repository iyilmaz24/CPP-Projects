
#include <iostream>

using namespace std;


template <typename T>
cop4530 :: List<T> :: List() {
    cout << "Default Constructor Called" << endl;
    this->init();
};

template <typename T>
cop4530 :: List<T> :: List(int num, const T& val) {
    cout << "Constructing List of 'num' elements initialized with value 'val' (num, val)" << endl;
    this->init();
    for(int i = 0; i < num; i++) {
        // if(i == 0) {
        //     this->head->next = new Node(val);
        //     this->tail->prev = this->head->next;
        //     this->theSize += 1;
        //     continue;
        // }
        this->push_front(val);
        // Node* temp = this->head->next;
        // this->head->next = new Node(val, nullptr, temp);
        // temp->prev = this->head->next;
        // this->theSize += 1;
    }
};

template <typename T>
cop4530 :: List<T> :: List(const List& rhs) {
    cout << "Copy Constructor Called" << endl;
    this->init();
    auto iter = rhs.begin();

    for(int i = 0; i < rhs.theSize; i++) {
        this->push_back(*iter);
        iter++; 
    }
 
};

        // if(i == rhs.theSize - 1) {
        //     break;
        // }    
template <typename T>
cop4530 :: List<T> :: List(List &&rhs) : theSize{rhs.theSize}, head{rhs.head}, tail{rhs.tail} {
    cout << "Move Constructor Called" << endl;
    rhs.theSize = 0;
    rhs.head = nullptr;
    rhs.tail = nullptr;
};

template <typename T>
const cop4530::List<T>& cop4530::List<T>::operator=(const List &rhs) {
    cout << "Copy Assignment Operator Overload Called" << endl;
    List copy = rhs;
    std::swap(*this, copy);
    return *this;
};

template <typename T>
cop4530::List<T>& cop4530::List<T>::operator=(List &&rhs) {
    cout << "Move Assignment Operator Called" << end;
    std::swap(theSize, rhs.theSize);
    std::swap(head, rhs.head);
    std::swap(tail, rhs.tail);
    return *this;
};

template <typename T>
cop4530 :: List<T> :: ~List() {
    cout << "Destructor Called" << endl;
    if(this->theSize > 0) {
        this->clear();
    }
    delete this->head;         
    delete this->tail;  
};

template <typename T>
void cop4530 :: List<T> :: init() {
    this->theSize = 0;
    this->head = new Node();         
    this->tail = new Node();    
    cout << "init done" << endl;   
}

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
    // auto curr = this->begin();
    // while(curr.current->next != nullptr) {
    //     auto prev = curr;
    //     curr++;
    //     delete prev.current;
    // }
    // delete curr.current;
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
    // cout << val << " pushed to the front (COPY)" << endl;
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
    // cout << val << " pushed to the front (MOVE)" << endl;
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
    // cout << val << " pushed to the back (COPY)" << endl;
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
    // cout << val << " pushed to the back (MOVE)" << endl;
};
template <typename T>
void cop4530 :: List<T> :: pop_front() {
    if(this->head->next != nullptr) {
        cout << "pop_front head->next: " << this->head->next->data << endl;
        Node* currentHead = this->head->next;
        this->head->next = this->head->next->next;
        this->head->next->prev = nullptr;
        delete currentHead;
        currentHead = nullptr;
        this->theSize -= 1;
    }
};
template <typename T>
void cop4530 :: List<T> :: pop_back() {
    if(this->tail->prev != nullptr) {
        cout << "pop_back tail->prev: " << this->tail->prev->data << endl;
        Node* currentTail = this->tail->prev;
        this->tail->prev = this->tail->prev->prev;
        this->tail->prev->next = nullptr;
        delete currentTail;
        currentTail = nullptr;
        this->theSize -= 1;
    }
};
template <typename T>
void cop4530 :: List<T> :: remove(const T& val) {
    
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
    // cout << "data: " << this->tail->prev->data << " pointer: " << this->tail->prev << endl;
    iterator newIter;
    if(this->theSize != 0) {
        newIter.current = this->tail->prev;
    }
    return newIter;
}
template <typename T>
typename cop4530::List<T>::const_iterator cop4530::List<T>::end() const {
    const_iterator newIter;
    if(this->theSize != 0) {
        newIter.current = this->tail->prev;
    }
    return newIter;
}
template <typename T>
typename cop4530::List<T>::iterator cop4530::List<T>::insert(iterator itr, const T& val) {

}
template <typename T>
typename cop4530::List<T>::iterator cop4530::List<T>::insert(iterator itr, T && val) {

}
template <typename T>
typename cop4530::List<T>::iterator cop4530::List<T>::erase(iterator itr) {
    if(itr.current == (this->end()).current) {
        iterator nextItr;
        nextItr.current = itr.current->prev;
        nextItr.current->next = nullptr;
        this->tail->prev = nextItr.current;
        delete itr.current;
        this->theSize -= 1;
        return nextItr;
    }
    if(itr.current == (this->begin()).current) {
        iterator nextItr;
        nextItr.current = itr.current->next;
        nextItr.current->prev = nullptr;
        this->head->next = nextItr.current;
        delete itr.current;
        this->theSize -= 1;
        return nextItr; 
    }
    iterator nextItr;
    nextItr.current = itr.current->next;
    nextItr.current->prev = itr.current->prev;
    itr.current->prev->next = nextItr.current;
    delete itr.current;
    this->theSize -= 1;
    return nextItr;
}
template <typename T>
typename cop4530::List<T>::iterator cop4530::List<T>::erase(iterator start, iterator end) {
    for(cop4530::List<T>::iterator curr = start; curr != end; ) {
        start = erase(start);
    }
}


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
    return this->current->data;
}
template <typename T>
const T& cop4530 :: List<T> :: const_iterator :: operator*() const {
    return this->retrieve();
}
template <typename T>
typename cop4530::List<T>::const_iterator& cop4530 :: List<T> :: const_iterator :: operator++() {
    if(this->current->next != nullptr) {
        this->current = this->current->next;
    }
    return *this;
}
template <typename T>
typename cop4530::List<T>::const_iterator cop4530 :: List<T> :: const_iterator :: operator++(int) {
    cop4530::List<T>::const_iterator iter = *this;
    if(this->current->next != nullptr) {
        ++(*this);
        return iter;
    }
    return iter;
}
template <typename T>
typename cop4530::List<T>::const_iterator& cop4530 :: List<T> :: const_iterator :: operator--() {
    if(this->current->prev != nullptr) {
        this->current = this->current->prev;
    }
    return *this;
}
template <typename T>
typename cop4530::List<T>::const_iterator cop4530 :: List<T> :: const_iterator :: operator--(int) {
    cop4530::List<T>::const_iterator iter = *this;
    if(this->current->prev != nullptr) {
        --(*this);
        return iter;
    }
    return iter;
}
template <typename T>
bool cop4530 :: List<T> :: const_iterator :: operator==(const const_iterator& rhs) const {
    return (this->current == rhs->current);
}
template <typename T>
bool cop4530 :: List<T> :: const_iterator :: operator!=(const const_iterator& rhs) const {
    return (*this != rhs);
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
    return cop4530::List<T>::const_iterator::retrieve();
}
template <typename T>
const T& cop4530 :: List<T> :: iterator :: operator*() const {
    return cop4530::List<T>::const_iterator::operator*();
}
template <typename T>
typename cop4530::List<T>::iterator& cop4530 :: List<T> :: iterator :: operator++() {
    if(this->current->next != nullptr) {
        this->current = this->current->next;
    }
    return *this;
}
template <typename T>
typename cop4530::List<T>::iterator cop4530 :: List<T> :: iterator :: operator++(int) {
    cop4530::List<T>::iterator iter = *this;
    if(this->current->next != nullptr) {
        ++(*this);
        return iter;
    }
    return iter;
}
template <typename T>
typename cop4530::List<T>::iterator& cop4530 :: List<T> :: iterator :: operator--() {
    if(this->current->prev != nullptr) {
        this->current = this->current->prev;
    }
    return *this;
}
template <typename T>
typename cop4530::List<T>::iterator cop4530 :: List<T> :: iterator :: operator--(int) {
    cop4530::List<T>::iterator iter = *this;
    if(this->current->prev != nullptr) {
        --(*this);
        return iter;
    }
    return iter;
}





template <typename T>
bool cop4530::operator==(const List<T>& lhs, const List<T>& rhs) {
    return (lhs == rhs);
}

template<typename T>
bool cop4530::operator!=(const List<T>& lhs, const List<T>& rhs) {
    return (!(lhs != rhs));
}

template<typename T> 
std::ostream& cop4530::operator<<(std::ostream &os, const cop4530::List<T> &l) {
    l.print(os);
    return os;
};

