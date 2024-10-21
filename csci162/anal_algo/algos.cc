#include <iostream>
using namespace std;
int main()
{
  int n = -1;
  int ops = 0;
  int sum1 = 0;
  int sum2 = 0;
  int sum3 = 0;
  int sum4 = 0;

  do {
    cout << "Input a positive integer (0 to quit): ";
    cin >> n;
    for (int i=0; i<n; i++, ops+=3) {
      sum1++;
      for (int j=0; j<n; j++, ops+=3) {
	sum2++;
	for (int k=0; k<n; k++, ops+=3) {
	  sum3++;
	}
      }
    }
    /*for (int i=0; i<n; i*=2, ops+=2) {
      sum4++;
      ops++;
      }*/

    cout << "Sum 1 is: " << sum1 << endl;
    cout << "Sum 2 is: " << sum2 << endl;
    cout << "Sum 3 is: " << sum3 << endl;
    cout << "The number of operations is: " << ops << endl;
    //cout << "n= " << n << " sum= " << sum1
    //	 << " ops= " << ops << endl;
    sum1 = 0;
    sum2 = 0;
    sum3 = 0;
    sum4 = 0;
    ops = 0;

  } while (n!=0);
  return 0;
}
