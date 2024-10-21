//******************************************************************************
//
// File: my_class.h
// Author: Christopher Nilssen (Jack)
// Date: January 23, 2017
// Updated: January 23, 2017
//
// Purpose: This program is for practice writing and compiling classes.
//
// Notes: 
//
// References: 
//******************************************************************************

#include <iostream>

class MyClass {
  public: //accessible data
    MyClass(); //constructor
    ~MyClass(); //destructor
    void Display(); //display function
    int GetProcessId(); //get process id function
  private: //inaccessible data
    int process_id; //sample process id integer
    std::string data; //sample data
};
