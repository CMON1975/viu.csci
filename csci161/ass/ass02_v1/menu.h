#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "list.h"

using namespace std;

class Menu {
  public:
    Menu(); //default constructor
    Menu(string input_file_name); //construct by file name
    ~Menu(); //destructor
    void Display();
  private:
    List *menu_list;
};

#endif
