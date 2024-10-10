## Day 5: Master Theorem and Recurrence Relations
- **Topics Covered**:
    - Solving recurrence relations using the Master Theorem.
    - Applying it to divide-and-conquer algorithms.
- **Study Activities**:
    - **Master Theorem Cases**: Review the three cases and their conditions.
    - **Problem Solving**: Solve various recurrence relations using the Master Theorem.
    - **Understanding Limitations**: Identify when the Master Theorem cannot be applied.
- **Practice**:
    - Derive the time complexity of given recursive algorithms.
    - Create your own recurrence relations and solve them.

1. What are the three cases of the Master Theorem and what are their conditions?
The Master Theorem  provides a method to determine the time complexity of recursive algorithms, particulalry those that divide problems into smaller subproblems of the same type. It applies to recurrences of the form:
$$
T(n)=aT(\frac{n}{b}) + f(n)
$$
where:
- $a\ge 1$: Number of recursive subproblems.
- $b>1$: Factor by which the problem size is reduced in each subproblem.
- $f(n)$: Cost of work done outside the recursive calls (e.g., dividing the problem, combining the results).

The theorem compares $f(n)$ with $n^{\log_ba}$, which represents the work done by the recursive calls.

The three cases of the Master Theorem and their conditions are:

### Case 1:
**Condition**:
$$
f(n)=O(n^{\log_ba-\epsilon}) \text{ for some } \epsilon>0
$$
- **Explanation:** The function $f(n)$ grows polynomially slower than $n^{\log_ba}$
**Result**:
$$
T(n) = \Theta(n^{\log_ba})
$$
- **Interpretation:** The total complexity is dominated by the work done within the recursive calls.

### Case 2:
**Condition**:
$$
f(n) = \Theta(n^{\log_ba}\log^{k+1}n) \text{ for some } k\ge0
$$
- **Explanation:** The function $f(n)$ grows at the same rate (up to a logarithmic factor) as $n^{\log_ba}$.
- **Result:**
$$
T(n) = \Theta(n^{\log_ba}\log^{k+1}n)
$$
- **Interpretation:** The total complexity includes an extra logarithmic factor due to both the recursive calls and the work $f(n)$.

### Case 3:
**Conditions:**
1. **Growth Condition:**
$$
f(n) = \Omega(n^{\log_ba+\epsilon}) \text{ for some } \epsilon > 0
$$
    - **Explanation:** The function $f(n)$ grows polynomially faster than $n^{\log_ba}$.
2. **Regularity (Smoothness) Condition:**
$$
af(\frac{n}{b})\le cf(n) \text{ for some constant } c<1 \text{ and sufficiently large }n
$$
    - **Explanation:** Ensures that $f(n)$ does not decrease too rapidly as $n$ decreases.

**Result:**
$$
T(n)=\Theta(f(n))
$$
- **Interpretation:** The total complexity is dominated by the work $f(n)$ done outside the recursive calls.

**Summary of Conditions and Outcomes:**
- **Case 1:** If $f(n)$ grows slower than $n^{\log_ba}$ (by a polynomial factor), then the recursive work dominates.
- **Case 2:** If $f(n)$ grows at the same rate as $n^{\log_ba}$ (possibly time a logarithmic factor), then both the recursive work and $f(n)$ contribute equally to the total complexity.
- **Case 3:** If $f(n)$ grows faster than $n^{\log_ba}$ (by a polynomial factor) and satisfies the regularity condition, then $f(n)$ dominates the total complexity.

**Note:** The Master Theorem does not apply if $f(n)$ does not satisfy the regularity condition in Case 3 or if the recurrence does not fit the specified form.

---
2. Solve three recurrence relations using the Master Theorem.
### Problem 1:
$T(n)=2T(\frac{n}{2})+n$

**Solution:**
1. **Identify the parameters:**
    - $a = 2$: Number of subproblems.
    - $b = 2$: Factor by which the problem size is reduced.
    - $f(n) = n$: Cost of the work done outside the recursive calls.
2. **Compute $n^{\log_ba}$:**
    - $\log_ba = \log_22 = 1$.
    - Therefore, $n^{\log_ba} = n^1 = n$.
3. **Compare $f(n)$ with $n^{\log_ba}$:**
    - $f(n) = n$.
    - $n^{\log_ba} = n$.
    - So, $f(n)=\Theta(n^{\log_ba})$.
4. **Determine the applicable case:**
    - This matches **Case 2** of the Master Theorem, where $f(n)=\Theta(n^{\log_ab}\log^kn)$ with $k=0$.
