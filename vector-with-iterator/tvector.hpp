

template <typename T>
TVector<T>::TVector() {
    std::cout << "Default Constructor Called" << std::endl;
    this->capacity = this->SPARECAPACITY;
    this->array = new T[this->capacity];
    this->size = 0;
}


template <typename T>
TVector<T>::TVector(T val, int num) {
    std::cout << "Parameterized Constructor Called" << std::endl;
    this->capacity = num + this->SPARECAPACITY;
    this->array = new T[this->capacity];
    this->size = num;
    for(int i = 0; i < this->size; i++) {
        this->array[i] = val;
    }
}


template <typename T>
TVector<T>::~TVector() {
    cout << "Destructor Called" << endl;
    delete [] this->array;
}


template <typename T>
TVector<T>::TVector(const TVector<T>& v) {
    std::cout << "Copy Constructor Called" << std::endl;
    this->capacity = v.capacity;
    this->size = v.size;

    this->array = new T[this->capacity];
    for(int i = 0; i < this->size; i++) {
        this->array[i] = v.array[i];
    }
}


template <typename T>
TVector<T>::TVector(TVector<T> && v) {
    std::cout << "Move Constructor Called" << std::endl;
    this->capacity = v.capacity;
    this->size = v.size;

    this->array = v.array;
    v.array = nullptr;
}


template <typename T>
TVector<T>& TVector<T>::operator=(const TVector<T>& v) {
    std::cout << "Copy Assignment Operator Called" << std::endl;
    this->capacity = v.capacity;
    this->size = v.size;

    delete [] this->array;
    this->array = new T[this->capacity];
    for(int i = 0; i < this->size; i++) {
        this->array[i] = v.array[i];
    }
}


template <typename T>
TVector<T>& TVector<T>::operator=(TVector<T> && v) {
    std::cout << "Move Assignment Operator Called" << std::endl;
    int tempC = this->capacity;
    this->capacity = v.capacity;
    v.capacity = tempC;

    int tempS = this->size;
    this->size = v.size;
    v.size = tempS;

    T* ptr = this->array; 
    this->array = v.array;
    v.array = ptr;

    return *this;
}


template <typename T>
bool TVector<T>::IsEmpty() const {
    std::cout << "IsEmpty: " << ((this->size == 0) == 1 ? "true" : "false" ) << std::endl;
    return this->size == 0;
}


template <typename T>
void TVector<T>::Clear() {
    std::cout << "Clear()" << std::endl;
    delete [] this->array;
    this->array = new T[this->capacity];
    this->size = 0;
}


template <typename T>
int TVector<T>::GetSize() const {
    std::cout << "Size: " << this->size << std::endl;
    return this->size;
}
		
