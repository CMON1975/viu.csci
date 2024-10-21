#include "person.h"
using namespace std;
Person::Person()
{
  cout << "Person default constructor called." << endl;
}
Person::~Person()
{
  cout << "Person default destructor called." << endl;
}
Person::Person(string the_name)
{
  cout << "Person overloaded constructor called." << endl;
  name = the_name;
}
Person::Person(const Person & Pobj)
{
  cout << "Person copy constructor called." << endl;
}
Person & Person::operator =(const Person &person_in)
{
  cout << "Person overloaded assign called." << endl;
  name = person_in.name;
  return *this;
}

string Person::GetName() const
{
  cout << "Person GetName called." << endl;
  return name;
}
void Person::SetName(string the_name)
{
  cout << "Person SetName called." << endl;
  name = the_name;
}
void Person::Display() const
{
  cout << "Person Display called." << endl;
  cout << "The person's name is " << name << "." << endl;
}
