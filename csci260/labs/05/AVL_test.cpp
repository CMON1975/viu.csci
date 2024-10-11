// CHRISTOPHER NILSSEN AVL_test.cpp for LAB 05 CSCI 260 F2402
#include "AVLTree.h"

int main() {
    AVLTree tree;

    // test case 1: single right rotation (LL rotation)
    tree.insert(30);
    tree.insert(20);
    tree.insert(10); // should trigger a single right rotation

    cout << "After LL rotation (in-order): ";
    tree.inOrder(); // expected output: 10 20 30

    cout << "After LL rotation (pre-order): ";
    tree.preOrder(); // expected output: 20 10 30

    // reset tree
    tree = AVLTree();

    // test case 2: single left rotation (RR rotation)
    tree.insert(10);
    tree.insert(20);
    tree.insert(30); // should trigger a single left rotation

    cout << "\nAfter RR rotation (in-order): ";
    tree.inOrder(); // expected output: 10 20 30

    cout << "After RR rotation (pre-order): ";
    tree.preOrder(); // expected output: 20 10 30

    // reset tree
    tree = AVLTree();

    // test case 3: left-right rotation (LR rotation)
    tree.insert(30);
    tree.insert(10);
    tree.insert(20); // should trigger a left-right rotation

    cout << "\nAfter LR rotation (in-order): ";
    tree.inOrder(); // expected output: 10 20 30

    cout << "After LR rotation (pre-order): ";
    tree.preOrder(); // expected output: 20 10 30

    // reset tree
    tree = AVLTree();

    // test case 4: right-left rotation (RL rotation)
    tree.insert(10);
    tree.insert(30);
    tree.insert(20); // should trigger a right-left rotation

    cout << "\nAfter RL rotation (in-order): ";
    tree.inOrder(); // expected output: 10 20 30

    cout << "After RL rotation (pre-order): ";
    tree.preOrder(); // expected output: 20 10 30

    // reset tree
    tree = AVLTree();

    // test case 5: deletion causing single right rotation (LL rotation)
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);

    tree.remove(50); // should trigger a single right rotation

    cout << "\nAfter deletion LL rotation (in-order): ";
    tree.inOrder(); // expected output: 10 20 30 40

    // reset tree
    tree = AVLTree();

    // test case 6: deletion causing single left rotation (RR rotation)
    tree.insert(50);
    tree.insert(40);
    tree.insert(30);
    tree.insert(20);
    tree.insert(10);

    tree.remove(10); // should trigger a single left rotation

    cout << "\nAfter deletion RR rotation (in-order): ";
    tree.inOrder(); // expected output: 20 30 40 50

    // reset tree
    tree = AVLTree();

    // test case 7: deletion causing left-right rotation (LR rotation)
    tree.insert(50);
    tree.insert(20);
    tree.insert(70);
    tree.insert(10);
    tree.insert(30);
    tree.insert(60);
    tree.insert(80);

    tree.remove(80); // should trigger a left-right rotation

    cout << "\nAfter deletion LR rotation (in-order): ";
    tree.inOrder(); // expected output: 10 20 30 50 60 70

    // reset tree
    tree = AVLTree();

    // test case 8: deletion causing right-left rotation (RL rotation)
    tree.insert(10);
    tree.insert(5);
    tree.insert(20);
    tree.insert(15);
    tree.insert(25);

    tree.remove(5); // should trigger a right-left rotation

    cout << "\nAfter deletion RL rotation (in-order): ";
    tree.inOrder(); // expected output: 10 15 20 25

    return 0;
}