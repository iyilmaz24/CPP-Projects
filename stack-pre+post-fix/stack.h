#ifndef STACK_H
#define STACK_H
#include<vector>
#include<iostream>


namespace cop4530 {

    template<typename T>
    class Stack {

        public:
            std::vector<T> stack;
            int s_size;

            Stack(); // zero-argument constructor   
            ~Stack(); // destructor
            Stack (const Stack<T>&); // copy constructor
            Stack(Stack<T> &&); // move constructor

            Stack<T>& operator=(const Stack <T>&); // copy assignment operator=
            Stack<T>& operator=(Stack<T> &&); // move assignment operator=

            bool empty() const; // true if Stack contains no elements, false otherwise
            void clear(); // delete all elements from the stack
            int size() const; // returns the number of elements stored

            void push(const T& x); // adds x to Stack (copy version)
            void push(T && x); // adds x to Stack (move version)

            void pop(); // removes and discards the last added element  

            T& top(); // returns reference to most recently added element (as a modifiable L-value)
            const T& top() const; // accessor that returns most recently added element (as a const reference)  

            void print(std::ostream& os, char ofc = ' ') const; // print elements of Stack to ostream os
            // ofc is the separator between elements when printed out
            // Note that print() prints elements in the opposite order of the Stack 
            // (that is, the oldest element should be printed first)


};
        template<typename T>
            std::ostream& operator<<(std::ostream& os, const Stack<T>& a); // invokes the print() method to print the Stack<T> a in the specified ostream    

        template<typename T>
            bool operator==(const Stack<T>&, const Stack<T>&); // return true if compared Stacks have the same elements, in same order, false otherwise  

        template<typename T>
            bool operator!=(const Stack<T>&, const Stack<T>&); // opposite of operator==().

        template<typename T>
            bool operator<=(const Stack<T>& a, const Stack <T>& b); // return true if every element in Stack a is smaller than or equal to the corresponding element of Stack b, false otherwise


#include "stack.hpp"

}

#endif

