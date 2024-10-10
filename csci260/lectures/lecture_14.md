# Lecture 14 Recursive Algorithm Analysis and Master Theorem
```
double EvaluatePolynomial (double a[], int N, double x) { // Horner algorithm
    double result = a[0];
    for (int i = 1l i < N; ++i)
        result = result * x + a[i];

    return result;
}
```
This is an efficient method for evaluating polynomials. It reduces the computational complexity by minimizing the number of multiplications required.

Let's say you have a polynomial of degree $N - 1$:
$$
P(x) = a_0 + a_1x + a_2x^2 + \dots + a_{N-1}x^{N-1}
$$
Normally, to evaluate this polynomial for some value of $x$, you'd compute each power of $x$ (like $x^2$, $x^3$, etc.) and multiply it by the corresponding coefficient. This would require a lot of multiplications and additions, leading to inefficient computation for higher-degree polynomials.

Horner's method rewrites the polynomial to reduce the number of operations by factoring:
$$
P(x) = a_0 + x(a_1 + x(a_2 + \dots + x(a_{N-2} + xa_{N-1})))
$$
This formulation allows you to compute the value of the polynomial using only $N-1$ multiplications and $N-1$ additions. In the loop of the code, each iteration updates the result by multiplying the current result by $x$ and adding the next coefficient, starting from the highest degree term and working backward.

#### Example
For a polynomial $P(x) = 2 + 3x + 4x^2 + 5x^3$ (i.e., $a[]={2, 3, 4, 5}$), it can be computed as:
$$
P(x) = 2 + x(3 + x(4 + x(5)))
$$
The code above works through this process using a for-loop. It starts with the coefficient $a[0]$ and then iteratively multiplies the result by $x$ and adds the next coefficient.

#### Efficiency
Horner's method performs in $O(N)$ time, where $N$ is the degree of the polynomial, which is much more efficient than the naive method, which would involve powers of $x$ and require $O(N^2)$ operations in the worst case.

---
## Recursive Algorithm Analysis
```
void Hanoi(int discs, char start, char destination, char temporary)
{
    if (discs == 1) {
        move disc from start to destination;
        return;
    }

    // move (discs - 1) discs from start to temporary using destination as auxiliary
    Hanoi (discs - 1, start, temporary, destination);

    // move the remaining disc from start to destination
    move last disc from start to destination;

    // move (discs -1) discs from temporary to destination using start as auxiliary
    Hanoi (discs - 1, temporary, destination, start);
}
```
$$
F(N) = \begin{cases} & 2 \text{ if } N \le 1 \\
& 2F(N -1) + 1 \text{ if } N > 1
        \end{cases}
$$
### Step 1: Unroll the Recurrence Relation
| N | F(N)
| :- | :-
| 1 | $F(1)=2$
| 2 | $F(2) = 2F(1) = 2 \times 2 + 1 = 5$
| 3 | $F(3) = 2F(2) = 2 \times 5 + 1 = 11$
| 4 | $F(4) = 2F(3) = 2 \times 11 + 1 = 23$

By unrolling the recursion, you can see the recurrence depends on the previous terms.
Let's generalize this:
$$
F(N) = 2F(N-1)+1  \\
F(N-1)=2F(N-2)+1  \\
F(N-2)=2F(N-3)+1 
$$
... and so on, until $F(1) = 2$.

### Step 2: Express $F(N)$ in Terms of $F(1)$
Now substitute the values backward:
$$
F(N)=2F(N-1)+1
$$
Substitute $F(N-1)=2F(N-2)+1$:
$$
F(N)=2(2F(N-2)+1)+1=2^2F(N-2)+2+1
$$
Substitute $F(N-2)=2F(N-3)+1$:
$$
F(N)=2^3F(N-3)+2^2+2+1
$$
You can see the pattern that forms. Eventually, you will reach $F(1)=2$:
$$
F(N)=2^{N-1}F(1)+2^{N-2}+2^{N-3}+\dots+2+1
$$
This simplifies to:
$$
F(N)=2^N+(2^{N-2}+2^{N-3}+\dots+2+1)
$$

