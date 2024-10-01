## Sorting Algorithms and Time Complexity
- **Topics Covered**:
    - Theoretical limits of comparison-based sorting algorithms.
    - Non-comparison-based sorting algorithms (Counting Sort, Radix Sort).
- **Study Activities**:
    - **Review Comparison Sorts**: Understand why $O(n\log n)$ is the lower bound.
    - **Study Non-Comparison Sorts**: Learn how Counting Sort and Radix Sort achieve linear time under certain conditions.
- **Practice**:
    - Implement Counting Sort and Radix Sort for integer arrays.
    - Solve problems that require choosing the appropriate sorting algorithm.

---
1. Why is $O(n\log n)$ the lower bound of comparison-based sorting algorithms?

The $O(n\log n)$ lower bound for comparison-based sorting algorithms arises from funadmental limitations in how these algorithms operate. In a comparison-based model, the only way to gain information about the order of elements is by comparing them pairwise. Here's a detailed explanation of why no comparison-based sorting algorithm can have a better (lower) time complexity than $O(n\log n)$:
#### 1. Decision Tree Model
- **Comparisons as Decisions:** Each comparison between two elements can be viewed as a binary decision (e.g., is $a_i < a_j$?).
- **Decisions Tree Representation:** The sequence of comparisons made by a sorting algorithm can be represented as a binary decision tree, where each internal node is a comparison, and each leaf node represents a possible coutcome (i.e., a permutation of the sorted elements).
#### 2. Number of Permutations
- **Total Possible Orderings:** For $n$ distinct elements, there are $n!$ possible permutations (ways the elements can be ordered).
- **Leaf Nodes Requirement:** To correctly sort any possible input, the decision tree must have at least $n!$ leaf nodes, each corresponding to a unique permutation.
#### 3. Height of the Decision Tree
- **Minimum Height:** The minimum height $h$ of a binary tree with $L$ leaves is at lease $\lceil \log _2 L \rceil$.
- **Applying to Sorting:** So, the decision tree must have a height $h \ge \log _2n!$ to accommodate all $n!$ permutations.
#### 4. Calculating $\log _2n!$
- **Using Stirling's Approximation:**
$$
\log_2n! \approx n\log _2n-n\log _2 e+\frac{1}{2}\log _2n+\frac{1}{2}\log _2(2\pi)
$$
- **Simplifying:**
$$
\log _2n! = Θ(n\log n)
$$
(Since constants and lower-order terms are negligible for large $n$)
#### 5. Implications for Time Complexity
- **Lower Bound on Comparisons:** The minimum number of comparisons (tree height) required is $Ω(n\log n)$.
- **Algorithmic Time Complexity:** Since each comparison takes constant time, the overall time complexity is also $Ω(n\log n)$.
- **No Faster Comparison-Based Sort:** Any comparison-based sorting algorithm must perform at least $Ω(n\log n)$ comparisons in the worst case.
#### Conclusion
- **Optimality of $O(n\log n)$:** Algorithms like Merge Sort and Heap Sort achieve this lower bound, making them asymptotically optimal among comparison-based sorts.
- **Non-Comparison Sorts:** To sort in linear time $O(n)$, algorithms must use additional information about the input (e.g., Counting Sort, Radix Sort), which are not purely comparison-based and have constraints like integer keys within a specific range.

**Therefore, $O(n\log n)$ is the lower bound for comparison-based sorting algorithms because distinguishing among all possible permutations of $n$ elements requries at least $O(n\log n)$ comparisons.**

**Answer:**
Because any comparison-based sort must make enough comparisons to distingush among all n! possible orderings--which requires at least O(n log n) time--so O(n log n) is the fundamental lower bound for such algorithms.

---
2. How do Counting Sort and Radix Sort achieve linear time under certain conditions?

Counting Sort and Radix Sort can achieve linear time complexity--specifically, $O(n)$--under certain conditions by leveraging additional information about the input data, which allows them to bypass the $O(n\log n)$ lower bound that applies to comparison-based sorting algorithm. Here's how they do it:

---
#### Counting Sort
**How Counting Sort Works:**
1. **Assumption of Input Range:**
    - Counting Sort assumes that the input elements are integers within a known, limited range, typically from O to $k$.
    - The range $k$ should not be significantly larger than the number of elements $n$.
2. **Counting Frequencies:**
    - Create a count array of size $k + 1$ to store the frequency of each unique element in the input.
    - Iterate over the input array and increment the count for each element.
3. **Cumulative Counts:**
    - Modify the count array by adding each count to the sum of counts before it. This gives the positions of elements in the sorted array.
