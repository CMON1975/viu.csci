#ifndef FOOD_MENU_H 
#define FOOD_MENU_H
#include "record.h"
struct Menu {
  Record * data;
  Menu * next;
  Menu * prev;
};
class FoodMenu {
  public:
    FoodMenu();
    ~FoodMenu();
    bool Insert(Record *);
    void DisplayAll();
    void LoadMenu(std::string); //build menu data from file
  private:
    Menu * menu_name;
};
#endif 