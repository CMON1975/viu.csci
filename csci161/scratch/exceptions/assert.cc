#define NDEBUG
#include <iostream>
#include <cassert>
using namespace std;

void PrintNumber(int* myInt) {
  assert (myInt!=NULL);
  cout << *myInt << endl;
}

int main ()
{
  int a = 10;
  int* b = NULL;
  int* c = NULL;

  b = &a;

  PrintNumber(b);
  PrintNumber(c);

  return 0;
}
  
