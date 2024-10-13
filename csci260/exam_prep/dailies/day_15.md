## Day 15: Proofs by Induction
- **Topics Covered**:
    - Proving statements using mathematical induction.
    - Applying induction to recurrence relations.
- **Study Activities**:
    - **Induction Steps**: Review the base case and inductive step.
    - **Common Pitfalls**: Understand where mistakes often occur in proofs.
- **Practice**:
    - Prove the correctness of formulas derived from recurrence relations.
    - Practice proofs with varying levels of complexity.

---
### 1. Review the base case and inductive step for solving recurrence relations.
When solving recurrence relations, mathematical induction is a fundamental technique used to prove that proposed closed-form formula (explicit formula) correctly represents the solution for all valid values of $n$. The process involves two main steps:
- **Base Case:** Verify that the formula holds for the initial values(s) of $n$. This step establishes that the foundation of the induction is valid. Depending on the recurrence, you might need to check more than one initial value, especially if the recurrence is defined for $n\ge k$ where $k>1$.
- **Inductive Step:** Assume that the formula holds for some arbitrary positive integer $k$ (this assumption is known as the *inductive hypothesis*). Then, using this assumption, prove that the formula also holds for $k+1$. This step demonstrates that if the formula is true for $n=k$, it must also be true for $n=k+1$, thereby proving it for all $n$ by induction.

---
### 2. Where do mistakes often occur in such proofs?
Mistakes in proofs involving recurrence relations and mathematical induction often occur due to:
- **Incorrect Base Case Verification:** Failing to properly verify the base case(s) can invalidate the entire proof. It's essential to ensure that the formula works for all required initial values.
- **Faulty Inductive Hypothesis:** Misapplying the inductive hypothesis, such as assuming the formula for $n=k+1$ instead of $n=k$, can lead to incorrect conclusions.
- **Algebraic Errors:** Mistakes in algebraic manipulations during the inductive step can result in an incorrect proof. Careful and precise calculations are crucial.
- **Assuming What Needs to Be Proven:** Using the result that you're trying to prove within the proof itself (circular reasoning) invalidates the logic of the induction.
- **Overlooking Domain Constraints:** Ignoring the constraingts on $n$ (e.g., $n\ge 1$ or $n$ must be an integer) can lead to incorrect generalizations.

---
### 3. Prove the correctness of 3 forumulas derived from recurrence relations.
**Example 1: Linear Recurrence Relations:**

*Recurrence Relation*: $T(n) = T(n - 1) + 5$, with $T(1) = 5$.

*Prove that:* $T(n) = 5n$.

*Proof by Induction:*

**Base Case ($n=1$):**
- $T(1) = 5$ (given).
- Closed-form formula: $5 \times 1 = 5$.
- Therefore, $T(1) = 5$, so the base case holds.

**Inductive Step:**
- *Inductive Hypothesis:* Assume $T(k) = 5k$ for some integer $k\ge 1$.
- *Show that:* $T(k+1) = 5(k+1)$.

Compute $T(k+1)$:
$$
\begin{aligned}
T(k+1) &= T(k)+5 \\
&= 5k+5 \text{ (using the inductive hypothesis)} \\
&= 5(k+1).
\end{aligned}
$$

This, $T(k+1) = 5(k+1), so the formula holds for $k+1$.

**Conclusion:**

By mathematical induction, $T(n) = 5n$ holds for all $n\ge 1$.

---
**Example 2: Divide-and-Conquer Recurrence Relation**

*Recurrence Relation:* $T(n) = 2T(\frac{n}{2}) + n$, with $T(1) = 1$, where $n$ is a power of 2.

*Prove that:* $T(n) = n\log_2n + n$.

*Proof by Induction:*

**Base Case ($n=1$):**
- $T(1) = 1$ (given).
- Closed-form formula: $1 \times log_21 + 1 = 0 + 1 = 1$.
- Therefore, $T(1) = 1$, so the base case holds.

**Inductive Step:**
- *Inductive Hypothesis:* Assume $T(k) = k\log_2k + k$ for $k = \frac{n}{2}$.
- *Show that:* $T(n) = n\log_2n + n$.

Compute $T(n)$:
$$
\begin{aligned}
T(n) &= 2T\left(\frac{n}{2}\right) + n \\
&= 2\left[\frac{n}{2}\log_2 \left(\frac{n}{2}\right)+\frac{n}{2}\right] + n \text{  (using the inductive hypothesis)} \\
&= n[\log_2n -1] + n + n \\
&= n(\log_2n - 1) + 2n \\
&= n\log_2n - n + 2n \\
&= n\log_2n + n
\end{aligned}
$$

Thus, $T(n) = n\log_2n + n$.

**Conclusion:**

By mathematical induction, $T(n) = n\log_2n + n$ holds for all $n$ that are powers of 2.

---
***Example 3: Summation of Squares**

*Recurrence Relation:* $T(n) = T(n-1) + n^2$, with $T(1) = 1$.

*Prove that:* $T(n) = \frac{n(n+1)(2n+1)}{6}$.

*Proof by Induction:*

**Base Case (n = 1):**
- $T(1) = 1$ (given).
- Closed-form formula: $\frac{1 \times 2 \times 3}{6} = 1$.
- Therefore, $T(1) = 1$, so the base case holds.

