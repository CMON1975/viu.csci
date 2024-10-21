/*---
  File: main.cc
  Author: Christopher Nilssen (Jack)
  Date: Feb 20/07
  Updated: Feb 27/07

  Overview: This program utilizes a C++ class whose objects represent math sets.

  Notes: I feel like my understanding of when to use pointers vs. operators is 
  still incomplete, but I've gained a deeper understanding of Classes, friend
  functions, and overloading. In particular, the use of arrays in functions is
  very clear to me now. The implementation of istream is incomplete.

  References: set.h
---*/
#include <iostream>
#include <string>
#include <sstream>
#include "set.h"
using namespace std;
Set MakeSet(); //create new set
int CheckSet(); //get input from user to check if present in set
int Insert(); //attempt to insert value into set
istream & operator << (istream & in, Set & set_in); //overloaded input friend
ostream & operator >> (ostream & out, Set & set_in); //overloaded output friend
int main()
{
  Set set_1 = MakeSet(); //create sample set
  cout << "Set 1 contains: "; //manual reporting
  set_1.Display();            //using Display function of Set
  Set set_2 = MakeSet(); //create second sample set for later union
  cout << "Set 2 contains: "; //manual reporting
  set_2.Display();            //using Display function of Set
  if(set_1 == set_2) cout << "Sets match!" << endl; //check for duplicate sets
  else cout << "Sets are not a match." << endl;
  Set set_3 = set_1 + set_2; //perform union using overloaded operator
  cout << "Union of set 1 and 2 contains: "; //manual reporting
  set_3.Display(); //using Display function of set
  if(set_3.Exists(CheckSet())) //check for user-entered existing value
    cout << "That value is present in the set." << endl;
  else cout << "That value is not present in the set." << endl;
  if(!set_3.Add(Insert())) //attempt to insert user-entered value into set
    cout << "That value is present in the set, aborted." << endl;
  else {
    cout << "Value inserted. New set: ";
    set_3.Display(); //display using overloaded >> operator
  }
  cout << set_3; //report values and size of set using overloaded operator
  return 0;
}
Set MakeSet() //manual set creation function to fulfill spec
{
  unsigned int members; //eventual size of set
  cout << "How many items in array?-";
  cin >> members; //get size
  string input; //init input string
  getline(cin, input); //clear buffer
  cout << "Please enter all items, separated by a single space: ";
  getline(cin, input); //get input from user
  Set new_set = Set(members, input); //call overloaded Set constructor
  return new_set;
}
int CheckSet() //input grabber
{
  int to_check;
  cout << "Check what value in set?-";
  cin >> to_check;
  return to_check;
}
int Insert() //input grabber
{
  int to_insert;
  cout << "Insert what value into set?-";
  cin >> to_insert;
  return to_insert;
}
istream & operator >> (istream & in, Set & set_in) //TODO doesn't work
{
  for(int i=0; i<set_in.size; i++) { //read value by value
    in >> set_in.data[i];
  }
  in >> set_in.size; //read size
  return in;
}
ostream & operator << (ostream & out, Set & set_in) //overloaded output
{ //friend of Set class, output set size..
  cout << "Set contains " << set_in.size << " elements: { ";
  for(int i=0;i<set_in.size;i++){ //.. and elements in single line
    if(i<set_in.size-1) cout << set_in.data[i] << ", ";
    else cout << set_in.data[i] << " }" << endl;
  }
  return out;
}
