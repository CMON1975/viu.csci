## Day 12: Collision Handling in Hash Tables
- **Topics Covered**:
    - What collisions are and why they occur.
    - Methods to resolve collisions: separate chaining and open addressing.
- **Study Activities**:
    - **Hash Function Limitations**: Understand why collisions are inevitable.
    - **Separate Chaining**: Learn how linked lists are used at each bucket.
    - **Open Addressing**: Study linear probing, quadratic probing, and double hashing.
- **Practice**:
    - Implement both collision resolution methods in C++.
    - Test your hash table with data designed to cause collisions.

### 1. Regarding hash functions, why are collisions inevitable?
Collisions in hash functions are inevitable due to the **Pigeonhole Principle**. A hash function maps a potentially infinite set of input keys to a finite set of hash values (the size of the hash table). Since there are more possible input keys than hash values, multiple keys will inevitably map to the same hash value, causing collisions. Even with a well-designed hash function, collisions cannot be entirely eliminated when the number of possible keys exceeds the number of available hash values.

---
### 2. In separate chaining, how are linked lists used at each "bucket"?
In **seperate chaining**, each bucket of the hash table contains a linked list (or another data structure like a dynamic array) that holds all the elements hashing to that bucket. When a key-value pair is inserted:
1. The hash function computes the bucket index.
2. The key-value pair is added to the linked list at that index.

If multiple keys hash to the same index, they are stored sequentially in the linked list of that bucket. This method efficiently handles collisions by allowing multiple entries per bucket without overwriting existing data.

---
### 3. In open addressing: explain linear probing, quadratic probing, and double hashing.
In **open addressing**, all elements are stored within the hash table array itself. When a collision occurs, the algorithm probes the array using a sequence until an empty slot is found. The probe sequence is determined different in each method:
- **Linear Probing:**
    - The simplest probing method.
    - If a collision occurs at index `i`, the next index checked is `(i + 1) % table_size`.
    - The probe sequence is linear: `hash(key) + i`, where `i` ranges from `0` to `table_size - 1`.
    - **Advantage:** Simple and easy to implement.
    - **Disadvantage:** Tends to create clusters of occupied slots, leading to longer search times (primary clustering).

- **Quadratic Probing:**
    - Uses a quadratic function to determine the next index.
    - The probe sequence is: `hash(key) + c1*i + c2*i^2`, where `c1` and `c2` are constants.
    - **Advantage:** Reduces primary clustering by spreading out probes more than linear probing.
    - **Disadvantage:** Can still suffer from secondary clustering and may not probe all slots in the table unless the table size is prime.

- **Double Hashing:**
    - Uses a second hash function to compute the probe step.
    - The probe sequence is: `hash1(key) + i * hash2(key)`, where `hash2(key)` is a non-zero value.
    - **Advantage:** Provides a more uniform distribution of probes, reducing clustering.
    - **Disadvantage:** Requires two hash functions and careful choice of `hash2` to ensure all slots can be probed.

---
### 4. Implement both resolution methods in C++ and test the hash tables with data designed to cause collisions.

Refer to the code examples at `code_examples/Hashing/`