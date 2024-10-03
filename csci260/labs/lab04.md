# Lab 04
Implement an n-ary tree class (where $n$ is the maximum child nodes allowed for a node in this tree) with the following interface: (To simplify your implementation and testing, assume that we store one string in each tree node. There are no duplicate strings in the whole tree).
```
class Tree
{
    public:
        // n represents the maximum children allowed for each node in the tree
        Tree(int n);
        ~Tree();

        // traversal methods
        void preOrder() const;
        void postOrder() const;

        int getHeight() const; // height of the tree
        int getSize() const; // number of nodes in the tree

        // insert as root, the old root becomes the child of this new root
        void insert(string);

        // parent should already be in the tree
        void insert(const string parent, string child);

        // display descendant strings of the given parameter string
        void listDescendants(const string) const;
        // display child strings of the given parameter string
        void listChildren(const string) const;
    private:
        // fill in the private data fields
};
```
One of the objectives of this exercise is to demonstrate that trees don't have to be search trees.

Submit using name `Lab4`.