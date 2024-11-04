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
