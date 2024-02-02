


template <typename T>
TVector<T>::TVector() {
    // std::cout << "Default Constructor Called" << std::endl;
    this->capacity = this->SPARECAPACITY;
    this->array = new T[this->capacity];
    this->size = 0;
}


template <typename T>
TVector<T>::TVector(T val, int num) {
    // std::cout << "Parameterized Constructor Called" << std::endl;
    this->capacity = num + this->SPARECAPACITY;
    this->array = new T[this->capacity];
    this->size = num;
    for(int i = 0; i < this->size; i++) {
        this->array[i] = val;
    }
}


template <typename T>
TVector<T>::~TVector() {
    // cout << "Destructor Called" << endl;
    delete [] this->array;
}


template <typename T>
TVector<T>::TVector(const TVector<T>& v) {
    // std::cout << "Copy Constructor Called" << std::endl;
    this->capacity = v.capacity;
    this->size = v.size;

    this->array = new T[this->capacity];
    for(int i = 0; i < this->size; i++) {
        this->array[i] = v.array[i];
    }
}


template <typename T>
TVector<T>::TVector(TVector<T> && v) {
    // std::cout << "Move Constructor Called" << std::endl;
    this->capacity = v.capacity;
    this->size = v.size;

    this->array = v.array;
    v.array = nullptr;
}


template <typename T>
TVector<T>& TVector<T>::operator=(const TVector<T>& v) {
    // std::cout << "Copy Assignment Operator Called" << std::endl;
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
    // std::cout << "Move Assignment Operator Called" << std::endl;
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
    // std::cout << "IsEmpty: " << ((this->size == 0) == 1 ? "true" : "false" ) << std::endl;
    return this->size == 0;
}


template <typename T>
void TVector<T>::Clear() {
    // std::cout << "Clear()" << std::endl;
    delete [] this->array;
    this->array = new T[this->capacity];
    this->size = 0;
}


template <typename T>
int TVector<T>::GetSize() const {
    // std::cout << "Size: " << this->size << std::endl;
    return this->size;
}
		

template <typename T>
T& TVector<T>::GetFirst() const {
    if(this->size == 0) { 
        // std::cout << "Vector is empty" << std::endl;
        return this->dummy;
    }
    return this->array[0];
}


template <typename T>
T& TVector<T>::GetLast() const {
    if(this->size == 0) { 
        // std::cout << "Vector is empty" << std::endl;
        return this->dummy;
    }
    return this->array[this->size-1];
}


template <typename T>
void TVector<T>::Print(std::ostream& os, char delim) const {
    // std::cout << "Print()" << std::endl;
    for(int i = 0; i < this->size; i++) {
        std::cout << this->array[i] << delim;
    }

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
    this->array[size] = dummy;
    this->size--;
}	


template <typename T>
void TVector<T>::SetCapacity(unsigned int c) {
    if(c != this->capacity) {
        T* temp = new T[c];

        this->size = (c < this->size ? c : this->size);
        for(int i = 0; i < this->size; i++) {
            temp[i] = this->array[i];
        }
        delete [] this->array;
        this->array = temp;
        this->capacity = c;
    }
}   


template <typename T>
TVector<T> operator+(const TVector<T>& t1, const TVector<T>& t2) {
    // std::cout << "operator+" << std::endl;
    TVector<T> temp;
    temp.SetCapacity(t1.GetSize() + t2.GetSize() + 10);
    TVectorIterator<T> tempIter = temp.GetIterator();

    TVectorIterator<T> t1Iter = t1.GetIterator();
    while(t1Iter.HasNext()) {
        temp.Insert(tempIter, t1Iter.GetData());
        tempIter.Next();
        t1Iter.Next();
    }
    if(t1.GetSize() != 0) {
        temp.Insert(tempIter, t1Iter.GetData());
        tempIter.Next();
        t1Iter.Next();   
    }
    
    TVectorIterator<T> t2Iter = t2.GetIterator();
    while(t2Iter.HasNext()) {
        temp.Insert(tempIter, t2Iter.GetData());
        tempIter.Next();
        t2Iter.Next();
    }
    if(t2.GetSize() != 0) {
        temp.Insert(tempIter, t2Iter.GetData());
        tempIter.Next();
        t2Iter.Next();   
    }

    return temp;
}


template <typename T>
TVectorIterator<T> TVector<T>::Insert(TVectorIterator<T> pos, const T& d) {
    if(pos.ptr == nullptr) {
        pos.ptr = this->array;
    }

    if(this->size == this->capacity) {
        this->capacity *= 2;
        T* tempArr = new T[this->capacity];
        for(int i = 0; i < this->size; i++) {
            tempArr[i] = this->array[i];
        }
        delete [] this->array;
        this->array = tempArr;
        pos.ptr = this->array;
        tempArr = nullptr;
    }

    if(this->size == 0 || pos.index > this->capacity - 1) {
        // insert in the back, if empty vector or out of range
        this->array[this->size] = d;
        pos.index = this->size;
        this->size++;
        pos.vsize = this->size;
        return pos;
    }

    T* tempArr = new T[this->capacity];
    int j = 0;
    for(int i = 0; i < this->size + 1; i++) {
        if(pos.index == i) {
            tempArr[i] = d;
            i += 1;
        }
        tempArr[i] = this->array[j];
        j++;
    }
    delete [] this->array;
    this->array = tempArr;
    pos.ptr = this->array;
    tempArr = nullptr;

    this->size++;
    pos.vsize = this->size;
    return pos;
    
    // returned iterator set to the inserted data
}


