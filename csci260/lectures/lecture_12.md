# Prof's Notes
## Sorting Algorithms
Assumption: All numbers in the array are distinct.

### The bad ones ($O(n^2)$)
#### Bubble sort:
```
void sort(double A[], int N)
{
    for(i = 0; i < N; ++i) {
        for(j = 0; j < N-1; ++j) {
            if (A[j] > A[j+1])
                swap(A, j, j+1);
        }
    }
}
```
#### Insertion sort:
```
void sort(double A[], int N)
{
    for(i = 1; i < N; ++i) {
        temp = A[i];
        for(j = i-1; j >= 0 && A[j] > temp; ++j) {
            A[j+1] = A[j];
        }
        A[j+1] = temp;
    }
}
```
#### Selection sort:
```
void sort(double A[], int N)
{
    for(i = 0; i < N; ++i) {
        smallest = i;
        for(j = i+1; j < N; ++j) {
            if (A[j] < A[smallest])
                smallest = j;
        }
        swap(A, i, smallest);
    }
}
```
### The good ones ($O(n\text{ log }n)$):
#### Quick sort:
```
void sort(double A[], int low, int high)
{
    if (low >= high)
        return;
    
    pivot = low;
    i = low + 1;
    j = high;
    // throw smaller ones to pivot's left
    // and larger ones to pivot's right
    while (i <= j) {
        if (A[i] < A[pivot]) {
            swap(A, i, pivot);
            pivot = i;
            i = pivot + 1;
        } else {
            swap(A, i, j);
            j = j - 1;
        }
    }

    // sort the pile with the smaller numbers
    sort(A, low, pivot-1);
    // sort the pile with the larger numbers
    sort(A, pivot+1, high);
}
```
#### Merge sort:
```
void sort(double A[], int low, int high)
{
    if(low >= high)
        return;
    
    // divide the pile into two piles
    mid = (low + high) / 2;
    // sort the left pile
    sort(A, low, mid);
    // sort the right pile
    sort(A, mid+1, high);

    // merge the two sorted piles into one sorted pile
    double B[high-low+1];
    i = low;
    j = mid+1;
    k = 0;
    while (i <= mid && j <= high) {
        if (A[i] < A[j]) {
            B[k] = A[i];
            ++i;
        } else {
            B[k] = A[j];
            ++j;
        }
        ++k;
    }
    while (i <= mid) {
        B[k] = A[i];
        ++i; 
        ++k;
    }
    while (j <= high) {
        B[k] = A[j];
        ++j;
        ++k;
    }
    for(i = low, k = 0; i <= high; ++i, ++k)
        A[i] = B[k];
}
```
#### Heap sort:
```
void sort(double A[], int N)
{
    // max heap insert
    for(i = 1; i < N; ++i) {
        j = i;
        parent = (i-1)/2;
        while (j > 0 && A[j] > A[parent]) {
            swap(A, j, parent);
            j = parent;
            parent = (j-1)/2;
        }
    }
    // extract from max heap
    // so the numbers are sorted from smallest to largest
    bool stop;
    for(i = N-1; i > 0; --i) {
        swap(A, 0, i);
        j = 0;
         child = j*2+1;
         stop = (child >= i);
         while (!stop) {
            if (child+1 < i && A[child] < A[child+1])
                child = child+1;
            if (A[j] < A[child]) {
                swap(A, j, child);
                j = child;
                child = j*2+1;
                stop = (child >= i);
            } else {
                stop = true;
            }
         }
    }
}
```
#### Shell sort:
```
void sort(double A[], int N)
{
    gap = N/2;
    while (gap >= 1) {
        for(i = gap; i < N; ++i) {
            j = i;
            k = j - gap;
            while (k >= 0 && A[j] < A[k]) {
                swap(A, j, k);
                j = k;
                k = j - gap;
            }
        }
        gap = gap/2;
    }
}
```
### The unconventional ones:
#### Bucket sort
```
void sort(int A[], int N)
{
    int smallest = min(A); // the smallest number in A
    int largest = max(A); // the largest number in A
    int size = largest-smallest+1;
    bool B[size];
    for(i = 0; i < size; ++i)
        B[i] = false;

    for(i = 0; i < N; ++i) {
        B[A[i]-smallest] = true;
    }
    i = 0;
    for(j = 0; j < size; ++j) {
        if (B[j]) {
            A[i] = j+smallest;
            ++i;
        }
    }
}
```
#### Radix sort:
```
void sort(int A[], int N)
{
    int largest = max(A); // the largest number in A
    Queue buckets[10];
    factor = 1;
    while (factor < largest) {
        for(i = 0; i < N; ++i) {
            buckets[A[i]/factor%10].enqueue(A[i]);
        }
        i = 0;
        for(j = 0; j < 10; j++) {
            while (!buckets[j].isEmpty()) {
                A[i] = buckets[j].dequeue();
                ++i;
            }
        }
        factor = factor * 10;
    }
}
```
## External Sorting Algorithms
### Internal sorting conditions:
- data stored in continous storage space (array)
- fully comparable keys (total order data typed keys)
- randomly accessible to every element (in main memory)
### External sorting conditions:
- input data amount too large for main memory
- input data stored in sequential storage
- output sorted sequence to sequential storage
- I/O cost is significantly larger than in-memory operation (such as comparison) cost
### External sorting algorithm criteria:
- access data in sequential order
- minimize number of times an item is accessed from disk
### External sorting algorithm:
1. break a large data file into shorter "runs" of data, so that each run can fit to main memory and be sorted (using internal sorting algorithm).
2. merge two or more runs (depends on how many input buffers there are) together into a longer run.
3. repeat step 2 until there is only one sorted file.
### Performance of the external sorting algorithm:
- If M records and be sorted in memory, and the file has N records, the number of initial runs is N/M.
- If we can merge T runs in each pass, then we need $\lceil \log_T \frac{N}{M} \rceil$ passes to merge all runs together since each pass reduces the number of runs by T.

