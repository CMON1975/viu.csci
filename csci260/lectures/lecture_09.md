# Lecture 9 Prof Notes
## AVL Tree
- AVL tree is a height-balanced binary search tree.
- Balance factor: the difference between the height of right subtree and that of left subtree.
- For each node in an AVL tree, the height of its right subtree and left subtree differs at most 1.
- Theorem: the height of an AVL tree with N nodes is O(log N).
Proof: We prove that an AVL tree with height of h has at least Omega$\left(c^h\right)$ nodes for some constant $c > 1$.
**Base case:** $h = 1$, AVL tree must have 1 node, so $n(1) = 1$.
           $h = 2$, AVL tree must have at least 2 nodes,
           so $n(2) \geq 2 \geq 2^{\frac{2}{1}}$
**Induction step:** $\text{for } h > 2,$
        $n(h) \geq 1 + n(h - 1) + n(h -2)$
        $> 2 \times n(h-2)$
        $\geq 2 \times 2^{(h-2)/2}$
        $\geq 2^{\frac{h}{2}}$
        $\geq \sqrt{2^h}$
    Therefore, if $n(h) = N, h \leq 2 \log N$
- Maintaining the balance of the AVL tree
    - Insert a new node:
        - Perform the normal BST insert while keep track of the last critical node;
        - Update the balance factors of the affected nodes; the update only may propagate all the way to the root node;
        - If a critical node is found, fix the possible unbalance using a single or a double rotation;
        - The rotation shouldn't affect the height of the subtree, therefore, the rotation won't propagate upwards.
    - Remove a node:
        - Perform the normal BST removal while keeping track of the last critical node;
        - If a critical node is found, update the balance factors of the affected nodes;
        - If unbalance happened, fix it using a single or a double rotation and update the balance factors of the affected nodes;
        - Both the above actions may decrease the height of the subtree, therefore the action may propagate to the parent nodes until hitting the root node.
