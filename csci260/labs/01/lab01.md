## Problem Description
Given an array `X`, the span `S[i]` of `X[i]` is the maximum number of consecutive elements `X[j]` immediately preceding `X[i]` and such that `X[j] <= X[i]`
## What Needs to be Done
Develop a C++ function that has an array of `double` numbers and the size of the array as its parameters, and then fill an integer array of the same size the span of each element in the first array.
**Function Prototype:**
    `void calculateSpan(double X[], int size, int S[]);`
First, develop the fucntion using a quadratic algorithm.
Then, develop a linear algorithm to solve the problem using a Stack. Try to analyze why this algorithm is a linear one.
## Submit
Practice submit the solution electronically:
* Gather all the files into one directory.
* Execute `~liuh/bin/submit 260 Lab1 .` 
* `~liuh/bin/checksubmit 260 Lab1` checks the submission status.
