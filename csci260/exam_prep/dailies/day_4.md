## Hash Tables and the Lookup Operations
- **Topics Covered**:
    - Implementing the `lookup` method in a hash table.
    - C++ implementation using open addressing.
- **Study Activities**:
    - **Hash Functions**: Review how hash functions distribute keys.
    - **Collision Resolution**: Understand open addressing and how linear probing works.
    - **Code Practice**: Implement the `lookup` function in C++.
- **Practice**:
    - Write test cases to verify your `lookup` implementation.
    - Analyze the impact of load factors on performance.

---
1. **How do hash functions distribute keys?**
Hash functions play a critical role in data structues like hash tables, where they map a large set of possible keys to a finite number of indices (or buckets) in an array. The primary goal of a hash function is to distribute keys uniformly across the available buckets to minimize collisions and optimize performance for operations such as insertion, deletion, and lookup.

**1. Mapping Keys to Indices:**
A hash function takes an input key and computes a hash value, an integer that is then typically reduced modulo the size of the hash table to obtain an index:
$$
\text{Index = Hash(Key) mod }m
$$
where $m$ is the number of buckets in the hash table.
**2. Uniform Distribution:**
An ideal hash function distributes keys uniformly across all buckets, meaning each bucket is equally likely to receive any given key. This uniformity ensures that:
- **Load Balancing:** No bucket becomes a hotspot with too many keys.
- **Minimized Collisions:** Fewer keys hash to the same index, reducing the need for collision resolution.

**3. Avoiding Patterns and Clustering:**
Good hash functions minimize patterns in key distribution by:
- **Spreading Similar Keys Apart:** Even keys with similar or sequential values should map to different indices.
- **Reduce Clustering:** Preventing groups of keys from being assigned to adjacent or the same buckets.

**4. Collision Handling:**
Since the key space is typically larger than the number of buckets, collisions are inevitable. Common strategies to handle collisions include:
- **Chaining:** Each bucket contains a list (or another data structure) of all keys hashing to that index.
- **Open Addressing:** If a collision occurs, the algorithm probes for the next available bucket using methods like linear probing, quadratic probing, or double hashing.

**5. Properties of Effective Hash Functions:**
- **Determinism:** The same key always hashes to the same index.
- **Uniformity:** Keys are evenly distributed across buckets.
- **Efficiency:** The hash function is computationally fast to compute.
- **Avalanche Effect:** A small change in the key should produce a significantly different hash value.

**6. Types of Hash Functions:**
- **Division Method:** Uses modulo operation with a prime number to spread keys. $h(k)=k \mod m$
- **Multiplication Method:** Multiplies the key by a constant fraction of $m$ and takes the fractional part. $h(k) = \lfloor m(kA \text{ mod }1)\rfloor$
- **Universal Hashing:** Selects a hash function at random from a family of functions to minimize the chance of collisions.
- **Cryptographic Hash Functions:** Like SHA-256, designed for security but often slower due to computational complexity.

**7. Practical Considerations:**
- **Choosing $m$:** Using a prime number for $m$ can reduce patterns and improve distribution.
- **Key Preprocessing:** Transforming keys (e.g., combining or modifying parts of composite keys) can enhance distribution.
- **Load Factor ($\alpha$):** Keeping the load factor low (ratio of the number of keys to the number of buckets) reduces collisions.

**8. Examples:**
- **String Keys:** For strings, a common hash function is the polynomial rolling hash: $h(k)= \left( \sum_{i=0}^{n-1} k_ip^i\right) \text{mod } m$ where $k_i$ is the ASCII value of the $i$-th character, and $p$ is a prime number.

**9. Limitations and Trade-offs:**
- **Perfect Hash Functions:** It's challenging to design a hash function that is both efficient and provides a perfect distribution for all possible keys.
- **Speed vs. Distribution Quality:** More complex hash functions may offer better distribution but at the cost of computational speed.

