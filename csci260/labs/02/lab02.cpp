#include "LinkedList.h"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
    // create a linkedlist with a capacity of 10
    LinkedList list(10);

    // test inserting elements
    cout << "inserting 5.0: " << (list.insert(5.0) ? "success" : "fail") << endl;
    cout << "inserting 10.0: " << (list.insert(10.0) ? "success" : "fail") << endl;
    cout << "inserting 15.0: " << (list.insert(15.0) ? "success" : "fail") << endl;

    // test finding elements
    cout << "finding 10.0: " << list.find(10.0) << endl; // should return index
    cout << "finding 20.0: " << list.find(20.0) << endl; // should return -1 (not found)

    // test inserting after a specific value
    cout << "inserting 12.0 after 10.0: " << (list.insertAfter(10.0, 12.0) ? "success" : "fail") << endl;
    cout << "inserting 18.0 after 15.0: " << (list.insertAfter(15.0, 18.0) ? "success" : "fail") << endl;

    // test removing elements
    cout << "removing 10.0: " << (list.remove(10.0) ? "success" : "fail") << endl;
    cout << "removing 5.0: " << (list.remove(5.0) ? "success" : "fail") << endl;
    cout << "removing 20.0 (not present): " << (list.remove(20.0) ? "success" : "fail") << endl;

    // final state: check if 12.0 and 18.0 are still present
    cout << "finding 12.0: " << list.find(12.0) << endl; // should return index
    cout << "finding 18.0: " << list.find(18.0) << endl; // should return index

    return 0;
}
