#include <iostream>
#include "flag.h"
using namespace std;

Flag::Flag() //default constructor
{
  width = 1;
  height = 1;
  symbol = '*';
} 

Flag::~Flag() {} //destructor

// create a Flag object 
Flag::Flag(int w, int h, char s)
{
  width = w;
  height = h;
  symbol = s;
}

int Flag::GetWidth() //get width of the flag object
{
  return width;
}

int Flag::GetHeight() //get height of the flag object
{
  return height;
}

char Flag::GetSymbol() //get the display symbol of the flag object
{
  return symbol;
}

void Flag::Resize(int new_width, int new_height) //resize the flag
{
  width = new_width;
  height = new_height;
}

void Flag::ChangeSymbol(char new_symbol) //change the flag's symbol
{
  symbol = new_symbol;
}

int Flag::Calculate() //calculate the number of display chars needed
{
  return height*width;
}

void Flag::Display() //display the Flag object using its symbol
{
  for (int h=0; h<height; h++) {
    for (int w=0; w<width; w++) {
      //if (h == height/2 && w == width/2) std::cout << symbol;
      std::cout << symbol;
    } 
    std::cout << endl;
  }
}

bool Flag::BigFlag() //return true if Flag object > 25 chars
{
  if(Calculate() > 25) return true;
  else return false;
}
