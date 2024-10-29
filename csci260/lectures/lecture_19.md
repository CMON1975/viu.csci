# Red-Black Tree

A red-black tree is a binary search tree that satisfies the following properties:
- **Search key property:** a red-black tree is a binary search tree.
- **Color property:** each node is either black or red.
- **Root property:** the root is black.
- **Internal property:** the children of a red node are black.
- **Depth property:** all the leaf nodes have the same black depth, which is defined as the number of black nodes along the branch from the root to the leaf node.

Intuitively, there is a mapping between a red-black tree and a (2,4)-tree.

Main operations:
- `lookup`: same ast binary search tree lookup.
- `insert`
    ```pseudocode
    Insert the new node as a normal BST insert;
    If the new Node is the root
        color it black;
    Else
        color it red;
    If there is a double-red problem, i.e., the parent node is red
        Case 1: the sibling of the parent node is black
                perform a tri-node restructure
        Case 2: the sibling of the parent node is also red
                (then the grandparent node must be black)
                color its parent node and parent's sibling node both black,
                color its grandparent node red, double red problem may propagate
    ```
    Performance: At most 1 tri-node restructure and O(logN) recoloring.
- `remove`
    ```pseudocode
    Find the victim node to delete
    If the victim node has two children
        swap it with its in-order successor node v // v has no left child
    Remove node v, place its right child r in its position
    // r can be null; and null pointers are all considered black
    If v is red, then its right child r must be black
        done
    If its right child r is red, v must be black
        color r black, done
    If v is black and r is also black
        color r double-black, and we have an underflow problem
        Case 1: sibling y of r is black and has a red child z
                perform a tri-node restructure, done
        Case 2: sibling y of r is black and bother its children are black
                if y and r's parent node x is red
                    color x black, color y red, color r black, done
                if x is black
                    color y red, color r black, color x double black,
                    double black problem propagate
        Case 3: sibling y of r is red, y and r's parent must be black
                perform a rotation adjustment, and reduce this case to case 1 or case 2
    ```
Performance: at most 1 tri-node restructure, 1 adjustment, and O(logN) recoloring.