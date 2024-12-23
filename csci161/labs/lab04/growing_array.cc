#include <iostream>
#include "growing_array.h"

GrowingArray::GrowingArray() { }
GrowingArray::~GrowingArray() { }
GrowingArray::GrowingArray(int capacity_in) 
{ 
  size = 0; //init size
  capacity = capacity_in; //record capacity
  array = new double[capacity_in]; //create array
}
bool GrowingArray::Insert(double num) //inserts numbers into array
{
 for(int i=0;i<capacity;i++) {
    if(!array[i]) {
      array[i] = num;
      size++;
      return true;
    }
  }
  return false; //DEBUG array doubling code here
}
void GrowingArray::Show() //displays all numbers stored in array
{
  for(int i=0;i<capacity;i++) {
    std::cout << "[" << i << "]" << " : " << array[i] << std::endl;
  }
}
int GrowingArray::GetSize()  //returns current size of array
{
  return size;
}
bool GrowingArray::operator ==(const GrowingArray array_in) 
{ //comparison overload
  //assume the arrays MUST be of the same size, otherwise functionality
  //breaks down
  /*if(size == array_in.size) { //check for value matching
    for(int i = 0; i<size; i++) { //iterate over size of array
      if(array[i] != array_in[i]) {
	return false;
      }
    }
    return true;
  }
  return false;*/
  return (this == array_in);
}
