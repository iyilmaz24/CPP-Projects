
#include <iostream>

using namespace std;


template <typename T>
cop4530 :: List<T> :: List() {
    cout << "Default Constructor Called" << endl;
    init();

};

template <typename T>
cop4530 :: List<T> :: List(int num, const T& val) {
    cout << "Constructing List of 'num' elements initialized with value 'val' (num, val)" << endl;
    init();

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
    int theSize = 0;          
    Node *head = Node();            
    Node *tail = Node();            
}

template<class T> 
int cop4530::List<T>::size() const {

};

template<class T> 
bool cop4530::List<T>::empty() const {

};

template<class T> 
void cop4530::List<T>::push_front(const T &val) {

};

template<class T> 
void cop4530::List<T>::push_front(T &&val) {

};

template<class T> 
void cop4530::List<T>::push_back(const T &val) {

};

template<class T> 
void cop4530::List<T>::push_back(T &&val) {

};

template<class T> 
void cop4530::List<T>::print(std::ostream &os, char ofc = (char)32) const {

};

template<class T> 
cop4530::List<T>::iterator cop4530::List<T>::begin() {

};

template<class T> 
std::ostream &cop4530::operator<<(std::ostream &os, const cop4530::List<T> &l) {

};