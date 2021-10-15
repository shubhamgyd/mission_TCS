// In this problem we are going to sort the stack

#include <bits/stdc++.h>
using namespace std;
stack<int> s;
void sort()
{
    stack<int> m;
    while (!s.empty())
    {
        int temp = s.top();
        s.pop();
        while (!m.empty() && m.top() > temp)
        {
            s.push(m.top());
            m.pop();
        }
        m.push(temp);
    }
    while (!m.empty())
    {
        cout << m.top() << " ";
        m.pop();
    }
}