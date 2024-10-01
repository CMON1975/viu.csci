#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

// counting sort function
void countingSort(int A[], int n, int k) {
    // A: input array of size n
    // n: number of elements in A
    // k: maximum value in A

    // step 1: initialize count array C
    vector<int> C(k + 1, 0); // C[0..k], initialized to 0

    // step 2: count the occurrences
    for (int i = 0; i < n; ++i) {
        ++C[A[i]];
    }

    // step 3: compute cumulative counts
    for (int i = 1; i <= k; ++i) {
        C[i] += C[i - 1];
    }

    // step 4: build the output array B
    vector<int> B(n); // output array of size n

    // iterate from n - 1 downto 0 to maintain stability
    for (int i = n - 1; i >= 0; --i) {
        B[C[A[i]] - 1] = A[i];
        --C[A[i]];
    }

    // step 5: copy the sorted elements back into original array A
    for (int i = 0; i < n; ++i) {
        A[i] = B[i];
    }
}

int main() {
    // example usage:
    int A[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(A) / sizeof(A[0]);
    int k = 8; // max value in A

    // call countingSort function
    countingSort(A, n, k);

    // output the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}