**10. Conclusion:**
Hash functions distribute keys by transforming them into hash values that are then mapped to indices in a hash table. The effectiveness of this distribution hinges on the hash function's ability to uniformly and efficiently spread keys across all available buckets while handling collisions gracefully.

**In Summary:**
- **Purpose:** Map keys to indices in a finite hash table.
- **Goal:** Achieve uniform key distribution to minimize collisions.
- **Methods:** Employ mathematical functions and collision resolution strategies.
- **Outcome:** Efficient data retrieval and storage in hash-based data structures.

---
2. **How do open addressing and linear probing work?**
Hash tables are data structures that provide efficient insertion, deletion, and lookup operations. When multiple keyts hash to the same index--a situation known as a collision--collision resolution strategies are necessary. **Open addressing** and **linear probing** are two such strategies used to handle collisions within hash tables.
### 1. Open Addressing Overview
**Open addressing** is a collision resolution method where all elements are stored within the hash table array itself. Instead of using linked lists or secondary data structures (as in chaining), open addressing finds another slot within the array for the colliding key.
**Key Concepts:**
- **Probe Sequence:** When a collision occurs, the algorithm probes or searches other slots in the array according to a specific sequence until an empty slot is found.
- **Single Array Storage:** All keys and their associated values are stored in the primary array, optimizing memory usage.
### 2. Linear Probing Explained
**Linear probing** is a type of open addressing where the probe sequence is linear. This means that if a collision occurs at index $i$, the algorithm checks the next slot at $i + 1$, and continues checking subsequent slots until an empty one is found.
**How Linear Probing Works:**
1. **Hash Function:**
    - Compute the initial hash index for a key $k$ using a hash function $h(k):h(k)=k \text{ mod } m$ where $m$ is the size of the hash table.
2. **Insertion:**
    - **Step 1:** Calculate the initial index $i = h(k)$.
    - **Step 2:** If slot $i$ is empty, insert the key-value pair there.
    - **Step 3:** If slot $i$ is occupied, probe the next slot: $i = (i+1) \text{ mod } m$
    - **Repeat:** Continue probing until an empty slot is found.
3. **Search:**
    - **Step 1:** Start at the initial index $i=h(k)$.
    - **Step 2:** If slot $i$ contains the key $k$, return the associated value.
    - **Step 3:** If slot $i$ is empty, the key is not in the table.
    - **Step 4:** If slot $i$ contains a different key, probe the next slot: $i=(i+1) \text{ mod }m$
    - **Repeat:** Continue until the key is found or an empty slot is encountered.
4. **Deletion:** 
    - **Step 1:** Locate the key using the search procedure.
    - **Step 2:** mark the slot as "deleted" (often using a special marker).
    - **Note:** Deleted slots are treated as occupied during probing to maintain the integrity of the search process.
### 3. Example of Linear Probing
Suppose we have a hash table with $m=7$ slots and the keys to insert are: **50, 700, 76, 85, 92, 73, 101.

**Hash Function: $h(k) = k \text{ mod } 7$**
**Insertion Porcess:**
1. **Insert 50:**
    - $h(50) = 50 \text{ mod } 7 = 1$
    - Slot 1 is empty. Insert 50 at index 1.
2. **Insert 700:**
    - $h(700) = 700 \text{ mod } 7 = 0$
    - Slot 0 is empty. Insert 700 at index 0.
3. **Insert 76:**
    - $h(76) = 76 \text{ mod } 7 = 6$
    - Slot 6 is empty. Insert 76 at index 6.
4. **Insert 85:**
    - $h(85) = 85 \text{ mod } 7 = 1$
    - Slot 1 is occupied (50). 
    - Probe to index 2. Slot 2 is empty. Insert 85 at index 2.
5. **Insert 92:**
    -$h(92) = 92 \text{ mod } 7 = 1$
    - Slots 1 (50) and 2 (85) are occupied.
    - Probe to index 3. Slot 3 is empty. Insert 92 at index 3.
