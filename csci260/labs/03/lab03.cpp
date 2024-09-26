// CHRISTOPHER NILSSEN lab03.cpp for LAB 03 CSCI 260 F2402
#include "HashTable.h"
#include <iostream>
#include <stdexcept> 

using std::cout;
using std::endl;
using std::runtime_error;
using std::string;

int main() {
    HashTable ht;

    cout << "Inserting key 10 with value 'earth'." << endl;
    ht.insert(10, "earth");

    cout << "Inserting key 20 with value 'wind'." << endl;
    ht.insert(20, "wind");

    cout << "Inserting key 79 with value 'fire'." << endl;
    ht.insert(79, "fire");

    // regular lookup for an existing key
    try {
        std::cout << "\nAttempting to lookup key 10 (exists)." << std::endl;
        std::string value10 = ht.lookup(10);
        std::cout << "Result of lookup key 10: " << value10 << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }

    // lookup for a key that doesn't exist
    try {
        std::cout << "\nAttempting to lookup key 100 (does not exist)." << std::endl;
        std::string value100 = ht.lookup(100);
        std::cout << "Result of lookup key 100: " << value100 << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;  // should print "Key 100 not found."
    }

    cout << "\nInserting duplicate key 10 with new value 'water'." << endl;
    ht.insert(10, "water");

    // lookup to verify the update
    try {
        cout << "\nAttempting to lookup key 10 after updating its value." << endl;
        string value10 = ht.lookup(10);
        cout << "Result of lookup key 10: " << value10 << endl;
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
    }

    return 0;
}
