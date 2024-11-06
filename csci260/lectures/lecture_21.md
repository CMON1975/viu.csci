# Lecture 21
## Red Black Tree Height
$N_B$ = number of black nodes
$H_B \approx \log(N_B+1)$
Total nodes = $N_B+H_B$
$$
\begin{align}
HT &= 2H_B \\
&= 2\log(N_B+1) \\
&< 2\log N \\
&\in \Theta \log N
\end{align}
$$

---
### Red-Black Tree Basics
In a Red-Black Tree, every node is colored either red or black, and there are specific rules that ensure the tree remains balanced. This balance is maintained by the following properties:
1. Every node is either red or black.
2. The root is always black.
3. Every leaf (NIL node) is black.
4. If a red node has chilren, they must be black (no two red nodes can be adjacent, enforcing the "red property").
5. Every path from a node to its descendant NIL nodes contains the same number of black nodes.

These properties help ensure that the height of the tree is kept logarithmic with respect to the number of nodes, $N$, making operations like insertion, deletion, and search run in $O(\log N)$ time.

### Analysis of Red-Black Tree Height
The key to analyzing the height of a Red-Black Tree is to consider the number of black nodes along any path from the root to a leaf, as black nodes provide a sort of "spine" to the tree's structure.
1. **Number of Black Nodes $N_B$:** The variable $N_B$ represents the number of black nodes in the Red-Black Tree. Since every path from the root to a leaf contains the same number of black nodes, we can derive the approximate height of the tree based on this count.
2. **Black Height $H_B$:** The black height $H_B$ is defined as the number of black nodes on any path from the root to a leaf. By Red-Black Tree properties, the height of the tree is at most twice the black height, because there could be alternating red nodes between each black node. Therefore:
$$
HT\approx 2H_B
$$
3. **Estimating $H_B$:** The black height $H_B$ can be approximated as:
$$
H_B\approx \log(N_B+1)
$$
since in a balanced tree, the black height is logarithmic in terms of the number of black nodes.
4. **Total Height $HT$:** Using the relationship $HT = 2H_B$, we get:
$$
HT=2\log(N_B+1)
$$
5. **Relating $N_B$ to Total Nodes $N$:** Since $N_B \le N$ (black nodes are a subset of the total nodes), we can substitute to find the maximum possible height:
$$
HT < 2\log N
$$
Thus, the total height $HT$ of a Red-Black Tree is bounded by $2\log N$, making it $O(\log N)$.

### Big-O Notation and Tight Boutns
Since we are interested in the asymptotic behavior, we conclude:
$$
HT\in \Theta(\log N)
$$
This showes that the height of a Red-Black Tree grows logarithmically with the number of nodes, ensuring efficient operations.

---
## Skip List
```cpp
    struct Cell {
        DATA
        LINKS
    };

Cell * search(Key k);  // returns item or location where to place item
Data & lookup(Key k);  // calls search to either return data or DNF key error
bool or void insert(Key k, Data& obj);  // exceptions and handles location creation & possible RNG-determined tower-growth (new layer creation)

Can also use exists(Key k) as helper to confirm item is in dictionary.
```

### Skip List Overview
A Skip List is a probabilistic data structure that allows for fast search, insertion, and deletion operations, comparable to balanced binary trees. Skip Lists achieve this efficiency by maintaining multiple "layers" or "levels" of linked lists that allow nodes to be "skipped" over, enabling faster traversal. Each element in the Skip List is stored in a `Cell` structure, which may have multiple "links" at different levels.

In a Skip List:
- The bottom layer is a regular sorted linked list.
- Higher layers contain a subset of elements from the layer below, allowing skips.
- New layers are created based on a random probability (often 50%), giving the structure its probabilistic nature.

### Skip List Node Structure
Each node (or `Cell`) inthe Skip List might look like this in C++
```cpp
struct Cell {
    Key key;        // key for searching
    Data data;      // associated data
    std::vector<Cell*> links;   // vector to store links at multiple levels
};
```
The `links` vector contains pointers to other `Cell` objects at each level in the Skip List. The number of levels for each `Cell` is determined when the `Cell` is inserted, often using randomization to decide how many levels (or "towers") a particular node will occupy.

