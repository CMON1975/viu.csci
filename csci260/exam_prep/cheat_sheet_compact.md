| | P Queue | Map | Tree
| :- | :- | :- | :-
| Prop. | Obj + Priority | <Key, Obj> pairs | Nodes & Edges
| Main Ops. | insert, removeMin | insert, remove, lookup | traverse
| Implementation | unsorted array or linked list; sorted list &rarr; heap: complete binary tree in heap order: array &rarr; element at index i &rarr; parent: (i - 1)/2, left child: i * 2 + 1, right child: i * 2 + 2 | unsorted list of array or linked list; sorted array with hash table (H(key)), BST &rarr; AVL Tree and balance factor. Collision handling: separate chaining; open addressing through linear probing, quadratic probing, or double hashing. | array, pointers.