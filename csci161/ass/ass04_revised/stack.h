/******************************************************************************* 
File: stack.h
Author: Christopher Nilssen (Jack)
Date: Mar 5/07
Updated: Mar 11/07

Overview: This is the template class for a generic stack, used by main.cc.

Notes: Data array should use a growing array, I neglected to implement this.
*******************************************************************************/
#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;
template <class T>
class Stack {
 public:
  Stack();        //default constructor
  ~Stack();       //default destructor
  void Push(T obj);   //push object in
  T Pop();        //pop object out
  T Peek();       //inspect top object
  bool IsEmpty(); //check for empty stack
  int GetSize(); //return top as number of items in stack
 private:
  void GrowArray(); //increase array capacity
  int capacity; //how many items data array can hold
  int top;    //top of stack, size of array  
  T *data; //empty stack
};

template <class T>
void Stack<T>::GrowArray()
{
  capacity = capacity * 2; //double capacity
  T *temp = new T[capacity]; //init swap array
  for(int i = 0; i < top; i++)
    temp[i] = data[i]; //strict copy
  delete [] data; //kill old array
  data = temp; //assign temp to old array
}

template <class T>
int Stack<T>::GetSize()
{
  return top;
}

template <class T>
Stack<T>::Stack():top(0), capacity(4) {
  data = new T[capacity];
}

template <class T>
Stack<T>::~Stack()
{
  cout << "Destructor called" << endl;
  delete [] data;
}

template <class T>
void Stack<T>::Push(T obj) 
{
  if (top >= capacity)
    GrowArray();
  data[top++] = obj;
}

template <class T>
T Stack<T>::Pop()
{
  top--;
  return data[top];
}

template <class T>
T Stack<T>::Peek()
{
  if(top>0)
    return data[top-1];
}

template <class T>
bool Stack<T>::IsEmpty()
{
  return (top == 0);
}
#endif
