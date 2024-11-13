// CHRISTOPHER NILSSEN - SL_test.cpp for LAB 08 CSCI 260 F2402
//
// This program demonstrates basic functionality of the SkipList data structure
// by performing insertions and lookups on a SkipList instance with integer keys
// and string values. It inserts several key-value pairs, then attempts to 
// retrieve values by key, including both present and absent keys to validate 
// expected behavior.
//
// Functions demonstrated:
// - insert(key, value): Adds a new key-value pair to the skip list
// - lookup(key, result): Searches for a value by key, printing either the 
//   associated value if found or a message if the key is absent

#include <iostream>
#include "SkipList.cpp"

using std::cout;
using std::endl;
using std::string;

int main() {
    // create a SkipList with integer keys and string values
    SkipList<int, string> skipList;

    // insert key-value pairs into the skip list
    skipList.insert(3, "Alice");
    skipList.insert(1, "Bob");
    skipList.insert(7, "Charlie");
    skipList.insert(5, "Diana");

    // test lookups
    std::string result;
    int keys[] = {1, 3, 5, 7, 2}; // includes a non-existent key (2)

    for (int key : keys) {
        if (skipList.lookup(key, result)) {
            cout << "Found key " << key << " with value: " << result << endl;
        } else {
            cout << "Key " << key << " not found in skip list." << endl;
        }
    }

    return 0;
}
