# Lecture 6: Dictionary/Map (in-class notes)
- 50% of course spent discussing the Dictionary and Map ADTs.
- A dictionary is a collection or container of <key, object> pairs.
- Common operations/interface:
    - new(); // empty dictionary, constructor
    - insert(key, object);
    - lookUp(key);
    - remove(key);
- Typically, key is store separate from data object.

```
class Dictionary {
    public:
        Dictionary();
        void insert (key, object & obj)
            throws (...);   // fixed size? could be full or duplicate key
        Object & lookUp(key K)
            throws (...);   // no key match?
        Object & remove(key K)
            throws (...);
    
    private:
        _______ search(key K);  // data type depends on object
        concrete data structures:
            - unsorted list
                - array
                - linked list
                - O(N) where N is the size of the array
            - sorted array
                - returns index used to find location of insert
                - O(log N)
}
```
Methods for searching keys, in order of use for increasing data set size:
1. hash table
2. binary search tree
3. balanced binary search tree
4. multiway search tree

## Hash Table
- Essentially an array
- **Associative Memory:** jump directly to data with no need to iterate through a list with comparison search.
- key to address mapping
**Naive Method:**
- create a massive array
- do not insert in order, one by one
data + k * offset = address calculation O(1). This refers to how hash tables implement the **dictionary ADT (Abstract Data Type) by calculating the memory address for a given key (k) through an offset. This technique is used to determine where to store or retrieve the associated data in a hash table.
- **data:** This represents the starting point, or base address, of where data might be stored in memory.
- **k:** The key for which you want to store or retrieve data.
- **offset:** The result of a hash function applied to the key. A hash function transforms the key `k` into a numeric value (called a hash value), which is then used as an offset from the base address.

The formula indicates how the **hash fucntion's output** (or the hash value of `k`) is used to calculate the address where the key-value pair is stored in memory.
In more practical terms:
- **data** is the base location in memory where the hash table's data begins.
- **k * offset** is the hashed key multiplied by an offset that helps find the exact location within the array (or memory space) where the data should go.

This part of **address computation** in hash tables, which allows for fast lookup time by directly computing where an element should be stored or found based on its key.

**Issues:**
1. Size of storage? Unrealistic on large data set.
2. Non-integer key?
3. Conflict: $k \neq k'$ but map to the same address.
---
1. How to choose size of storage?
- pick a BigN > N where BigN is the size of the storage.
- key not in the range of [0, BigN - 1]
- choose a prime number to help calculate the keys: h(key) = $key \mod BigN \in [0, BigN - 1]$
- key mod BigN is the **hash function**

2. How to deal with non-integer keys?
- Generate `int` hash code according to the key.
- Use ASCII code value.
- Sum components while considering order.
```
for (i = 1; i < P; ++i)
    sum = sum * a + X;
```
- `sum`: This variable accumulates the result of the hash calculation.
- `a`: This is a constant multiplier, often a prime number, chosen to reduce collisions and spread values more uniformly across the hash table.
- `X`: This represents the numeric value of the character or element being processed. For alphanumeric keys, `X` would typically  be the ASCII or Unicode value of the character.
- `P`: This could be the length of the string (or alphanumeric key) you're hashing.

**What the code does:**
1. Initalize `sum` (though not shown, this usually starts at 0 or the numeric value of the first character of the string).
2. Loop through each character in the key (from `i = 1` to `P - 1`), and for each character:
    - Multiply the current `sum` by the constant `a`.
    - Add the numeric value of the current `X` to the running total (`sum`).

**Purpose:**
This process essentially treats the string as a **polynomial**. For example, suppose the string is `abc`. Using this method, you would calculate the hash value as:
hash = ($a^2 *$ value of 'a') + ($a$ * value of 'b') + (value of 'c')
This rolling multiplication creates a **polynomial hash** that take into account the order of characters in the string, so `'abc'` would hash to a different value than `'bca'`.

**Why use this technique?**
- It's a simple yet effective way to map strings (or alphanumeric keys) to integers.
- The constant multiplier `a` helps to reduce **collisions** (when different keys result in the same hash value).
- The rolling polynomial makes this hash function sensitive to the order of the characters, ensuring that `'abc'` is different from `'bac'`.

**Example:**
Suppose you're hashing the string `"abc"` with `a = 31` (a common choice), and let's say the ASCII values for 'a', 'b', and 'c' are `97`, `98`, and `99`, respectively. The hash function would calculate:
hash $=(31^2 \times 97) + (31 \times 98) + 99$
This result will be the final hash value for the string `"abc"`.

**Summary:** 
This code snippet is a simple implementation of a **polynomial rolling hash** function for alphanumeric keys. Each character in the string contributes to the final hash value by multiplying the current sum by a constant and adding the character's numeric value.

# Prof's Notes
- Keys are directly associated with the addresses of the corresponding objects.
- The simplest case
    - a bucket array of size N, where N defines the capacity of the array, as the hash table
    - the keys of all objects are integers well distributed in the range of 0 to N-1.
    - keys are used to directly and uniquely find where the objects are
    - performance: insert, remove, and lookup all take O(1) time