### Core Operations
1. **Search:** The `search(Key k)` function traverses the Skip List, starting from the top layer. At each level, it moves horizontally across nodes until it finds a node with a key greater than or equal to $k$. When a larger key is encountered, it moves down one layers and repeats this process. The function either returns the node containing the key or the location where the key would be inserted.
```cpp
Cell* search(Key k) {
    Cell* current = head;   // starting from head of skip list
    for (int level = maxLevel; level >= 0; --level) {
        while (current->links[level] && current->links[level]->key < k) {
            current = current->links[level];    // move horizontally
        }
    }
    return current->links[0];   // return node or insertion point
}
```
2. **Lookup:** The `lookup(Key k)` function calls `search(k)` to find the target node. If the nodes' key matches $k$, it returns the data; otherwise, it throws an arror for a "Key Not Found" situation (often a domain-specific exception).
```cpp
Data& lookup(Key k) {
    Cell* found = search(k);
    if (found && found->key == k) {
        return found->data; // found the data
    } else {
        throw std::runtime_error("Key Not Found");
    }
}
```
3. **Insert:** The `insert(Key k, Data& obj)` function inserts a new `Cell` with key $k$ and associated data. It calls `search(k)` to locate the position for insertion. If the key is not found, it generates a new node and decideds how many levels it should occupy based on a random probability function (this determines how high its "tower" is). Then, it updates the `links` of surrounding nodes to include this new node.
```cpp
void insert(Key k, Data& obj) {
    std::vector<Cell*> update(maxLevel + 1);
    Cell* current = head;

    // find insertion point and populate update array
    for (int level = maxLevel; level >= 0; --level) {
        while (current->links[level] && current->links[level]->key < k) {
            current = current->links[level];
        }
        update[level] = current;    // store last node at each level before k
    }

    // create a new node if k doesn't already exist
    int newLevel = randomLevel();
    Cell* newNode = new Cell{k, obj, std::vector<Cell*>(newLevel + 1)};

    // insert node and update pointers
    for (int i = 0; i <= newLevel; ++i) {
        newNode->links[i] = update[i]->links[i];
        update[i]->links[i] = newNode;
    }
}

int randomLevel() {
    int level = 0;
    while ((rand() % 2) && level < maxLevel) {
        ++level;
    }
    return level;
}
```
4. **Existence Check Helper:** The `exists(Key k)` function can simply call `search(k)` and check if the returned node has the same key $k$. This can be useful for confirming if an item is in the list without needing to retrieve its data.
```cpp
bool exists(Key k) {
    Cell* found = search(k);
    return (found && found->key == k);
}
```
### Additional Details
- **Random Level Generation:** The `randomLevel` function uses randomness to determine how many levels a new node should span. Each level in a Skip List is generally added with a 50% chance, which helps the Skip List maintain logarithmic search complexity on average.
- **Time Complexity:** Due to the layered structure and randomization, search, insertion, and deletion in a Skip List typically achieve $O(\log N)$ time complexity.

These functions together allower for an efficient dictionary-like structure, with operations that can dynamically "skip" parts of the list thanks to the higher levels, ensuring speed and flexibility.

---
```cpp
Data& remove(Key k) {   // attempt to return data rather than throw exception
    p = search(k);  // returns cell in bottom layer
    if(p->key != k)
        throw not found exception
    Data *temp = p->d;
    Cell *q;
    while (p != nullptr) {
        p->before->after = p->after;    // doubly-linked
        p->after->before = p->before;   // list remove
        // now delete entire tower
        q = p;
        p = p->above;
        delete q;
    }
    return *temp;
}
```
Other possible methods:
- `getSize()` counts the bottom layer or uses an internal `size` variable.
- `displayKeys()`
```cpp
int getSize() const {
    return size;    // size should be updated in insert and remove operations
}

void displayKeys() const {
    Cell* current = head->links[0]; // start at the bottom layer
    while (current != nullptr) {
        std::cout << current->key << " ";
        current = current->after;
    }
    std::cout << std::endl;
}
```

