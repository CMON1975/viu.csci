#include <iostream>
#include "AVLTree.h"
using namespace std;

int main() {
    AVLTree tree;

    // Test case 1: Insert values in ascending order
    cout << "Inserting values in ascending order (1, 2, 3, 4, 5)..." << endl;
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);

    // Output in-order, pre-order, and post-order to check balance
    cout << "In-Order Traversal (should be sorted with balance factors):" << endl;
    tree.inOrder();  // Expected sorted order with balances to confirm balancing

    cout << "Pre-Order Traversal (to check root and balance changes):" << endl;
    tree.preOrder();

    cout << "Post-Order Traversal (to confirm structure):" << endl;
    tree.postOrder();

    // Test case 2: Insert values in descending order to force different rotations
    AVLTree tree2;
    cout << "\nInserting values in descending order (5, 4, 3, 2, 1)..." << endl;
    tree2.insert(5);
    tree2.insert(4);
    tree2.insert(3);
    tree2.insert(2);
    tree2.insert(1);

    cout << "In-Order Traversal:" << endl;
    tree2.inOrder();

    cout << "Pre-Order Traversal:" << endl;
    tree2.preOrder();

    cout << "Post-Order Traversal:" << endl;
    tree2.postOrder();

    // Test case 3: Insert values that cause left-right and right-left rotations
    AVLTree tree3;
    cout << "\nInserting values to cause left-right and right-left rotations (3, 1, 2, 4, 5, 6)..." << endl;
    tree3.insert(3);
    tree3.insert(1);
    tree3.insert(2);  // Should cause a left-right rotation at 3
    tree3.insert(4);
    tree3.insert(5);
    tree3.insert(6);  // Should cause a right-left rotation at 4

    cout << "In-Order Traversal:" << endl;
    tree3.inOrder();

    cout << "Pre-Order Traversal:" << endl;
    tree3.preOrder();

    cout << "Post-Order Traversal:" << endl;
    tree3.postOrder();

    // Test case 4: Check duplicate insertion handling
    cout << "\nAttempting to insert duplicate value 3 into tree3..." << endl;
    tree3.insert(3);  // Expect a message "Duplicate Key"

    // Summary
    cout << "\nAll tests complete. Please check the balance factors and orders above for AVL correctness." << endl;

    return 0;
}
