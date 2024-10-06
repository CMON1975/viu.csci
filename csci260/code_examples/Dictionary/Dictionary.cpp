#include <iostream>
#include <vector>
#include <list>
#include <string>

using std::vector;
using std::list;
using std::pair;
using std::string;
using std::cout;

// dictionary class using hash table with separate chaining
class Dictionary {
private:
    // size of the hash table
    static const int TABLE_SIZE = 128;

    // hash table: a vector of lists to handle collisions via chaining
    vector<list<pair<string, int>>> table;

    // hash function to compute and index for a given key
    int hashFunction(const string& key) const {
        int hash = 0;
        for (char c : key) {
            hash = (hash * 31 + c) % TABLE_SIZE; // 31 is a prime multiplier
        }
        return hash;
    }

public:
    // constructor initializes the table with empty lists
    Dictionary() {
        table.resize(TABLE_SIZE);
    }

    // insert a key-value pair into the dictionary
    void insert(const string& key, int value) {
        int index = hashFunction(key);
        // check if the key already exists and update its value value if it does
        for (auto& kvp : table[index]) {
            if (kvp.first == key) {
                kvp.second = value; // update existing value 
                return;
            }
        }
        // if the key does not exist, insert it at the end of the list
        table[index].push_back({key, value});
    }

    // remove a key-value pair from the dictionary
    void remove(const string& key) {
        int index = hashFunction(key);
        auto& entries = table[index];
        // iterate over the list to find the key
        for (auto it = entries.begin(); it != entries.end(); ++it) {
            if (it->first == key) {
                entries.erase(it); // remove the key-value pair
                return;
            }
        }
        cout << "Key not found: " << key << "\n";
    }

    // search for a key and return its associated value
    bool search(const string& key, int& value) const {
        int index = hashFunction(key);
        const auto& entries = table[index];
        // iterate over the list to find the key
        for (const auto& kvp : entries) {
            if (kvp.first == key) {
                value = kvp.second; // found the key, set the output parameter
                return true;
            }
        }
        return false; // key not found
    }

    // update the value associated with a key
    void update(const string& key, int newValue) {
        int index = hashFunction(key);
        auto& entries = table[index];
        // iterate over the list to find the key
        for (auto& kvp : entries) {
            if (kvp.first == key) {
                kvp.second = newValue; // update the value
                return;
            }
        }
        cout << "Key not found: " << key << "\n";
    }

    // print the contents of the dictionary
    void print() const {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            if (!table[i].empty()) {
                cout << "Index " << i << ": ";
                for (const auto& kvp : table[i]) {
                    cout << "(" << kvp.first << ", " << kvp.second << ") ";
                }
                cout << "\n";
            }
        }
    }
};

// example usage
int main() {
    Dictionary dict;

    // insert key-value pairs into the dictionary
    dict.insert("apple", 1);
    dict.insert("banana", 2);
    dict.insert("orange", 3);
    dict.insert("grape", 4);
    dict.insert("melon", 5);

    // print the dictionary contents
    dict.print();

    // search for a key
    int value;
    if (dict.search("banana", value)) {
        cout << "Found banana: " << value << "\n";
    } else {
        cout << "Banana not found\n";
    }

    // update a key's value
    dict.update("banana", 20);
    if (dict.search("banana", value)) {
        cout << "Update banana" << value << "\n";
    }

    // remove a key from the dictionary
    dict.remove("orange");
    if (!dict.search("orange", value)) {
        cout << "Orange successfully removed\n";
    }

    // print the dictionary contents after removal
    dict.print();

    return 0;
}