5. **Apply the result of Case 2:**
    - $T(n) = \Theta(n^{\log_ba}\log^{k+1}n)$.
    - Substituting values: $T(n)=\Theta(n\log n)$.

**Answer:**

$T(n)=\Theta(n\log n)$

### Problem 2:
$T(n)=4T(\frac{n}{2})+n^2$

**Solution:**
1. **Identify the parameters:**
    - $a = 4$
    - $b = 2$
    - $f(n) = n^2%

2. **Compute $n^{\log_ba}$:**
    - $\log_ba = \log_24=2$.
    - Therefore, $n^{\log_ba} = n^2$.

3. **Compare $f(n)$ with $n^{\log_ba}$:**
    - $f(n) = n^2$.
    - $n^{\log_ba}=n^2$.
    - So, $f(n)=\Theta(n^{log_ba})$.

4. **Determine the applicable case:**
    - This matches **Case 2** with $k=0$.

5. **Apply the result of Case 2:**
    - $T(n)=\Theta(n^2\log n)$

**Answer:**

$T(n)=\Theta(n^2\log n)$


### Problem 3:

**Solution:**
1. **Identify the parameters:**
    - $a = 3$.
    - $b = 4$.
    - $f(n) = $n\log n$.

2. **Compute $n^{\log_ba}$:**
    - $\log_ba$ = $\log_43\approx 0.792$.
    - Therefore, $n^{\log_ba}=n^{0.792}$

3. **Compare $f(n)$ with $n^{\log_ba}$:**
    - $f(n)=n\log n$
    - Since $n\log n = \Omega(n^{0.792+\epsilon})$ for any $\epsilon< 0.208$ choose $\epsilon=0.1$.
    - Therefore, $f(n)=\Omega(n^{0.892})$.

4. **Check the regularity condition:**
    - Verify that $af(\frac{n}{b})\le cf(n)$ for some constant $c<1$ and sufficiently large $n$.
    - Compute $af(\frac{n}{b}) = 3(\frac{n}{4}\log\frac{n}{4})=\frac{3n}{4}(\log n-\log 4)$.
    - For large $n$, $\frac{3n}{4}(\log n -2) \le cn \log n$.
    - Choose $c=\frac{3}{4}$ (since $\log n - 2 \le \log n$).

5. **Determine the applicable case:**
    - Since $f(n)=\Omega(n^{\log_ba+\epsilon})$ and the regularity condition holds, this fits **Case 3**.
 

6. **Apply the result of Case 2:**
    - $T(n)=\Theta(f(n))=\Theta(n\log n)$.
 

**Answer:**

$T(n)=\Theta(n\log n)$

---
## 3. In what cases can't we apply the Master Theorem?
### Situations Where the Master Theorem Cannot Be Applied
1. **Non-Constant Parameters $a$ or $b$:**
    - **Issue:** The Master Theorem requires that $a\ge 1$ and $b>1$ be constraints.
    - **Example:** $T(n)=nT(\frac{n}{2}) + n$
        - Here, $a=n$, which is not a constant but a function of $n$.
    - **Explanation:** Since $a$ varies with $n$, the standard form of the Master Theorem does not hold.
2. **Recurrence Not in Standard Form:**
    - **Issue:** The recurrence must be of the form $T(n)=aT(\frac{n}{b})+f(n)$.
    - **Examples:** 
        - **Different Subproblem Sizes:** $T(n) = T(\frac{n}{2})+T(\frac{n}{3})+n$
            - Subproblems are of different sizes ($n/2$ and $n/3$).
        - **Non-Division of $n$:** $T(n)=2T(\sqrt n)+n$
            - The subproblem size is $\sqrt n$, not $n$ divided by a constant.
    - **Explanation:** The Master Theorem assumes equal division of the problem size by a constant factor.
3. **Subproblem Sizes Not Decreasing:**
    - **Issue:** The subproblem size must decrease in each recursive call.
    - **Example:** $T(n) = T(2n/3)+n$
        - Here, $n$ is reduced to ($2n/3$), which is less than $n$, so this is acceptable.
        - However, if $T(n)=T(2n)+n$, the subproblem size increases.
    - **Explanation:** The Master Theorem does not handle cases where the subproblem size does not decrease.
4. **Negative or Zero Values of $a$ or $b$:**
    - **Issue:** The constants $a$ and $b$ must satisfy $a\ge1$ and $b>1$.
    - **Example:** $T(n) = 0.5T(\frac{n}{2})+n$
        - Here, $a=0.5$, which is less than 1.
    - **Explanation:** The value of $a<1$ implies that the algorithm combines results from less than one subproblem, which is not meaningful in this context.
