/******************************************************************************* 
	File: record.h
	Author: Christopher Nilssen (Jack)
	Date: Jan 19/07
	Updated: Feb 11/07

	Overview: header for record.cc

	Notes:

	References: 
*******************************************************************************/
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
    std::string GetName();
    double GetPrice();
    int GetNum();
  private:
    std::string item_name;
    double item_price;
    int item_num;
};
#endif 
