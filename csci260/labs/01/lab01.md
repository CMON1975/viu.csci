## Problem Description
Given an array `X`, the span `S[i]` of `X[i]` is the maximum number of consecutive elements `X[j]` immediately preceding `X[i]` and such that `X[j] <= X[i]`
### Reframed:
You have an array `X`, and for each element `X[i]`, you're trying to figure out how far back you can go while the previous elements are smaller than or equal to `X[i]`. This "distance" is called the span of `X[i]`.
* **Span** means: How many consecutive numbers, including `X[i]` itself, are either smaller than or equal to `X[i]` starting from `X[i]` and moving backwards in the array.
#### Example:
Let's take an example array `X = [6, 3, 4, 5, 2]`
For each element `X[i]`, we will calculate the span `S[i]`.
* For `X[0] = 6`:
    * There are no elements before it, so the span is `1`.
    * `S[0] = 1`.
* For `X[1] = 3`:
    * There is only `X[0] = 6` before it, but `6 > 3`, so it doesn't count. The span is just `1` (itself).
    * `S[1] = 1`.
* For `X[2] = 4`:
    * Look backward from `4`. You can count `X[1] = 3` because `3 <= 4`, but you can't count `X[0] = 3` because `6 > 4`. The span is `2` (itself + one preceding element).
    * `S[2] = 2.`
* For `X[3] = 5`:
    * Look backward from `5`. You can count `X[2] = 4` and `X[1] = 3`, because both are `<= 5`. You can't count `X[0] = 6`. The span is `3`.
    * `S[3] = 3.`
* For `X[4] = 2`:
    * No previous elements are `<= 2`. So the span is just `1` (itself).
    * `S[4] = 1`.

In summary, the span array `S` for `X = [6, 3, 4, 5, 2]` is `[1, 1, 2, 3, 1]`.
## What Needs to be Done
Develop a C++ function that has an array of `double` numbers and the size of the array as its parameters, and then fill an integer array of the same size the span of each element in the first array.
**Function Prototype:**
    `void calculateSpan(double X[], int size, int S[]);`
First, develop the function using a quadratic algorithm.
Then, develop a linear algorithm to solve the problem using a Stack. Try to analyze why this algorithm is a linear one.
## Submit
Practice submit the solution electronically:
* Gather all the files into one directory.
* Execute `~liuh/bin/submit 260 Lab1 .` 
* `~liuh/bin/checksubmit 260 Lab1` checks the submission status.
