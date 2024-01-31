#ifndef TVECTOR_HPP
#define TVECTOR_HPP


#include <iostream>
#include <utility>

using namespace std;


template <typename T> class TVectorIterator;


template <typename T>
class TVector 
{
    friend class TVectorIterator<T>;

    public:
        TVector();
        TVector(T val, int num);

        ~TVector();
        TVector(const TVector<T>& v);
        TVector(TVector<T> && v);
        TVector<T>& operator=(const TVector<T>& v);
        TVector<T>& operator=(TVector<T> && v);

        bool IsEmpty() const;	
        void Clear();		
        int GetSize() const;			



    private:
        T* array;			// pointer to dynamic array of items
        unsigned int capacity;	// tracker for allocation of array
        unsigned int size;		// number of items in the array
        static T dummy;		// dummy object, for empty vector data returns
                    //  assuming type T has default construction
        static const unsigned int SPARECAPACITY = 10;
};



#include "tvector.hpp"
#endif // TVECTOR_HPP
