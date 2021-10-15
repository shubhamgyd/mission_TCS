// In this problem we are going to reverse the stack by using the recursion
#include<bits/stdc++.h>
using namespace std;

void insert_at_bottom(stack<int>&s,int x)
{
    if(s.empty())
    {
        s.push(x);
    }
    else
    {
        int z=s.top();
        s.pop();
        insert_at_bottom(s,x);
        s.push(z);
    }
}

void reversed(stack<int>&s)
{
    if(s.size()>0)
    {
        int x=s.top();
        s.pop();
        reversed(s);

        insert_at_bottom(s,x);
    }
}

int main()
{
    stack<int>s;
    for(int i=1;i<=5;i++)
    {
        s.push(i);
    }
    // while(!s.empty())
    // {
    //     cout<<s.top()<<" ";
    //     s.pop();
    // }
    reversed(s);
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}