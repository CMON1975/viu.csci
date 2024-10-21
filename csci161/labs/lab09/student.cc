#include "student.h"
using namespace std;
Student::Student()
{
  //cout << "Child default constructor called." << endl;
}
Student::~Student()
{
  //cout << "Child default destructor called." << endl;
}
Student::Student(string the_name) : Person(the_name)
{
 
  //cout << "Child overloaded constructor called." << endl;
}
Student::Student(const Student & Sobj)
{
  cout << "Child copy constructor called." << endl;
}
Student & Student::operator = (const Student &student_in)
{
  cout << "Student overloaded assign called." << endl;
  name = student_in.name; 
  return *this;
}
