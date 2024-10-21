#include "queue.h"
using namespace std;
Queue::Queue() 
{ 
  head = tail = 0; //set links
  size = 0; //set size to zero
  capacity = -1; //limitless
}
Queue::Queue(int cap) 
{ 
  head = tail = 0; //set links
  size = 0; //set size to zero
  capacity = cap; //set capacity
}
Queue::Queue(Queue &obj) 
{
  size = obj.size;
  capacity = obj.capacity;
  Enqueue(obj.Peek());
}
Queue::~Queue() 
{
  Node *ptr; //create deletion pointer
  while(head != 0) { //as long as queue has items
    ptr = head->next; //take first object in queue
    delete head; //delete it
    head = ptr; //move head along
  }
}
bool Queue::Enqueue(Data &obj)
{ //attempt to queue object
  if(IsFull()) return false; //if queue full, cannot add, abort
  Node *ptr = new Node; //init new node
  ptr->data = &obj; //set node's data to incoming
  if(tail == 0) { //if empty queue
    head = tail = ptr; //insert incoming at front
  } else { //otherwise add to back
    tail->next = ptr;
    tail = tail->next;
  }
  ptr->next = 0; //point tail
  size++; //increment size
  return true;
}
Data &Queue::Dequeue()
{
  Data &obj = *(head->data); //deref front data, place in object
  Node *ptr = head; //temp head copy
  head = head->next; //assign head to next in queue
  delete ptr; //delete pointer for dequeued obj
  if(head == 0) tail = 0; //check for empty queue
  --size; //decrement size
  return obj; //return the dequeued object
}
Data &Queue::Peek()
{
  return *(head->data); //dereference data 
}
bool Queue::IsEmpty()
{ //check for null size
  return (size == 0);
}
bool Queue::IsFull()
{ //verify that queue has a capacity and is exceeding it
  return ((capacity > 0) && (size >= capacity));
}
int Queue::GetSize()
{
  return 0;
}
