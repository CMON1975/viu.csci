#include <iostream>
#include <vector>
#include <algorithm> // for std::max_element
#include <cmath>        // for pow function

using std::max_element;
using std::vector;
using std::cout;
using std::endl;

// function to get the digit at a given position
int getDigit(int number, int digitPosition, int base) {
    return (number / static_cast<int>(pow(base, digitPosition))) % base;
}

// counting sort based on a specific digit
void countingSortByDigit(vector<int>& A, int digitPosition, int base) {
    int n = A.size();
    vector<int> output(n);
    vector<int> count(base, 0);

    // step 1: count occurrences
    for (int i = 0; i < n; ++i) {
        int digit = getDigit(A[i], digitPosition, base);
        ++count[digit];
    }

    // step 2: compute cumulative counts
    for (int i = 1; i < base; ++i) {
        count[i] += count[i - 1];
    }

    // step 3: build the output array
    for (int i = n - 1; i >= 0; --i) {
        int digit = getDigit(A[i], digitPosition, base);
        output[count[digit] - 1] = A[i];
        --count[digit];
    }

    // copy the output array to A
    for (int i = 0; i < n; ++i) {
        A[i] = output[i];
    }
}

// radix sort function
void radixSort(vector<int>& A) {
    int n = A.size();
    int base = 10; // base 10 for decimal numbers

    // find the maximum number to determine the number of digits
    int maxNumber = *max_element(A.begin(), A.end());

    // determine the number of digits in the maximum number
    int numDigits = 0;
    while (maxNumber != 0) {
        ++numDigits;
        maxNumber /= base;
    }

    // performing counting sort for each digit position
    for (int digitPosition = 0; digitPosition < numDigits; ++digitPosition) {
        countingSortByDigit(A, digitPosition, base);
    }
}

int main() {
    // example usage:
    vector<int> A = {170, 45, 75, 90, 802, 24, 2, 66};

    // call radixSort function
    radixSort(A);

    // output the sorted array
    cout << "Sorted array: ";
    for (int num : A) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}