4. **Building the Output:**
    - Create an output array of size $n$.
    - Iterate over the input array in reverse order to maintain stability (if needed).
    - Place each element into its correct position in the output array based on the count array, and decrement the count.
5. **Result:**
    - The output array is the sorted version of the input array.

**Time Complexity Analysis:**
- **Counting Frequencies: $O(n)$**
- **Cumulative Counts: $O(k)$**
- **Building the Output: $O(n)$**
- **Total Time Complexity: $O(n + k)$**

**Conditions for Linear Time:**
- If $k = O(n)$, meaning the range of input values is proportional to the number of elements, the total time complexity becomes $O(n)$.
- Counting Sort is efficient when the range of input data is not significantly larger than the number of elements to sort.

---
#### Radix Sort
**How Radix Sort Works:**
1. **Assumption of Input:**
    - Radix Sort works on integers or strings where each element can be processed digit by digit.
    - The number of digits $d$ in the maximum element should be a constant or grow slowly relative to $n$.
2. **Digit-by-Digit Sorting:**
    - Starting from the least significant digit (LSD) or most significant digit (MSD), sort the elements based on that digit.
    - Use a stable sorting algorithm (like Counting Sort) at each digit level to maintain the relative order of elements.
3. **Iterative Process:**
    - Repeat the process for each digit position.
    - After processing all digits, the array is sorted.

**Time Complexity Analysis:**
- **Per Digit Sorting:** $O(n + k)$, where $k$ is the range of digit values (e.g., 0-9 for decimal digits).
- **Total Time Complexity:** $O(d \times (n + k))$

**Conditions for Linear Time:**
- If $d$ and $k$ are constants or $O(1)$, then the total time complexity simplifies to $O(n)$.
    - For example, sorting 32-bit integers where $d=32$ bits and $k=2$ binary digits.
- Radix Sort is efficient when the number of digits $d$ is not significantly larger than $n$.

---
#### Why They Achieve Linear Time:
- **Not Comparison-Based:**
    - Both algorithms do not rely on element-to-element comparisons.
    - They use the structure of the input data (like digit positions or value ranges) to sort elements.
- **Exploiting Input Properties:**
    - **Counting Sort** leverages the limited range of input values.
    - **Radix Sort** breaks down elements into digits, effectively reducing the sorting problem into sorting smaller ranges.
- **Avoiding the $Ω(n\log n)$ Lower Bound:**
    - The lower bound applies only to comparison-based sorting algorithms.
    - Since Counting Sort and Radix Sort are not purely comparison-based, they are not subject to this limitation.

---
#### Practical Considerations:
- **Space Complexity:**
    - Both algorithms require additional space for counting arrays or output arrays.
    - Counting Sort has a space complexity of $O(n + k)$.
    - Radix Sort has a space complexity of $O(n + k)$ per digit level.
- **Stability:**
    - Both algorithms are stable sorts, preserving the relative order of equal elements.
    - Stability is important when sorting data with multiple keys.
- **Limitations:**
    - **Counting Sort** is impractical if the range $k$ is significantly larger than $n$.
    - **Radix Sort** may become inefficient if the number of digits $d$ is large.

---
#### Examples:
**Counting Sort Example:**
- **Input:** An array of $n$ integers where each integer is in the range 0 to 100.
- **Process:**
    - Create a count array of size 101.
    - Count the occurrences and build the output.
- **Time Complexity:** $O(n+100)$ simplifies $O(n)$.

**Radix Sort Example:**
- **Input:** An array of $n$ integers representing 10-digit phone numbers.
- **Process:**
    - Sort the array 10 times, once for each digit position.
    - Use Counting Sort at each step.
- **Time Complexity:** $O(10\times (n+10))$ simplifies to $O(n)$.

---
#### Conclusion
Counting Sort and Radix Sort achieve linear time complexity under specific conditions by:
- Utilizing additional knowledge about the input data (e.g., limited range, number of digits).
- Eliminating the need for element comparisions, thus not constrained by the $O(n\log n)$ lower bound.
- Applying efficient counting and grouping techniques to organize data rapidly.

**Answer:**
Because they use additional information about the input data--such as a limited range of integer values or a fixed number of digits--to sort elements without relying on comparisons, allowing them to organize $n$ elements in $O(n)$ time when certain conditions (like small range or constant number of digits) are met.

---
3. Give the pseudocode for Counting Sort and then a basic C++ implementation.
Counting Sort is an efficient algorithm for sorting integers when the range of input data ($k$) is not significantly larger than the number of elements ($n$).