---
## Abstract Data Type Considerations
- properties (what is it?)
- operations (implementation)
- insert/remove: how can it maintain its properties?
These are universal considerations when defining an abstract data type.

---
## Exact String Matching
string S, `S[i]` returns `char` at `i`
substring[i..j]
pattern P

if $\exists$ $i$ such that $S[i..i + m - 1] == P$
$\forall j, 0\le j\le m -1$
$S[i+j]= P[j]$

### Explanation
In exact string matching, we are given:
- String $S$: This is the main text in which we're looking for the occurences of the pattern.
    - For simplicity, let's assume $S$ has length $n$.
- Pattern $P$: This is the substring we want to find within $S$.
    - Let's assume $P$ has length $m$.

The objective is to find all indices $i$ in $S$ where the substring starting at $i$ matches $P$ exactly. In other words, we are looking for positions $i$ where the substring $S[i..i + m - 1]$ matches $P$.

### Formalized Conditions for Exact Match
1. **Pattern Matching Condition:**
    - We say there's a match at position $i$ if:
    $$
    S[i..i + m - 1] = P
    $$
    - In other words, starting from index $i$, the next $m$ characters in $S$ must match all characters in $P$.
2. **Element-wise Matching:**
    - For the match to be exact, each character in $P$ must match the corresponding character in the substring of $S$ at that location. Formally, this means:
    $$
    \forall j, 0\le j\le m - 1, S[i + j] = P[j]
    $$
    - Here, $j$ is an offset within the pattern $P$, and $S[i + j]$ is the corresponding character in $S$ that must match $P[j]$ for the entire substring to be a match.