6. **Insert 73:**
    - $h(73) = 73 \text{ mod } 7 = 3$
    - Slot 3 is occupied (92).
    - Probe to index 4. Slot 4 is empty. Insert 73 at index 4.
7. **Insert 101:**
    - $h(101) = 101 \text{ mod } 7 = 3$
    - Slot 3 (92) and 4 (73) are occupied.
    - Probe to index 5. Slot 5 is empty. Insert 101 at index 5.

**Final Hash Table:**
| Index | Key
| :- | :-
| 0 | 700
| 1 | 50
| 2 | 85
| 3 | 92
| 4 | 73
| 5 | 101
| 6 | 76
### 4. Advantages of Linear Probing
- **Simplicity:** Easy to implement with straightforward logic.
- **Memory Efficiency:** No additional memory is needed beyond the array.
- **Cache Performance:** Sequential access patterns improve cache utilization, leading to faster lookups in practice.

### 5. Disadvantages of Linear Probing
- **Primary Clustering:** A phenomenon where consecutive occupied slots create long runs of occupied indices, increasing the number of probes required.
- **Performance Degradation:** As the hash table becomes fuller (higher load factor), the number of probes increases, leading to slower operations.
- **Deletion Complexity:** Requires special markers to handle deletions without disrupting the probe sequences.

### 6. Dealing with Clustering
To mitigate clustering, alternative probing methods can be used:
**Quadratic Probing:**
- **Probe Sequence:** Increase the interval between probes quadratically.
- **Formula:** $i = (h(k)+c_1 \cdot j+c_2 \cdot j^2) \text{ mod } m$ where $j$ is the number of probes, and $c_1, c_2$ are constants.

**Double Hashing:**
- **Probe Sequence:** Uses a second hash function to determine the interval between probes.
- **Formula:** $i =(h_1(k)+j\cdot h^2(k))\text{ mod } m$ where $h_1$ and $h_2$ are different hash functions.

### 7. Load Factor and Performance
- **Load Factor($\alpha$):** The ratio of the number of elements $n$ to the table size $m:\alpha = \frac{n}{m}$
- **Optimal Load Factor:** Keeping $\alpha$ below 0.7 is recommended for linear probing to maintain efficient operations.
- **Resizing the Table:** When $\alpha$ exceeds the optimal range, the table should be resized (usually doubled in size), and all elements rehashed.

### 8. Handling Deletions
- **Tombstones:**
    - Use special markers to indicate deleted slots.
    - During insertion and search, tombstones are treated as occupied.
- **Rehashing:**
    - Periodically rehashing the table can remove tombstones and improve performance.

### 9. Practical Considerations
- **Choosing a Good Hash Function:**
    - A good hash function minimizes collisions by distributing keys uniformly.
    - For example, using multiplicative hashing or universal hashing techniques.
- **Table Size Selection:**
    - Using a prime number for the table size $m$ can reduce clusering.
    - Alternatively, ensure that $m$ is not a power of two to aavoid patterns in hash values.
- **Key Preprocessing:**
    - For composite keys or non-integer keys (like strings), preprocess them into integer values using methods like polynomial rolling hash.

### 10. Summary
**Open Addressing with Linear Probing:**
- **Mechanism:** Resolves collisions by sequentially probing for the next available slot.
- **Efficiency:** Offers efficient memory usage and good cache performance.
- **Challenges:** Susceptible to primary clustering, which can degrade performance as the table fills.
- **Mitigation:** Keeping the load factor low and considering alternative probing methods like quadratic probing or double hashing.

**When to Use Linear Probing:**
- Suitable for applications where simplicity and memory efficiency are priorities.
- Effective when the expected number of elements is knowns, and the load factor can be controlled.
- Not ideal for situations where the table is expected to be densely populated.

