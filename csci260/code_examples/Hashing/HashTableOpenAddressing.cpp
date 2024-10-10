#include <iostream>
#include <vector>
#include <functional>

using std::vector;
using std::cout;
using std::endl;

class HashTableOpenAddressing {
protected:
    int tableSize;
    vector<int> table;
    vector<bool> occupied;
    int numElements;

    virtual int probe(int key, int i) = 0;

    int hashFunction(int key) {
        return key % tableSize;
    }

public:
    HashTableOpenAddressing(int size) : tableSize(size), table(size, -1), occupied(size, false), numElements(0) {}

    void insert(int key) {
        if (numElements == tableSize) {
            cout << "Hash table is full\n";
            return;
        }
        int i = 0;
        int index;
        do {
            index = probe(key, i);
            if (!occupied[index]) {
                table[index] = key;
                occupied[index] = true;
                numElements++;
                return;
            }
            i++;
        } while (i < tableSize);
        cout << "Could not insert key: " << key << endl;
    }

    bool search(int key) {
        int i = 0;
        int index;
        do {
            index = probe(key, i);
            if (!occupied[index])
                return false;
            if (table[index] == key)
                return true;
            i++;
        } while (i < tableSize);
        return false;
    }

    void display() {
        for (int i = 0; i < tableSize; ++i) {
            cout << i << " : ";
            if (occupied[i])
                cout << table[i];
            cout << endl;
        }
    }
};

// linear probing
class LinearProbingHashTable : public HashTableOpenAddressing {
protected:
    int probe(int key, int i) override {
        return (hashFunction(key) + i) % tableSize;
    }

public:
    LinearProbingHashTable(int size) : HashTableOpenAddressing(size) {}
};

// quadratic probing
class QuadraticProbingHashTable : public HashTableOpenAddressing {
private:
    int c1, c2;

protected:
    int probe(int key, int i) override {
        int index = (hashFunction(key) + c1 * i + c2 * i * i) % tableSize;
        return (index < 0) ? index + tableSize : index;
    }

public:
    QuadraticProbingHashTable(int size, int constant1 = 1, int constant2 = 3)
        : HashTableOpenAddressing(size), c1(constant1), c2(constant2) {}
};

// double hashing 
class DoubleHashingHashTable : public HashTableOpenAddressing {
protected:
    int hashFunction2(int key) {
        // second hash function should not return zero
        return 1 + (key % (tableSize - 1)); 
    }

    int probe(int key, int i) override {
        return (hashFunction(key) + i * hashFunction2(key)) % tableSize;
    }

public:
    DoubleHashingHashTable(int size) : HashTableOpenAddressing(size) {}
};