#include <iostream>
#include <list>
#include <vector>

using std::vector;
using std::list;
using std::cout;
using std::endl;

class HashTableSeparateChaining {
private:
    int tableSize;
    vector<list<int>> table;

    int hashFunction(int key) {
        return key % tableSize;
    }

public:
    HashTableSeparateChaining(int size) : tableSize(size) {
        table.resize(tableSize);
    }

    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    bool search(int key) {
        int index = hashFunction(key);
        for (const int& element : table [index]) {
            if (element == key)
            return true;
        }
        return false;
    }

    void display() {
        for (int i = 0; i < tableSize; ++i) {
            cout << i;
            for (const int& key : table[i]) {
                cout << " --> " << key;
            }
            cout << endl;
        }
    }
};