---
**Conclusion**
Understanding open addressing and linear probing is crucial for implementing efficient hash tables. Linear probing offers a straighforward approach to collision resolution, but it requires careful consideration of load factors and hash functions to maintain optimal performance. By managing these factors and being aware of potential clustering issues, linear probing can be an effective strategy for hash table implementation.


---
3. **Show the pseudocode for then implement a hash table `lookup` function in C++.**

### Pseudocode for Hash Table Lookup Function
**Assumptions:**
- The hash table uses **open addressing with linear probing** for collision resolution.
- The table size is `m`.
- A simple hash function `h(k)` computes the initial index for a key `k`.
- The table stores key-value pairs.
- Special markers are used to indicate empty (`EMPTY`) and deleted (`DELETED`) slots.

**Pseudocode:**
```
function lookup(key):
    i = h(key)          // compute initial hash index
    start = i           // remember the start index to detect full cycle

    while table[i] is not EMPTY:
        if table[i] is not DELETED and table[i].key == key:
            return table[i].value   // key found, return associated value
        i = (i + 1) mod m           // move to next slot (linear probing)
        if i == start:
            break                   // full cycle completed, key not found
    return NOT_FOUND                // key not present in the table
```
**Explanation:**
- **Initialization:** Compute the inital index `i` using the hash function `h(k)`.
- **Probe Loop:** Continue probing while the slot at `i` is not `EMPTY`.
    - **Check for Match:** If the slot is not `DELETE` and the key matches, return the value.
    - **Linear Probing:** Move to the next index `(i + 1) mod m`.
    - **Full Cycle Check:** If `i` returns to the starting index, the entire table has been searched.
- **Result:** If the key is not found, return `NOT_FOUND`.

---
### C++ Implementation of Hash Table Lookup Function
```
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
```

---
### Explanation of the C++ Code
**1. Entry Structure**
- **Purpose:** Represents each slot in the hash table.
- **Members:**
    - `int key`: The key stored in the slot.
    - `int value`: The value associated with the key.
    - `SlotStatus status`: Indicates if the slot is `EMPTY`, `OCCUPIED`, or `DELETED`.

**2. HashTable Class**
- **Private Members:**
    - `vector<Entry> table`: The underlying container for the hash table.
    - `int m`: The size of the table.
    - `int hash(int key)`: A simple hash function using modulo arithmetic.
- **Public Methods:**
    - **Constructor**
        - Initializes the table with a specified size and sets all the slots to `EMPTY`.
    - **Insert Function**
        - **Purpose:** Inserts a key-value pair into the hash table.
        - **Process:**
            - Compute the initial index using the hash function.
            - Probe the table linearly until an `EMPTY` or `DELETED` slot is found.
            - If the key already exists, update its value.
            - Handle the case where the table is full.
    - **Lookup Function**
        - **Purpose:** Retrieves the value associated with a given key.
        - **Process:**
            - Compute the initial index.
            - Probe linearly while handling collisions.
            - Return the value if the key is found.
            - Return `NOT_FOUND` if the key is not present.
    - **Remove Function**
        - **Purpose:** Removes a key-value pair form the hash table.
        - **Process:**
            - Locate the key using linear probing.
            - Set the slot's status to `DELETED`.
            - Handle the case where the key is not found.
    - **Display Function**
        - **Purpose:** Outputs the current state of the hash table for visualization.
**3. Main Function**
- Demonstrates the functionality of the hash table:
    - Inserts multiple key-value pairs.
    - Performs lookups on existing and non-existing keys.
    - Deletes a key and attempts to lookup again.
    - Displays the contents of the hash table.

---
### Key Concepts Illustrated
**Open Addressing with Linear Probing**
- **Collision Resolution:** When a collision occurs, the next slot is probed until an `EMPTY` or `DELETED` slot is found.
- **Linear Probing:** The probing sequence is linear `(i + 1) % m`.

**Slot Status Management**
- **EMPTY:** Indicates a slot has never been used.
- **OCCUPIED:** Contains a valid key-value pair.
- **DELETED:** Slot has been used but the key has been removed.
    - Important for maintaining probe sequences during lookups and inserts.