#### Psuedocode for Counting Sort
```
COUNTING-SORT(A, B, k)
Input:
    A[1..n]: input array of n integers, each in the range of 0 to k
    k: the maximum integer value in array A
Output:
    B[1..n]: output array containing the sorted integers

1. Let C[0..k] be a new array
2. Initialize C[i] = 0 for i = 0 to k

3. // Step 1: Count the occurrences
4. for j = i to n do
5.      C[A[j]] = C[A[j]] + 1

6. // Step 2: Computer cumulative counts
7. for i = 1 to k do
8.      C[i] = C[i] + C[i - 1]

9. // Step 3: Place elements into the output array B
10. for j = n downto 1 do
11.     B[C[A[j]]] = A[j]
12.     C[A[j]] = C[A[j]] - 1

13. Return B
```
**Explanation:**
- **Counting Occurrences (Lines 4-5):**
    - Counts how many times each value appears in the input array $A$.
- **Cumulative Counts (Lines 7-8):**
    - Transforms the count array $C$ so that $C[i]$ now contains the number of elements less than or equal to $i$.
- **Building the Output Array (Lines 10-12):**
    - Places each element from $A$ into its correct sorted position in $B$.
    - Iterates from $n$ downto $1$ to maintain stability (preserves the relative order of equal elements).

#### Basic C++ Implementation of Counting Sort
```
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
```

**Explanation:**
- **Headers and Namespaces:**
    - Includes `<iostream>` for input/output operations.
    - Includes `<vector>` for dynamic array (vector) usage.
- **Function `countingSort`:**
    - **Parameters**:
        - `int A[]`: The input array to be sorted.
        - `int n`: The number of elements in the array `A`.
        - `int k`: The maximum value in `A` (range of input data is `0` to `k`).
    - **Local Variables:**
        - `vector<int> C(k + 1, 0)`: The count array initialized with zeroes.
        - `vector<int> B(n)`: The output array to store sorted elements.
    - **Process:**
        - Counts the frequency of each element.
        - Computes the cumulative counts.
        - Places elements into the correct positions in the output array `B` while maintaining stability.
        - Copies the sorted elements back into the original array `A`.
- **`main` Function:**
    - Demonstrates how to use the `countingSort` function with a simple array.
    - Calculates `n` (number of elements) and defines `k` (maximum value in `A`).
    - Calls `countingSort` to sort the array.
    - Outputs the sorted array to the console.

**Sample Output:**
```
Sorted array: 1 2 2 3 3 4 8
```

