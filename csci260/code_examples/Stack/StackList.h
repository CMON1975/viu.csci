// StackList.h
#ifndef STACKLIST_H
#define STACKLIST_H

#include <stdexcept>

// Node structure for the linked list
struct Node
{
    int data;   // Stores data
    Node *next; // Pointer to the next node
};

// Stack class using a linked list
class StackList
{
private:
    Node *top; // Pointer to the top of the stack

public:
    // Constructor: initializes the top to nullptr
    StackList();

    // Destructor: deletes all the nodes in the stack
    ~StackList();

    // Function to push an element onto the stack
    void push(int value);

    // Function to remove the top element from the stack
    void pop();

    // Function to get the top element of the stack
    int peek() const;

    // Function to check if the stack is empty
    bool isEmpty() const;
};

#endif // STACKLIST_H