## Algorithm Analysis
The performance of a program usually depends on:
- Data structures and algorithms;
- Characteristics of input data;
- Computer hardware, including but not limiteed to CPU, memory, and disk;
- Programming language used to develop the program;
- Compiler/Interpreter;
- Software environment; and
- Network communication protocols and connections.

An algorithm is a step-by-step procedure for solving a problem in a finite amount of time. Time efficiency of an algorithm indicates how fast an algorithm runs; space efficiency deals with the extra space the algorithm requires. Other analysis includes correctness, robustness, and maintainability.

The running time of an algorithm typically grows with the input size. Average case time efficiency is often difficult to determine. So we usually focus on the worst case scenario analysis because it's easier to analyze and crucial to applications.

We can use experiments to measure an algorithm's running time as a function of the input size. But there are limitations with this method:
- The algorithm needs to be implemented first, which may be difficult and costly;
- The measured results may not be comprehensive enough to capture the characteristics of all types of inputs;
- The results are only measured on a specific hardware and software environment.

The preffered way is to analyze the running time of an algorithm theoretically, charactize the running time as a function of the input size (N). This method allows us to evaluate the time efficiency of an algorithm independent of the hardware and software environment.

General steps of asymptotic analysis of an algorith:
- Define the problem size (input size), N;
- Count the number of the primitive operations as a function of N;
- Decide the growth rate of the function.

It is obvious that almost all algorithms take longer to run on larger inputs. We usually use a parameter, N, to indicate the input size of an algorithm. Sometimes, several parameters combined together are used to define the input size.

Primitive Operations include:
- assigning a value to a variable;
- calling a method;
- performing an arithmetic operation;
- comparing two numbers;
- accessing an array element;
- following a pointer or a reference;
- returning from a method.

Treating all primitive operations the same and ignoring the hardware and software environment difference may affect the estimate of the running time of an algorithm by a constant factor, but it does not alter the growth rate of the running time efficiency function.

For large input size N, it is the functions order of growth that matters:

