#ifndef UI_H
#define UI_H
#include <iostream>
#include "order_list.h"
#include "food_menu.h"

class UI {
	public:
		UI();
		~UI();
		char MainMenuChoice(); //main UI option
		int OrderChoice(); //ordering option
		void DisplayMain(); //show main menu
		void UseMenu(char option_in, OrderList *order_list);
		void TakeOrder(); //take user's order
	private:
		FoodMenu *burger_menu;
		FoodMenu *sidedish_menu;
		FoodMenu *drink_menu; 
};

#endif	