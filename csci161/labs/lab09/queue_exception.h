#ifndef QUEUE_EXCEPTION_H
#define QUEUE_EXCEPTION_H
#include <iostream>
using namespace std;
class QueueException {
public:
  QueueException(string msg) { message = msg; }
  virtual ~QueueException() { }
  string what() { return message; }
protected:
  string message;
};

class FullQueue : public QueueException {
public:
  FullQueue() : QueueException("Full queue") { }
};

class EmptyQueue : public QueueException {
public:
  EmptyQueue() : QueueException("It's an empty queue") { }
};
#endif
