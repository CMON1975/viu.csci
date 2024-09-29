// StackArray.cpp
#include "StackArray.h"
#include <iostream>

using std::cout;
using std::endl;

StackArray::StackArray(int size)
{
    maxSize = size;
    top = -1;               // Stack is initially empty
    arr = new int[maxSize]; // Allocate memory dynamically
    for (int i = 0; i < maxSize; i++)
    {
        arr[i] = 0;
    }
}

StackArray::~StackArray()
{
    delete[] arr; // Free the allocated memory
}

bool StackArray::isEmpty()
{
    return top == -1;
}

bool StackArray::isFull()
{
    return top == maxSize - 1;
}

void StackArray::push(int value)
{
    if (isFull())
    {
        cout << "Stack Overflow!" << endl;
    }
    else
    {
        top++;
        arr[top] = value;
    }
}

int StackArray::pop()
{
    if (isEmpty())
    {
        cout << "Stack Underflow!" << endl;
        return 0;
    }
    else
    {
        int popValue = arr[top];
        arr[top] = 0; // Optional, for clarity
        top--;
        return popValue;
    }
}

int StackArray::peek()
{
    if (isEmpty())
    {
        cout << "Stack is empty!" << endl;
        return 0;
    }
    else
    {
        return arr[top];
    }
}

void StackArray::display()
{
    cout << "Stack contents: ";
    for (int i = maxSize - 1; i >= 0; i--)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