| $N$ | $logN$ | $N$ | $NlogN$ | $N^2$ | $N^3$ | $2^N$ | $N!$
| :- | :- | :- | :- | :- | :- | :- | :- 
| 10 | 3 | 10 | 33 | 100 | 1K | 1K | 3.6M
| 32 | 5 | 32 | 160 | 1K | 32K | 4B | large
| 64 | 6 | 64 | 384 | 4K | 256K | 16BB | large
| 10$^3$ | 10 | 10$^3$ | 10$^4$ | 10$^6$ | 10$^9$ | - | -
| 10$^6$ | 20 | 10$^6$ | 10$^7$ | 10$^{12}$ | 10$^{18}$ | - | -

As a comparison, 16 billion billion seconds is 543 billion years. The Earth's age is about 4.5 billion years, and the universe's age is about 14 billion years.

### Asymptotic Notations
- **The upper bound O definition:**
    - Let $f(n)$ and $g(n)$ be functions mapping non-negative integers to real numbers.
    - $f(n)$ is $O(g(n))$ if there exists a real constant $c > 0$ and an integer constant $n_0 \ge 1$ such that $f(n) \le cg(n)$ for every integer $n \le n_0$.
    - In other words, the growth rate of $f(n)$ is no more than that of $g(n)$.
- **$\Omega$ and $\Theta$:**
    - If $g(n)$ is $O(f(n))$, then $f(n)$ is $\Omega (g(n))$.
    - If $f(n)$ is $O(g(n))$ and $\Omega (g(n))$, then $f(n)$ is $\Theta(g(n))$.
- **o and $\omega$:**
    - $f(n)$ is $o(g(n))$ if for every real constant $c>0$, there exists an integer constant $n_0\ge 1$ such that $f(n)\le cg(n)$ for every integer $n\ge n_0$.
    - In other words, the growth rate of $f(n)$ is less than that of $g(n)$.
    - If $g(n)$ is $o(f(n))$, then $f(n)$ is $\omega (g(n))$.

The O notation denotes a class of functions. The growth rates of all functions in the same class are the same. The O families provide a convenient way to analyze algorithms because they let us focus on the big picture rather than the details.

#### O Rules
- If $f(n)$ is a polynomial of degree $d$, then $f(n)$ is $O(n^d)$, i.e., drop the lower order terms and the constant factors.
- Use the smallest possible class of functions. For example, $2n$ is $O(n^2)$, but we usually say $2n$ is $O(n)$.
- Use the simplest expression of the class. $O(3n^2)$ should be $O(n^2)$.

#### Rules for O Analysis of running time of an algorithm:
- **Sequential Composition:** 
    - $S_1, S_2, ..., S_k$
    - $T_S = O(\max(T_1,T_2,...,T_k))$
- **Iteration:**
    - for $i$ from 1 to k { Exp }
    - $T_I=O(\max(k, T_{\text{Exp}} * k))$
- **Conditional Execution:**
    - if cond then Exp1 else Exp2
    - $T_C=O(\max(T_{\text{cond}},T_{\text{Exp1}},T_{\text{Exp2}}))$

#### O Analysis for recursive algorithms:
- Write a recurrence equation for running time function;
- Solve the recurrence equation;
- Classify the result to a $\Theta (f(n))$ family.

### The Master Theorem:
$$
T(n) = aT(\frac{n}{b}) + f(n), \text{ if } n \ge d
$$

1. **Case 1:** If there exists a small constant $\epsilon > 0$, such that $f(n)=O(n^{\log_ba- \epsilon})$, then $T(n)$ is $\Theta (n^{\log_ba})$.
2. **Case 2:** If there exists a constant $k \ge 0$, such that $f(n)=\Theta (n^{\log_ba}  \log^kn)$, then $T(n)$ is $\Theta (n^{\log_ba} \log^{k+1}n)$
3. **Case 3:** If there exist small constants $\epsilon > 0$ and $\delta < 1$, such that $f(n) = \Omega(n^{\log_ba+\epsilon})$ and $af(\frac{n}{b}) \le \delta f(n)$ for $n \ge d$, then $T(n)=\Theta(f(n))$.

