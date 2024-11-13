CHRISTOPHER NILSSEN README.md for LAB 08 CSCI 260 F2402
# Skip List Implementation

## Overview
This project implements a Skip List data structure in C++. The Skip List provides efficient insertion and lookup for key-value pairs by organizing nodes across multiple probabilistic layers, achieving average-case O(log n) time complexity.

## Files
- **SkipList.cpp**: Contains the implementation of the `SkipList` class and `SkipListNode` structure.
- **SL_test.cpp**: A test program that demonstrates the functionality of the `SkipList` class by inserting and looking up several key-value pairs.
- **Makefile**: Builds the `SL_test` executable.

## Usage
To compile and run the program:
```bash
make
./SL_test
```