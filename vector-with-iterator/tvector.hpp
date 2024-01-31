


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
		

template <typename T>
T& TVector<T>::GetFirst() const {
    if(this->size == 0) { 
        std::cout << "Vector is empty" << std::endl;
        return this->dummy;
    }
    return this->array[0];
    // this->size--;

    // do we need to shift the array after getting first element?
    
}


template <typename T>
T& TVector<T>::GetLast() const {
    if(this->size == 0) { 
        std::cout << "Vector is empty" << std::endl;
        return this->dummy;
    }
    return this->array[this->size-1];
    // this->size--;

    // make sure the last element in the array is set to empty after returning?

}


template <typename T>
void TVector<T>::Print(std::ostream& os, char delim) const {
    std::cout << "Print()" << std::endl;
    for(int i = 0; i < this->size; i++) {
        std::cout << this->array[i] << " ";
    }
    std::cout << std::endl;

}


template <typename T>
void TVector<T>::InsertBack(const T& d) {
    if(this->size == this->capacity) {
        this->capacity *= 2;
        T* tempArr = new T[this->capacity];
        for(int i = 0; i < this->size; i++) {
            tempArr[i] = this->array[i];
        }
        delete [] this->array;
        this->array = tempArr;
    }

    this->array[size] = d;
    this->size++;
}


template <typename T>
void TVector<T>::RemoveBack() {

    // do we set the spot to dummy or to empty?

    T empty;
    this->array[size] = empty;
    this->size--;
}	





template <typename T>
TVectorIterator<T> TVector<T>::GetIterator() const {
    std::cout << "Return Iterator to first item" << std::endl;
    TVectorIterator<T> temp;
    temp.ptr = this->array;
    temp.index = 0;
    temp.vsize = this->size;
    return temp;
}

// ========================================================================================= //

template <typename T>
TVectorIterator<T>::TVectorIterator() {
    std::cout << "Default Iterator Constructor" << std::endl;
    this->index;
    this->vsize;
    this->ptr;
}

template <typename T>
T& TVectorIterator<T>::GetData() const {
    std::cout << "GetData(): " << this->ptr[index] << std::endl;
    return this->ptr[index];
}


template <typename T>
bool TVectorIterator<T>::HasNext() const {
    if(this->index != this->vsize - 1) {
        return true;
    }
    return false;
}


template <typename T>
bool TVectorIterator<T>::HasPrevious() const {
    if(this->index == 0) {
        return false;
    }
    return true;
}

template <typename T>
TVectorIterator<T> TVectorIterator<T>::Next() {
    std::cout << "Next: Current index " << this->index << std::endl;
    if(this->HasNext()) {
        TVectorIterator<T> newI;
        newI.index = this->index + 1;
        newI.ptr = this->ptr;
        newI.vsize = this->vsize;
        *this = newI;
        std::cout << "Next: New index " << newI.index << std::endl << std::endl;
        return *this;
    }
    std::cout << "No Next Element" << std::endl;
}

template <typename T>
TVectorIterator<T> TVectorIterator<T>::Previous() {
    std::cout << "Prev: Current index " << this->index << std::endl;
    if(this->HasPrevious()) {
        TVectorIterator<T> newI;
        newI.index = this->index - 1;
        newI.ptr = this->ptr;
        newI.vsize = this->vsize;
        *this = newI;
        std::cout << "Prev: New index " << newI.index << std::endl << std::endl;
        return *this;
    }
    std::cout << "No Prev Element" << std::endl;
}

