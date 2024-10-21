#ifndef RECORD_H
#define RECORD_H

#include <iostream>

struct Data {
  int id; //identifier
  std::string name; //data item (food name)
  double price; //item price
}; 

class Record {
  public:
    Record(); //constructor
    ~Record(); //destructor
    void Display(); //display order
    Data *GetData(); //get data
    void SetName(std::string name_in); //set name
    void SetPrice(double price_in); //set price

    Data * data_ptr; //master pointer to data
};

#endif
