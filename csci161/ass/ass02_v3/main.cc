/******************************************************************************* 
	File: main.cc
	Author: Christopher Nilssen (Jack)
	Date: Jan 18/07
	Updated: Feb 11/07

	Overview: This program loads data from three files called burger.txt,
	sidedish.txt and drink.txt respectively. These three files provide the
	information about available menu items and their price. The program prompts
	the user to make orders, presenting the available menu items (plus a choice of
	"none of the above") and gets the user's choice for burger, sidedish and drink
	respectively. If the user chooses "none of the above" for all three entries,
	the program displays an error message and discards the order. Otherwise, the
	order is OK and the program assigns an order number to the order, displays the
	order number and the price to the customer, and submits the order as the
	newest one to the order list. The price of the order is calculated as the sum
	of the price of each item plus five percent of sales tax. When the program
	terminates, it displays both the total number of orders processed and the
	total amount of sales made in the run.  

	Notes: Overall, my implementation of linked lists leaves much to be desired, 	
	particularly with assumptions and naming of list heads.

	References: ui.h
*******************************************************************************/
#include "ui.h"
int main()
{
	UI ui = UI(); //init ui
	OrderList *orders = new OrderList(); //init order list
	std::cout << "\n*** Welcome to Fast Food Ordering System ***\n\n"; //start msg
	ui.DisplayMain(); //show main menu
	char user_input = ui.MainMenuChoice(); //get input
	ui.UseMenu(user_input, orders); //first-run menu system
}
