## Day 7: Dictionary ADT Operations
- **Topics Covered**:
    - Main operations of the Dictionary ADT.
    - Parameter and functionality of each operation.
- **Study Activities**:
    - **Operation Details**: Understand insert, remove, search, update, and other operations.
    - **Implementations**: Explore how dictionaries are implemented using hash tables or balance trees.
- **Practice**:
    - Implement a simple dictionary in C++ using a hash table.
    - Write functions for each dictionary operation.
---
### 1. How do the operations insert, remove, search, and update work in a Dictionary ADT?
A **Dictionary Abstract Data Type (ADT)** is a data structure that stores data in key-value pairs, allowing for efficient insertion, deletion, lookup, and update operations based on keys. It is also known as an associative array or map. Here's how the primary operations-**insert, remove, search,** and **update**--work in a Dictionary ADT:

---
#### 1. Insert (key, value)
**Purpose:** Add a new key-value pair to the dictionary.

**How it works:**
- **Check for Key Existence:** Before insertion, the dictionary may check if the key already exists.
    - **If the key exists:** Depending on the implementation, it might overwrite the existing value, throw an error, or ignore the insertion.
    - **If the key doesn't exist:** Proceed with insertion.
- **Insertion Process:**
    - **Hash Table Implementation:**
        - **Compute Hash:** Calculate the hash code of the key to determine the index in the underlying array.
        - **Handle Collisions:** If another key maps to the same index, use collision resolution techniques like chaining (linked lists) or open addressing (probing).
        - **Store Key-Value Pair:** Place the key-value pair at the computed index or appropriate position in the chain.
    - **Binary Search Tree (BST) implementation:**
        - **Start at Root:** Compare the key with the root node's key.
        - **Traverse Tree:** Move left if the key is smaller, or right if larger.
        - **Insert Node:** Place the new key-value pair at the correct leaf position to maintain the BST property.
---
#### 2. Remove (key)
**Purpose:** Delete the key-value pair associated with the given key from the dictionary.

**How it works:**
- **Locate the Key:**
    - Use the **search** operation to find the key's location.
- **Removal Process:**
    - **Hash Table Implementation:**
        - **Compute Hash:** Find the index using the key's hash code.
        - **Locate Key:** Search through the chain or probe sequence if collisions occurred.
        - **Delete Entry:** Remove the key-value pair and adjust links if using chaining.
        - **Maintain Integrity:** In open addressing, mark the slot as deleted but keep it in the probe sequence.
    - **BST Implementation:**
        - **Find Node:** Locate the node containing the key.
        - **Delete Node:** Three cases to handle:
            - **No Children:** Remove the node directly.
            - **One Child:** Replace the node with its child.
            - **Two Children:** Replace the node with its in-order successor or predecessor and adjust the tree accordingly.
---
#### Search (key)
**Purpose:** Retrieve the value associated with the given key.

**How it works:**
- **Search Process:**
    - **Hash Table Implementation:**
        - **Compute Hash:** Determine the index from the key's hash code.
        - **Check Slot:** If the key matches, return the value.
        - **Handle Collisions:** If not found, follow the chain or probe sequence to locate the key.
    - **BST Implementation:**
        - **Start at Root:** Compare the key with the current node's key.
        - **Traverse the Tree:** Move left or right based on comparison.
        - **Locate Key:** Continue until the key is found or a leaf is reached (key not present).
---
#### Update (key, new_value)
**Purpose:** Modify the value associated with an existing key.

**How it works:**
- **Locate the Key:**
    - Use the **search** operation to find the key's location.
- **Update Process:**
    - **Modify Value:** Once the key is found, replace the old value with the new one.
    - **Consistency Check:** Ensure that the update does not violate any constraints of the dictionary (e.g., if the dictionary maintains sorted order in a BST).
---
#### Underlying Implementation Considerations
- **Collision Resolution in Hash Tables:**
    - **Chaining:** Each slot in the table's array holts a linked list of entries that hash to the same index.
    - **Open Addressing:** If a collision occurs, the algorithm probes the array (linear probing, quadratic probing, or double hashing) to find an empty slot.
