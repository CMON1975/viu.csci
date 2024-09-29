// main.cpp
#include "StackArray.h"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
    StackArray stack(5);

    // Push elements onto the stack
    cout << "Pushing elements: 10, 20, 30, 40, 50" << endl;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);

    // Attempt to push another element to a full stack
    cout << "Attempting to push 60 onto a full stack..." << endl;
    stack.push(60); // Should display "Stack Overflow!"

    // Display the stack contents
    stack.display();

    // Peek at the top element
    cout << "Top element is: " << stack.peek() << endl;

    // Pop elements from the stack
    cout << "Popping elements:" << endl;
    while (!stack.isEmpty())
    {
        cout << stack.pop() << " ";
    }
    cout << endl;

    // Attempt to pop from an empty stack
    cout << "Attempting to pop from an empty stack..." << endl;
    stack.pop(); // Should display "Stack Underflow!"

    return 0;
}