**Hash Function**
- A simple modulo-based hash function:
    ```
    int hash(int key) {
        return key % m;
    }
    ```
- In practice, a more sophisticated hash function can reduce collisions.

**Handling Full Table**
- The insert function checks if the table has been fully probed.
- Outputs an error message if the table is full.

---
### Possible Enhancements
- **Dynamic Resizing and Rehashing:**
    - Implement automatic resizing when the load factor exceeds a threshold.
    - Rehash all existing entries into the new larger table.
- **Template Implementation:**
    - Modify the `HashTable` class to use templates, allowing keys and values of any data type.
- **Improved Hash Function:**
    - Utilize more advanced hash functions for better distribution.
- **Exception Handling:**
    - Replace `cerr` messages with exceptions for better error handling.
- **Thread Safety:**
    - Add synchronization mechanisms if the hash table is to be used in multithreaded applications.

---
### Conclusion
The provided pseudocode and C++ implementation demonstrate how to perform a `lookup` operation in a hash table using open addressing with linear probing. This approach efficiently handles collisions and maintains performance through careful management of slot statuses and probing sequences.

By understanding this implementation, you can extend and adapt the hash table to suit various applications, ensuring efficient key-value storage and retrieval.

---
## 5. Analyze the impact of load factors on performance.
### Introduction
The **load factor is a critical parameter in hash table design that significantly influences performance. It is defined as the ratio of the number of elements stored in the hash table ($n$) to the total number of available slots or buckets ($m$):
$$
\alpha = \frac{n}{m}
$$
The load factor ($\alpha$) affects the efficiency of fundamental operations such as insertion, deletion, and lookup. Understanding its impact is essential for optimizing hash table performance, especially under different collision resolution strategies like **chaining** and **open addressing**.

---
### Impact on Different Collision Resolution Strategies
The effect of the load factor varies depending on the collision resolution method used:
1. **Chaining (Separate Chaining)**
2. **Open Addressing**

We'll analyze each method to understand how the load factor influences performance.

---
### 1. Chaining (Separate Chaining)
**Mechanism**
- **Structure:** Each slot in the hash table contains a linked list (or another dynamic data structure) of all elements hashing to that index.
- **Collision Resolution:** Multiple keys mapping to the same index are stored in the list at that slot.

**Impact of Load Factor**
- **Flexibility with $\alpha$:** In chaining, the load factor can exceed 1 because each slot can hold multiple elements.
- **Average Case Performance:**
    - **Successful Search Time: $\Theta(1 + \alpha)$**
        - **Explanation:** On average, half the list at a slot needs to be traversed.
    - **Uncessful Search Time: $\Theta(1 + \alpha)$**
- **Effect of Increasing $\alpha$:**
    - **Low $\alpha$:** Short chains, faster operations.
    - **High $\alpha$:** Longer chains, increased search time.

**Advantages**
- **Memory Utilization:** Efficient when the number of elements is unpredictable or can significantly exceed the number of slot.
- **Simplicity:** Easy to implement and manage.

**Disadvantages**
- **Memory Overhead:** Additional pointers in linked lists consume extra memory.
- **Cache Performance:** Linked lists may lead to poor cache utilization due to non-contiguous memory allocation.

---
### 2. Open Addressing
**Mechanism**
- **Structure:** All elements are stored within the hash table array itself.
- **Collision Resolution:** Probing sequences (e.g., linear, quadratic, double hashing) are used to find an empty slot.

**Impact of Load Factor**
- **Critical Range:** $0<\alpha <1$ (since the table cannot be overfilled).
- **Performance Sensitivity:** Performance deteriorates rapidly as $\alpha$ approaches 1.

