#include <stack>
// quadratic algorithm function: O(n^2)
void calculateSpanQuadratic(double X[], int size, int S[])
{
    for (int i = 0; i < size; i++)
    {
        // initialize span for X[i]
        S[i] = 1;

        // move backwards checking elements
        for (int j = i - 1; j >= 0 && X[j] <= X[i]; j--)
        {
            S[i]++;
        }
    }
}
// linear algorithm: O(n)
#include <stack>

void calculateSpanLinear(double X[], int size, int S[])
{
    std::stack<int> st; // stack stores element indices

    for (int i = 0; i < size; i++)
    {
        // pop elements from the stack while the current element X[i] is greater
        // than or equal to the element corresponding to the index at the top of the stack
        while (!st.empty() && X[st.top()] <= X[i])
        {
            st.pop();
        }

        // measure span:
        // if stack is empty, all previous elements are smaller, so the span is i + 1
        // else span is the difference between the current index i and the index of the top element in the stack
        S[i] = (st.empty()) ? (i + 1) : (i - st.top());

        // push the current index onto the stack
        st.push(i);
    }
}

// linear algorithm with vector implementation: O(n)
#include <vector>

void calculateSpanVector(double X[], int size, int S[])
{
    std::vector<int> vec; // vector stores indices

    for (int i = 0; i < size; i++)
    {
        // use iterators to traverse and remove elements from vec
        auto it = vec.rbegin();
        while (it != vec.rend() && X[*it] <= X[i])
        {
            ++it;
        }
        vec.erase(it.base(), vec.end()); // remove using iterator

        // calculate the span using the iterators
        S[i] = (vec.empty()) ? (i + 1) : (i - vec.back());

        // push the current index onto the vector
        vec.push_back(i);
    }
}
