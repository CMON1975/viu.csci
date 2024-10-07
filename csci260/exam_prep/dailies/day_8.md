## Day 8: Lookup in a Sorted Array-Based Dictionary
- **Topics Covered**:
    - Implementing the `lookup` operation using binary search.
- **Study Activities**:
    - **Binary Search Algorithm**: Review how binary search works in sorted arrays.
    - **Code Implementation**: Write the `lookup` function in C++.
    - **Edge Cases**: Consider how to handle keys not present in the array.
- **Practice**:
    - Analyze the time complexity of lookup operations.
    - Modify your implementation to return additional information (e.g., insertion point for missing keys).

### 1. How does binary search work in sorted arrays?
Binary search is an efficient algorithm for finding a specific element in a **sorted array** by repeatedly dividing the search interval in half. It leverages the sorted property of the array to eliminate half of the remaining elements at each step, significantly reducing the number of comparisions needed compared to linear search.

**How Binrary Search Works:**
1. **Initialize Pointers:**
    - **Low Pointer (`low`):** Start at the beginning of the array (index 0).
    - **High Pointer (`high`):** Start at the end of the array (index `n - 1`, where `n` is te number of elements).

2. **Iterative Process:**
    - **Calculate Midpoint (`mid`):**
        $$
        \text{mid = low}+\left(\frac{\text{high - low}}{2}\right)
        $$
        (Using this formula avoids potential integer overflow in some programming languages.)
    - **Compare Key with Middle Element:**
        - **If `array[mid] == key`:** The target value is found; return `mid`.
        - **If `array[mid] < key`:** The target must be in the right half. Set `low = mid + 1`.
        - **If `array[mid] > key`:** The target must be in the left half. Set `high = mid - 1`.

3. **Repeat:**
    - Continue the process until `low` exceeds `high`.
    - If the element is not found, return an indicator (e.g., `-1`) signifying that the key is not present.

**Visual Representation:**

Imagine you're looking for a word in a dictionary:
- Open it roughly in the middle.
- If the word you're looking at is alphabetically before your target, you discard the left half.
- If it's after, you discard the right half.
- Repeat this process on the remaining half.

**Example:**
Let's search for the number `7` in the sorted array `[1, 3, 5, 7, 9, 11, 13]`.
1. **First iteration:**
    - `low = 0`, `high = 6`
    - `mid = 0 + (6 - 0) // 2 = 3`
    - `array[3] = 7`
    - `array[mid] == key` ⇒ Element found at index `3`.

**Pseudocode:**
```
function binarySearch(array, key):
    low = 0
    high = length(array) - 1

    while low <= high:
        mid = low + (high - low) / 2

        if array[mid] == key:
            return mid // key found at index mid
        else if array[mid] < key:
            low = mid + 1 // search in the right half
        else:
            high = mid - 1 // search in the left half

    return -1 // key not found
```
**Time Complexity:**
- **Base Case:** O(1) when the middle element is the target.
- **Average and Worse Case:** O(log n), where `n` is the number of elements.
- This logarithmic complexity makes binary search extremely efficient for large datasets.

**Key Considerations:**
- **Sorted Array Required:** Binary search only works correctly on arrays sorted in ascending or descending order.
- **Duplicate Elements:** If the array contains duplicates of the key, binary search may return any one of them. Modifications are needed to find all occurrences.
- **Integer Overflow:** When calculating `mid`, use `mid = low + (high - low) // 2` to prevent potential overflow.

**Conclusion:**
Binary search is a fundamental algorithm in computer science, crucial for efficient searching in sorted datasets. By halving the search space with each comparison, it ensures optimal performance and is widely used in various applications like databases, libraries, and more.

---
### 2. Write a C++ implementation of binary search `lookup`.
```
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int lookup(const vector<int>& array, int key) {
    int low = 0;
    int high = array.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (array[mid] == key) {
            return mid; // key found at index mid
        } else if (array[mid] < key) {
            low = mid + 1; // search the right half
        } else {
            high = mid - 1; // search in the left half
        }
    }

    return -1; // key not found
}

int main() {
    vector<int> sortedArray = {1, 3, 5, 7, 9, 11, 13};
    int key = 7;
    int index = lookup(sortedArray, key);

    if (index != -1) {
        cout << "Element " << key << " found at index: " << index << endl;
    } else {
        cout << "Element " << key << " not found in the array." << endl;
    }

    return 0;
}
```
#### Notes:
- **Sorted Array Requirement:** The binary search algorithm requires that the input array is sorted in ascending order.
- **Data Type Flexibility:** While this examples uses `int`, you can template the function to work with other comparable data types.
- **Efficiency:** Binary search operates in O(log n) time, making it efficient for large datasets.