template <typename T>
TVectorIterator<T> TVector<T>::Remove(TVectorIterator<T> pos) {

    if(this->size == 0 || pos.index > this->capacity - 1) {
        // return default iterator, if empty vector or index out of range
        TVectorIterator<T> defaultIter;
        return defaultIter;
    }

    T* tempArr = new T[this->capacity];
    int j = 0;
    for(int i = 0; i < this->size; i++) {
        if(pos.index == i) {
            i += 1;
        }
        tempArr[j] = this->array[i];
        j++;
    }
    delete [] this->array;
    this->array = tempArr;
    tempArr = nullptr;
    pos.ptr = this->array;

    // std::cout << "pos.index: " << pos.index << ", this->array[pos.index]: " << this->array[pos.index] << std::endl; 
    this->size--;
    pos.vsize = this->size;
    return pos;
    
    // returned iterator set to the next data element after deleted one
}


template <typename T>
TVectorIterator<T> TVector<T>::Remove(TVectorIterator<T> pos1, TVectorIterator<T> pos2){

    if(this->size == 0 || pos1.index > this->capacity - 1) {
        // return default iterator, if empty vector or first index out of range
        TVectorIterator<T> defaultIter;
        return defaultIter;
    }

    if(pos2.index - pos1.index == 1) {
        return Remove(pos1);
    }
    // if pos2 iterator index is before the pos1 iterator or is on the same element, return pos1 iterator
    if(pos2.index - pos1.index <= 0 || pos2.index == 0) {
        return pos1;
    }

    T* tempArr = new T[this->capacity];
    int start = pos1.index;
    int end = pos2.index;
    if(pos2.index > this->capacity - 1) {
        int end = this->capacity - 1;
    }
    int j = 0;
    // while loop iterates i until we reach end of delete range
    for(int i = 0; i < this->size; i++) {
        if(start == i) {
            while(i != end) {
                i += 1;
            }
        }
        tempArr[j] = this->array[i];
        j++;
    }

    delete [] this->array;
    this->array = tempArr;
    tempArr = nullptr;
    pos1.ptr = this->array;

    this->size -= pos2.index - pos1.index;
    pos1.vsize = this->size;
    return pos1;
    
    // returned iterator set to the next data element after the one deleted last
}


template <typename T>
TVectorIterator<T> TVector<T>::GetIterator() const {
    // std::cout << "Return Iterator to first item" << std::endl;
    TVectorIterator<T> temp;
    if(this->size > 0) {
        temp.ptr = this->array;
    }
    temp.index = 0;
    temp.vsize = this->size;
    return temp;
}


template <typename T>
TVectorIterator<T> TVector<T>::GetIteratorEnd() const {
    // std::cout << "Return Iterator to last item" << std::endl;
    TVectorIterator<T> temp;
    temp.index = 0;
    if(this->size > 0) {
        temp.ptr = this->array;
        temp.index = this->size - 1;
    }
    temp.vsize = this->size;
    return temp;
}

// ========================================================================================= //

template <typename T>
TVectorIterator<T>::TVectorIterator() {
    // std::cout << "Default Iterator Constructor" << std::endl;
    this->index;
    this->vsize;
    this->ptr = nullptr;
}

template <typename T>
T& TVectorIterator<T>::GetData() const {
    // std::cout << "GetData(): " << this->ptr[index] << std::endl;
    // std::cout << "Current index: " << this->index << std::endl;
    if(this->ptr == nullptr) {
        return TVector<T>::dummy;
    }
    return this->ptr[index];
}


template <typename T>
bool TVectorIterator<T>::HasNext() const {
    if(this->ptr == nullptr) {
        return false;
    }
    if(this->index != this->vsize - 1) {
        return true;
    }
    return false;
}


template <typename T>
bool TVectorIterator<T>::HasPrevious() const {
    if(this->ptr == nullptr) {
        return false;
    }
    if(this->index == 0) {
        return false;
    }
    return true;
}

template <typename T>
TVectorIterator<T> TVectorIterator<T>::Next() {
    // std::cout << "Next: Current index " << this->index << std::endl;
    // std::cout << "Current vsize: " << vsize << std::endl;
    if(this->HasNext()) {
        TVectorIterator<T> newI;
        newI.index = this->index + 1;
        newI.ptr = this->ptr;
        newI.vsize = this->vsize;
        *this = newI;
        // std::cout << "Next: New index " << newI.index << std::endl << std::endl;
        return *this;
    }
    // std::cout << "No Next Element" << std::endl;
}

template <typename T>
TVectorIterator<T> TVectorIterator<T>::Previous() {
    // std::cout << "Prev: Current index " << this->index << std::endl;
    if(this->HasPrevious()) {
        TVectorIterator<T> newI;
        newI.index = this->index - 1;
        newI.ptr = this->ptr;
        newI.vsize = this->vsize;
        *this = newI;
        // std::cout << "Prev: New index " << newI.index << std::endl << std::endl;
        return *this;
    }
    // std::cout << "No Prev Element" << std::endl;
}

