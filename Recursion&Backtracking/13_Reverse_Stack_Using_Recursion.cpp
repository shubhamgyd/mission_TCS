// In this problem we are going to reverse stack using recursion

#include<bits/stdc++.h>
using namespace std;


void Insert(int val,stack<int>&st)
{
    if(st.size()==0)
    {
        st.push(val);
        return;
    }
    int temp=st.top();
    st.pop();
    Insert(val,st);
    st.push(temp);
    return;
}

void Reverse(stack<int>&st)
{
    if(st.size()==0)
    {
        return;
    }
    int val=st.top();
    st.pop();
    Reverse(st);
    Insert(val,st);
    return;
}

int main()
{
    int n;
    cin>>n;
    stack<int>st;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        st.push(a);
    }
    Reverse(st);
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}

/*
Time complexity" O(n^2)
*/