/******************************************************************************* 
	File: order.cc
	Author: Christopher Nilssen (Jack)
	Date: Jan 19/07
	Updated: Feb 11/07

	Overview: creates order objects and handles their display

	Notes:

	References: order.h 
*******************************************************************************/
#include "order.h"
using namespace std;
Order::Order() { }
Order::Order(int num_in, string burg_in, string side_in, string drink_in)
{ //base constructor, fills with values
	order_num = num_in;
	burger = burg_in;
	sidedish = side_in;
	drink = drink_in;
}
Order::~Order() { }
void Order::Display() //display order data
{
  cout << "-----------------------------------" << endl
			 << "Order number: " << order_num << endl
  		 << "      burger: " << burger << endl
  		 << "    sidedish: " << sidedish << endl
  		 << "       drink: " << drink << endl;
}
