#ifndef STACKLIST_H
#define STACKLIST_H

#include <iostream>
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
    StackList() : top(nullptr) {}

    // Destructor: deletes all the nodes in the stack
    ~StackList()
    {
        while (!isEmpty())
        {
            pop();
        }
    }

    // Function to push an element onto the stack
    void push(int value)
    {
        Node *newNode = new Node(); // Create a new node
        newNode->data = value;      // Assign value
        newNode->next = top;        // Link the new node to the previous top
        top = newNode;              // Update top to the new node
    }

    // Function to remove the top element from the stack
    void pop()
    {
        if (isEmpty())
        {
            throw std::underflow_error("Stack underflow: Cannot pop from an empty stack.");
        }
        Node *temp = top; // Store the top node
        top = top->next;  // Move top to the next node
        delete temp;      // Delete the old top node
    }

    // Function to get the top element of the stack
    int peek() const
    {
        if (isEmpty())
        {
            throw std::underflow_error("Stack underflow: Cannot peek on an empty stack.");
        }
        return top->data; // Return the data of the top node
    }

    // Function to check if the stack is empty
    bool isEmpty() const
    {
        return top == nullptr;
    }
};

#endif // STACKLIST_H
