#include <iostream>
#include <string>

#include "tvector.h"

using namespace std;

int main() {

    TVector<int> v1;
    TVector<int> v2(5, 10); // (T val, int num)

    TVector<int> v3 = v2; // also can use like: TVector<int> v3(v2);
    TVector<int> v5;
    v5 = std::move(v2);

    TVector<int> v6;
    v6 = v5;


    TVector<int> v4 = std::move(v2);

    v3.IsEmpty();
    v3.Clear();
    v3.GetSize();
    v3.IsEmpty();

    v3.GetFirst();
    v3.GetLast();

    v5.GetFirst();
    v5.Print(cout);
    v6.Print(cout);

    int firstv6 = v6.GetFirst();
    int firstv2 = v2.GetFirst();

    cout << "firstv6: " << firstv6 << endl;
    cout << "firstv2: " << firstv2 << endl;


    TVectorIterator<int> iter = v6.GetIterator();
    iter.GetData();
    cout << (iter.HasNext() == 1 ? "True" : "False") << " " << (iter.HasPrevious() == 1 ? "True" : "False") << endl;

    iter.Next();
    iter.GetData();

    // iter.Previous();
    // iter.GetData();
    // iter.Previous();
    // iter.GetData();
    // iter.Previous();
    // iter.GetData();
    // iter.Previous();
    // iter.GetData();


    iter.Next();
    iter.Next();
    iter.Next();
    iter.Next();
    iter.Previous();
    iter.Previous();
    iter.Previous();

    cout << "Iterator at end" << endl;
    TVectorIterator<int> iterEnd = v6.GetIteratorEnd();
    iterEnd.Next();
    iterEnd.Next();
    iterEnd.Previous();

    v6.SetCapacity(5);
    v6.Print(cout);
    v6.SetCapacity(7);
    v6.Print(cout);

    TVector<int> v7;
    v7.Print(cout);
    // v7 = v3 + v4;

    int insertNum = 9;
    TVectorIterator<int> newIter = v6.GetIterator();
    newIter.Next();
    newIter.Next();
    TVectorIterator<int> iterFirst = v6.Insert(newIter, insertNum);
    iterFirst.Next();
    v6.Print(cout);
        newIter.Next();
            newIter.Next();
                newIter.Next();
                    newIter.Next();
                        newIter.Next();
                            newIter.Next();
    cout << "iterSecond construction" << endl;
    TVectorIterator<int> iterSecond = v6.Insert(newIter, insertNum);
    iterSecond.GetData();
    iterSecond.Next();
    v6.Print(cout);
    iterSecond.Next();

    TVector<int> v10(10, 3);
    TVector<int> v11;
    v11 = v10 + v6;
    v11.Print(cout);

    cout << "Remove method testing" << endl;
    TVectorIterator<int> iterv11 = v11.GetIterator();
    iterv11.Next();
    iterv11.Next();
    iterv11.GetData();
    v11.Print(cout);

    cout << "Delete 1:" << endl;
    iterv11 = v11.Remove(iterv11);
    v11.Print(cout);
    iterv11.GetData();


    cout << "Delete 2:" << endl;
    iterv11 = v11.Remove(iterv11);
    v11.Print(cout);
    iterv11.GetData();

    cout << "Delete 3:" << endl;
    iterv11 = v11.Remove(iterv11);
    v11.Print(cout);
    iterv11.GetData();

    TVectorIterator<int> iterv11End = v11.GetIteratorEnd();
    iterv11End.GetData();

    iterv11 = v11.Remove(iterv11, iterv11End);
    iterv11.GetData();
    v11.Print(cout);

    cout << "vNull testing:" << endl;
    TVector<int> vNull;
    TVectorIterator<int> vNI = vNull.GetIterator();
    cout << "Next, GetData, Previous" << endl;
    vNI.Next();
    cout << vNI.GetData() << endl;
    vNI.Previous();
    cout << vNI.HasNext() << " and " << vNI.HasPrevious() << endl;

    return 0;
}

// valgrind --leak-check=full -v ./vec.x
// g++6 demoDriver.cpp -o vec.x
