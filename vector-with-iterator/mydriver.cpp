#include <iostream>
#include <string>

#include "myTvector.h"

// using namespace std;

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
    
    return 0;
}

// valgrind --leak-check=full -v ./vec.x
// g++6 mydriver.cpp -o vec.x