**Performance Analysis**
**Average Number of Probes**
- **Linear Probing:**
    - **Successful Search:**
        $$
        \text{Expected Probes} = \frac{1}{2}\left(1 + \frac{1}{1-\alpha}\right)
        $$
    - **Unsuccessful Search:**
        $$
        \text{Expected Probes} = \frac{1}{2}\left(\frac{1}{(1-\alpha)^2}+1\right)
        $$
- **Quadratic Probing and Double Hashing:**
    - Generally perform better than linear probing at higher load factors.
    - Less susceptible to clustering.

**Effect of Increasing $\alpha$:**
- **Low $\alpha(\alpha < 0.5)$:**
    - Operations are close to $O(1)$.
    - Few collisions, quick searches.
- **High $\alpha(\alpha \rarr 1)$:**
    - Average number of probes increases sharply.
    - Performance can degrade to $O(n)$ in the worst case.
    - Table becomes saturated, leading to longer probe sequences.

**Clustering Effects**
- **Primary Clustering (Linear Probing):**
    - Clusters of occupied slots form, causing longer probe sequences.
    - Higher $\alpha$ exacerbates clustering.
- **Secondary Clustering (Quadratic Probing):**
    - Reduces clustering compared to linear probing but doesn't eliminate it.
- **Double Hashing:**
    - Minimizing both primary and secondary clustering.
    - Maintains better performance at higher load factors.

---
### Graphical Representation of Performance
- **For Linear Probing:**
    - The graph of average probes vs. load factor shows an exponential increase as $\alpha$ approaches 1.
    - At $\alpha=0.5$, the average number of probes is approximately 1.5 for successful searches.
    - At $\alpha=0.9$, the average number of probes can exceed 10.

---
### Practical Recommendations
**Optimal Load Factor**
- **Chaining:**
    - Can tolerate higher $\alpha$ since chains can grow dynamically.
    - Keep $\alpha$ such that average chain length remains acceptable.
- **Open Addressing:**
    - Maintain $\alpha \leq 0.7$ for efficient performance.
    - Beyond $\alpha = 0.7$, performance degrades significantly.

**Resizing and Rehashing**
- **Threshold-Based Resizing:**
    - Set a maximum accceptable $\alpha_\text{max}$ (e.g., 0.75).
    - When $\alpha$ exceeds $\alpha_\text{max}$, resize the table (usually double the size) and rehash all elements.
- **Incremental Resizing:**
    - Gradually adjust the table size to keep $\alpha$ within the optimal range.

**Memory vs. Performance Trade-Off**
- **Lower $\alpha$:**
    - **Pros:**
        - Faster operation due to fewer collisions.
        - Better performance consistency.
    - **Cons:**
        - Increased memory usage (more empty slots).
- **Higher $\alpha$:**
    - **Pros:**
        - More efficient memory utilization.
    - **Cons:**
        - Slower oprations due to increased collisions and longer probe sequences.
    
---
### Conclusion
The load factor ($\alpha$) plays a pivotal role in determining hash table performance:
- **Chaining:**
    - More resilient to higher $\alpha$.
    - Performance degrades linearly with $\alpha$.
    - Suitable when memory overhead of chains is acceptable.
- **Open Addressing:**
    - Highly sensitive to $\alpha$ approaching 1.
    - Performance degrades exponentially as $\alpha$ increases.
    - Best performance when $\alpha$ is kept below 0.7.

**Key Takeaways:**
- **Maintain Optimal Load Factors:**
    - Regularly monitor and adjust $\alpha$ through resizing.
    - Choose appropriate $\alpha$ thresholds based on the applications performance requirements.
- **Select Appropriate Collision Resolution Strategies:**
    - Use chaining if higher $\alpha$ is expected and memory overhead is acceptable.
    - Use open addressing with an effective probing method for better performance at lower $\alpha$.
- **Use Effective Hash Functions:**
    - Good hash functions distribute keys uniformly.
    - Reduce clustering and improve performance.

By carefully managing the load factor and selecting suitable strategies, hash tables can achieve efficient performance tailored to specific applications and constraints.0