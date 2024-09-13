// main.cpp
#include "StackList.h"
#include <iostream>
#include <stdexcept>

using std::cout;
using std::endl;
using std::underflow_error;

int main()
{
    StackList stack;

    try
    {
        // Push elements onto the stack
        cout << "Pushing elements: 10, 20, 30" << endl;
        stack.push(10);
        stack.push(20);
        stack.push(30);

        // Peek at the top element
        cout << "Top element is: " << stack.peek() << endl;

        // Pop elements from the stack
        cout << "Popping elements:" << endl;
        while (!stack.isEmpty())
        {
            cout << stack.peek() << " ";
            stack.pop();
        }
        cout << endl;

        // Attempt to pop from an empty stack
        cout << "Attempting to pop from an empty stack..." << endl;
        stack.pop(); // Should throw an exception
    }
    catch (const underflow_error &e)
    {
        cout << "Underflow error: " << e.what() << endl;
    }

    return 0;
}
