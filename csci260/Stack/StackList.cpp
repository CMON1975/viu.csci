// StackList.cpp
#include "StackList.h"
#include <iostream>
#include <stdexcept>

using std::cout;
using std::endl;
using std::underflow_error;

StackList::StackList() : top(nullptr)
{
    // Constructor body (empty since initialization is done in the initializer list)
}

StackList::~StackList()
{
    while (!isEmpty())
    {
        pop();
    }
}

void StackList::push(int value)
{
    Node *newNode = new Node(); // Create a new node
    newNode->data = value;      // Assign value
    newNode->next = top;        // Link the new node to the previous top
    top = newNode;              // Update top to the new node
}

void StackList::pop()
{
    if (isEmpty())
    {
        throw underflow_error("Stack underflow: Cannot pop from an empty stack.");
    }
    Node *temp = top; // Store the top node
    top = top->next;  // Move top to the next node
    delete temp;      // Delete the old top node
}

int StackList::peek() const
{
    if (isEmpty())
    {
        throw underflow_error("Stack underflow: Cannot peek on an empty stack.");
    }
    return top->data; // Return the data of the top node
}

bool StackList::isEmpty() const
{
    return top == nullptr;
}
