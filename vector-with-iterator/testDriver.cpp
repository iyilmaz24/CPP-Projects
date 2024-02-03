#include <iostream>
#include <string>

#include "tvector.h"

using namespace std;

int main() {

    TVector<char> c1;		// char list
    c1.InsertBack('a');
    c1.InsertBack('b');
    c1.InsertBack('c');
    c1.InsertBack('d');
    c1.InsertBack('e');
    cout << "After adding all the chars: ";
    c1.Print(cout);
    cout << endl;

    c1.RemoveBack();
    c1.RemoveBack();
    cout << "Using RemoveBack 2x: ";
    c1.Print(cout);
    cout << endl;

    TVectorIterator<char> c1Iter = c1.GetIterator();
    cout << "GetIterator and Remove 2x : ";
    c1Iter = c1.Remove(c1Iter);
    c1Iter = c1.Remove(c1Iter);
    c1.Print(cout);
    cout << endl;

    cout << "c1Iter HasNext: " << (c1Iter.HasNext() ? "True" : "False") << endl;
    cout << "c1Iter HasPrevious: " << (c1Iter.HasPrevious() ? "True" : "False") << endl;
    cout << "c1 IsEmpty: " << (c1.IsEmpty() ? "True" : "False") << endl;
    cout << "c1 GetSize: " << c1.GetSize() << endl;
    cout << " - Used c1 Clear -" << endl;
    c1.Clear();
    cout << "c1 IsEmpty: " << (c1.IsEmpty() ? "True" : "False") << endl;
    cout << "c1 GetSize: " << c1.GetSize() << endl;




    cout << endl << endl;




    TVector<int> v1;		// integer list

    cout << "Using GetIterator on v1 and traversing forwards, inserting i+=1 each time to the list" << endl;
    TVectorIterator<int> v1Iterator = v1.GetIterator();
    for (int i = 0; i < 10; i++) {
        // note that we are supposed to have the iterator return at the same index, meaning we can never insert
        // directly at the end, but rather always will push the end element further down when inserting at it's index
        v1Iterator = v1.Insert(v1Iterator, i);
        v1.Print(cout);
        v1Iterator.Next();
        v1Iterator.Next();
        cout << endl;
    }
    cout << "Now lets traverse our newly populated list" << endl;

    cout << "Using GetIterator on v1 and traversing forwards until last index" << endl;
    TVectorIterator<int> v1Iter = v1.GetIterator();
    for (int i = 0; i < 10; i++) {
        cout << v1Iter.GetData() << " ";
        v1Iter.Next();
    }
    cout << endl;

    cout << "Using GetIteratorEnd on v1 and traversing backward till index 0" << endl;
    TVectorIterator<int> v1IterEnd = v1.GetIteratorEnd();
    for (int i = v1.GetSize(); i > 0; i--) {
        cout << v1IterEnd.GetData() << " ";
        v1IterEnd.Previous();
    }
    cout << endl;

    cout << "Now lets use Remove to take out half of the list" << endl;
    TVectorIterator<int> v1IteratorRemove = v1.GetIterator();
    for (int i = 0; i < v1.GetSize(); i++) {
        v1IteratorRemove = v1.Remove(v1IteratorRemove);
    }
    v1.Print(cout);
    cout << endl;




    cout << endl << endl;




    cout << "Now we can make a list of 50 ints, and use a range based Remove to manipulate them" << endl;
    TVector<int> v50;		// integer list
    for (int i = 0; i < 50; i++) {
        v50.InsertBack(i);
    }
    v50.Print(cout);
    cout << endl;

    TVectorIterator<int> v50Iterator1 = v50.GetIterator();
    TVectorIterator<int> v50Iterator2 = v50.GetIterator();
    cout << "Removing indexes 0 - 4 with range (0, 5)" << endl;
    for (int i = 0; i < 5; i++) {
        v50Iterator2.Next();
    }
    v50Iterator1 = v50.Remove(v50Iterator1, v50Iterator2);
    v50.Print(cout);
    cout << endl;

    cout << "Removing indexes 0 - 9 with range (0, 10)" << endl;
    for (int i = 0; i < 5; i++) {
        v50Iterator2.Next();
    }
    v50Iterator1 = v50.Remove(v50Iterator1, v50Iterator2);
    v50.Print(cout);
    cout << endl;

    cout << "Removing indexes 0 - 14 with range (0, 15)" << endl;
    for (int i = 0; i < 5; i++) {
        v50Iterator2.Next();
    }
    v50Iterator1 = v50.Remove(v50Iterator1, v50Iterator2);
    v50.Print(cout);
    cout << endl;

    cout << "First Element: " << v50.GetFirst() << endl;
    cout << "Last Element: " << v50.GetLast() << endl;
    
    cout << "Use SetCapacity to shrink array to 10 elements" << endl;
    v50.SetCapacity(10);
    v50.Print(cout);
    cout << endl;




    cout << endl << endl;




    // Copy Assignment Operator
    TVector<int> v50Copy;
    v50Copy = v50;
    cout << "v50Copy: ";
    v50Copy.Print(cout);
    cout << endl;

    TVectorIterator<int> v50ci = v50Copy.GetIteratorEnd();
    v50ci = v50Copy.Remove(v50ci);
    v50ci = v50Copy.Remove(v50ci);
    v50ci = v50Copy.Remove(v50ci);
    cout << "v50Copy after 3 removes with iterator at end: ";
    v50Copy.Print(cout);
    cout << endl;

    int insert99 = 99;
    v50Copy.Insert(v50ci, insert99);
    v50ci = v50Copy.Insert(v50ci, 99);
    v50ci = v50Copy.Insert(v50ci, 99);
    v50ci = v50Copy.Insert(v50ci, 99);
    cout << "v50Copy after 4 inserts of 99 with iterator at end: ";
    v50Copy.Print(cout);
    cout << endl;

    v50Copy.RemoveBack();
    v50Copy.RemoveBack();
    v50Copy.RemoveBack();
    cout << "v50Copy after 3 remove back: ";
    v50Copy.Print(cout);
    cout << endl;

    v50Copy.InsertBack(101);
    v50Copy.InsertBack(101);
    cout << "v50Copy after 2 insert back of 101: ";
    v50Copy.Print(cout);
    cout << endl;

    TVectorIterator<int> v50rbr1 = v50Copy.GetIterator();
    TVectorIterator<int> v50rbr2 = v50Copy.GetIterator();
    v50rbr2.Next();
    v50rbr2.Next();
    v50rbr1 = v50Copy.Remove(v50rbr1, v50rbr2);
    cout << "v50Copy after range based remove 1: ";
    v50Copy.Print(cout);
    cout << endl;

    v50rbr1 = v50Copy.Remove(v50rbr1, v50rbr2);
    cout << "v50Copy after range based remove 2: ";
    v50Copy.Print(cout);
    cout << endl;

    v50rbr1 = v50Copy.Remove(v50rbr1, v50rbr2);
    cout << "v50Copy after range based remove 3: ";
    v50Copy.Print(cout);
    cout << endl;

    v50rbr1 = v50Copy.Remove(v50rbr1, v50rbr2);
    cout << "v50Copy after range based remove 4: ";
    v50Copy.Print(cout);
    cout << endl;

    


    cout << endl << endl;




    // Move Assignment Operator
    TVector<int> v50Move;
    v50Move = move(v50);
    cout << "v50Move: ";
    v50Move.Print(cout);
    cout << endl;

    TVectorIterator<int> v50start = v50Move.GetIterator();
    v50Move.Remove(v50start);
    v50Move.Remove(v50start);
    cout << "v50Move after 2x remove from index 0 iterator: ";
    v50Move.Print(cout);
    cout << endl;

    v50Move.RemoveBack();
    v50Move.RemoveBack();
    cout << "v50Move after 2x remove back: ";
    v50Move.Print(cout);
    cout << endl;

    v50Move.Remove(v50start);
    v50Move.Remove(v50start);
    cout << "v50Move after 2x remove again from index 0 iterator: ";
    v50Move.Print(cout);
    cout << endl;




    cout << endl << endl;




    // operator+
    TVector<int> v50Add;
    v50Add = v50Move + v50Copy;
    cout << "v50Add = v50Move + v50Copy: ";
    v50Add.Print(cout);
    cout << endl;



    
    cout << endl << endl;




    // Copy Constructor
    TVector<int> intV = v50Add;
    cout << "Copy construction of intV from v50Add: ";
    intV.Print(cout);
    cout << endl;



    
    cout << endl << endl;




    // Move Constructor
    TVector<int> vMove = move(v50Add);
    cout << "Move construction of vMove from v50Add: ";
    vMove.Print(cout);
    cout << endl;

    TVectorIterator<int> vMoveIter = vMove.GetIterator();
    vMove.Insert(vMoveIter, 88);
    vMove.Insert(vMoveIter, 88);
    cout << "vMove after 2x insert of 88: ";
    vMove.Print(cout);
    cout << endl;

    vMove.RemoveBack();
    cout << "vMove after remove back: ";
    vMove.Print(cout);
    cout << endl;



    
    cout << endl << endl;



    
    // TVector(T val, int num)
    cout << "doubleV: ";
    TVector<double> doubleV(5.5, 3);
    doubleV.Print(cout);
    cout << endl;

    doubleV.RemoveBack();
    doubleV.RemoveBack();
    cout << "doubleV after RemoveBack 2x: ";
    doubleV.Print(cout);
    cout << endl;

    doubleV.InsertBack(44.4);
    doubleV.InsertBack(77.7);
    cout << "doubleV after InsertBack 2x: ";
    doubleV.Print(cout);
    cout << endl;

    TVectorIterator<double> dvIter = doubleV.GetIterator();
    doubleV.Insert(dvIter, 11.1);
    doubleV.Insert(dvIter, 11.2);
    doubleV.Insert(dvIter, 11.3);
    cout << "doubleV after Insert 3x: ";
    doubleV.Print(cout);
    cout << endl;

    TVectorIterator<double> dvIter2 = doubleV.GetIterator();
    dvIter2.Next();
    dvIter2.Next();
    dvIter = doubleV.Remove(dvIter, dvIter2);
    cout << "doubleV after range based remove 1: ";
    doubleV.Print(cout);
    cout << endl;

    dvIter = doubleV.Remove(dvIter, dvIter2);
    cout << "doubleV after range based remove 2: ";
    doubleV.Print(cout);
    cout << endl;

    dvIter = doubleV.Remove(dvIter, dvIter2);
    cout << "doubleV after range based remove 3: ";
    doubleV.Print(cout);
    cout << endl;

    dvIter = doubleV.Remove(dvIter, dvIter2);
    cout << "doubleV after range based remove 4: ";
    doubleV.Print(cout);
    cout << endl;



    return 0;

}


// valgrind --leak-check=full -v ./vec.x
// g++6 mydriver.cpp -o vec.x

