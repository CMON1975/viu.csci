#include <iostream>
class GrowingArray {
  public:
    GrowingArray(); //default constructor
    ~GrowingArray(); //default destructor
    GrowingArray(int capacity_in); //dynamic constructor
    bool Insert(double num); //inserts numbers into array
    void Show(); //displays all numbers stored in array
    int GetSize(); //returns current size of array
    bool operator ==(const GrowingArray array_in); //comparison overload
  private:
    int capacity; //array capacity
    int size; //array size
    double *array; //init array
};
