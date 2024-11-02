CHRISTOPHER NILSSEN README.md for LAB 07 CSCI 260 F2402
# (2,4)-Tree Implementation

This project implements a **(2,4)-Tree** (`TwoFourTree`) in C++. A (2,4)-Tree is a balanced tree where each node can have 2, 3, or 4 children, allowing for efficient insertion and search operations while maintaining a balanced structure.

## Project Structure

- **TwoFourTree.cpp**: Contains the `TwoFourTree` class definition and implementation.
- **TF_test.cpp**: Provides a test program to demonstrate the usage of the `TwoFourTree` class, including insertion and lookup operations.
- **Makefile**: Automates the build process, compiling both `TwoFourTree.cpp` and `TF_test.cpp` into an executable.

## Class Interface

```cpp
class TwoFourTree {
public:
    TwoFourTree();              // Constructor to create an empty (2,4)-tree
    ~TwoFourTree();             // Destructor to clean up nodes and data
    bool insert(int, std::string); // Inserts a key-value pair; returns false on duplicate
    bool lookup(int, std::string&); // Looks up a key and retrieves data
private:
    // Private data members and helper methods
};
```

## Key Features
- **Insertion**: Adds nodes with integer keys and associated string data, splitting nodes when necessary to maintain (2,4)-Tree properties.
- **Lookup**: Searches for a key and retrieves the associated data, returning true if the key exists in the tree.

## Usage
1. **Build** the project using the provided `Makefile`:
```bash
make
```
2. **Run** the executable to test the `TwoFourTree` implementation:
```bash
./TT_test
```
3. **Clean** up compiled files with:
```bash
make clean
```

## Example
The following sequence of insertions: `(10, "Data10"), (20, "Data20"), (5, "Data5"), (6, "Data6"), (12, "Data12")` will allow retrieval using the `lookup` method, such as:
```
Lookup for key 6 returns: Data6
```

## Requirements
- Compiler: Any C++ 11 compatible compiler (e.g., g++)
- Make: To utilize the `Makefile`

## Notes
- This implementation assumes keys are unique integers and each key has an associated string.
- See comments in `TwoFourTree.cpp` for further details on the tree balancing and splitting mechanics.