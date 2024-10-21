#ifndef RECORD_H
#define RECORD_H
#include <iostream>
static int whitespace = 25; //menu item -> price whitespace
class Record {
  public:
    Record();
    ~Record();
    void Display();
    void SetName(std::string name_in);
    void SetPrice(double price_in);
    void SetNum(int num);
  private:
    std::string item_name;
    double item_price;
    int item_num;
};
#endif 