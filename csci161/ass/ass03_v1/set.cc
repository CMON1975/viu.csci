/*---
  File: set.cc
  Author: Christopher Nilssen (Jack)
  Date: Feb 20/07
  Updated: Feb 27/07

  Overview: implementation of set.h

  Notes: There's a bunch of overdesign in here that I've left intact to
  show my process. Since I attempted the assignment "in order" of the
  spec, I implemented the I/O overloads last and therefore had already
  come up with a couple of debug solutions. I have a feeling I didn't
  quite nail the overloaded Set constructor, but it works as expected so
  I'm not going to make too big a deal out of it.

  References: set.cc
---*/
#include "set.h"
using namespace std;
Set::Set() { } //default constructor
Set::Set(unsigned int members, string set_in) 
{
  stringstream set_out(set_in); //put input into a stringstream
  size = members; //sync sizes
  data = new int[size]; //init array
  int n; //shuttle for incoming integers
  int i = 0; //index of data
  while(set_out >> n) { //fill data
    data[i] = n;
    i++;
  }
}
//the following constructor was made in order for internal functions to
//properly process. I feel this is a hack, but it made the program work.
Set::Set(unsigned int members, int* arr_in)
{
  size = members; //assign size
  data = new int[size]; //init data array
  for(int i=0;i<size;i++) data[i] = arr_in[i]; //fill data array
}
//copy constructor
Set::Set(const Set &set_in)
{
  size = set_in.size;
  data = new int[size];
  for(int i=0;i<size;i++) data[i] = set_in.data[i];
}
//destructor
Set::~Set() 
{
  delete [] data;
}
//assign overload
Set & Set::operator =(const Set &set_in)
{
  size = set_in.size;
  data = new int[size];
  for(int i=0;i<size;i++) data[i] = set_in.data[i];
  return *this;
}
//union function, + overload
Set Set::operator +(const Set &set_in)
{
  int new_size = set_in.size + size; //combine sizes
  int new_data[new_size]; //init new array
  int j = 0; //index for new array
  for(int i=0;i<size;i++){ //fill new array from this set
    new_data[j] = data[i];
    j++;
  }
  for(int i=0;i<set_in.size;i++){ //finish fill from incoming set
    new_data[j] = set_in.data[i];
    j++;
  }
  Sort(new_size, new_data); //sort in ascending order
  int uniques = CountDuplicates(new_size, new_data); //count dupes
  int final[uniques]; //init final array 
  RemoveDuplicates(new_size, new_data, final); //remove dupes for true, sorted union
  Set return_set = Set(uniques, final); //construct Set with data (HACK)
  return return_set;
}
//boolean compare overload
bool Set::operator ==(const Set&set_in) const
{
  //if sizes don't match, sets cannot
  if(size != set_in.size) return false;
  bool match; //switch for iterative check
  for (int i=0;i<size;i++){
    match = false;
    for (int j=0;j<size;j++){ //search for matching values
      if(data[i] == set_in.data[j]) match = true;
    } //maintain true state as long as matching values found
    if(!match) return false; //first non-match quits search
  }
  return true;
}
bool Set::Exists(int int_in) //simple check for existing value
{
  for(int i=0;i<size;i++){
    if(data[i] == int_in) return true;
  }
  return false;
}
bool Set::Add(int int_in) //attempt to insert value
{
  if(Exists(int_in)) return false; //already exists, cannot add
  size = size+1; //increment size to accomodate new value
  int new_data[size]; //new array with +1 size
  for(int i=0;i<size;i++){ //put old values and new value into new array
    if(i<size-1) new_data[i] = data[i];
    else new_data[i] = int_in;
  }
  delete [] data; //clear old array
  data = new int[size]; //init new array
  for(int i=0;i<size;i++){ //fill new array
    data[i] = new_data[i];
  }  
  Sort(size, data); //run a sort
  return true;
}
void Set::Display() //manual display
{
  cout << "{ ";
  for(int i=0;i<size;i++) {
    cout << data[i];
    if(i==size-1) cout << " }" << endl;
    else cout << ", ";
  }
}
/*void Set::Display(int size_in, int *arr_in) //DEBUG
{
  cout << "{ ";
  for(int i=0;i<size_in;i++) {
    cout << arr_in[i];
    if(i==size_in-1) cout << " }" << endl;
    else cout << ", ";
  }
  }*/
void Set::Sort(int size_in, int* arr_in) //sort in asc order
{
  int tmp; //"holding" int
  for(int i=0;i<size_in;i++) {
    for(int j=0;j<size_in;j++) {
      if(arr_in[j]>arr_in[j+1]) {
	tmp = arr_in[j];
	arr_in[j] = arr_in[j+1];
	arr_in[j+1] = tmp;
      }
    }
  }
  //cout << "First sort produced: "; //DEBUG
  //Display(size_in, arr_in); //DEBUG
}
int Set::CountDuplicates(int size_in, int* arr_in)
{
  //iterate through, counting only unique values
  unsigned int unique_size = 0; //counts unique values
  for(int i=0;i<size_in;i++) {
    if(arr_in[i]!=arr_in[i+1]) unique_size++;
  }
  return unique_size;
}
void Set::RemoveDuplicates(int size_in, int* arr_in, int* final_in)
{
  int k = 0; //uniques index
  for (int i=0;i<size_in;i++){
    if(arr_in[i]!=arr_in[i+1]) {
      final_in[k] = arr_in[i];
      k++;
    }
  }  
}