5. **Irregular or Non-Polynomial f(n):**
    - **Issue:** The function $f(n)$ must be polynomially related to $n^{\log_ba}$.
    - **Examples:**
        - **Exponential** $f(n):T(n)=2T(\frac{n}{2})+2^n$
        - **Oscillating** $f(n):T(n)=2T(\frac{n}{2})+n\sin n$
    - **Explanation:** If $f(n)$ grows faster than any polynomial (e.g., exponentially) or is not comparable to $n^{\log_ba}$ using Big O notation, the Master Theorem does not apply.
6. **Failure of the Regularity Condition in Case 3:**
    - **Issue:** For Case 3, the regularity condition must hold $af(\frac{n}{b})\le cf(n)$ for some $c<1$
    - **Example:** $T(n)=2T(\frac{n}{2})+n^2\log n$
        - Here, $f(n)=n^2\log n$, and $n^{\log_ba}=n^1=n$.
        - Since $f(n)=\Omega(n^{log_ba+\epsilon})$ with $\epsilon = 1$, we check the regularity condition.
        - Calculating $af(\frac{n}{b})=2\left((\frac{n}{2})^2\log \frac{n}{2}\right)=\frac{n^2}{2}(\log n -1)$
        - For lage $n$, $\frac{n^2}{2}(\log n -1)>cn^2\log n$ for any $c<1$.
    - **Explanation:** Since the regularity condition does not hold, the Master Theorem cannot be applied.
7. **Non-Polynomial Logarithmic Factors:**:
    - **Issue:** The function $f(n)$ contains logarithmic factors that do not fit the conditions.
    - **Example:** $T(n)=2T(\frac{n}{2})+n \log \log n$.
        - $f(n)=\log\log n$ grows slower than $n\log n$.
    - **Explanation:** Comparing $f(n)$ to $n^{log_ba}$ becomes complex when logarithmic functions are involved, and the Master Theorem may not directly apply.
8. **Additional Non-Standard Terms in the Recurrence:**
    - **Issue:** The recurrence includes terms that are not accounted for in the Master Theorem.
    - **Examples:**
        - **Cross-Terms:** $T(n)=T(\frac{n}{2})+T(\frac{n}{4})+n$
        - **Multiplicative Recurrence:** $T(n)=\sqrt n T(\frac{n}{2}) + n$
    - **Explanation:** The prescence of multiple recursive calls with different sizes or multiplicative factors on $T(n)$ invalidates the use of the Master Theorem.
9. **Division by a Function of $n$:**
    - **Issue:** The problem size is divided by a function of $n$, not a constant.
    - **Example:** $T(n)=2T(\frac{n}{\log n})+n$
    - **Explanation:** Since $b=\log n$, which is not constant, the standard form required for the Master Theorem is violated.
10. **Recurrences with Variable Number of Subproblems:**
    - **Issue:** The number of recurse calls $a$ changes with $n$.
    - **Example:** $T(n)=nT(\frac{n}{2})+n$
        - Here, $a=n$, which varies with $n$.
    - **Explanation:** A variable $a$ means the recursion tree has an exponentially growing number of subproblems, which the Master Theorem does not handle.

---
### Understanding The Limitations
The Master Theorem is designed to sovlve recurrences that represent divide-and-conquer algorithms dividing a problem into smaller subproblems of equal size and combining the results in a specific way. When the characteristics of the recurrence deviate from these assumptions, alternative methods are required.

**Alternative Methods Include:**
- **Recursion Tree Method:**
    - Visualizing the recurrence as a tree and summing the costs at each level.
- **Substitution Method:**
    - Making an educated guess about the solution and proving it via mathematical induction.
- **Akra-Bazzi Theorem:**
    - A generalization of the Master Theorem that can handle more complex recurrences.

---
### Examples Illustrating Non-Applicability
1. **Different Subproblem Sizes:**
    - **Recurrence:** $T(n)=T(\frac{n}{2})+T(\frac{2n}{3})+n$
    - **Explanation:** The subproblems are of sizes $n/2$ and $2n/3$, which are not equal or consistent fractions of $n$.
2. **Non-Constant Division Factor:**
    - **Recurrence:** $T(n)=2T(n^{0.9})+n$
    - **Explanation:** The subproblem size is $n^{0.9}$, which is not $n$ divided by a constant.
3. **Multiplicative Factor on $T(n)$:**
    - **Recurrence:** $T(n)=nT(\frac{n}{2})+n$
    - **Explanation:** The $n$ multiplier on $T(n/2)$ is not accounted for in the Master Theorem.

