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
        TVector<T>& operator=(const TVector<T>& v);

        TVector(TVector<T> && v);
        TVector<T>& operator=(TVector<T> && v);

        bool IsEmpty() const;	
        void Clear();		
        int GetSize() const;			

        void InsertBack(const T& d);
        void RemoveBack();	
        
        T& GetFirst() const;			
        T& GetLast() const;			

        TVectorIterator<T> GetIterator() const;
        TVectorIterator<T> GetIteratorEnd() const;

        void SetCapacity(unsigned int c);


        TVectorIterator<T> Insert(TVectorIterator<T> pos, const T& d);

        TVectorIterator<T> Remove(TVectorIterator<T> pos);

        TVectorIterator<T> Remove(TVectorIterator<T> pos1, TVectorIterator<T> pos2);


        void Print(std::ostream& os, char delim = ' ') const;

    private:
        T* array;			// pointer to dynamic array of items
        unsigned int capacity;	// tracker for allocation of array
        unsigned int size;		// number of items in the array
        static T dummy;		// dummy object, for empty vector data returns
                    //  assuming type T has default construction
        static const unsigned int SPARECAPACITY = 10;
};

template <typename T>
T TVector<T>::dummy;		// initialization of static member

// stand-alone function for concatenating two TVector objects
template <typename T>
TVector<T> operator+(const TVector<T>& t1, const TVector<T>& t2);


template <typename T>
class TVectorIterator
{
   friend class TVector<T>;

    public:
        TVectorIterator();			
        bool HasNext() const;		
        bool HasPrevious() const;		
        TVectorIterator<T> Next();		
        TVectorIterator<T> Previous();	
        T& GetData() const;			

    private:
        unsigned int index;			// index of current item in vector
        T* ptr;				// pointer to the data item
        unsigned int vsize;			// size of associated vector
};


#include "tvector.hpp"
#endif // TVECTOR_HPP