---
### Expanding on the Master Theorem
The Master Theorem provides a way to determine the asymptotic behavior of recurrences of the form:
$$
T(n) = aT\left(\frac{n}{b}\right)+f(n)\text{, for n }\ge d
$$
Where:
- $T(n)$ is the recurrence relation that describes how the time to solve a problem of size $n$ is related to the time to solve its subproblems, along with any additional work done at each level of the recursion.
- $a \ge 1$: Number of recursive calls.
- $b > 1$: Factor by which the problem size is reduced.
- $f(n)$: Cost of the work done outside the recursive calls.

Define:
$$
k=log_ba
$$

**Case 1: Polynomially Smaller** $f(n)$
- **Condition:** $f(n)=O(n^{k-\epsilon})$ for some $\epsilon > 0$.
- **Interpretation:** $f(n)$ grows significantly slower than $n^k$.
- **Conclusion:** The recursive part dominates, so:
    $$
    T(n) = \Theta(n^k)
    $$
- **Example:**
    $$
    T(n) = 2T\left(\frac{n}{2}\right) + n
    $$
    Here, $a=2,b=2,\text{ so }k=\log_2 2=1$, and $f(n) = n = O(n^{1-\epsilon})\text{ for }\epsilon=0.5$. 
    Thus, $T(n)=\Theta(n^1)=\Theta(n)$.

**Case 2: Polynomially Equivalent** $f(n)$
- **Condition:** $f(n) =\Theta(n^k\log^pn)$ for some $p\ge0$
- **Interpretation:** $f(n)$ grows at the same rate as $n^k$ up to logarithmic factors.
- **Conclusion:** Both the recursive and non-recursive parts contribute equally, so:
    $$
    T(n) = \Theta(n^k\log^{p+1}n)
    $$
- **Example:**
    $$
    T(n) = 2T\left(\frac{n}{2}\right)+n\log n
    $$
    Here, $f(n) = n\log n=\Theta(n^1\log^1n)$, so $T(n) = \Theta(n\log^2n)$.

**Case 3: Polynomially Larger** $f(n)$
- **Condition:**
    - $f(n)=\Omega(n^{k+\epsilon})$ for some $\epsilon > 0$.
    - There exists a constant $\delta < 1$ such that $af(\frac{n}{b}) \le \delta f(n)$ for $n\ge d$.
- **Interpretation:** $f(n) grows faster than $n^k$.
- **Conclusion:** The non-recursive part dominates, so:
    $$
    T(n) = \Theta(f(n))
    $$
- **Example:**
    $$
    T(n)=2T\left(\frac{n}{2}\right)+n^2
    $$
    Here, $k=1$, but $f(n)=n^2=\Omega(n^{1+\epsilon})$ with $\epsilon = 1$.
    Also, $af(\frac{n}{b}) = 2(\frac{n}{b})^2=\frac{n^2}{2}\le \delta n^2$ with $\delta = 0.5$.
    Thus, $T(n)=\Theta(n^2)$.

---
### Tips and Tricks for Applying the Master Theorem
1. **Identify $a$, $b$, and $f(n)$:**
    - Carefully extract these values from your recurrence.
2. **Compute $k = log_ba$:**
    - Remember that $log_ba=\frac{\ln a}{\ln b}$.
3. **Compare $f(n)$ with $n^k$:**
    - Determine if $f(n)$ is polynomially smaller, equivalent, or larger than $n^k$.
4. **Check the Regularity Condition for Case 3:**
    - Verify $af(\frac{n}{b})\le \delta f(n)$ for some $\delta < 1$.
5. **Use the Correct Case:**
    - Apply the case that fits based on your comparison.
6. **Handling Logarithms:**
    - Use logarithm properties to simplify expressions.
    - Remember that $log_bn=\frac{\ln n}{\ln b}$
7. **Polynomial Multiples of Logarithms:**
    - Recognize that terms like $n^k\log^pn$ indicate Case 2.
8. **Practicing with Examples:**
    - Solve various examples to become familiar with identifying and applying the correct case.

---
### Example Problems
**Example 1:**
$$
T(n)=3T\left(\frac{n}{2}\right)+n
$$
**Solution:**
**1. Identify $a$, $b$, and $f(n):**
- $a = 3$: This is the number of recursive calls in the recurrence.
- $b = 2$: This is the factor by which the problem size is reduced in each recursive call.
- $f(n) = n$: This is the cost of the work done outside the recursive calls.

