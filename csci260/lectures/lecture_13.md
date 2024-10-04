# Lecture 13: Iterative Algorithm Analysis
## Process
1. Define problem size $n$.
2. Count the number of primitive operations as a function of $n$.
3. Determine the growth rate of the function.

## Example
```
double polyEval(double a[], int n, double x) {
    double result = 0;                      // 1
    double sub_res = 0;                     // 1

    for (int i = 0; i < n; ++i) {           // 1 (init) + n (checks) + n (increments)
        sub_res = 1;                        // n

        for (int j = i+1; j < n; ++j) {     // n(n - 1)/2 (checks and increments)
            sub_res = sub_res * x;          // n(n - 1)/2 (multiplications)
        }
        result = result + a[i] * sub_res;   // n
    }
    return result;                          // 1
}
```
### Step-by-Step Breakdown
**1. Initialize Variables:**
- `double result = 0;` → 1 operation
- `double sub_res = 0;` → 1 operation

**2. Outer Loop Analysis:**
- `for (int i = 0; i < n; ++i)`:
    - Initialization (`int i = 0`): 1 operation.
    - Loop condition check (`i < n`): occurs `n + 1` times (once more after the last iteration fails).
    - Increment (`++i`): occurs `n` times.
    
    Therefore, the total for the outer loop is `1 (init) + n (checks) + n (increments) = 2n + 1` operations.

**3. Inner Loop Analysis:**
- The inner loop runs with `j = i + 1` until `j < n`. The number of interations for each value of `i` depends on `i`.
- The iterations can be counted as a summation:
    $$
    \sum^{n-1}_{i=0}(n-(i+1))=\frac{n(n-1)}{2}
    $$
- This is because, for each value of `i`, `j` starts at `i + 1` and goes up to `n - 1`, giving `n - (i + 1)` iterations.
- Loop condition check and increment occur for each iteration, resulting in approximately `n(n - 1)/2` operations.

**4. Operations inside the Inner Loop:**
- `sub_res = sub_res * x;` occurs every iteration of the inner loop, meaning it also runs `n(n - 1)\2` times.

**5. Operations after Inner Loop:**
- `result = result + a[i] * sub_res;` occurs `n` times (once for each iteration of the outer loop).

**6. Return Statement:**
- `return result;` → 1 operation.

### Total Number of Operations
To summarize the count of primitive operations:
- **Initialization and Return:
    - `2` operations (`double result = 0;` and `double sub_res = 0;`).
    - `1` operation for `return result;`.
- **Outer Loop:**
    - `2n + 1` operations (initialization, loop condition checks, and increments).
- **Inner Loop:**
    - Loop condition checks and increments: `n(n - 1)/2`.
    - Multiplications (`sub_res = sub_res * x`): `n(n - 1)/2`.
- **Result Update:** (`result = result + a[i] * sub_res`):
    - `n` operations.

Total number of operations:
$$
2+1+(2n+1)+n+\frac{n(n-1)}{2}+\frac{n(n-1)}{2}
$$
Simplifying the leading term, this results in:
$$
c_1n^2+c_2n+c_3
$$
where $c_1$, $c_2$, and $c_3$ are constants that represent coefficients of the respective terms.

### Growth Rate
When analyzing the growth rate, we only care about the dominant term as $n$ becomes very large:
- The **dominant term** here is $n^2$, which ceoms from the nested loops.

Therefore, the growth rate is $O(n^2)$.

## Big O Notation
- Let $f(n)$ and $g(n)$ be functions mapping non-negative integers to a real number.
- $f(n)$ is in $O(g(n))$ if there exists a real constant $c > 0$ and an integer $n_0\ge1$ such that $f(n)\le c \cdot g(n)$ for every integer $n\ge n_0$.
- If $f(n)$ is in $O(g(n))$ (upper bound), then $g(n)$ is in $\Omega(f(n))$ (lower bound).
- Growth rate of $f(n)\le$ growth rate of $g(n)$.
- If $f(n)$ is in $O(g(n))$ and $f(n)$ is in $\Omega(g(n))$, then $f(n)$ is in $\Theta(g(n))$.
- $f(n)$ is in $o(g(n))$ if for every real constant $c>0$ there exists an integer constant $n_0\ge 1$ such that $f(n)\le c \cdot g(n)$ for every integer $n\ge n_0$.
- If $f(n)$ is in $o(g(n))$, then $g(n)$ is in $\omega(f(n))$.

### Examples
- Given $f(n) = 3n^2+\frac{1}{2}n+4$ and $g(n) = n^2$ prove that $f(n) \in \Theta(g(n))$.

To prove $f(n) \in \Theta(g(n))$, we need to show that there exist positive constants $c_1$, $c_2$, and $n_0$ such that:
$$
c_1g(n)\le f(n)\le c_2g(n) \text{ for all } n\ge n_0
$$

#### Given:
- $f(n) = 3n^2 + \frac{1}{2}n + 4$
- $g(n) = n^2$

#### Step-by-Step
1. **Find Upper Bound (Big O):**
    $$
    f(n) = 3n^2 + \frac{1}{2}n + 4 \le 4n^2 \text{ for sufficiently large }n
    $$
    Set $c_2=4$ and $n_0=8$ (or a sufficiently large value to ensure this inequality holds).
2. **Find Lower Bound (Big Omega):
    $$
    f(n) = 3n^2 + \frac{1}{2}n + 4 \ge 3n^2 \text{ for sufficiently large }n
    $$
    Set $c_1=3$ and $n_0=1$ (or a sufficiently large value to ensure this inequality holds).

Since we have found constants $c_1$, $c_2$, and $n_0$ such that:
$$
3n^2 \le f(n) \le 4n^2 \text{ for all } n\ge n_0
$$
we conclude:
$$
f(n)\in \Theta(g(n))
$$

---
- Prove $f(n) \in O(g(n))$

To prove that $f(n) \in O(g(n))$, we need to find a positive constant $c$ and an integer $n_0 \ge 1$ such that:
$$
f(n)\le c \cdot g(n) \text{ for all } n \ge n_0
$$

#### Given:
- $f(n) = $3n^2 + \frac{1}{2}n + 4
- $g(n) = n^2$

#### Step-by-Step:
1. **Set Up the Inequality:**
$$
3n^2 + \frac{1}{2}n + 4 \le c \cdot n^2
$$
2. **Find a Suitable $c$:**
    - To ensure the inequality holds for sufficiently large $n$, let's choose $c=4$:
        $$
        3n^2 + \frac{1}{2}n + 4 \le 4n^2
        $$
3. **Verify the Inequality:**
    - For $n\ge 8$, the inequality $3n^2 + \frac{1}{2}n + 4 \le 4n^2$ holds true.

#### Conclusion:
With $c = 4$ and $n_0 = 8$, we have:
$$
f(n)\le 4n^2 \text{ for all } n\ge 8
$$
Thus, $f(n) \in O(g(n))$.