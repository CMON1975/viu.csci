/******************************************************************************* 
	File: order.h
	Author: Christopher Nilssen (Jack)
	Date: Jan 19/07
	Updated: Feb 11/07

	Overview: header for order.cc

	Notes:

	References: 
*******************************************************************************/
#ifndef ORDER_H 
#define ORDER_H
#include <iostream>
using namespace std;
class Order {
  public:
    Order();
    Order(int num_in, string burg_in, string side_in, string drink_in);
    ~Order();
    void Display();
  private:
    string burger;
    string sidedish;
    string drink;
    int order_num;
};
#endif 