---
### Key Takeaways
- **Check the Form:** Ensure the recurrence matches $T(n)=aT(\frac{n}{b})+f(n)$ with constants $a\ge 1$ and $b>1$.
- **Verify the Conditions:** Confirm that $f(n)$ and the parameters satisfy one of the three cases of the Master Theorem.
- **Be Cautious with $f(n)$:** Functions involving logarithms, exponentials, or non-polynomial growth may require alternative analysis methods.
- **Understanding the Limitations:** Recognize when the theorem does not apply and be prepared to use other techniques.

---
### Conclusion
The Master Theorem is not a one-size-fits-all solution. It is essential to analyze the recurrence carefully and determine whether it fits within the theorem's scope. When it doesn't, leveraging other methods like the recursion tree or substitutuion method will allow you to find the recurrence's solution and understand the algorithm's time complexity.

By being aware of these Limitations, you can avoid common pitfalls and ensure accurate analyses of recursive algorithms.

---
## 4. Derive the time complexity of three recursive algorithms.
### Algorithm 1. Karatsuba's Integer Multiplication
**Description:**
Karatsuba's algorithm multiplies two $n$-digit numbers more efficiently that the standard grade-school method. It reduces the multiplication of two $n$-digit numbers to three multiplications of $n/2$-digit numbers.

**Recurrence Relation:**
$$
T(n)=3T(\frac{n}{2})+cn
$$
- $T(n)$: Time to multiply two $n$-digit numbers.
- $cn$: Time for additions and subtractions (linear time).

**Derivation:**
1. **Identify Parameters:**
    - $a=3$: Number of subproblems.
    - $b=2$: Division factor.
    - $f(n)=cn$: Cost outside recursive calls.
2. **Compute $n^{\log_ba}$:**
    - $\log_ba = \log_23\approx 1.58496$
    - $n^{\log_ba} = n^{1.58496}$
3. **Compare $f(n)$ with $n^{\log_ba}$:**
    - $f(n)=cn=O(n^1)$.
    - Since $n^1=O(n^{\log_ba-\epsilon})$ for $\epsilon \approx 0.58496$, this fits **Case 1** of the Master Theorem.
4. **Apply Master Theorem (Case 1):**
    - $T(n)=\Theta(n^{\log_ba})=\Theta(n^{1.58496})$

**Time Complexity:**
$$
T(n)=\Theta(n^{\log_23})\approx \Theta(n^{1.585})
$$

---
### Algorithm 2. Towers of Hanoi
**Description:**
The Towers of Hanoi is a classic problem involving moving $n$ disks from one peg to another, following specific rules.

**Recurrence Relation:**
$$
T(n)=2T(n-1)+c
$$
- $T(n)$: Time to solve the problem with $n$ disks.
- $c$: Constant time to move one disk.

**Derivation:**
This recurrence does not fit the Master Theorem because the subproblem size decreases by 1, not by a constant factor of $n$.

**Solution via Iterative Substitution:**
1. **Expand the Recurrence:**
$$
\begin{aligned}
T(n) &= 2T(n-1)+c \\
&= 2(2T(n-2)+c) +c \\
&= 4T(n-2)+2c+c \\
&= 4(2T(n-3)+c)+3c \\
&= 8T(n-3)+4c+3c \\
&\vdots \\
&=2^kT(n-k)+c\sum^{k-1}_{i=0}2^i
\end{aligned}
$$
2. **Base Case:**
When $k=n$:
- $T(0)$ is a constant (moving zero disks takes zero time).
- Sum of a geometric series:
    $$
    \sum^{n-1}_{i=0} 2^i=2^n-1
    $$

3. **Final Expression:**
$$
T(n)=2^nT(0)+c(2^n-1)
$$
    - Since $T(0)$ is a constant, $T(n) = O(2^n)$.

**Time Complexity:**
$$
T(n)=\Theta(2^n)
$$

---
### Algorithm 3: Quick Sort (Worst-Case Analysis)
**Description:**
Quick Sort is a divide-and-conquer algorithms for sorting arrays. In the worst case, the pivod divides the array into one subarray of size $n-1$ and one of size 0 (e.g., when the smallest or largest element is always chosen as the pivot).

**Recurrence Relation:**
$$
T(n)=T(n-1)+cn
$$
- $T(n)$: Time to sort an array of size $n$.
- $cn$: Time to partition the array.

**Derivation:**
This recurrence does not fit the Master Theorem due to the decrement of 1 in subproblem size.

