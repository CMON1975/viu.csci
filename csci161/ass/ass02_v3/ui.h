/******************************************************************************* 
	File: ui.h
	Author: Christopher Nilssen (Jack)
	Date: Jan 19/07
	Updated: Feb 11/07

	Overview: header for ui.cc  

	Notes: Not sure if use of statics is good here, but put them in to avoid
	hardcoding the values in the functions.

	References: order_list.h, food_menu.h
*******************************************************************************/
#ifndef UI_H
#define UI_H
#include <iostream>
#include "order_list.h"
#include "food_menu.h"
static double kTaxRate = 0.5;
static int kMaxOrders = 999;
class UI {
	public:
		UI();
		~UI();
		char MainMenuChoice(); //main UI option
		int OrderChoice(); //ordering option
		void DisplayMain(); //show main menu
		void UseMenu(char option_in, OrderList *order_list); //menu functionality
		void TakeOrder(OrderList *order_list); //take user's order
	private:
		//menus
		FoodMenu *burger_menu;
		FoodMenu *sidedish_menu;
		FoodMenu *drink_menu;
		int order_number; //master order number count
		int orders_processed; //master orders processed count
		double total_sales; //master total sales
};
#endif	
