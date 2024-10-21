#include "order.h"
using namespace std;
Order::Order() { }
Order::~Order() { }
void Order::Display() //possible to handle line formatting here
{
  cout << "-----------------------------------" << endl
			 << "Order number: " << order_num << endl
  		 << "			 burger: " << burger << endl
  		 << "    sidedish: " << sidedish << endl
  		 << " 			drink: " << drink << endl;
}
void Order::SetBurger(std::string burger_in)
{
	burger = burger_in;
}
void Order::SetSidedish(std::string sidedish_in)
{
	sidedish = sidedish_in;
}
void Order::SetDrink(std::string drink_in)
{
	drink = drink_in;
}
void Order::SetOrderNumber(int order_num_in)
{
	order_num = order_num_in;
}
void Order::SetCharge(double charge_in)
{
	charge = charge_in;
}	