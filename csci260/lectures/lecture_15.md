# Lecture 15 The Master Theorem
$F(N) = aF(\frac{N}{b}) + f(N)$

compare $N\log_ba$ with $f(N)$.

$af(frac{N}{b}) \le \delta \cdot f(n)$ for some $\delta < 1$

**Reminder:** $\log_ba = x$ means $a^x = b$

## Examples
1. **Recurrence:**
$$
F(N) = 4F(\frac{N}{2}) + N
$$
2. **Identify $a$, $b$, and $f(N)$:**
    - $a = 4$ (the number of subproblems),
    - $b = 2$ (the factor by which the problem size is divided),
    - $f(N) = N$ (the non-recursive work).
3. **Compare f(N) with $N^{\log_ba}$:**
$$
N^{\log_ba}=N^{\log_24}=N^2
$$
4. **Compare $f(N) = N$ with $N^2$:**
    - $f(N) = N$ grows slower than $N^2$.
5. **Apply the Master Theorem:**
    - Since $f(N) \in O(N^{2-\epsilon})$ where $\epsilon = 1$, the non-recursive part grows slower than $N^2$, so the recursion dominates.
6. **Conclusion:**
$$
F(N) \in \Theta(N^2)
$$

---
1. **Recurrence:**
$$
F(N) = 2F(\frac{N}{2}) + N\log N
$$
2. **Identify $a$, $b$, and $f(N)$:**
    - $a = 2$ (the number of subproblems),
    - $b = 2$ (the factor by which the problem size is divided),
    - $f(N) = N\log N$ (the non-recursive work).
3. **Compare $f(N)$ with $N^{\log_ba}$:**
$$
N^{\log_ba}=N^{\log_22}=N
$$
4. **Compare $f(N) = N\log N$ with $N^{\log_ba} = N$:**
    


