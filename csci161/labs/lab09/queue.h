#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include "queue_exception.h"
using namespace std;
template <class T>
class Queue {
 public:
  Queue();        //default constructor
  Queue(int cap);     //overloaded fix-cap constructor
  ~Queue();       //default destructor
  void Enqueue(T &obj) throw (FullQueue); //add object to queue in
  T & Dequeue() throw (EmptyQueue); //remove object from queue
  T & Peek();       //inspect object in queue
  bool IsEmpty(); //check for empty queue
  int GetSize(); //return number of items in queue
  void CheckSize(); //verbose size check
 private:
  void GrowArray(); //increase array capacity
  int capacity; //how many items data array can hold
  int queued_objects;  //how many items enqueued
  int front; //index of front of queue
  T **data; //empty stack
};

template <class T>
Queue<T>::Queue() : front(0), queued_objects(0), capacity(4) {
  //cout << "Default constructor called" << endl;
  data = new T*[capacity];
}

template <class T>
Queue<T>::Queue(int cap) : front(0), queued_objects(0), capacity(cap) {
  cout << "overloaded fix-cap constructor called" << endl;
  data = new T*[capacity];
}

template <class T>
Queue<T>::~Queue()
{
  //cout << "Destructor called" << endl;
  delete [] data;
}

template <class T>
void Queue<T>::Enqueue(T & obj) throw (FullQueue) 
{
  //cout << "Enqueue called" << endl;
  if (queued_objects >= capacity)
    throw FullQueue();
    //GrowArray();
  data[queued_objects++] = & obj;
}

template <class T>
T & Queue<T>::Dequeue() throw (EmptyQueue)
{
  cout << "Dequeue called" << endl;
  if(IsEmpty())
    throw EmptyQueue();
  queued_objects--;
  front++;
  return *data[front-1];
}

template <class T>
T & Queue<T>::Peek()
{
  cout << "Peek called: " << front << endl;
  if(queued_objects>0)
    return *data[front]; //dereference
}

template <class T>
bool Queue<T>::IsEmpty()
{
  //cout << "IsEmpty called" << endl;
  return (queued_objects == 0);
}

template <class T>
int Queue<T>::GetSize()
{
  //cout << "GetSize called" << endl;
  return queued_objects;
}

template <class T>
void Queue<T>::CheckSize()
{
  if(IsEmpty())
    cout << "Queue is empty" << endl;
  else     
    cout << "Queue contains " << GetSize() << " objects"
	 << endl;
}

template <class T>
void Queue<T>::GrowArray()
{
  capacity = capacity * 2; //double capacity
  T **temp = new T*[capacity]; //init swap array
  for(int i = 0; i < queued_objects; i++)
    temp[i] = data[i]; //strict copy
  delete [] data; //kill old array
  data = temp; //assign temp to old array
}
#endif
