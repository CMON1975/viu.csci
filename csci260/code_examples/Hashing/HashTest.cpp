#include "HashTableOpenAddressing.cpp"
#include "HashTableSeparateChaining.cpp"
#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;

int main() {
    // keys designed to cause collisions (all keys hash to the same index)
    vector<int> keys = {14, 21, 28, 35, 42}; // all keys % 7 = 0

    // testing separate chaining
    cout << "Testing Separate Chaining Hash Table:\n";
    HashTableSeparateChaining hashTableSC(7);
    for (int key : keys) {
        hashTableSC.insert(key);
    }
    hashTableSC.display();

    // testing open addressing with linear probing
    cout << "\nTesting Open Addressing Hash Table with Linear Probing:\n";
    LinearProbingHashTable linearHashTable(7);
    for (int key : keys) {
        linearHashTable.insert(key);
    }
    linearHashTable.display();

    // testing open addressing with quadratic probing
    cout << "\nTesting Open Addressing Hash Table with Quadratic Probing:\n";
    QuadraticProbingHashTable quadraticHashTable(11);
    for (int key : keys) {
        quadraticHashTable.insert(key);
    }
    quadraticHashTable.display();

    // testing open addressing with double hashing
    cout << "\nTesting Open Addressing with Double Hashing:\n";
    DoubleHashingHashTable doubleHashTable(7);
    for (int key : keys) {
        doubleHashTable.insert(key);
    }
    doubleHashTable.display();

    return 0;
}