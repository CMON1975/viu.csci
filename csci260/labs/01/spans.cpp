#include "spans.h"
#include <stack>
#include <vector>

// quadratic algorithm function: O(n^2)
void calculateSpanQuadratic(double X[], int size, int S[])
{
    for (int i = 0; i < size; i++)
    {
        S[i] = 1;
        for (int j = i - 1; j >= 0 && X[j] <= X[i]; j--)
        {
            S[i]++;
        }
    }
}

// linear algorithm: O(n)
void calculateSpanLinear(double X[], int size, int S[])
{
    std::stack<int> st;
    for (int i = 0; i < size; i++)
    {
        while (!st.empty() && X[st.top()] <= X[i])
        {
            st.pop();
        }
        S[i] = (st.empty()) ? (i + 1) : (i - st.top());
        st.push(i);
    }
}

// linear algorithm with vector implementation: O(n)
void calculateSpanVector(double X[], int size, int S[])
{
    std::vector<int> vec;
    for (int i = 0; i < size; i++)
    {
        auto it = vec.rbegin();
        while (it != vec.rend() && X[*it] <= X[i])
        {
            ++it;
        }
        vec.erase(it.base(), vec.end());
        S[i] = (vec.empty()) ? (i + 1) : (i - vec.back());
        vec.push_back(i);
    }
}