---
### 3. Analze the time complexity of binary search `lookup`.
#### Time Complexity Analysis:
**Best-Case Complexity (O(1)):**
- **Scenario:** The key is found at the first mid calculation.
- **Explanation:**
    - The `while` loop executes once.
    - The condition `array[mid] == key` is `true` in the first iteration.
- **Operations:**
    - Initialization: O(1)
    - One iteration of the loop: O(1)
- **Time Complexity: O(1)**

**Worst-Case Complexity (O(log n)):**
- **Scenario:** The key is not present, or it is located at the far end of the array.
- **Explanation:**
    - The search space is halved in each iteration.
    - The maximum number of iterations is proportional to $\log_2n$
- **Operations per iteration:**
    - Calculation of `mid`: O(1)
    - Comparison `array[mid]` with `key`: O(1)
    - Updating `low` or `high`: O(1)
- **Total Operations:**
    - $O(1) \times \text{ number of iterations}$
    - Number of iterations $\approx \log_2n$
- **Time Complexity: O(log n)**

**Average-Case Complexity (O(log n)):**
- **Scenario:** The key is equally likely to be at any position.
- **Explanation:**
    - On average, the number of iterations will still be proportional to $\log_2n$.
- **Time Complexity: O(log n)**

---
#### Mathematical Justification:
**Number of Iterations Calculation:**
At each iteration, the size of the search interval reduces by half:
1. **Initial Interval Size:** $n$
2. **After 1st Iteration:** $n/2$
3. **After 2nd Iteration:** $n/4$
4. **...**
5. **After $k$ iterations:** $n/2^k$

We continue until the interval size becomes less than or equal to 1:
$$
\frac{n}{2^k}\le1
$$
Solving for $k$:
$$
2^k\ge n
k\ge \log_2n
$$
So, the maximum number of iterations is $\log_2n$.

---
#### Per-Operation Analysis:
**Initialization:**
- **Variables:** `low`, `high`
- **Time:** O(1)

**Loop Iteration:**
Each iteration performs O(1) operations:
1. **Calculate `mid`:** O(1)
2. **Compare `array[mid]` and `key`:** O(1)
3. **Update `low` or `high`:** O(1)

**Total Loop Time:**
- **Iterations:** At most $\log_2n$
- **Time:** $O(1) \times \log_2n = O(\log n)$

**Final Return Statement:**
- **Time:** O(1)

#### Space Complexity Analysis:
- **Variables Used:**
    - `low`, `high`, `mid`: O(1) space
- **Space Complexity: O(1)**
- **Explanation:** The function uses a constant amount of additional memory regardless of the input size.

---
#### Practical Implications:
**Efficiency with Large Datasets:**
- **Example:** For $n = 1,000,000$
    - $\log_2 1,000,000 \approx 20$
    - Maximum of 20 iterations needed.
- **Benefit:** Significantly faster than linear search (O(n)), which would require up to 1,000,000 comparisons.

**Consistent Performance:**
- **Predicatable:** Time complexity grows logarithmically, ensuring scalability.
- **Optimized for Read Operations:** Ideal for static datasets where search operations are frequent.

---
#### Comparison with Other Algorithms:
**Linear Search:**
- **Time Complexity:** O(n)
- **When to Use:**
    - Small datasets
    - Unsorted arrays

**Binary Search:**
- **Time Complexity:** O(log(n))
- **Requirement:** Array must be sorted
- **When to Use:**
    - Large datasets
    - Frequent search operations
    - Performance-critical applications

---
#### Limitations and Considerations:
**Sorted Array Requirement:**
- **Necessity:** The array must be sorted in ascending order for the binary search to function correctly.
- **Impact:** If the array is unsorted, the binary search will not yield correct results.

**Duplicate Elements:**
- **Issue:** If the array contains duplicate keys, the function will return the index of one of them, not necessarily the first or last occurrence.
- **Solution:** Modify the algorithm to find the first or last occurrence if needed.

**Integer Overflow:**
- **Potential Problem:** In languages where integer overflow is a concern (e.g., when `low` and `high` are large), calculating `mid` using `(low + high) / 2` can cause overflow.
- **Prevention:** Use `mid = low + (high - low) /2`.

---
#### Visualization
**Binary Search Tree Analogy:**
- **Nodes:** Each possible subarray corresponds to a node.
- **Depth:** The maximum depth of the tree is $\log_2n$.
- **Traversal:** The search path from root to leaf corresponds to the iterations of the loop.

---
#### Conclusion:
- **Time Complexity:** The `lookup` function has a time complexity of **O(log n)** due to the logarithmic reduction of the search space.
- **Space Complexity:** It uses constant space, **O(1)**.
- **Efficiency:** The algorithm is highly efficient for searching in large, sorted arrays.
- **Reliability:** Offers consistent performance and is a fundamental algorithm in computer science.

---

