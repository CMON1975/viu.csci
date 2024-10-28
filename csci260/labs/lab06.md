# Lab 06

Implement a thread tree class with the following interface:

```
class ThreadTree
{
public:
    ThreadTree();
    ~ThreadTree();
    void inOrder() const; // iterative algorithm
    void insert(double k);
private:
    // fill in the private data fields and methods yourself
};

Note that a thread tree is a binary search tree. To simplify the implementation, you can assume that the thread tree will be used to store `double` numbers.

Submit with name `Lab6`.