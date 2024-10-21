#ifndef MENU_H 
#define MENU_H

#include <iostream>
#include "list.h"

class Menu {
  public:
    Menu();
    ~Menu();
    List LoadMenu(std::string input_file_name);
    void Display();
  private:
  	List *menu_list;
};

#endif
