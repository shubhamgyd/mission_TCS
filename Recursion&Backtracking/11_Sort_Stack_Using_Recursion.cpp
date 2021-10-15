// In this problem we are going to sort the stack using recursion

#include<bits/stdc++.h>
using namespace std;


void Insert(int data,stack<int>&st)
{
    //cout<<"Hello"<<endl;
    if(st.top()<=data || st.size()==0)
    {
        st.push(data);
        return;
    }
    int val=st.top();
    st.pop();
    Insert(data,st);
    st.push(val);
    return;
}

void SortStack(stack<int>&st)
{
    
    if(st.size()<=1)
    {
        return;
    }
    int temp=st.top();
    st.pop();
    SortStack(st);
    Insert(temp,st);
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
    SortStack(st);
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}

/*
time complexity will be O(n^2).
Its because n calls for sortStack function & for each of the call, 
sortedInsert is of the order of n. So, the overall complexity will be O(n^2).
*/