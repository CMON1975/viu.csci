#include <iostream>
#include <cassert>
#include <string>
using namespace std;
typedef int fsm_state;
typedef char fsm_input;
bool IsFinalState(fsm_state state)
{
  return (state == 3) ? true : false;
}
fsm_state GetStartState(void)
{
  return 0;
}
fsm_state Move(fsm_state state, fsm_input input)
{
  //our alphabet only includes 'a' and 'b'
  if (input != 'a' && input != 'b')
    assert(0);
  switch (state) {
  case 0:
    if (input == 'a')
      return 1;
    else if (input == 'b')
      return 0;
    break;
  case 1:
    if (input == 'a')
      return 1;
    else if (input == 'b')
      return 2;
    break;
  case 2:
    if (input == 'a')
      return 1;
    else if (input == 'b')
      return 3;
    break;
  case 3:
    if (input == 'a')
      return 1;
    else if (input == 'b')
      return 0;
    break;
  default:
    assert(0);
  }
}
bool Recognize(string str)
{
  if (str == "")
    return false;
  fsm_state state = GetStartState();
  string::const_iterator i = str.begin();
  fsm_input input = *i;
  while (i != str.end()) {
    state = Move(state, *i);
    ++i;
  }
  if (IsFinalState(state))
    return true;
  else
    return false;
}
//simple driver for testing
int main(int argc, char** argv)
{
  Recognize(argv[1]) ? cout << 1 << endl: cout << 0 << endl;
  return 0;
}
   
	
