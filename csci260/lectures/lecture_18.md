# (Balanced) Multi-way Search Tree

A multi-way search tree is an ordered tree. Each internal node has at least 2 child nodes and at most $d$ (the degree of the tree) child nodes. If we visit the data items stored in the multi-way search tree in an augmented in-order traversal, then the keys of these data items are in a specific order.

**Augmented in-order traversal** refers to a modification of the standard in-order traversal to accommodate the structure of a multi-way search tree, which has more than two children per internal node.

**Internal node:** A node that has one ore more child nodes.

An **(a,b)-tree** is a multiway search tree that satisfies the following requirements:
- **Depth Property:** All the leaf nodes are in the same level (at the same depth).
- **Size Property I:** Each internal node (except the root node) must have at least $a$ child nodes and at most $b$ child nodes (with $a<b$).
- **Size Property II:** Each leaf node (except the root node) must have at least $a-1$ data items and at most $b-1$ data items.
- **Size Property III:** The number of data items stored in the internal nodes must be exactly one less than the number of its child nodes.
- **Search Key Property:** A slightly modified in-order traversal of the (a,b)-tree would visit the data items in the ascending order of their keys.

A **(2-4)-tree** is an (a,b)-tree where $a=2$ and $b=4$.

(2-4)-tree operations:
- **lookup**
- **insert:** always insert into a leaf node; handle the possible overflow by splitting; overflow may propagate to the parent node.
- **remove:** swap the victim to a leaf node then remove it; handle the possible underflow by borrowing or merging; underflow handled by merging may propagate to the parent node.

A **B-tree** is an (a,b)-tree where $a$ is about half of $b$.