**Inductive Step:**
- *Inductive Hypothesis:* Assume $T(k) = \frac{k(k+1)(2k+1)}{6}$ for some integer $k\ge 1$.
- *Show that:* $T(k+1) = \frac{(k+1)(k+2)(2k+3)}{6}$.

Compute $T(k+1)$:
$$
\begin{aligned}
T(k+1) &= T(k) + (k+1)^2 \\
&= \frac{k(k+1)(2k+1)}{6} + (k+1)^2 \text{ (using the inductive hypothesis)} \\
&= \frac{k(k+1)(2k+1)+6(k+1)^2}{6} \\
&= \frac{(k+1)[k(2k+1)+6(k+1)]}{6} \\
\end{aligned}
$$

Simplify the numerator:
$$
\begin{aligned}
k(2k+1)+6(k+1) &= 2k^2 + k + 6k + 6 \\
&= 2k^2 + 7k + 6. \\
\end{aligned}
$$

Factor $2k^2 + 7k + 6$:
$$
(2k+3)(k+2) = 2k^2 + 4k + 3k + 6 = 2k^2 + 7k + 6
$$

Thus,
$$
T(k+1) = \frac{(k+1)(2k+3)(k+2)}{6}
$$

Therefore, the formula holds for $k+1$.

**Conclusion:**

By mathematical induction, $T(n) = \frac{n(n+1)(2n+1)}{6}$ holds for all $n\ge 1$

---
### 4. Practice three proofs of varying levels of complexity (within the expected skill level of a second-year computer science student.)

**Proof 1 (Basic Level)**

*Recurrence Relation:* $T(n) = T(n-1) + 4$, with $T(0) = 0$.

*Prove that:* $T(n) = 4n$.

*Proof:*

**Base Case $(n = 0)$:**
- $T(0) = 0$ (given).
- Closed-form formula: $4 \times 0 = 0$.
- Therefore, $T(0) = 0$, so the base case holds.

**Inductive Step:**
- *Inductive Hypothesis:* Assume $T(k) = 4k$ for some integer $k\ge 0$.
- *Show that:* $T(k+1) = 4(k+1)$.

Compute $T(k+1)$:
$$
\begin{aligned}
T(k+1) &= T(k) + 4 \\
&= 4k + 4 \text{ (using the inductive hypothesis)} \\
&= 4(k+1) 
\end{aligned}
$$

Thus, $T(k+1) = 4(k+1)$.

**Conclusion:**

By induction, $T(n) = 4n$ holds for all $n\ge 0$.

---
**Proof 2 (Intermediate Level)**

*Recurrence Relation:* $T(n) = 3T(n-1)$, with $T(0) = 2$.

*Prove that:* $T(n) = 2 \times 3^n$.

*Proof:*

**Base Case $(n=0)$:**
- $T(0) = 2$ (given).
- Closed-form formula: $2 \times 3^0 = 2 \times 1 = 2$
- Therefore, $T(0) = 2$, so the base case holds.

**Inductive Step:**
- *Inductive Hypothesis:* Assume $T(k) = 2 \times 3^k$ for some integer $k \ge 0$.
- *Show that:* $T(k+1) = 2 \times 3^{k+1}$.

Compute $T(k+1)$:
$$
\begin{aligned}
T(k+1) &= 3T(k) \\
&= 3 \times 2 \times 3^k \text{ (using the inductive hypothesis)} \\
&= 2 \times 3^{k+1}.
\end{aligned}
$$

Thus, $T(k+1) = 2 \times 3^{k+1}$.

**Conclusion:**

By induction, $T(n) = 2 \times 3^n$ holds for all $n\ge 0$.

---
**Proof 3 (Advanced Level)**

*Recurrence Relation:* $T(n) = T(n-1) + \frac{1}{n(n+1)}$, with $T(1) = \frac{1}{2}$.

*Prove that:* $T(n) = 1 - \frac{1}{n+1}$.

*Proof:*

**Base Case $(n = 1)$:**
- $T(1) = \frac{1}{2}$ (given).
- Closed-form formula: $1-\frac{1}{1+1} = 1 - \frac{1}{2} = \frac{1}{2}$.
- Therefore, $T(1) = \frac{1}{2}$, so the base case holds.

**Inductive Step:**
- *Inductive Hypothesis:* Assume $T(k) = 1 - \frac{1}{k+1}$ for some integer $k\ge 1$.
- *Show that:* $T(k+1) = 1 - \frac{1}{k+2}$.

Compute $T(k+1)$:
$$
\begin{aligned}
T(k+1) &= T(k) + \frac{1}{(k+1)(k+2)} \\
&= \left(1 - \frac{1}{k+1}\right) + \frac{1}{(k+1)(k+2)} \text{ (using the inductive hypothesis)} \\
&= 1 - \frac{1}{k+1} + \frac{1}{(k+1)(k+2)} \\
&= 1 - \frac{(k+2) - 1}{(k+1)(k+2)} \\
&= 1 - \frac{(k+1)}{(k+1)(k+2)} \\
&= 1 - \frac{1}{k+2}.
\end {aligned}
$$

Thus, $T(k+1) = 1 - \frac{1}{k+2}$

**Conclusion:**

By induction, $T(n) = 1 - \frac{1}{n+1}$ holds for all $n \ge 1$.