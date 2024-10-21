#ifndef DICT_EXCEPT_H
#define DICT_EXCEPT_H
#include <iostream>
using namespace std;
class DictionaryException {
 public:
  DictionaryException(string msg) { message = msg; }
  virtual ~DictionaryException() { }
  string what() { return message; }
 protected:
  string message;
};

class DuplicateKey : public DictionaryException {
 public:
  DuplicateKey() : DictionaryException("Duplicate key found") { }
};

class DictionaryFull : public DictionaryException {
 public:
  DictionaryFull() : DictionaryException("Full dictionary") { }
};

class NotFound : public DictionaryException {
 public:
  NotFound(): DictionaryException("Key not found") { }
};
#endif
