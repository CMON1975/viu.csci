CHRISTOPHER NILSSEN README.md for LAB 06 CSCI 260 F2402
# ThreadTree Implementation

This project implements a **Threaded Binary Search Tree** (`ThreadTree`) in C++. A thread tree is a variation of a binary search tree where null pointers in each node are used to point to in-order predecessor or successor nodes, allowing efficient in-order traversal without recursion or a stack.

## Project Structure

- **ThreadTree.cpp**: Contains the `ThreadTree` class definition and implementation.
- **TT_test.cpp**: Provides a test program to demonstrate the usage of the `ThreadTree` class and its in-order traversal.
- **Makefile**: Automates the build process, compiling both `ThreadTree.cpp` and `TT_test.cpp` into an executable.

## Class Interface

```cpp
class ThreadTree {
public:
    ThreadTree();              // Constructor
    ~ThreadTree();             // Destructor
    void inOrder() const;      // Iterative in-order traversal
    void insert(double k);     // Insert a double value into the tree
private:
    // Private data members and helper methods
};
```

### Key Features

- **Insertion:** Adds nodes with double values into the tree, maintaining the binary search property.
- **In-Order Traversal:** Iteratively traverses the tree in in-order sequence, leveraging threaded pointers for efficiency.

## Usage
1. **Build** the project using the provided `Makefile`:
```bash
make
```
2. **Run** the executable to test the `ThreadTree` implementation:
```bash
./TT_test
```
3. **Clean** up compiled files with:
```bash
make clean
```

## Example
The in-order traversal of an example tree, built by inserting nodes in this order: `20.3, 15.2, 9.1, 3.6, 12.7, 8.5, 1.9`, will produce the sorted output:
```
In-order traversal: 1.9 3.6 8.5 9.1 12.7 15.2 20.3
```

## Requirements
- **Compiler:** Any C++ 11 compatible compiler (e.g., `g++`)
- **Make:** To utilize the `Makefile`

## Notes
- This implementation assumes the tree only stores unique `double` values.
- See comments in the `ThreadTree.cpp` for more details on the structure and threading logic.