- Issues:
    - How to choose the appropriate capacity N? N should be much larger than the number of objects stored in the hash table. But if N is too large, a lot of the storage space is wasted.
    - Sometimes keys are not integers, or they are integers but not in the range of 0 to N-1.
    - Conflict could happen if keys are not unique or if h(k) = h(k') where k =/= k'.
- A good hash function maps any key to an integer in the range of O to N-1, and minimizes the possibility of h(k) = h(k') when k =/= k', and is fast and easy to compute.
- Hash Function generally takes two steps:
    - generate integer hash code for keys that are not integers;
    - compress the hash code into the range of 0 to N-1.
- Polynomial Hash Code
    - Generate hash code for any integer representation sequence (x$_0$, ..., x$_p$). String can be viewed as such a sequence.
    - Pick a non-zero constant a such that a =/= 1, h(k) = x$_0$a$^p$ + x$_1$a$^{p-1}$ + ... + x${_p-1}$a + x$_p$ which can be re-written as: h(k) = x$_p$ + a(x$_{p-1}$ + a(x$_{p-2}$ + ... + a(x$_2$ + a(x$_1$ + ax$_0$)) ... ))
    - Advantage of polynomial hash code:
        - easy to compute
        - experimental studies show that if `a` is 33, 37, 39, or 41, then the hash function works very well with English words.
- MAD -- Multiply, Add and Divide
    - Map hash code to an integer in the range of 0 to N-1, where N is the capacity of the hash table.
    - h(k) = abs(ak + b) mod N
    - It works best if N is a prime number.
    - `a` and `b` are randomly chosen, non-negative integers and a mod N =/= 0.
- After the hashing, we hope the `n` keys will be distributed in the range of 0 to N-1, such that the probability of an two different keys will collide is at most 1/N, i.e., the probability is the same as we randomly put keys into the bucket array.
- Collision
    - There is always 1/N possibility that collision will happen no matter how good the hash function is. And keys may not even be unique.
    - Separate Chaining to handle collision
        - store a pointer pointing to an external unsorted dictionary in the bucket cell.
```
Data & lookup (Key k)
{
    int index = h(k);
    head = bucket[index];
    while (head != 0 && head->key != k)
        head = head->next;
    if (head == 0)
        throw exception of data not found;
    else
        return head->object;
}
```
-
    -
        - load factor (n/N) is about the average length of the external dictionary. And the load factor determines the performance of the hash table operations.
        - Re-hashing to keep the load factor a constant. Note that N will change so the hash function will also change.
    - Open addressing to handle collision
        - Handle collisions within the fixed storage space. When collision happens, go to the next spot by jumping a pre-designed offset.
        - h is the hash function and g is the pre-designed offset calculator, each cell in the bucket has one of the following three states: Occupied, Free, Removed.
```
void insert(Key k, Data & object)
{
    int index = h(k);
    int i = index;
    for(int j = 1; bucket[i] is Occupied; j++)
        i = (i + g(j, k)) mod N;
    insert object to bucket[i];
    change bucket[i].status to Occupied;
}

Data & lookup(Key k)
{
    int index = h(k);
    int i = index;
    for(int j = 1; bucket[i] is not Free; j++) {
        if (bucket[i] is Occupied && bucket[i].key == k)
            return bucket[i].object;
        i = (i + g(j, k)) mod N;
    }
    throw exception if not found;
}

Data & remove(Key k)
{
    int index = h(k);
    int i = index;
    for(int j = 1; bucket[i] is not Free; j++) {
        if (bucket[i] is Occupied && bucket[i].key == k)
            change bucket[i].state to Removed;
            return bucket[i].object;
        i = (i + g(j, k)) mod N;
    }
    throw exception if not found;
}
```
-
    -
        - To calculate the offset:
            - linear probing: `g(j, k) = 1;` May cause clustering
            - quadradic probing: `g(j, k) = j * j;` May not be able to find a spot even if the array is not full
            - double hashing: `g(j, k) = h'(k);` usually `h'(k) = q - (k mod q);` where `q` is a prime number that is less than N.

- Universal Hashing
    - A randomly picked hash function may perform poorly. Universal hashing wants to provide a set of good candidates.
    - Problem definition:
        - After the hash code has been generated, the problem can be viewed as mapping integers from range of 0 to M-1 to integers in the range of 0 to N-1.
        - We consider the set of candidate hash functions that can do the mapping as a family `H` of hash functions. For example:
        - H1 = {h | h(k) = k$^a$ mod N, a > 1}, or
        - H2 = {h | h(k) = (ak + b) mod N, a > 0, b >= 0}
    - A family `H` is called a universal family if it satisfies the following condition: we randomly pick a function `h` from this family, and for any pair of integers `k1` and `k2` in the range of 0 to M-1, the probability that Pr(h(k1) == h(k2)) <= 1/N.
    - If you pick hash functions from the universal family, then the good performance is guaranteed.
    - A practical way to find a universal family:
        - Given M and N, find a prime number P such that M < P < 2M. (By the way, according to Bertrand's Postulate, there must exist such a P.)
        - H = { h$_{a,b}$ | 0 < a < P and 0 <= b < P, h$_{a,b}$(k) = ((ak + b) Mod P) Mod N }