**Solution via Iterative Substitution:**
1. **Expand the Recurrence:**
$$
\begin{aligned}
T(n) &= T(n-1)+cn \\
&= (T(n-2)+c(n-1))+cn \\
&= T(n-2)+c(n-1+n) \\
&= T(n-2)+c(2n-1) \\
&= (T(n-3)+c(n-2))+c(2n-1) \\
&= T(n-3)+c(n-2+2n-1) \\
&= T(n-3)+c(3n-3) \\
&\vdots \\
&= T(1) + c\sum^n_{k=2}k
\end{aligned}
$$

2. **Compute the Sum:**
    - Sum of integers from 2 to $n$:
$$
\sum^n_{k=2}k=\frac{n(n+1)}{2}-1
$$

3. **Final Expression:**
$$
T(n)=T(1) + c\left(\frac{n(n+1)}{2}-1\right)
$$
    - Since $T(1)$ is a constat, $T(n)=O(n^2)$.

**Time Complexity:**
$$
T(n)=\Theta(n^2)
$$

---
## 5. How can I create my own recurrence relations?
Creating you own recurrence relations involves modeling the behavior of recursive algorithms or processes to analyze their time or space complexity. Here's how you can create them:

---
### Steps to Create Recurrence Relations
1. **Understand the Algorithm's Structure:**
    - **Identify the Recursive Calls:** Determine how many times the function calls itself recursively.
    - **Determine Subproblem Sizes:** Find out how the size of the input decreases with each recursive call.
2. **Identify the Base Case:**
    - Establish the simplest case where the problem can be solved directly without further recursion (e.g., $T(1)$ or $T(0)$).
3. **Determine the Cost of Each Component:**
    - **Recursive Cost ($aT(\frac{n}{b})$):** Based on the number of recursive calls ($a$) and the factor by which the problem size reduces ($b$).
    - **Non-Recursive Work ($f(n)$):** Calculate the time spent on dividing the problem and combining results outside of the recursive calls.
4. **Formulate the Recurrence Relation:**
    - Combine the recursive and non-recursive costs into a recurrence of the form:
        $$
        T(n)=aT(\frac{n}{b})+f(n)
        $$
        - $T(n)$: Total time to solve a problem of size $n$.
        - $a$: Number of subproblems.
        - $\frac{n}{b}$: Size of each subproblem.
        - $f(n)$: Cost of work done outside the recursive calls.
5. **Include the Base Case(s):**
    - Specify $T(n)$ for the smalles input size(s) where the recursion ends.

---
### Example: Creating a Recurrence for Merge Sort
**Algorithm Overview:**
    - **Divide:** Split the array into two halves.
    - **Conquer:** Recursively sort each half.
    - **Combine:** Merge the two sorted halves into one sorted array.

**Steps:**
1. **Recursive Calls:**
    - The algorithm makes 2 recursive valls (one for each half).
2. **Subproblem Size:**
    - Each subarray is of size $\frac{n}{2}$.
3. **Non-Recursive Work:**
    - Merging two sorted arrays takes $O(n)$ time.
4. **Formulate the Recurrence:**
$$
T(n)=2T(\frac{n}{2})+n
$$
5. **Base Case:**
    - When $n=1$, the array is already sorted:
        $$
        T(1)=c \text{ (constant time)}
        $$

---
### Tips for Creating Recurrence Relations
- **Be Precise with Subproblem Sizes:**
    - Ensure you correctly represent how the input size changes with each recursive call.
- **Account for All Costs:**
    - Include the costs of all significant operations, especially those outside the recursive calls.
- **Consider Different Cases if Necessary:**
    - Some algorithms may have best, average, and worst-case scenarios that require different recurrences.
- **Check for Non-Standard Forms:**
    - If the algorithm doesn't fit the standard divide-and-conquer pattern, adjust the recurrence accordingly.
- **Validate with Small Inputs:**
    - Test your recurrence relation with small values of $n$ to ensure it accurately reflects the algorithm's behavior.

---
### Common Patterns in Recurrence Relations
- **Binary Search:**
    $$
    T(n)=T(\frac{n}{2})+c
    $$
- **Exponentiation by Squaring:**
    $$
    T(n)=T(\frac{n}{2})+c
    $$
- **Strassen's Matrix Multiplication:**
    $$
    T(n)=7T(\frac{n}{2})+cn^2
    $$
- **Fibonacci Sequence (Recursive Computation):**
    $$
    T(n)=T(n-1)+T(n-2)+c
    $$

---
### Conclusion
By thoroughly analyzing the recursive structure and costs associated with each part of your algorithm, you can construct a recurrence relation that models its performance. This relation is a crucial step in determining the algorithm's efficiency and can be solved using various methods to find its time complexity.