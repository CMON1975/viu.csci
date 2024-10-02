#include <iostream>
#include <vector>

using std::vector;
using std::cerr;
using std::cout;

const int TABLE_SIZE = 10;
const int NOT_FOUND = -1; // indicates that the key was not found

// special markers for empty and deleted slots
enum SlotStatus { EMPTY, OCCUPIED, DELETED };

// entry struct to hold key-value pairs
struct Entry {
    int key;
    int value;
    SlotStatus status;

    Entry() : key(0), value(0), status(EMPTY) {}
};

class HashTable {
private:
    vector<Entry> table;
    int m; // table size

    // hash function
    int hash(int key) {
        return key % m;
    }

public:
    // constructor
    HashTable(int size = TABLE_SIZE) : m(size) {
        table.resize(m);
    }

    // insert function
    void insert(int key, int value) {
        int i = hash(key);
        int start = i;

        do {
            if (table[i].status == EMPTY || table[i].status == DELETED) {
                table[i].key = key;
                table[i].value = value;
                table[i].status = OCCUPIED;
                return;
            } else if (table[i].status == OCCUPIED && table[i].key == key) {
                // update existing key
                table[i].value = value;
                return;
            }
            i = (i + 1) % m;
        } while (i != start);

        cerr << "Hash table is full, cannot insert key " << key << "\n";
    }

    // lookup function
    int lookup(int key) {
        int i = hash(key);
        int start = i;

        do {
            if (table[i].status == EMPTY) {
                return NOT_FOUND; // key not found
            } else if (table[i].status == OCCUPIED && table[i].key == key) {
                return table[i].value; // key found
            }
            i = (i + 1) % m;
        } while (i != start);

        return NOT_FOUND; // key not found after full cycle
    }

    // delete function
    void remove(int key) {
        int i = hash(key);
        int start = i;

        do {
            if (table[i].status == EMPTY) {
                cerr << "Key " << key << " not found\n";
                return;
            } else if (table[i].status == OCCUPIED && table[i].key == key) {
                table[i].status = DELETED;
                return;
            }
            i = (i + 1) % m;
        } while (i != start);

        cerr << "Key " << key << " not found\n";
    }

    // display function
    void display() {
        for (int i = 0; i < m; ++i) {
            cout << i << ": ";
            if (table[i].status == EMPTY) {
                cout << "EMPTY\n";
            } else if (table[i].status == DELETED) {
                cout << "DELETED\n";
            } else {
                cout << "Key = " << table[i].key << ", Value = " << table[i].value << "\n";
            }
        }
    }
};

int main() {
    HashTable ht;

    // insert key-value pairs
    ht.insert(5, 50);
    ht.insert(15, 150);
    ht.insert(25, 250);
    ht.insert(35, 350);

    // lookup keys
    cout << "Lookup key 15: " << ht.lookup(15) << "\n"; // should ouput 150
    cout << "Lookup key 25: " << ht.lookup(25) << "\n"; // should ouput 250
    cout << "Lookup key 35: " << ht.lookup(35) << "\n"; // should ouput 350
    cout << "Lookup key 45: " << ht.lookup(45) << "\n"; // should ouput -1 (NOT_FOUND)

    // remove a key
    ht.remove(25);

    // try to lookup the removed key
    cout << "Lookup key 25 after deletion: " << ht.lookup(25) << "\n"; // should ouput -1

    // display the hash table
    ht.display();

    return 0;
}