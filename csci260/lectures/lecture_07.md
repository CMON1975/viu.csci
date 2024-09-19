# Lecture 7: Hashing
Midterm October 16, 2024 in class (one double-sided pages of notes allowed).

Hash-table implements Map <key, object> pairs.

| Key Types | | hash code |
| --- | --- | --- |
| integers | &rarr; | it's own code |
| strings or sequences of <$X_0, X_1, ..., X_p$> | &rarr; | hash code; polynomial function |

`h(key)` = x$_p$ + a(x$_{p-1}$ + a(x$_{p-2}$ + ... + a(x$_2$ + a(x$_1$ + ax$_0$)) ... )
&uarr; *polynomial rolling hash*
This function can be used to map a key (usually a string or integer) to a numerical value, commonly employed in hash tables.

Here's a breakdown of the equation:
- $x_0,x_1,...,x_p$ are the components of the key, often characters or numerical values.
- $a$ is a constant multiplier (typically a prime number) used in hashing functions to reduce collisions.
- The function applies a recursive pattern where each term is multiplied by $a#, and the previous result is added in.

This pattern builds up a hash value by treating the key components as coefficients of a polynomial. The equation expands to something like:
$$
h(\text{key}) = x_p + a(x_{p-1} + a(x_{p-2}+ ... + a(x_1 + ax_0)...))
$$
It's correct as long as $a$ is a constant that ensures a good distribution of hash values for the input keys. This form of hash function works well for strings or sequences by turning them into numbers and avoiding clustering (collisions) in a hash table.

$a$ = 37 is a widely accepted multiplier for English words. Other languages with more characters may require a larger prime, such as 53 or 101.

**From hash code to index:**
1. **Handling negative hash values:**
    - Hash functions can sometimes produce negative values (especially with certain keys or when applying mathematical operations like modulo).
    - To ensure that the index for the hash table is always within the valid range $[0, M - 1]$ &mdash; where $M$ is the size of the hash table &mdash; you can add a positive value to the negative result to shift it into this range. The positive value is usually $M$ itself.
    - Example: If a hash function gives you -5 as a result, and the table size $M$ is 10, you could add 10 to it: $-5 + 10 = 5$. This brings the value back within the valid index range $[0, M - 1]$.
2. **Using a relational database for large object sets:**
    - When dealing with large data sets (more than 1000 objects, for example), use a relational database.
    - This implies that for large sets, it may be more efficient to store and manage the objects in a relational database (which has built-in indexing, querying, and storage mechanisms) rather than using an in-memory hash table. The database typically allows mapping or partitioning a larger set of data $[0, N - 1]$, where $N$ is the total number of records, into smaller, more manageable ranges, improving performance and scalability.

## How do we compress a large range into a smaller one?
1. Generate hash code.
2. Compress step.
3. Handle conflicts.

$| key | mod N$ (absolute value only necessary for negative numbers)

If a pattern in the key exists, this will cause collisions.

MAD: **M**ultiply, **A**dd, & **D**ivide ($mod$)

$h(key) = |(ak+b)|modN$ pick values $a$ and $b$ randomly, non-negative constants.

$N$ should be an appropriate number (size) and *prime*.

```
Object & LookUp(key k)
    hash code = H₁(k);               // Compute the initial hash code from the key
    index = H₂(hash code);           // Map the hash code to an index in the hash table
    i = 0;                           // Initialize a counter for quadratic probing
    
    // Start probing to find the correct position
    while ((data[index] is occupied || data[index].key == sentinel) 
           && data[index].key != k)  // Continue while index is occupied or sentinel key, and key isn't a match
    {
        ++i;                         // Increment probe counter
        offset = i * i;              // Quadratic probing: increment grows as square of `i`
        index = (index + offset) mod N; // New index calculated with offset, wrapped by table size N
    }
    
    // Return the object found at the final index or a reference to that slot
```

1. **hash code = H₁(k);**
    - The first hash function `H₁(k)` generates a hash code for the key `k`. This is likely a numeric value that will later be mapped to an index in the table.
2. **index = H₂(hash code);**
    - The second hash function `H₂(hash code)` maps the hash code to an index in the table, possibly using a modulus operation to ensure it fits within the table's range.
3. **i = 0;**
    - Initializes the counter `i`, which will be used for quadratic probing.
4. **while ((data[index] is occupied || data[index].key == sentinel) && data[index].key != k)**
    - The loop continues probing (looking for an available or matching slot) as long as:
        - The slot at `data[index]` is either occupied, or it holds a "sentinel" value (a reserved value that marks deleted elements).
        - The current slot's key does not match `k`.
5. **++i;**
    - Increments `i` on each iteration of the loop. This counter is used for calculating the quadratic offset.
6. **offset = i * i;**
    - Quadratic probing: the offset increases quadratically, meaning the step size grows as `i^2`.
7. **index = (index + offsef) mod N;**
    - The new index is calculated by adding the quadratic offset to the current index. The modulo `N` ensures the index stays within the bounds of the hash table (of size `N`).

### Conclusion
This pseudocode is a typical example of how quadratic probing is applied to resolve hash collisions. Quadratic probing adjusts the next index to check by an increasingly large step size (i.e., the square of the probe count), which helps distribute the probe sequence across the table and reduce the risk of clustering.

There is always a change for collision:
Key1 $\neq$ Key2 yet H(Key1) = H(Key2).

## Handling Collisions:
- **Load Factor:**
    - Calculated as $\frac{n}{N}$, where $n$ is the number of itesm and $N$ is the table capacity.
    - Keep the load factor below 75% to minimize collisions.
- **Separate Chaining (Open Hashing):**
    - Each index in the table points to a linked list of entries that hash to the same index.
- **Open Addressing (Closed Hashing):**
    - Use the hash function to determine the index $H$(key).
    - If the slot is occupied, probe to find the next available unoccupied spot.
    - **Linear Probing:**
        - Probe by checking the next slot, with an offset of 1 (index + 1).
        - All probing occurs in-place, guaranteeing either a spot is found or no space is available.
    - **Quadradic Probing:**
        - Probe by checking the next slot with an increasing quadratic offset ($i^2$ for the $i$-th probe).
        - May miss some spots, but reduces primary clustering.
    - **Double Hashing:**
        - Use a second hash function to compute an offset: $\text{index} =H(\text{key}); \text{offset} = H'(\text{key})$.
        - The hope is that the second hash function produces a different distribution to avoid clustering.
        - Like quadratic probing, this method may miss some spots.

### Handling Lookups After an Object is Removed
- When an object is removed from a hash table, we need to ensure that future lookups can still find the correct target, even if the search involves probing (offset checks).
- **Solution:** Use a **sentinel value** in place of the removed object.
    - The sentinel marks the position to indicate that a key once occupied this spot but was removed.
    - The sentinel allows the lookup process to continue probing through the table, as it signals that further probing may still find the target elsewhere.

## Universal Hash Function
- A **universal hash function** is a type of hash function designed to minimize collisions by using random parameters $a$ and $b$.
### Different Forms of the Hash Function:
1. $H(\text{key})=(a \times \text{key}+b)\text{ mod }N$
2. $H(\text{key})=(\text{key}^a)\text{ mod }N$
3. $H(\text{key})=(\text{key}^a\times b+c)\text{ mod }N$

### Mapping and Parameters:
- The hash function maps values from the range $[0, M - 1] \text{ to } [0, N - 1]$.
- Choose a prime number $p$ such that $M < p < 2M$. This helps ensure good distribution and avoids certain types of collisions.
- **Parameters:**
    - $0 < a < p$
    - $0 \leq b < p$
- The complete universal hash function:
$$
H(\text{key})=((a\times \text{key} +b)\text{ mod }p)\text{ mod }N
$$
    - Here, $p$ is a prime number that acts as a modulus to reduce collision frequency.
    - The second modulus $N$ ensures that the result fits within the hash table's index range.