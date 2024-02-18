#include <iostream>
#include <string>
#include "List.h"

using namespace std;
using namespace cop4530;

// Function object types, for use with remove_if()
class isOdd {
public:
  bool operator() (const int& value) { return (value%2)!=0; }
};

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
    cout << "l2iter start: " << *l2iter << endl;
    l2iter++;
    cout << "l2iter +1: " << *l2iter << endl;
    ++l2iter;    ++l2iter;
    cout << "after ++l2iter" << endl;
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

    auto l2copy = l2;
    cout << "l2copy theSize: " << l2copy.size() << endl;
    cout << "l2copy: " << l2 << endl;
    l2copy.pop_back();
    l2copy.pop_front();
    cout << "l2copy theSize: " << l2copy.size() << endl;
    cout << "l2copy: " << l2copy << endl;

    auto l2end = l2copy.end();
    cout << "l2end: " << *(l2copy.end()) << endl;
    l2copy.erase(l2end);
    cout << "l2copy after erase with end(): " << l2copy << endl;
    
    auto l2start = l2copy.begin();
    l2copy.erase(l2start);
    cout << "l2copy after erase with begin(): " << l2copy << endl;

    List<float> l3(5, 2.4);
    cout << "l3 before erase with begin(), end(): " << l3 << endl;
    cout << "l3 size: " << l3.size() << endl;
    l3.erase(l3.begin(), l3.end());
    cout << "l3 after erase with begin(), end(): " << l3 << endl;
    cout << "l3 size: " << l3.size() << endl;

    l3.insert(l3.begin(), 3.5);
    cout << "l3 after insert w begin(): " << l3 << endl;
    cout << "l3 size: " << l3.size() << endl;
    cout << "l3end: " << *(l3.end()) << endl;
    l3.insert(l3.end(), 4.5);
    cout << "l3 after insert w end(): " << l3 << endl;
    cout << "l3 size: " << l3.size() << endl;

    l3.print(cout);
    cout << endl << l3 << endl;
    l3.remove(3.5);
    cout << l3 << endl;

    cout << "l2copy: " << l2copy << endl;
    l2copy.remove(7);
    cout << "l2copy after remove(7): " << l2copy << endl;
    
    List<int> l4(4, 8);
    cout << l4 << endl;
    l4.push_back(9);
    l4.push_front(7);
    cout << l4 << endl;
    cout << "size: " << l4.size() << endl;
    l4.remove(8);
    cout << l4 << endl;
    l4.remove(7);
    cout << l4 << endl;
    l4.remove(9);
    cout << l4 << endl;

    List<int> listRemove(3, 4);
    listRemove.remove_if(isOdd());
    cout << "listRemove: " << listRemove << endl;
    cout << "listRemove size: " << listRemove.size() << endl;
    listRemove.push_back(5);
    listRemove.push_back(5);
    listRemove.push_back(6);
    listRemove.push_back(7);
    listRemove.push_front(3);
    listRemove.push_front(2);
    cout << "listRemove: " << listRemove << endl;
    cout << "listRemove size: " << listRemove.size() << endl;
    listRemove.remove_if(isOdd());
    cout << "listRemove: " << listRemove << endl;
    cout << "listRemove size: " << listRemove.size() << endl;

    auto iterConstructEnd = listRemove.end();
    iterConstructEnd--;
    auto iterConstructStart = listRemove.begin();
    iterConstructStart++;
    List<int> iterConstruct(iterConstructStart, iterConstructEnd);
    cout << "iterConstruct: " << iterConstruct << endl;
    cout << "iterConstruct size: " << iterConstruct.size() << endl;
 
  	List<int> iList {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 100, 90, 80, 70, 60, 50};
    cout << "iList: " << iList << endl;
    cout << "iList size: " << iList.size() << endl;

    List<int> iList2 = {100, 90, 80, 70, 60, 50};
    cout << "iList2: " << iList2 << endl;
    cout << "iList2 size: " << iList2.size() << endl;

    return 0;
}


// valgrind --leak-check=full --track-origins=yes -v ./doubleLinkL.x

// gdb doubleLinkL.x vgcore.

// g++ demoDriver.cpp -o doubleLinkL.x
// g++ -g demoDriver.cpp -o doubleLinkL.x
