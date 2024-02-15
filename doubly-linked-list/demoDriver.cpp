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

    cout << endl << l2 << endl;

    cout << endl;
    auto l2iter = l2.begin();
    cout << "l2iter: " << *l2iter << endl;
    l2iter++;
    cout << "l2iter +1: " << *l2iter << endl;
    ++l2iter;    ++l2iter;    ++l2iter;    ++l2iter;    ++l2iter;    ++l2iter;    ++l2iter;
    cout << "l2iter +7: " << *l2iter << endl;
    l2iter--;
    cout << "l2iter -1: " << *l2iter << endl;
    --l2iter;
    cout << "l2iter -1: " << *l2iter << endl;
    l2iter++;
    cout << "l2iter +1: " << *l2iter << endl;

    auto l2front = l2.front();
    auto l2back = l2.back();
    cout << "l2front: " << l2front << endl;
    cout << "l2back: " << l2back << endl;

    l2.push_front((4+1));
    l2front = l2.front();
    cout << "l2front: " << l2front << endl;

    int nine = 9;
    l2.push_front(nine);
    l2front = l2.front();
    cout << "l2front: " << l2front << endl;

    cout << "current l2: " << l2 << endl;
    l2.pop_back();
    cout << "l2 after pop_back: " << l2 << endl;
    l2.pop_front();
    cout << "l2 after pop_front: " << l2 << endl;


// this is broken because we need to reverse the prev and next pointers
// when we flipped the list, we did not flip the pointers so print or << wont work
    cout << "l2 before: " << l2 << endl;
    l2.reverse();
    cout << "Empty: " << l2.empty() << endl;
    cout << "theSize: " << l2.size() << endl;
    cout << "l2 reversed: " << l2 << endl;
    l2.clear();
    cout << "Empty: " << l2.empty() << endl;
    cout << "theSize: " << l2.size() << endl;
    cout << "l2 cleared: " << l2 << endl;
    l2.print(cout);

    return 0;
}


// valgrind --leak-check=full -v ./doubleLinkL.x

// g++6 demoDriver.cpp -o doubleLinkL.x
// g++ demoDriver.cpp -o doubleLinkL.x