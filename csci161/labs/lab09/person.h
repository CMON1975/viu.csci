#ifndef PERSON_H
#define PERSON_H
#include <iostream>
using namespace std;
class Person {
 public:
  Person();
  virtual ~Person();
  Person(string the_name);
  Person(const Person & Pobj);
  Person & operator = (const Person &person_in);
  virtual string GetName() const;
  virtual void SetName(string the_name);
  virtual void Display() const;
 protected:
  string name;
};
#endif