- **Balancing in Trees:**
    - **Self-Balancing Trees (e.g., AVL, Red-Black Trees):** Automatically adjust their structure during insertions and deletions to maintain optimal search times ($O(\log n)$).
- **Performance Complexity:**
    - **Hash Tables:**
        - **Average Case:** $O(1)$ time for insert, remove, search, and update.
        - **Worst Case:** $O(n)$ time if many collisions occur.
    - **BSTs:**
        - **Average Case:** $O(\log n)$ time for all operations.
        - **Worse Case:** $O(n)$ time if the tree becomes unbalanced.
---
#### Summary
- **Insert:** Add a new key-value pair by computing the key's position and handling any potential conflicts or tree adjustments.
- **Remove:** Delete the key-value pair by locating the key and restructuring the data structure if necessary.
- **Search:** Find the value associated with a key by traversing to its location using hashing or tree navigation.
- **Update:** Modify the value of an existing key by first finding it and then replacing its value.

These operations are fundamental to the functionality of a Dictionary ADT, enabling efficient data management and retrieval in varios applications like databases, caches, and indexing systems.

---
### 2. What other operations are there for Dictionary ADT?
In addition to the fundamental operations of **insert, remove, search,** and **update**, the Dictionary Abstract Data Type (ADT) often includes several other operations to enhance its functionality and usability. These operations allow for more advanced interactions with the dictionary's contents and can be essential in various programming scenarios.

---
#### Additional Operations in a Dictionary ADT
**1. isEmpty()**
- **Purpose:** Check whether the dictionary condtains any key-value pairs.
- **How it works:** Returns `true` if the dictionary has zero entries; otherwise, returns `false`.

**2. size()**
- **Purpose:** Retrieve the number of key-value pairs currently stored in the dictionary.
- **How it works:** Maintains a count that is incremented or decremented during insertions and deletions.

**3. clear()**
- **Purpose:** Remove all key-value pairs from the dictionary, resetting it to an empty state.
- **How it works:** Deletes all entries or reinitializes the underlying data structures.

**4. containsKey(key)**
- **Purpose:** Determine in a particular key exists within the dictionary.
- **How it works:** Performs a search operation and returns `true` if the key is found; otherwise, `false`.

**5. containsValue(value)**
- **Purpose:** Check if the dictionary contains one or more keys associated with a given value.
- **How it works:** Iterates over all entries to find if the value exists.

**6. keys()**
- **Purpose:** Retrieve a collection (e.g., list, set, or iterator) of all the keys in the dictionary.
- **How it works:** Gathers all keys from the data structure for iteration or other operations.

**7. values()**
- **Purpose:** Retrieve a collection of all the values in the dictionary.
- **How it works:** Collects all values, allowing operations on just the values without the keys.

**8. entries()**
- **Purpose:** Obtain a collection of all key-value pairs.
- **How it works:** Provides access to the full set of entries, often as objects or tuples containing both key and value.

**9. getOrDefault(key, defaultValue)**
- **Purpose:** Retrieve the value associated with a given key or return a default value if the key is not present.
- **How it works:** Searches for the key; if found, returns its value; otherwise, returns the `defaultValue`.

**10. pop(key)**
- **Purpose:** Remove the key-value pair associated with the key and return the value.
- **How it works:** Combines removal and retrieval; if the key exists, removes it and returns its value, else may throw an exception or return a default.

**11. updateOrInsert(key, value)**
- **Purpose:** Insert a new key-value pair or update the existing value if the key already exists.
- **How it works:** Checks if the key exists; if so, updates the value; if not, inserts the new key-value pair.

**12. merge(otherDictionary)**
- **Purpose:** Combine another dictionary into the current one, optionally overwriting existing keys.
- **How it works:** Iterates over the other dictionary's entries and inserts or updates them in the current dictionary.