### Putting It All Together 
Given a string $S$ of length $n$ and a pattern $P$ of length $m$, the goal is to find all indices $i$ where:
1. **Length Constraint:** $i + m - 1 < n$ (i.e., the pattern can fit starting from $i$ without exceeding $S$'s length).
2. **Match Condition:** $S[i..i + m - 1] = P$.

If both conditions are satisfied, then $S[i..i + m - 1]$ is an exact match of $P$ within $S$.

### Example in Code 
A simple implementation of exact string matching using this logic would look like this in C++:
```cpp
#include <string>
#include <vector>

std::vector<int> exactStringMatch(const std::string& S, const std::string& P) {
    std::vector<int> matches;
    int n = S.length();
    int m = P.length();

    for (int i = 0; i <= n - m; ++i) {  // ensure pattern fits within bounds of S
        bool match = true;
        for (int j = 0; j < m; ++j) {
            if (S[i + j] != P[j]) { // check each character in the substring
                match = false;
                break;
            }
        }
        if (match) {
            matches.push_back(i);   // record starting index of the match
        }
    }
    return matches; // return indices where pattern P is found in S
}
```

### How the Code Works
- **Loop through $S$:** The outer loop checks each potential starting index $i$ where $P$ could fit within $S$.
- **Character-by-Character Comparison:** The inner loop checks if all characters of $P$ match the substring starting at $i$ in $S$. If a mismatch is found, it breaks out of the loop.
- **Store Matches:** When all characters match, $i$ is added to the `matches` vector, indicating that an exact match of $P$ was found starting at index $i$ in $S$.

### Complexity
This brute-force algorithm has a time complexity of $O((n - m + 1) \times m)$ in the worst case, where:
- $n$ is the length of $S$
- $m$ is the length of $P$

This approach is simple but can be inefficient for long strings. For more efficient exact matching, algorithms like the **Knuth-Morris-Pratt (KMP), Boyer-Moore, or Rabin-Karp** are often used.

---
1. **Brute Force Algorithm**
```cpp
int BFSearch (const string& S, const string& P) {
    int lenS = S.length();
    int lenP = P.length();

    for (int i = 0; i <= lenS - lenP; ++i) {    // iterate over possible start positions in S 
        int j = 0;
        while (j < lenP && S[i + j] == P[j])    // compare characters of P with substring of S
            ++j;
        if (j == lenP)  // if we matched all of P
            return i;   // return the starting index of the match
    }
    return -1;  // return -1 if no match is found
}
```

2. **Boyer-Moore Algorithm**
Preprocess the pattern string $P$ with respect to the alphabet $\sum$.
```cpp
#include <string>

const int ALPHABET_SIZE = 256;  // size of ASCII alphabet

// calculates the last occurrence of each character in pattern P
void calculate_last(const std::string& P, int last[], int alphabet_size) {
    for (int i = 0; i < alphabet_size; ++i) {
        last[i]
    }
}
```
Best case = $\Theta(\frac{n}{m} + m)$
Worst case = $\Theta(m \times n)$

The Boyer-Moore algorithm is a more efficient exact string matching algorithm, especially useful when the pattern is large relative to the text. It uses preprocessing and two key heuristics--**last occurrence** and **good suffix**--to skip sections of the text, thus reducing the number of comparisons.

### Overview of the Boyer-Moore Algorithm
1. **Last Occurence Table:**
    - We preprocess the pattern $P$ to create a table that records the last occurence of each character in $P$. This table allows the algorithm to skip over characters that don't need to be checked based on mismatches.
    - If a mismatch occurs, we look up the last occurrence of the mismatched character in $P$ to determine how far to shift $P$ in relation to $S$.
2. **Searching with Boyer-Moore:**
    - The Boyer-Moore algorithm starts comparing $P$ to $S$ from the end of $P$ (right to left).
    - If a mismatch is found, the last occurrence table tells us how much to shift $P$ so that either:
        - The mismatched character in $S$ aligns with its last occurence $P$, or
        - $P$ is shifted past the mismatched character if it doesn't appear in $P$.

### C++ Example 
```cpp
#include <string>
using std::string;

const int ALPHABET_SIZE = 256;  // size for ASCII alphabet

// calculates the last occurrence of each character in pattern P
void calculate_last(const string& P, int last[], int alphabet_size) {
    for (int i = 0; i < alphabet_size; ++i) {
        last[i] = -1;   // initialize all values to -1
    }
    for (int i = 0; i < P.length(); ++i) {
        last[P[i]] = i; // record the last position of each character in P
    }
}

int BMSearch(const string& S, const string& P) {
    int lenS = S.length();
    int lenP = P.length();
    int last[ALPHABET_SIZE];    // array for last occurrence of each character
    calculate_last(P, last, ALPHABET_SIZE);

    int i = lenP - 1;   // start position in S (aligned with the end of P)
    int j = lenP - 1;   // position in P

    while (i < lenS) {
        if (S[i] == P[j]) { // if characters match
            if (j == 0) {
                return i;   // full match found at index i in S
            }
            --i;
            --j;    // move both indices left
        } else {    // mismatch case
            int last_occurrence = last[S[i]];   // get last occurrence in pattern
            i = i + lenP - ((j < last_occurrence + 1) ? j : last_occurrence + 1);
            j = lenP - 1;   // reset j to the end of P
        }
    }
    return -1;  // return -1 if no match found
}
```

### Code Explanation 
1. **Preprocessing with `calculateLast`:**
    - `calculateLast` fills an array `last` where each index represents a character in the alphabet (e.g., ASCII characters from 0 to 255).
    - For each character in $P$, it stores the index of its **last occurrence**. Characters not in $P$ are set to `-1`.
    - This array allows us to quickly look up where a mistmachted character last appears in $P$, which helps determine the shift amount.
2. **Search Logic in `BMSearch`:**
    - The `BMSearch` function starts from the end of $P$ and tries to match it to $S$ from right to left.
    - **Match Case:** If characters match (`S[i] == P[j]`), both indices `i` and `j` move one position left.
    - **Mismatch Case:** When a mismatch is detected, we use the `last` array to shift $P$ by the following amount:
    $$
    \text{shift}= \text{lenP} - \text{min}(j\text{, last}[S[i]]+1)
    $$
    - After shifting, `j` is reset to the end of $P$.

### Complexity Analysis
- **Best Case $(\Theta(\frac{n}{m}+m))$:** When there are frequent mismatches early in $P$, allowing large shifts in each step, Boyer-Moore can be very efficient.
- **Worst Case $(\Theta(m \times n))$:** In the worst case, the algorithm might behave light a brute force search (e.g., for specific patterns and texts where mismatches happen near the end of $P$).

### Summary
The Boyer-Moore algorithm is efficient for large texts, leveraging the last occurrence table to skip unnecessary comparisons. In this code:
- `calculateLast` initializes the `last` array.
- `BMSearch` uses the `last` array to guide pattern shifts, aiming to minimize character-by-character comparisons in the search.

## 3. **KMP (Knuth Morris Pratt) Algorithm**

The **Knuth-Morris-Pratt (KMP) Algorithm** is a string-searching algorithm that uses efficient preprocessing of the pattern $P$ to skip unnecessary comparisons in the search text $S$. Let's expand on each concept, including the idea of **bootstrapping** in the context of the failure function.

### Key Concepts of the KMP Algorithm
1. **Prefix and Suffix Matching:**
    - The KMP algorithm is based on the observation that, when a mismatch occurs, we can ski certain positions in the search text rather than starting over.
    - This is achieved by identifying "partial matches" between the prefix and suffix of the pattern $P$.
    - Specifically, for each position in $P$, we calculate the length of the longest prefix that is also a suffix. This information is stored in an array called the **failure function** (often denoted `f[]`).
2. **Failure Function (Prefix Table):**
    - The **failure function** (or prefix table) `f[j]` indicates the length of the longest prefix of $P[0..j]$ that matches a suffix of $P[1..j]$.
    - This allows the KMP algorithm to skip over positions in $S$ where matches would not be possible based on prior information.
3. **Bootstrapping:**
    - **Bootstrapping** in the KMP algorithm refers to the iterative process of building the failure function, where each calculated value of `f[i]` relies on the previous computed values.
    - As we build `f[]`, we reuse the results of earlier calculations (prefixes and suffixes of shorter lengths) to efficiently determine `f[i]` for longer prefixes.
    - This "bootstrapping" avoids redundant comparison and speeds up the preprocessing phase.

### Detailed Code and Explanation
```cpp
#include string
using std::string;

void failure(int f[], const string& P) {
    f[0] = 0;   // the first position has no proper prefix-suffix match
    int i = 1;  // the current position in P for which we're calculating f[i]
    int j = 0;  // the length of the longest prefix suffix

    int lenP = P.length();
    while (i < lenP) {
        if (P[i] == P[j]) { // if characters match
            f[i] = j + 1;   // set f[i] to length of longest prefix suffix
            ++i;
            ++j;
        } else if (j > 0) { // mismatch after some matches
            j = f[j - 1]l   // set j to the last known longest prefix suffix
        } else {    // no match at all
            f[i] = 0;   // no prefix suffix match for this position
            ++i;
        }
    }
}

// KMP search function
int KMPSearch(const string& S, const string& P) {
    int lenS = S.length();
    int lenP = P.length();
    int f[lenP];        // failure function array
    failure(f, P);      // preprocess pattern P to build the failure function

    int i = 0;      // position in S
    int j = 0;      // position in P

    while (i < lenS) {
        if (S[i] == P[j]) {     // match characters in S and P
            if (j == lenP - 1)  // full match of P in S
                return i = j;   // return starting index of the match in S
            ++i;
            ++j;
        } else if (j > 0) {     // mismatch after some matches
            j = f[j - 1];       // jump to the last known position in P based on failure function
        } else {
            ++i;                // move to the next character in S
        }
    }
    return -1;                  // no match found
}
```
 
### Explanation of Each Function 
**Failure Function `failure()`**
The `failure` function constructs the prefix table `f[]`, where each entry `f[i]` gives the length of the longest proper prefix of $P$ that is also a suffix of $P[1..i]$. Here's the logic in each part of this function:
1. **Initialize Values:**
    - `f[0]` is set to `0` because the first character has no proper prefix that matches a suffix.
    - `i` is the position in `P` that we're currently processing, and `j` is the length of the longest prefix suffix we've found so far.
2. **Character Matching (`P[i] == P[j]):**
    - When `P[i]` matches `P[j]`, the length of the longest prefix suffix increases by 1.
    - We set `f[i] = j + 1` to record this and then increment both `i` and `j` to continue checking the next characters.
3. **Mismatch with Partial Matches (`j > 0`):**
    - If there's a mismatch but `j > 0` (meaning there's a partial match already), we set `j = f[j - 1]`. This reduces `j` to the length of the next longest prefix suffix in `P`.
    - This "bootstrapping" step allows the algorithm to reuse previously computed values, skipping redundant checks.
4. **No Match at All (`j == 0`):**
    - If `P[i]` and `P[j]` don't match and there's no prefix suffix (`j == 0`), set `f[i] = 0`, then increment `i` to check the next position in `P`.

**KMP Search `KMPSearch()`**
The `KMPSearch` function performs the actual search of $P$ in $S$ using the failure function `f[]`:
1. **Initialize Values:**
    - `i` is the index for $S$ (text), and `j` is the index for $P$ (pattern).
2. **Character Matching:**
    - If `S[i] == P[j]`, both `i` and `j` are incremented. If `j` reaches the end of $P$ (i.e., `j == lenP - 1`), a full match of $P$ has been found in $S$.
    - The starting index of the match in $S$ is `i - j`.
3. **Mismatch with Partial Match (`j > 0`):**
    - If characters don't match and `j > 0`, we use the failure function to skip to `f[j - 1]`. This allows us to continue comparing with $P$ without starting from the beginning, utilizing previously matched prefixes.
4. **No Partial Match (`j == 0`):**
    - If there's no partial match (`j == 0`), increment `i` to move to the next character in $S$.

### Complexity of KMP
- **Time Complexity: $\Theta(n+m)$**, where $n$ is the length of $S$ and $m$ is the length of $P$. This is because each character in $S$ and $P$ is processed at most once.
- **Space Complexity: $\Theta(m)$** due to the failure function array.

### Summary
The KMP algorithm preprocesses the pattern $P$ using the failure function, which enables it to skip redundant checks by bootstrapping on already computed prefix information. This leads to efficient search with minimal backtracking, making it optimal for exact string matching.

## 4. KR (Karp-Rabin) Algorithm
The **Karp-Rabin (KR) Algorithm** is a probabilistic string-searching algorithm that uses **hashing** to efficiently locate a pattern $P$ within a target text $S$. This algorithm is particularly useful for finding multiple occurrences and works well with a rolling hash function to make shifting the pattern efficient.

Here's a more organized and expanded explanation, followed by cleaned-up code with an explanation of adjustments for multiple occurrences.

### Key Concepts of the Karp-Rabin Algorithm
1. **Hash Functions:**
    - The algorithm starts by selecting a hash function $H$ that maps strings (like the pattern $P$ and segments of $S$) to numeric values.
    - The chosen hash function should be:
        - **Efficient to compute.**
        - **Consistent** (the same input produces the same output).
        - **Sensitive to permutations** (different strings should ideally produce different hash values to minimize collisions).
2. **Rolling Hash:**
    - The **rolling hash** function computes a hash value for a substring of length $m$ (length of $P$) in $S$ and allows us to efficiently update this hash when shifting by one character.
    - The hash function for a substring $S[i..j]$ of length $m$ is generally computed as:
    $$
    H(S[i..j]) = S[i] \cdot a^{m-1} + S[i + 1] \cdot a^{m-2} + ... + S[j]
    $$
    - When moving from position $i$ to $i + 1$ in $S$, the hash can be **updated** in constant time by removing the contribution of `S[i]`, multiplying the remaining hash by the base, and adding the next character $S[i + m]$.

### Code Implementation
```cpp
#include <string>
using std::string;

int compute_hash(const string& str, int len, int a) {
    int hash = 0;
    for (int i = 0l i < len; ++i) {
        hash = hash * a + str[i];   // compute initial hash for length len
    }
    return hash;
}

int KRSearch(const string& S, const string& P, int* results, int max_results, int a = 33) {
    int lenS = S.length();
    int lenP = P.length();
    int d = 1;          // precompute d = a^(lenP - 1) for rolling hash
    for (int i = 1; i < lenP; ++i) {
        d *= a;
    }

    int hp = compute_hash(P, lenP, a);      // hash for the pattern
    int hs = compute_hash(S, lenP, a);      // initial hash for the first window in S
    int result_count = 0;                   // track number of matches found

    for (int i = 0; i <= lenS - lenP; ++i) {
        if (hp == hs) {                     // if hash values match, do character check
            bool match = true;
            for (int j = 0; j < lenP; ++j) {
                if (S[i + j] != P[j]) {     // character comparison to confirm match
                    match = false;
                    break;
                }
            }
            if (match) {                    // if characters match exactly
                if (result_count < max_results) {
                    results[result_count++] = i;    // store the starting index in results array
                }
            }
        }
        if (i < lenS - lenP) {              // update hash hs for next window
            hs = (hs - S[i] * d) * a + S[i + lenP];
        }
    }
    return result_count;                    // return the number of matches found
}
```

### Explanation of Code
1. **Computer Initial Hash:**
    - `compute_hash` calculates the hash of a given string over a specified length using the base $a$. We use it to calculate both the initial pattern hash `hp` and the initial hash `hs` for the first window in $S$.
2. **Rolling Hash Update:**
    - After each check, `hs` is updated to reflect the hash of the next substring in $S$. This is done by:
        - Substracting the influence of the first character in the current window (`S[i] * d`).
        - Multiplying the remaining hash by $a$ to "shift" left.
        - Adding the next character $S[i + \text{lenP}]$.
3. **Match Verification:**
    - If `hp == hs`, we verify the match to avoid false positives by comparing characters in `S[i..i + lenP - 1]` to `P`.
    - If a match is found, we store the index `i` in the `results` array if there's space left (ensuring `result_count < max_results`).
4. **Finding Multiple Occurrences:**
    - The function records each matching index in the `results` array, up to the `max_results` limit.
    - `result_count` keeps track of the number of matches found, which the function returns at the end.

### Complexity
- **Time Complexity:** The Karp-Rabin algorithm operates in $O(n + m)$ on average due to the efficient rolling hash updates.
- **Space Complexity:** $O(m)$ for storing hash values, with additional space for the `results` array.

### Summary
The Karp-Rabin algorithm efficiently locates patterns within text by:
- Using a rolling hash function to compute hash values for each substring in $S$.
- Comparing hashing to quickly skip over non-matching sections of $S$.
- Only verifying character-by-character when hashes match to handle collisions.

## Wildcard (not part of this course)
- such search uses **finite state machines**

## Trie
### Key Concepts
1. **Text Strings Broken into Components:**
    - In a Trie, a single text string can be broken down into **prefixes** of shorter strings. Each path from the root to a node represents a prefix, and each complete path to a terminal node represents a stored word.
2. **Fixed Alphabet:**
    - Tries generally work on a **fixed, finite alphabet $\sum$** (e.g., lowercase English letters or digits). This finite alphabet allows each node to have a fixed number of child pointers, simplifying insertion and lookup.
    - For example, in a Trie for lowercase English words, each node might have 26 pointers (one for each letter of the alphabet).
3. **Multiple Patterns:**  
    - Tries are well-suited for handling multiple pattern strings, making them ideal for tasks like dictionary management or autocomplete systems.
    - A Trie can store multiple words or patterns while allowing efficient prefix-based searches, which is valuable for matching or validating patterns with shared prefixes.
4. **Prefix-Free Property:**
    - A Trie can enforce that no word is the prefix of another by ensuring that each word reaches a terminal or leaf node. This means that if one word is stored as a complete path, any longer word that shares this path will branch off from it.

### Trie Abstract Data Type (ADT)
The **Trie ADT** is a tree-based data structure that consists of nodes where each node represents a character or set of characters in a word. The Trie supports several key operations:
1. **Insertion:**
    - Insert a word by following or creating nodes for each character. When a complete word is inserted, mark the final node as a terminal node to indicate the end of the word.
2. **Search:**
    - Search for a word by following nodes for each character. When a complete word is inserted, mark the final node as a terminal node to indicate the end of the word.
3. **Prefix Matching:**
    - To find all words that share a given prefix, start from the root and follow the nodes for each character in the prefix. Once the prefix is matched, all descendants from that point are words that share the prefix.

### Types of Tries
1. **Standard Trie:**
    - In a **standard Trie**, each node represents a single character. Nodes are connected in such a way that paths from the root represent words.
    - Each node has a fixed array of pointers (one for each character in the alphabet), making it straightforward but potentially memory-intensive for large alphabets.
2. **Compressed Trie:**
    - A **compressed Trie** (also known as a Patricia Trie or a Radix Trie) reduces the memory footprint by compressing chains of nodes. Instead of each node containing a single character, nodes may store a substring, representing multiple characters.
    - Compression is useful for saving space when there are long paths in the Trie with no branching.

### Concrete Implementation Details

When implementing a Trie, there are several factors to consider:
- **Node Structure:** Each node should have an array of pointers, with each index corresponding to a character in the alphabet. The example structure shown is designed for lowercase English leters plus one additional entry for a null terminator:
```cpp
struct Node {
    Node* A[27];    // 26 letters + 1 for end-of-word marker
    bool is_end_of_word;    // indicates if the node represents the end of a word
    Node() : is_end_of_word(false) {
        for (int i = 0; i < 27; ++i) A[i] = nullptr;
    }
};
```
- **Fixed Alphabet and Memory Usage:**
    - For an alphabet with $\sum$ characters, each node contains an array of $\sum + 1$ pointers. This can use a lot of memory, especially when storing sparse data.
    - For large alphabets or sparse data, you may use a `std::map` for dynamic storage, though this sacrifices some efficiency.
- **Insertion Example:**
    ```cpp
    void insert(Node* root, const string& word) {
        Node* current = root;
        for (char ch : root) {
            int index = ch - 'a';   // calculate array index for character
            if (!current->A[index]) {
                current->A[index] = new Node();
            }
            current = current->A[index];
        }
        current->is_end_of_word = true; // mark end of the word
    }
    ```
- **Search Example:**
    ```cpp
    bool search(Node* root, const string& word) {
        Node* current = root;
        for (char ch : word) {
            int index = ch = 'a';
            if (!current->A[index]) {
                return false;
            }
            current = current->A[index];
        }
        return current->is_end_of_word;
    }
    ```

### Complexity Analysis
- **Space Complexity:**
    - The worst-case space complexity for a Trie is $O(n \times m)$ where:
        - $n$ is the number of words stored.
        - $m$ is the maximum length of the words.
    - The worst case arises when each word is unique, requiring a new branch at each level of the Trie.
- **Time Complexity:**
    - **Insertion** and **Search**: $O(m)$, where $m$ is the length of the word.
    - Tries offer efficient $O(m)$ time complexity for insertion and search operations, which is generally faster than other data structures for large datasets with many strings.

### Summary of Trie Properties and Use Cases
- **Efficient Prefix Search:** Tries are ideal for applications like autocomplete and spell-checking, where fast prefix matching is essential.
- **Memory Trade-off:** Tries are memory-intensive for large or sparse datasets due to the number of pointers stored in each node.
- **Applications:** Common applications of Tries include dictionaries, autocomplete systems, IP routing tables, and even DNA sequence matching.