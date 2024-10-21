#ifndef COMPLEXNUM_H
#define COMPLEXNUM_H
#include <iostream>
using namespace std;
class ComplexNum {
 public:
  ComplexNum(); //default constructor
  ComplexNum(double, double);
  ~ComplexNum(); //default destructor
  ComplexNum & operator = (const ComplexNum & obj);
  bool operator == (const ComplexNum & obj) const;
  ComplexNum & operator ++ (); //prefix increment
  double & operator [] (int index);
  ComplexNum operator ++ (int dummy); //postfix increment
  ComplexNum operator + (const ComplexNum & obj);
  ComplexNum operator - (); //invert
  ComplexNum operator - (const ComplexNum & obj);
  ComplexNum operator * (const ComplexNum & obj);
  friend istream & operator >> (istream & in, ComplexNum & obj);
  friend ostream & operator << (ostream & out, const ComplexNum & obj);
 private:
  double a;
  double b;
};
istream & operator >> (istream & in, ComplexNum & obj);
ostream & operator << (ostream & out, const ComplexNum & obj);

#endif
