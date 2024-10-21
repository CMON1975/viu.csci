#include "complexnum.h"
using namespace std;
ComplexNum::ComplexNum()
  :a(0), b(0) {}
ComplexNum::~ComplexNum() { }
ComplexNum::ComplexNum(double x, double y)
  :a(x), b(y) {}
ComplexNum & ComplexNum::operator = (const ComplexNum & obj)
{
  a = obj.a;
  b = obj.b;
  return *this;
}
bool ComplexNum::operator == (const ComplexNum & obj) const
{
  return ((a == obj.a) && (b == obj.b));
}
ComplexNum & ComplexNum::operator ++ ()
{
  a = a + 1;
  b = b + 1;
  return *this;
}
double & ComplexNum::operator [] (int index)
{
  if (index == 0)
    return a;
  else if (index == 1)
    return b;
  /*else
    throw runtime_error("subscript out of range");*/
}
ComplexNum ComplexNum::operator ++ (int dummy)
{
  ComplexNum tmp(*this);
  a = a + 1;
  b = b + 1;
  return tmp;
}
ComplexNum ComplexNum::operator + (const ComplexNum & obj)
{
  ComplexNum tmp;
  tmp.a = a + obj.a;
  tmp.b = b + obj.b;
  return tmp;
}
ComplexNum ComplexNum::operator - ()
{
  ComplexNum tmp;
  tmp.a = -a;
  tmp.b = -b;
  return tmp;
}
ComplexNum ComplexNum::operator - (const ComplexNum & obj)
{
  ComplexNum tmp;
  tmp.a = a - obj.a;
  tmp.b = b - obj.b;
  return tmp;
}
ComplexNum ComplexNum::operator * (const ComplexNum & obj)
{
  ComplexNum tmp;
  tmp.a = (a * obj.a) - (b * obj.b);
  tmp.b = (b * obj.a) - (a * obj.b);
  return tmp;
}
istream & operator >> (istream & in, ComplexNum & obj)
{
  in >> obj.a;
  in >> obj.b;
  return in;
}
ostream & operator << (ostream & out, const ComplexNum & obj)
{
  out << obj.a << " + " << obj.b << "i";  
  return out;
}  
