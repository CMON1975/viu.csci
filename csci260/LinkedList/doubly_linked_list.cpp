// Basic Node Structure for a Doubly-Linked List
// First, leat's create the fundamental building block, the Node class.
struct Node
{
    int data;   // data stored in the node
    Node *next; // pointer to the next node
    Node *prev; // pointer to the previous node

    // constructor
    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};
// Here, Node holds an integer data, and two pointers, next (to the next node) and
// prev (to the previous node). The constructor initializes these pointers to nullptr.

// Creating the Doubly-Linked List with Dummy Nodes
// Key Operations:
// * Constructor: Initializes the list with dummy head and tail nodes.
// * Destructor: Cleans up the dynamically allocated memory.
// * Insert: Adds a new element between two existing nodes.
// * Remove: Removes a node from the list.
#include <iostream>
using std::cout;
using std::endl;

class DoublyLinkedList
{
private:
    struct Node
    {
        int data;   // data stored in the node
        Node *next; // pointer to the next node
        Node *prev; // pointer to the previous node

        Node(int value = 0) : data(value), next(nullptr), prev(nullptr) {}
    };

    Node *head; // dummy head node
    Node *tail; // dummy tail node

public:
    // constructor
    DoublyLinkedList()
    {
        // initialize dummy head and tail
        head = new Node();
        tail = new Node();

        // connect dummy head and tail
        head->next = tail;
        tail->prev = head;
    }

    // destructor
    ~DoublyLinkedList()
    {
        // delete all nodes
        Node *current = head;
        while (current != nullptr)
        {
            Node *nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    // check if list is empty
    bool isEmpty() const
    {
        return head->next == tail;
    }

    // insert a new node at the back (before the tail dummy)
    void insertBack(int value)
    {
        Node *newNode = new Node(value);

        Node *prevNode = tail->prev;

        // link newNode between prevNode and tail
        prevNode->next = newNode;
        newNode->prev = prevNode;
        newNode->next = tail;
        tail->prev = newNode;
    }

    // remove node (assuming pointer exists to node)
    void remove(Node *node)
    {
        if (node == head || node == tail)
            return; // don't remove dummies

        Node *prevNode = node->prev;
        Node *nextNode = node->next;

        // link previous node to next node, skipping node we want to remove
        prevNode->next = nextNode;
        nextNode->prev = prevNode;

        // delete the node
        delete node;
    }

    // print the contents of the list
    void printList() const
    {
        Node *current = head->next; // start at node after head dummy
        while (current != tail)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};
// Explanation of Key Components:
// 1. Dummy Head and Tail
// * In the constructor, the `head` and `tail` are dummy nodes. The dummy
// head's `next` points to the tail, and the dummy's tail `prev` points to the
// head, creating and "empty" list.
// * This simplifies operations, particularly at the boundaries
// (insertions/removals at the head or tail), because you always have valid
// nodes to work with.
// 2. Insertions at the Back:
// * The `insertBack(int value)` function inserts a new node before the
// dummy tail node. This is similar to inserting at the end of the list.
// * The `newNode` is placed between the `prevNode` (which is the current last
// node) and the `tail` node.
// 3. Removing a Node:
// * the `remove(Node* node) function takes a pointer to the node you want
// to remove and bypasses it by connecting its previous node to its next
// node. This operation runs in O(1) time.
// 4. isEmpty Function:
// * the `isEmpty() function checks if the listy is empty by comparing if the
// node following the `head` is the `tail`. If true, the list is empty.
// 5. Destructor:
// * The destructor iterates through the list and deletes every node, ensuring
// no memory leaks.
// Example Usage:
int main()
{
    DoublyLinkedList list;

    list.insertBack(10);
    list.insertBack(20);
    list.insertBack(30);

    list.printList(); // Output: 10 20 30

    return 0;
}
// This prints the list after inserting three elements. The dummy head and tail nodes
// ensure that edge cases (like inserting or deleting at the front or back) are handled
// easily.
// Moving Forward:
// * You can extend this class by adding more operations like `insertFront`, `find`,
// or more complex functionality like sorted insertion.
// * You can also add an iterator class to support traversing the list in a more
// idiomatic way.