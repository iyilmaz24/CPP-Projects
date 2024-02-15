#include <iostream>
#include <string>
#include "List.h"

using namespace std;
using namespace cop4530;


int main() {

    List<int> l1;
    List<int> l2(5, 7);

    // cout << "List Constructed" << endl;
    // cout << "Size: " << l2.size() << endl;
    // cout << "Empty: " << l2.empty() << endl;

    int n4 = 4;
    l2.push_back(n4);
    l2.push_back(std::move(8));
    l2.print(cout);

    cout << endl;
    auto l2iter = l2.begin();
    cout << "l2iter: " << *l2iter << endl;


    return 0;
}


// valgrind --leak-check=full -v ./doubleLinkL.x

// g++6 demoDriver.cpp -o doubleLinkL.x
// g++ demoDriver.cpp -o doubleLinkL.x