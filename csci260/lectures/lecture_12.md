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

1. If there is a small constant $\epsilon > 0$, such that $f(n)$ is $O(n^{\log_ba- \epsilon})$, then $T(n)$ is $\Theta (n^{\log_ba})$.
2. If there is a constant $k \ge 0$, such that $f(n)$ is $\Theta (n^{\log_ba} \times \log^kn)$, then $T(n)$ is $\Theta (n^{\log_ba} \times \log^{k+1}n)$
3. If there are small constants $\epsilon > 0$ and $\delta < 1$, such that $f(n)$ is $\Omega(nlog_ba+\epsilon)$ and $af(\frac{n}{b}) \le \delta f(n)$ for $n \ge d$, then $T(n)$ is $\Theta(f(n))$.