# Lecture 31
## P and NP
- **Polynomial Time (P):**
    - Class of decision problems that can be solved by a deterministic Turing machine in polynomial time.
    - A problem is in P if there exists an algorithm that solves it in time $O(n^k)$ for some constant $k$, where $n$ is the size of the input.
- **Non-deterministic Polynomial Time (NP):**
    - Class of deicison problems for which a solution can be *verified* in polynomial time by a deterministic Turing machine.
    - Alternatively, problems that can be solved in polynomial time by a non-deterministic Turing machine.
- **Definition of Polynomial Time:**
    - An algorithm runs in polynomial time if its running time is upper-bounded by a polynomial expression in the size of the input.
- **Relationship to Turing Machines:**
    - **Deterministic Turing Machines:** A theoretical model of computation that performs a predetermined sequence of operations.
    - **Non-deteministic Turing Machine:** A theoretical model that can explore many computation paths simultaneously.
- **NP-Complete Problems:**
    - The hardest problems in NP; if any NP-complete problem is solvable in polynomial time, all problems in NP are.
    - **Satisfiability Problem (SAT):**
        - Determines if there exists an assignment of truth values to variables that makes a Boolean formula true.
    - **3-SAT:**
        - A specific type of SAT where the formula is in conjunctive normal form with exactly three literals per cluase.
    - **Conjunctive Normal Form (CNF):**
        - A way of structuring Boolean expressions as an AND of ORs.
        - Any Boolean expression can be transformed into CNF.

---