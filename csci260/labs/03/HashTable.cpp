// CHRISTOPHER NILSSEN HashTable.cpp for LAB 03 CSCI 260 F2402
#include "HashTable.h"
#include <iostream>

using std::cout;
using std::endl;
using std::runtime_error;
using std::to_string;

// initialize hash table by setting the table size
HashTable::HashTable() : table(TABLE_SIZE) {}

// destructor (vector/list auto-manage memory clean-up)
HashTable::~HashTable() {}

// simple modulus hash function
int HashTable::hashFunction(int k) const {
    return k % TABLE_SIZE;
}

// insert key-value pair into hash table
void HashTable::insert(int k, string e) {
    int index = hashFunction(k);    // find appropriate bucket

    // iterate through bucket to check for key
    for (auto& pair : table[index]) {
        if (pair.first == k) {
            // key found, update
            cout << "Key " << k << " already exists. Updating its value to '" << e << "'." << endl;
            pair.second = e;
            return;
        }
    }

    // key not found, insert new kv pair
    table[index].emplace_back(k, e);
    cout << "Inserting new key " << k << " with value '" << e << "'." << endl;
}

// lookup value associated with key
string HashTable::lookup(int k) {
    int index = hashFunction(k);    // find aprop. bucket

    // search list in bucket
    for (const auto& pair : table[index]) {
        if (pair.first == k) {
            return pair.second; // returns if found
        }
    }

    /// If key is not found, throw an exception
    throw runtime_error("Key " + to_string(k) + " not found.");
}