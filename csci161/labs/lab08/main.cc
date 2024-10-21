#include "person.h"
#include "student.h"
using namespace std;
int main()
{
  cout << "Main executed." << endl;

  Student s1;
  Person p1;

  s1.SetName("Joe");
  p1.SetName("Jill");
  
  Person p2 = s1;

  Student s2 = Student("Mike");

  s1 = s2;

  p1 = p2;

  s2.GetName();

  p1.GetName();

  s1.Display();
  p1.Display();
  
  return 0;
}
