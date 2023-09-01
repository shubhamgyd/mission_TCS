#include <bits/stdc++.h>
using namespace std;

class MinStack
{
    stack<int> st;
    int mn;

public:
    /** initialize your data structure here. */
    MinStack()
    {
        mn = INT_MAX;
    }

    void push(int val)
    {
        if (val <= mn)
        {
            st.push(mn);
            mn = val;
        }
        st.push(val);
    }

    void pop()
    {
        if (st.top() == mn)
        {
            st.pop();
            mn = st.top();
            st.pop();
        }
        else
        {
            st.pop();
        }
    }
    int top()
    {
        return st.top();
    }

    int getMin()
    {
        return mn;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */