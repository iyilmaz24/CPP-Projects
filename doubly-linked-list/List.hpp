
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
            this->tail->prev = this->head->next;
            this->theSize += 1;
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
    Node* currentHead = this->head->next;
    Node* newNode = new Node(val, nullptr, currentHead);

    currentHead->prev = newNode;
    this->head->next = newNode;
    this->theSize += 1;
    // cout << val << " pushed to the front (COPY)" << endl;
};
template <typename T> 
void cop4530::List<T>::push_front(T&& val) {
    Node* currentHead = this->head->next;
    Node* newNode = new Node(val, nullptr, currentHead);

    currentHead->prev = newNode;
    this->head->next = newNode;
    this->theSize += 1;
    // cout << val << " pushed to the front (MOVE)" << endl;
};
template <typename T> 
void cop4530::List<T>::push_back(const T& val) {
    Node* currentTail = this->tail->prev;
    Node* newNode = new Node(val, currentTail, nullptr);

    currentTail->next = newNode;
    this->tail->prev = newNode;
    this->theSize += 1;
    // cout << val << " pushed to the back (COPY)" << endl;
};
template <typename T> 
void cop4530::List<T>::push_back(T&& val) {
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
template <typename T>
typename cop4530::List<T>::const_iterator& cop4530 :: List<T> :: const_iterator :: operator++() {
    if(this->current->next != nullptr) {
        this->current = this->current->next;
    }
    return *this;
}
template <typename T>
typename cop4530::List<T>::const_iterator cop4530 :: List<T> :: const_iterator :: operator++(int) {
    if(this->current->next != nullptr) {
        cop4530::List<T>::const_iterator iter = *this;
        ++(*this);
        return iter;
    }
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
    if(this->current->prev != nullptr) {
        cop4530::List<T>::const_iterator iter = *this;
        --(*this);
        return iter;
    }
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
    if(this->current->next != nullptr) {
        cop4530::List<T>::iterator iter = *this;
        ++(*this);
        return iter;
    }
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
    if(this->current->prev != nullptr) {
        cop4530::List<T>::iterator iter = *this;
        --(*this);
        return iter;
    }
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

