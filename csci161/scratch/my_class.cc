#include <iostream>
#include "my_class.h"
using namespace std;

MyClass::MyClass() //constructor
{
  string null_clear; //string for clearing read buffer
  cout << "PROCESS ID (INT): "; //ask user for id
  cin >> process_id; //read id
  getline(cin, null_clear); //clear buffer
  cout << "DATA (STRING): "; //ask user for data
  getline(cin, data);
}

MyClass::~MyClass() {} //destructor

void MyClass::Display()
{
  cout << "PROCESS ID: " << process_id << endl;
  cout << "      DATA: " << data << endl;
}

int MyClass::GetProcessId()
{
  return process_id;
}
