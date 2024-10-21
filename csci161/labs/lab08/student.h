#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include "person.h"
using namespace std;
class Student : public Person
{
 public:
  Student();
  virtual ~Student();
  Student(string the_name);
  Student(const Student & Sobj);
  Student & operator = (const Student &student_in);
};
#endif
