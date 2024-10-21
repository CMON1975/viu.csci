/*---
  File: set.h
  Author: Christopher Nilssen (Jack)
  Date: Feb 20/07
  Updated: Feb 27/07

  Overview: header for set.cc

  Notes: I'm not sure if I'm cleaning everything up properly, and I'm not sure
  if I've used references and constants correctly.

  References: set.cc
---*/
#ifndef SET_H
#define SET_H
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class Set
{
 public:
  Set(); //default constructor
  Set(unsigned int members, string set_in); //overloaded constructor
  Set(unsigned int members, int* arr_in); //array constructor
  Set(const Set &set_in); //copy constructor
  ~Set(); //default destructor
  Set & operator = (const Set &set_in); //assignment operator
  Set operator + (const Set &set_in); //union operator
  bool operator ==(const Set &set_in) const; //comparison operator
  bool Exists(int int_in); //check if incoming value is present in set
  bool Add(int int_in); //attempts to add incoming value to set
  void Display(); //print values in set
  // void Display(int size_in, int *arr_in); //DEBUG
  //friend overloads, present in main.cc
  friend istream & operator >> (istream & in, Set & set_in);
  friend ostream & operator << (ostream & out, Set & set_in);
 private:
  int* data; //array values
  unsigned int size; //array length
  void Sort(int size_in, int* arr_in); //sort function
  int CountDuplicates(int size_in, int* arr_in); //count duplicates
  void  RemoveDuplicates(int size_in, int* arr_in, int* final_in); //duplicate value evaluator
};
#endif
