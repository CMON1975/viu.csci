/******************************************************************* 
File: dict_except.h
Author: Christopher Nilssen (Jack)
Date: Mar 31/07
Updated: Apr 4/07

Overview: Exception classes for dictionary.h

Notes: Very happy with my understanding of try-catch and exception
classes.

References: 
*******************************************************************/
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

class DictionaryEmpty : public DictionaryException {
 public:
  DictionaryEmpty() : DictionaryException("Empty dictionary") { }
};

class NotFound : public DictionaryException {
 public:
  NotFound(): DictionaryException("Key not found") { }
};
#endif