---
**Notes:**
- **Stability:**
    - The algorithm maintains the relative order of elements with equal values.
    - Iterating from the end of the array (`for (int i = n - 1; i >=0; --i)) ensures stability.
- **Complexity:**
    - **Time Complexity: $O(n + k)$**, which is linear when $k = O(n)$.
    - **Space Complexity: $O(n + k)$** due to the count array `c` and the output array `B`.
- **Assumptions:**
    - All elements in the input array `A` are non-negative integers within the range `0` to `k`.
    - If the input contains negative integers or values outside the specified range, the algorithm needs to be adjusted accordingly.
- **Usage Tips:**
    - Ensure that the maximum value `k` is known and not significantly larger than `n`.
    - Suitable for sorting integers; not directly applicable to floating-point numbers or strings without modifications.

---
4. Give the pseudocode for Radix Sort and then a basic C++ implementation.
Radix Sort is an efficient sorting algorithm that sorts numbers by processing individual digits. It can achieve linear time complexity $O(nk)$ when the number of digits $k$ is constant or grows slowly relative to the number of elements $n$.

---
#### Pesudocode for Radix Sort (Least Significant Digit - LSD)
Radix Sort processes the digits of the numbers from the least significant digit to the most significant digit. At each digit position, it uses a stable sorting algorithms, such as Counting Sort, to sort the numbers based on that digit.
##### RADIX SORT(A, d)
```
Input:
    A[1..n]: array of n integers
    d: number of digits in the maximum number

Algorithm:
1. for i = 1 to d do
2.     // use a stable sort to sort array A on digit i
3.     A = COUNTING-SORT-BY-DIGIT(A, i)
4. end for
5. return A
```
##### COUNTING-SORT-BY-DIGIT(A, digit_position)
```
Input:
    A[1..n]: array of n integers
    digit_position: the digit position to sort by (1 for least significant digit)

1. Let B[1..n] be a new array
2. Let C[0..k] be a new array (k is the base, e.g., 9 for decimal digits 0-9)
3. Initialize C[i] = 0 for i = 0 to k

// step 1: count the occurrences
4. for j = 1 to n do
5.      digit_value = GET-DIGIT(A[j], digit_position)
6.      C[digit_value] = C[digit_value] + 1
7. end for

// step 2: compute cumulative counts
8. for i = 1 to k do
9.      C[i] = C[i] + C[i - 1]
10. end for

// step 3: build the output array B
11. for j = n downto 1 do
12.     digit_value = GET-DIGIT(A[j], digit_position)
13.     B[C[digit_value]] = A[j]
14.     C[digit_value] = C[digit_value] - 1
15.     end for

16. return B
```
##### GET-DIGIT(number, digit_position)
```
Input: 
    number: the integer number
    digit_position: the position of the digit to extract (1 for least significant digit)

1. base = 10 // for decimal numbers
2. return (number / base^(digit_position - 1)) mod base
```

**Explanation:**
- **`RADIX-SORT` Function:**
    - Iterates over each digit position from the least significant digit to the most significant digit.
    - Uses `COUNTING-SORT-BY-DIGIT` to sort the array based on the current digit.
- **`COUNTING-SORT-BY-DIGIT` Function:**
    - A modified Counting Sort that sorts numbers based on a specific digit.
    - Uses `GET-DIGIT` to extract the digit at the required position.
    - Maintains stability by iterating from the end of the array when building the output array.
- **`GET-DIGIT` Function:**
    - Extracts the digit at the specified position from a number.
    - For base 10 numbers, `base` is 10.
    - `digit_position` is 1 for the least significant digit.

---
#### Basic C++ Implementation of Radix Sort
```
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
```

#### Explanation:
- **Headers and Namespaces:**
    - Includes `<iostream>` for input/output operations.
    - Includes `<vector>` for dynamic arrays.
    - Includes `<algorithm>` for `max_element` to find the maximum element.
    - Includes `<cmath>` for the `pow` function used in digit extractions.
- **Functions `getDigit`:**
    - **Parameters:**
        - `int number`: The number from which to extract the digit.
        - `int digitPosition`: The position of the digit (starting from 0 for the least significant digit).
        - `int base`: The numerical base (e.g., 10 for decimal numbers).
    - **Operation:**
        - Calculates the digit at the specified position using integer division and modulo operations.
- **Function `countingSortByDigit`:**
    - **Parameters:**
        - `vector<int>& A`: Reference to the array to be sorted.
        - `int digitPosition`: The current digit position to sort by.
        - `int base`: The numerical base.
    - **Process:**
        - Initializes a count array `count` of size equal to the base.
        - Counts the occurrences of each digit at `digitPosition`.
        - Computes cumulative counts to determine positions.
        - Builds the output array `output`, placing elements based on digit values.
        - Copies the sorted elements back into the original array `A`.
- **Function `radixSort`:**
    - **Parameters:**
        - `vector<int>& A`: Reference to the array to be sorted.
    - **Process:**
        - Determines the maximum number in the array to find out how many digits need to be processed.
        - Iterates over each digit position, from least significant to most significant digit.
        - Calls `countingSortByDigit` for each digit position.
- **`main` Function:**
    - Demonstrates how to use the `radixSort` function with a simple array.
    - Outputs the sorted array to the console.

#### Sample Output:
```
Sorted array: 2 24 45 55 75 90 170 802
```

---
#### Notes:
- **Stability:**
    - The Counting Sort used within Radix Sort must be stable to ensure the overall algorithm sorts correctly.
    - Stability is maintained by  processing elements in reverse order when building the output array.
- **Handling Negative Numbers:**
    - The provided implementation assumes all numbers are non-negative.
    - To handle negative numbers, you can separate the array into negative and non-negative parts, sort them individually, and then combine the results appropriately.
- **Base Selection:**
    - The base (`base`) is set to 10 for decimal numbers.
    - You can change the base to optimize performance (e.g., base 256 for byte-wise processing). Larger bases reduce the number of passes but increase the size of the count array.
- **Performance Considerations:**
    - Radix Sort is efficient when the number of digits (`numdigits`) is not significantly larger than the number of elements (`n`).
    - For very large numbers with many digits, the algorithm may become less efficient compared to comparison-based sorts like Quick Sort or Merge Sort.
- **Time Complexity:**
    - The time complexity is $O(nk)$, where $n$ is the number of elements and $k$ is the number of digits.
    - When $k$ is a constant or grows relative to $n$, Radix Sort performs in linear time.
- **Space Complexity:**
    - Requires additional space for the output array and count array, resulting in $O(n + b)$ space complexity, where $b$ is the base.

---



5. How does one choose Counting Sort or Radix Sort to solve a problem?
- **Choose Counting Sort when:**
    - Sorting integers within a small, known range.
    - Memory usage for the count array is acceptable.
    - You need a simple and fast sorting algorithm.
- **Choose Radix Sort when:**
    - Sorting large integers or data with multiple digits/characters.
    - The number of digits $d$ is manageable.
    - You need to sort data types that can be processed digit by digit.