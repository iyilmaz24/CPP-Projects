

template<typename T>
cop4530::Stack<T>:: Stack() {
    this->s_size = 0;
};
template<typename T>
cop4530::Stack<T>:: Stack(const Stack<T>& rhs) {
    *this = rhs;
};
template<typename T>
cop4530::Stack<T>:: Stack(Stack<T>&& rhs) {
    *this = rhs;
};
template<typename T>
Stack<T>& cop4530::Stack<T>:: operator=(const Stack<T>& rhs) {
    this->stack = rhs.stack;
    return *this;
};
template<typename T>
Stack<T>& cop4530::Stack<T>:: operator=(Stack<T>&& rhs) {
    this->stack = rhs.stack;
    return *this;
};
template<typename T>
cop4530::Stack<T>:: ~Stack() {
    this->clear();
};


template<typename T>
bool cop4530::Stack<T>:: empty() const {
    return this->s_size == 0;
};
template<typename T>
void cop4530::Stack<T>:: clear() {
    this->stack.clear();
    this->s_size = 0;
};
template<typename T>
int cop4530::Stack<T>:: size() const {
    return this->s_size();
};


template<typename T>
void cop4530::Stack<T>:: push(const T& x) {
    this->stack[this->s_size];
    this->s_size += 1;
};
template<typename T>
void cop4530::Stack<T>:: push(T && x) {
    this->stack[this->s_size];
    this->s_size += 1;
};
template<typename T>
void cop4530::Stack<T>:: pop() {
    this->s_size -= 1;
};
template<typename T>
T& cop4530::Stack<T>:: top() {
    return this->stack[(this->s_size - 1)];;
};
template<typename T>
const T& cop4530::Stack<T>:: top() const {
    return this->stack[(this->s_size - 1)];
};


template<typename T>
void cop4530::Stack<T>:: print(std::ostream &os, char ofc) const {
    for(int i = 0; i < this->s_size; i++) {
        std::cout << this->stack[i] << ofc;
    };
};



template<typename T>
std::ostream& cop4530::operator<<(std::ostream &os, const cop4530::Stack<T> &a) {
    a.print(os);
    return os;
}
template<typename T>
bool cop4530::operator==(const cop4530::Stack<T>& a, const cop4530::Stack<T>& b) {
    if(a.s_size() != b.s_size()) {
        return false;
    }
    while(a.s_size() != 0) {
        auto x1 = a.top();
        auto x2 = b.top();
        if(x1 != x2) {
            return false;
        }
        a.pop();
        b.pop();
    };
    return true;
}
template<typename T>
bool cop4530::operator!=(const cop4530::Stack<T>& a, const cop4530::Stack<T>& b) {
    return (!(a == b));
}
template<typename T>
bool cop4530::operator<=(const cop4530::Stack<T>& a, const cop4530::Stack<T>& b) {
    if(a.s_size() != b.s_size()) {
        return false;
    }
    while(a.s_size() != 0) {
        auto x1 = a.top();
        auto x2 = b.top();
        if(x1 != x2) {
            return false;
        }
        a.pop();
        b.pop();
    };
    return true;
}