**13. clone()**
- **Purpose:** Create a shallow or deep copy of the dictionary.
- **How it works:** Duplicates the data structure, resulting in a new dictionary with the same key-value pairs.

**14. traversal methods**
- **Purpose:** Iterate over the dictionay's entries in a specified order.
- **How it works:** 
    - **Unordered Dictionaries:** Iteration order is arbitrary (e.g., based on hash codes).
    - **Ordered Dictionaries (e.g., BST):** Provide in-order, pre-order, or post-order traversals.

**15. min() and max()**
- **Purpose:** Retrieve the entry with the minimum or maximum key value.
- **How it works:** Particularly in ordered dictionaries, finds the smallest or largest key by traversing the tree structures.

**16. floorKey(key) and ceilingKey(key)**
- **Purpose:**
    - **floorKey(key):** Find the greatest key less than or equal to the given key.
    - **ceilingKey(key)** Find the smallest key greater than or equal to the given key.
- **How it works:** Navigates the ordered structure to find keys that satisfy the floor or ceiling condition.

**17. subDictionary(fromKey, toKey)**
- **Purpose:** Obtain a view or subset of the dictionary with keys ranging from `fromKey` to `toKey`.
- **How it works:** Creates a new dictionary or view that includes only the entries within the specified key range.

**18. rehash() or resize()**
- **Purpose:** Adjust the size of the underlying data structures to maintain performance as the number of entries grows.
- **How it works:** In hash tables, when the load factor exceeds a threshold, the table is resized, and all existing entries are rehashed.

**19. custom comparator support**
- **Purpose:** Allow the use of custom logic for comparing keys in ordered dictionaries.
- **How it works:** Uses a comparator function provided suring the dictionary's creation to order the keys.

---
#### Implementation-Specific Operations
- **Serialization/Deserialization:**
    - **Purpose:** Convert the dictionary to and from a format suitable for storage or transmission.
    - **How it works:** Transforms the dictionary into a byte stream or string and reconstructs it back.
- **Thread-Safety Features:**
    - **Purpose:** Ensure sage access in multi-threaded environments.
    - **How it works:** Implements locking mechanisms or uses concurrent data structures.
- **Bulk Operations:**
    - **Purpose:** Perform operations on multiple entries at once.
    - **Examples:**
        - **putAll(otherDictionary):** Inserts all entries from another dictionary.
        - **removeIf(predicate):** Removes entries that satisfy a certain condtion.
- **Event Handling:**
    - **Purpose:** Trigger actions when certain operations occur.
    - **How it works:** Uses callbacks or observers to respond to insertions, deletions, etc.
---
#### Summary
The dictionary ADT is versatile and can include a variety of operations beyond the basic four:
- **Utility Operations:** `isEmpty()`, `size()`, `clear()`
- **Containment Checks:** `containsKey(key)`, `containsValue(value)`
- **Collection Retrieval:** `keys()`, `values()`, `entries()`
- **Enhanced Retrieval:** `getOrDefault(key, defaultValue)`, `pop(key)`
- **Traversal and Ordering:** `min()`, `max()`, `floorKey(key)`, `ceilingKey(key)`, `subDictionary(fromKey, toKey)`
- **Structural Adjustments:** `rehash()`, `resize()`, `clone()`
- **Customization and Advanced Features:** Custom comparators, serialization, thread-safety mechanisms.

These additional operations allow you to:
- Efficiently manage and manipulate large sets of key-value pairs.
- Iterate over entries in meaningful ways.
- Integrate the dictionary with other systems through serialization.
- Ensure performance and safety in complex applications.

By leveraging these operations, you can fully utilize the capabilities of the Dictionary ADT to suit the needs of your specific application or use case.

---
**Note:** The availablility of these operations may vary depending on the programming language and the specific implementation of the dictionary. Always refer to the documentation of the dictionary or map class you are using to understand the supported operations and their behaviors.

---
### 3. Implement a simple dictionary in C++ using a hash table.
```
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
}
```


---