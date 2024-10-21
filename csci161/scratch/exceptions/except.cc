// exceptions
#include <iostream>
#include <exception>
using namespace std;

int main() {
  try {
    int* my_array = new int[1000];
  }
  catch (exception &e) {
    cout << "Standard exception: " << e.what() << endl;
  }
  return 0;
}
