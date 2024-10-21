#ifndef RECORD_H 
#define RECORD_H
#include <iostream>

class Record {
  public:
    Record();
    ~Record();
    void Display();
    void SetName(std::string name_in);
    void SetPrice(double price_in);
  private:
    std::string item_name;
    double item_price;
};

#endif 
