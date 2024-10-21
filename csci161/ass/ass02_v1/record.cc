#include <iostream>
#include "record.h"

Record::Record() {
  data_ptr = new Data;
}

Record::~Record() { }

void Record::Display()
{
  std::cout << "Name: " << data_ptr->name 
    << "Price: " << data_ptr->price << std::endl;
}

void Record::SetName(std::string name_in)
{
  data_ptr->name = name_in;
}

void Record::SetPrice(double price_in)
{
  data_ptr->price = price_in;
}

Data* Record::GetData()
{
  return data_ptr;
}
