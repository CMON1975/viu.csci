# AVL Tree Project

## Overview

This project implements an AVL Tree, a self-balancing binary search tree, in C++. The implementation includes the main functionality for inserting and removing nodes while maintaining the AVL property, ensuring that the tree remains balanced after every operation. This ensures logarithmic time complexity for search, insert, and delete operations.

## Files

- **AVLTree.h:** Header file that defines the `AVLTree` class and its member functions.

- **AVLTree.cpp:** Implementation file containing the logic for all `AVLTree` operations (e.g., insertion, deletion, rotations).

- **AVL_test.cpp:** A test file that demonstrates the usage of the `AVLTree` class with example operations.

- **makefile:** A makefile that compiles the project into an executable.

## Compilation

To compile the project, run the following command in the terminal:
```
make
```
This will generate an executable named `AVL_test` that you can run to test the functionality of the AVL Tree.

## Usage

After compiling the project, run the following command to execute the test cases:
```
./AVL_test
```
The test cases demonstrate inserting, deleting, and displaying elements in the AVL Tree to verify its balancing properties.

## Features

- **Insertion:** Inserts nodes while maintaining balance using rotations.

- **Deletion:** Removes nodes and rebalances the tree when necessary.

- **Rotations:** Implements single and double rotations (left, right, left-right, right-left) to keep the tree balanced.