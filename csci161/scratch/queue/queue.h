#ifndef QUEUE_H
#define QUEUE_H
#include <cstdio>
using namespace std;
struct Data {
  int x; //data value
};
struct Node {
  Data *data; //pointer to data
  Node *next; //pointer to next node
};
class Queue {
 public:
   Queue(); //default constructor
   Queue(int); //constuctor with cap limit
   Queue(Queue &obj); //copy constructor
   ~Queue(); //destructor
   bool Enqueue(Data &obj); //place object into queue
   Data &Dequeue(); //remove obj from queue
   Data &Peek(); //inspect obj
   bool IsEmpty(); //check if queue empty
   bool IsFull(); //check if queue full
   int GetSize(); //get size of queue
 private:
   Node *head; //head node
   Node *tail; //tail node
   int size; //queue size
   int capacity; //if needed, cap on queue
};
#endif
