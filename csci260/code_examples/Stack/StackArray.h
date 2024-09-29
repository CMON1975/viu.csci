// StackArray.h
#ifndef STACKARRAY_H
#define STACKARRAY_H

class StackArray
{
private:
    int top;
    int *arr;    // Dynamically allocated array
    int maxSize; // Maximum size of the stack

public:
    // Constructor to define array size
    StackArray(int size);

    // Destructor to release allocated memory
    ~StackArray();

    bool isEmpty();
    bool isFull();
    void push(int value);
    int pop();
    int peek();
    void display();
};

#endif // STACKARRAY_H