**2. Compute $k = \log_ba$:**
- $k = \log_ba = \log_23 \approx 1.58496$

**3. Compare $f(n)$ with $n^k$:**
- **Calculate $n^{k-\epsilon}$ for some $\epsilon > 0$:**
Let's choose $\epsilon=0.08496$ (so $\epsilon$ is small and positive).
    - $k- \epsilon = 1.58496 - 0.08496 = 1.5$.
    - $n^{k-\epsilon} = n^{1.5}$
- **Check if $f(n) = O(n^{k-\epsilon})$:**
    - $f(n) = n$.
    - Since $n = O(n^{1.5})$ (because $n^1$ grows slower than $n^{1.5}$), this condition holds.

**4. Determine which case applies:**
- Since $f(n) = O(n^{k-\epsilon})$ for some $\epsilon > 0$, **Case 1** of the Master Theorem applies.

**5. Apply the conclusion of Case 1:**
- $T(n) = \Theta(n^k) = \Theta(n^{\log_23})$

**6. Final Answer:**
- Therefore, $T(n) = \Theta(n^{log_23}) \approx \Theta(n^{1.58496})$

---
**Example 2:**
$$
T(n) = 2T\left(\frac{n}{4}\right)+\sqrt n
$$
**Solution**
**1. Identify $a$, $b$, and $f(n)$:**
- $a = 2$: Number of recursive calls.
- $b = 4$: Reduction factor.
- $f(n) = \sqrt n = n^{0.5}$: Cost of non-recursive work.

**2. Compute $k=\log_ba$:**
- $k=\log_ba=\log_42$.
    - Recall that $\log_ba=\frac{\ln a}{\ln b}$.
    - So, $k=\frac{\ln 2}{\ln 4} = \frac{\ln 2}{2\ln2}=\frac{1}{2}=0.5$

**3. Compare $f(n)$ with $n^k$:**
- $n^k=n^{0.5}$.
- $f(n)=n^{0.5}$.
- Thus, $f(n)=\Theta(n^k)$.

**4. Check for logarithmic factors in $f(n)$:**
- Since $f(n) = \Theta(n^k\log^pn)$ with $p=0$.

**5. Determine which case applies:**
- Since $f(n) = \Theta(n^k\log^pn)$, **Case 2** applies.

**6. Apply the conclusion of Case 2:**
- The result is $T(n)=\Theta(n^k\log^{p+1}n)$.
- Substituting $k=0.5$ and $p=0$:
    - $T(n) = \Theta(n^{0.5}\log^1n)$.

**7. Final Answer:**
- Therefore, $T(n)=\Theta(\sqrt n\log n)$

---
**Example 3:**
$$
T(n)=T\left(\frac{n}{2}\right)+n
$$
**Solution**
**1. Identify $a$, $b$, and $f(n)$:**
- $a = 1$: One recursive call.
- $b = 2$: Problem size is halved each time.
- $f(n) = n$: Non-recursive work.

**2. Compute $k=\log_ba$:**
- $k=\log_ba=\log_21=0$

**3. Compare $f(n)$ with $n^k$:**
- $n^k=n^0=1$.
- $f(n)=n$
- So $f(n)=n=\Omega(n^{k+\epsilon})$ for any $\epsilon > 0$ because $n=\Omega(n^{0+\epsilon})=\Omega(n^\epsilon)$
Let's choose $\epsilon = 0.5$:
    - $n^{k+\epsilon} = n^{0+0.5}= n^{0.5}$
    - Since $n=\Omega(n^{0.5})$ (because $n$ grows faster than $n^{0.5}), the condition holds.

**4. Verify the Regularity Condition:**
- **Regularity Condition:** $af(\frac{n}{b})\le \delta f(n)$ for some $\delta < 1$ and sufficiently large $n$.
- Compute $af(\frac{n}{b})$:
    - $af(\frac{n}{b})=1 \times f(\frac{n}{b})=f(\frac{n}{b})=\frac{n}{b}$.
