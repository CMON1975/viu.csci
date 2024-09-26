// CHRISTOPHER NILSSEN HashTable.h for LAB 03 CSCI 260 F2402
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <vector>
#include <list>

using std::string;
using std::vector;
using std::list;
using std::pair;

class HashTable
{
    public:
        HashTable();        // constructor
        ~HashTable();       // destructor
        void insert(int k, string e);   // insert a key-value pair
        string lookup(int k);           // retrieve the value associated with key k
    private:
        // define prime number for hash table size
        static const int TABLE_SIZE = 79;

        // each bucket will be a list of pairs (key, value)
        vector<list<pair<int, string>>> table;

        // hash function to map keys to bucket indices
        int hashFunction(int k) const;

};

#endif // HASHTABLE_H