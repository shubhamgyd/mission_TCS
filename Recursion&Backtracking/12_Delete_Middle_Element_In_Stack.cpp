// In this problem we are going to delete the middle element from the stack

#include<bits/stdc++.h>
using namespace std;

void DeleteK(stack<int>&st,int k)
{
    if(k==1)
    {
        st.pop();
        return;
    }
    int temp=st.top();
    st.pop();
    DeleteK(st,k-1);
    st.push(temp);
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
    int k;
    k=st.size()/2+1;
    DeleteK(st,k);
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}

/*
Time Complexity: O(n)
*/