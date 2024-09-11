#ifndef STACKARRAY_H
#define STACKARRAY_H
#include <iostream>
using namespace std;

class StackArray
{
private:
    int top;
    int *arr;    // Dynamically allocated array
    int maxSize; // Maximum size of the stack

public:
    // Constructor to define array size
    StackArray(int size)
    {
        maxSize = size;
        top = -1;               // Stack is initially empty
        arr = new int[maxSize]; // Allocate memory dynamically
        for (int i = 0; i < maxSize; i++)
        {
            arr[i] = 0;
        }
    }

    // Destructor to release allocated memory
    ~StackArray()
    {
        delete[] arr; // Free the allocated memory
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == maxSize - 1;
    }

    void push(int value)
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

    int pop()
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

    int peek()
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

    void display()
    {
        cout << "Stack contents: ";
        for (int i = maxSize - 1; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

#endif