### Step 3: Summation of Powers of 2
The sum of powers of 2 from $2^0$ to $2^{N-2}$ is a geometric series:
$$
S=2^{N-2}+2{N-3}+\dots+2+1
$$
The sum of a geometric series is given by:
$$
S=\frac{2^{N-1}-1}{2-1}=2^{N-1}-1
$$

### Step 4: Final Closed-Form Expression
Substitute this back into the equation:
$$
F(N) = 2^N+(2^{N-1}-1)
$$
Thus, the close form expression is
$$
F(N) = 2^N+2^{N-1}-1
$$

### Prove By Induction

**Assumption:** $F(N) = 2^N+2^{N-1}-1$

| N | Equation Side | Solution Side 
| :- | :- | :-
| $1$ | $F(1) = 2$ | $F(1) = 2^1+2^{1-1}-1=2$
| $N+1$ | $F(N+1) = 2F(N) +1$ | $F(N+1) = 2^{N+1}+2^{N+1-1}-1$
| $N+1$ | $=2(2^N+2^{N-1}-1) + 1$ | $= 2^{N+1}+2^N-1$
| $N+1$ | $=2^{N+1} + 2^N - 1$ |

Therefore, $F(N) \in \Theta(2^N)$

---
## Merge Sort
```
mergeSort (double A[], int low, int high)
{
    if (low >= high)
        return;
    
    int mid = (low + high) / 2;
    MergeSort(A, low, mid);
    MergeSort(A, mid + 1, high);

    merge all low-high together;
}
```
### Recurrence Equation
$$
F(N) = \begin{cases} & C_1 \text{ if } N \le 1 \\
& 2F(\frac{N}{2}) + N \text{ if } N > 1
        \end{cases}
$$

Let $N = 2^k$.

$$
F(2^k) = \begin{cases} & C_1 \text{ if } 2^k \le 1 \\
& 2F(2^{k-1}) + 2^k \text{ if } 2^k > 1
        \end{cases}
$$

$$
T(k) = \begin{cases} & C_1 \text{ if } k \le 0 \\
& 2T(k-1) + 2^k \text{ if } k > 0
        \end{cases}
$$

| $k$ | Expansion of $T(k)$
| :- | :-
| $k = 0$ | $C_1$
| $k = 1$ | $2 \cdot C + 2^1$
| $k = 2$ | $2 \cdot (2 \cdot C + 2^1) + 2^2 = C_1 \cdot 2^2 + 2 \cdot 2^2$
| $k = 3$ | $2 \cdot (C_1 \cdot 2^2 + 2 \cdot 2^2) + 2^3 = C_1 \cdot 2^3 + 3 \cdot 2^3$
| $k = 4$ | $2 \cdot (C_1 \cdot 2^3 + 3 \cdot 2^3) + 2^4 = C_1 \cdot 2^4 + 4 \cdot 2^4$
| $k$ | $C_1 \cdot 2^k + k \cdot 2^k$


| Equation | Hypothesis
| :- | :-
| $k = 0, T(0) = C_1$ | $T(0) = C_1 \cdot 2^0 + 0 \cdot 2^0 = C_1$

Assume $T(k) = C_1 \cdot 2^k + k \cdot 2^k$

$$
\begin{aligned}
T(k+1) &= 2 \cdot T(k) + 2^{k+1} \\
&= 2 \cdot (C_1 \cdot 2^k + k \cdot 2^k) + 2^{k+1} \\
&= C_1 \cdot 2^{k+1} + k \cdot 2^{k+1} + 2^{k+1} \\
&= 2^{k+1} \cdot (C_1 + k + 1) \\
&= C_1 \cdot 2^{k+1} + (k+1) \cdot 2^{k+1}
\end{aligned}
$$

$N = 2^k \rarr K = \log N$
$F(N) = C_1 \cdot N + N \log N \in \Theta N \log N$

