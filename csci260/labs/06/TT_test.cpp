// CHRISTOPHER NILSSEN TT_test.cpp for LAB 06 CSCI 260 F2402
#include "ThreadTree.cpp"

int main() {
    ThreadTree tree;

    tree.insert(20.3);
    tree.insert(15.2);
    tree.insert(9.1);
    tree.insert(3.6);
    tree.insert(12.7);
    tree.insert(8.5);
    tree.insert(1.9);

    cout << "In-order traversal: ";
    tree.inOrder();

    return 0;
}