- Compare $af(\frac{n}{b})$ with $\delta f(n)$:
    - $\delta f(n)=\delta n$.
    - We need $\frac{n}{2} \le \delta n$.
    - Simplify: $\frac{1}{2}n\le \delta n$.
    - Divide both sides by $n$ (assuming $n > 0$):
        - $\frac{1}{2} \le \delta$.
    - So any $\delta \ge \frac{1}{2}$ satisfied the inequality.
- Choose $\delta = \frac{1}{2} < 1$, which satisfies the condition.

**5. Determine which case applies:**
- Since $f(n)=\Omega(n^{k+\epsilon})$ and the regularity condition is satisfied, **Case 3* applies.

**6. Apply the conclusion of Case 3:**
- $T(n)=\Theta(f(n))=\Theta(n)$.

**7. Final Answer:**
- Therefore, $T(n) = \Theta(n).$

---
**Example 4:**
$$
T(n)=4T\left(\frac{n}{2}\right) + n^2
$$
**Solution**
**1. Identify $a$, $b$, and $f(n)$:**
- $a = 4$.
- $b = 2$.
- $f(n) = n^2$

**2. Compute $k=\log_ba$:**
- $k=\log_24=2$

**3. Compare $f(n)$ with $n^k$:**
- $n^k=n^2$
- $f(n)=n^2$
- Therefore, $f(n)=\Theta(n^k)$

**4. Check for logarithmic factors in $f(n)$:**
- $f(n)=\Theta(n^k\log^0n)$ (since there is no logarithmic factor, $p=0$)

**5. Determine which case applies:**
- Since $f(n)=\Theta(n^k\log^pn)$, **Case 2** applies.

**6. Apply the conclusion of Case X:**
- $T(n)=\Theta(n^k\log^{p+1}n)$
- Substituting $k=2$ and $p=0$:
    - $T(n)=\Theta(n^2\log n)$

**7. Final Answer:**
- Therefore, $T(n)=\Theta(n^2\log n)$

---
### Key Takeaways
- **Always identify $a$, $b$, and $f(n)$ first.**
- **Compute $k=\log_ba$ accurately.**
- **Compare $f(n)$ with $n^k$ by considering whether $f(n)$ is polynomially smaller, equivalent, or larger than $n^k$.**
- **Check the regularity condition in Case 3 carefully.**
- **Apply the appropriate case of the Master Theorem based on your analysis.**
- **Include all calculations and comparisons in your solution to make your reasoning clear.**

---
### Final Tips for Exams
* **Memorize the Conditions:**
    - Understand the conditions for each case instead of rote memorization.
- **Practice Different Scenarios:**
    - Work through examples with varying $a$, $b$, and $f(n).
- **Understand Underlying Concepts:**
    - Grasp why each case leads to its conclusion (e.g., which part of the recurrence dominates).
- **Time Management:**
    - In examples, quickly identify $k$ and compare $f(n)$ to $n^k$ to decide on the case.
- **Check Edge Cases:**
    - Be cautious with logarithmic factors and constants that might affect which case applies.
- **Write Clearly:**
    - Show your steps in applying the theorem to potentially earn partial credit.
- **Write Down All Steps:**
    - Even if steps seem straightforward, write them down to ensure you haven't overlooked anything.
- **Be Precises with Inequalities:**
    - When stating that $f(n) = O(n^{k-\epsilon})$ or $f(n)=\Omega(n^{k+\epsilon})$, specify the value of $\epsilon$ and verify the inequality.
- **Calculating $\log_ba$:**
    - Use change of base formula if necessary:
        - $\log_ba = \frac{\ln a}{\ln b}$
- **Regularity Condition in Case 3:**
    - Explicitly compute $af(\frac{n}{b})$ and compare it to $\delta f(n)$.
- **State Your Conclusion Clearly:**
    - After determining which case applies, write down the final asymptotic behavior of $T(n)$.
- **Practice with Different Functions $f(n)$:**
    - Try examples where $f(n)$ includes logarithmic factors, exponential terms, or other complexities.

---
