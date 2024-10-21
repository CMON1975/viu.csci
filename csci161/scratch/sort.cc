#include <iostream>
using namespace std;
void QuickSort(double* A, int low, int high);
void Swap(double &x, double &y);
void Display (double* A, int length);
int main()
{
  double test[12] = { 22, 18, 9, 44, 2, 11, -3, -7, 77, 99, 0, 6 };
  Display(test, 12);
  QuickSort(test, 5, 7);
  Display(test, 12);
  return 0;
}
void QuickSort(double* A, int low, int high)
{
  if (low >= high)
    return;
  int pivot = low;
  for(int i = low+1; i<=high; i++) {
    if(A[i] < A[pivot]) {
      swap(A[i], A[pivot+1]);
      swap(A[pivot], A[pivot+1]);
      pivot++;
    }
  }
  QuickSort(A, low, pivot-1);
  QuickSort(A, pivot+1, high);
}
void Swap(double &x, double &y)
{
  double temp = x;
  x = y;
  y = temp;
}
void Display(double* A, int length)
{
  for (int i=0; i<length; i++){
    if(i<length-1) cout << A[i] << ", ";
    else cout << A[i] << endl;
  }
}
