

template<typename T, class container>
cop4530::Stack<T, container>:: Stack() {
    this->s_size = 0;
};
template<typename T, class container>
cop4530::Stack<T, container>:: Stack(const Stack<T>& rhs) {
    // std::cout << "copy constructor called" << std::endl;
    this->s_size = 0;
    for(int i = 0; i < rhs.s_size; i++) {
        this->push(rhs.stack[i]);
    }
};
template<typename T, class container>
cop4530::Stack<T, container>:: Stack(Stack<T>&& rhs) {
    // std::cout << "move constructor called" << std::endl;
    this->s_size = rhs.s_size;
    stack = rhs.stack;
};
template<typename T, class container>
Stack<T>& cop4530::Stack<T, container>:: operator=(const Stack<T>& rhs) {
    // std::cout << "copy operator called" << std::endl;
    this->s_size = 0;
    for(int i = 0; i < rhs.s_size; i++) {
        this->push(rhs.stack[i]);
    }
    return *this;
};
template<typename T, class container>
Stack<T>& cop4530::Stack<T, container>:: operator=(Stack<T>&& rhs) {
    // std::cout << "move operator called" << std::endl;
    std::swap(s_size, rhs.s_size);
    std::swap(stack, rhs.stack);
    return *this;
};
template<typename T, class container>
cop4530::Stack<T, container>:: ~Stack() {
    this->clear();
};


template<typename T, class container>
bool cop4530::Stack<T, container>:: empty() const {
    return this->s_size == 0;
};
template<typename T, class container>
void cop4530::Stack<T, container>:: clear() {
    this->stack.clear();
    this->s_size = 0;
};
template<typename T, class container>
int cop4530::Stack<T, container>:: size() const {
    return this->s_size;
};


template<typename T, class container>
void cop4530::Stack<T, container>:: push(const T& x) {
    this->stack.push_back(x);
    this->s_size += 1;
};
template<typename T, class container>
void cop4530::Stack<T, container>:: push(T && x) {
    this->stack.push_back(x);
    this->s_size += 1;
};
template<typename T, class container>
void cop4530::Stack<T, container>:: pop() {
    this->s_size -= 1;
};
template<typename T, class container>
T& cop4530::Stack<T, container>:: top() {
    return this->stack[(this->s_size - 1)];;
};
template<typename T, class container>
const T& cop4530::Stack<T, container>:: top() const {
    return this->stack[(this->s_size - 1)];
};


template<typename T, class container>
void cop4530::Stack<T, container>:: print(std::ostream &os, char ofc) const {
    for(int i = 0; i < this->s_size; i++) {
        std::cout << this->stack[i] << ofc;
    };
};



template<typename T, class container>
std::ostream& cop4530::operator<<(std::ostream &os, const cop4530::Stack<T, container> &a) {
    a.print(os);
    return os;
}
template<typename T, class container>
bool cop4530::operator==(const cop4530::Stack<T, container>& a, const cop4530::Stack<T, container>& b) {
    if(a.s_size != b.s_size) {
        return false;
    }
    for(int i = a.s_size - 1; i >= 0; i--) {
        auto x1 = a.stack[i];
        auto x2 = b.stack[i];
        if(x1 != x2) {
            return false;
        }
    };
    return true;
}
template<typename T, class container>
bool cop4530::operator!=(const cop4530::Stack<T, container>& a, const cop4530::Stack<T, container>& b) {
    return (!(a == b));
}
template<typename T, class container>
bool cop4530::operator<=(const cop4530::Stack<T, container>& a, const cop4530::Stack<T, container>& b) {
    for(int i = a.s_size - 1; i >= 0; i--) {
        auto x1 = a.stack[i];
        auto x2 = b.stack[i];
        if(x1 > x2) {
            return false;
        }
    };
    return true;
}


