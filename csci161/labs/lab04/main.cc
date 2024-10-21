#include <iostream>
#include "growing_array.h"

int main()
{
  GrowingArray array1 = GrowingArray(5);
  array1.Insert(22.5);
  array1.Insert(1.5);
  array1.Insert(0.0);
  array1.Insert(3.5);
  array1.Insert(99.532);
  std::cout << "Size of array1 is: " << array1.GetSize() << std::endl;
  array1.Show();
  GrowingArray array2 = GrowingArray(5);
  array2.Insert(22.5);
  array2.Insert(1.5);
  array2.Insert(0.0);
  array2.Insert(3.5);
  array2.Insert(99.532);
  std::cout << "Size of array2 is: " << array2.GetSize() << std::endl;
}
