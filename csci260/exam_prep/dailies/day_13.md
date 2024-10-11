## Day 13: Recurrence Relations in Recursive Algorithms
- **Topics Covered**:
    - Writing recurrence relations for recursive functions.
    - Solving linear recurrence relations.
- **Study Activities**:
    - **Identify Recurrence Patterns**: Learn how to express the running time recursively.
    - **Solving Techniques**: Use methods like unrolling and induction.
- **Practice**:
    - Write recurrence relations for various recursive functions.
    - Solve them to find the time complexity.

---
### 1. How is running time expressed recursively?
When analyzing recursive algorithms, we often express their running time using **recurrence relations**. A recurrence relation defines the running time $T(n)$ on an input of size $n$ in terms of the running time on smaller inputs. This is because recursive algorithms solve a problem by solving smaller instances of the same problem.

For example, consider a recursive algorithm that splits the input into two halves and processes each half recursively (like Merge Sort). Its running time can be expressed as:
$$
T(n) = 2 \cdot T\left(\frac{n}{2}\right) + f(n)
$$

- $2 \cdot T\left(\frac{n}{2}\right)$ represents the time taken by the two recursive calls on half-sized inputs.
- $f(n)$ represents the time taken by the non-recursive (or "divide" and "combine") parts of the algorithm.

This recursive expression continues until the base case is reached, where the input size is small enough to be solved directly (e.g., $T(1) = c$, where $c$ is a constant).

---
### 2. How are methods like unrolling and induction used?

To solve recurrence relations and find the closed-form expression for $T(n)$, we use methods like **unrolling (iteration)** and **mathematical induction**.
- **Unrolling (iteration):**
    - **Process:**
        1. Expand the recurrence relation step by step to observe a pattern.
        2. Continue expanding until a general formula emerges.
        3. Identify the number of times the recurrence needs to be expanded to reach the base case.
    - **Purpose:** It helps in transforming the recursive expression into a summation or a closed-form expression.
- **Mathematical Induction:**
    - **Process:**
        1. **Base Case:** Verify that the formula holds for the initial value (e.g., $n=1$).
        2. **Inductive Step:** Assume the formula holds for $n=k$, and then prove it holds for $n=k+1$.
    - **Purpose:** It confirms that the closed-form expression derived from unrolling is valid for all $n$.

These methods help in deriving the time complexity of recursive algorithms by solving their recurrence relations.

---
### 3. Write the recurrence relations for three recursive functions and solve them to find the time complexity.

**Example 1. Factorial Function**

*Function Definition*
```
int factorial(int n) {
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}
```

*Recurrence Relation:*
$$
T(n) = T(n - 1) + c
$$
- $T(n - 1)$: Time to compute *factorial*$(n - 1)$.
- $c$: Constant time for multiplication and function call overhead.
- **Base Case: $T(1) = d$** (some constant time).

*Solving the Recurrence:*

Unrolling the recurrence:
$$
\begin{aligned}
T(n) &= T(n - 1) + c \\
&= \lfloor T(n-2)+c\rfloor + c \\
&= T(n-2) + 2c \\
&\vdots \\
&= T(1) + (n -1)c \\
&= d+(n-1)c
\end{aligned}
$$

*Time Complexity:*
$$
T(n) = O(n)
$$

---
**Example 2: Binary Search**

*Function Definition:*
```
int binary_search(data arr[], data* target, int low, int high) {
    if(low > high)
        return -1;
    int mid = (low + high) / 2;
    if (arr[mid] == *target)
        return mid;
    else if (arr[mid] < *target)
        return binary_search(arr, target, mid + 1, high);
    else
        return binary_search(arr, target, low, mid - 1);
}
```

*Recurrence Relation:*
$$
T(n) = T\left(\frac{n}{2}\right) + c
$$
- $T\left(\frac{n}{2}\right)$: Time for the recursive call on half the array.
- $c$: Constant time for comparisons and calculating `mid`.
- **Base Case:** $T(1) = d$ (constant time when `low = high`).

*Solving the Recurrence:*

Unrolling the recurrence:
$$
\begin{aligned}
T(n) &= T\left(\frac{n}{2}\right) + c \\ 
&= T\left(\frac{n}{4}\right) + 2c \\
&= T\left(\frac{n}{8}\right) + 3c \\
&\vdots \\
&= T(1) + c\log_2n
&=d+ c\log_2n
\end{aligned}
$$

*Time Complexity:*
$$
T(n) = O(\log n)
$$

---
**Example 3: Merge Sort**

*Function Defition:*
```
void merge_sort(vector<int>& arr, int low, int high) {
    if (low >= high) return;

    int mid = (low + high) / 2;

    // Recursively sort the first and second halves
    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);

    // Merge the two sorted halves
    vector<int> temp;
    int i = low, j = mid + 1;

    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) temp.push_back(arr[i++]);
        else temp.push_back(arr[j++]);
    }

    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= high) temp.push_back(arr[j++]);

    // Copy the merged result back into the original array
    for (int k = low; k <= high; ++k) {
        arr[k] = temp[k - low];
    }
}
```

*Recurrence Relation:*
$$
T(n) = 2\cdot T\left(\frac{n}{2}\right) + cn
$$
- $2\cdot T\left(\frac{n}{2}\right)$: Time for sorting two halves.
- $cn$: Time for merging two sorted halves.
- **Base Case:** $T(1)=d$ (constant time when the array has one element).

*Solving the Recurrence:*
Using the Master Theorem for $T(n) = a\cdot \left(\frac{n}{b}\right) + f(n)$:
- $a=2$, $b=2$, $f(n) = cn$
- Since $f(n) = O(n^{\log_ba})$, and $\log_ba = \log_22 = 1$, $f(n) = O(n^1)$
- Case 2 of the Master Theorem applies.

*Therefore:*
$$
T(n) = O(n\log n)
$$

*Alternatively, Unrolling the Recurrence:*

At each level of the recursion, the total work is proportional to $n$:
- Level 0: $cn$
- Level 1: $2 \times c\frac{n}{2} = cn$
- Level 2: $4 \times c\frac{n}{4} = cn$
- $\vdots$
- Number of levels: $\log_2n$

*Total Time:*
$$
T(n) = cn\log_2n + n \cdot d
$$

*Time Complexity:*
$$
T(n) = O(n\log n)
$$

