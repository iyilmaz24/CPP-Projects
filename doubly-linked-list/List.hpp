
#include <iostream>

using namespace std;


template <typename T>
cop4530 :: List<T> :: List() {
    cout << "Default Constructor Called";
};

template <typename T>
cop4530 :: List<T> :: ~List() {
    cout << "Destructor Called";
};