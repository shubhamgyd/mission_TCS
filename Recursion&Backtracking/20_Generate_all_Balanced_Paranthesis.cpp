/*
In this problem we are going to generate all the valid balance paranthesis
*/
#include<bits/stdc++.h>
using namespace std;

void solve(int op,int cl,string ot)
{
    if(op==0 && cl==0)
    {
        cout<<ot<<endl;
        return;
    }
    if(op!=0)
    {
        string op1=ot;
        op1.push_back('(');
        solve(op-1,cl,op1);
    }
    if(cl>op)
    {
        string op2=ot;
        op2.push_back(')');
        solve(op,cl-1,op2);
    }
    return;

}

int main()
{
    int n;
    cin>>n;
    int open=n,close=n;
    solve(open,close,"");
    return 0;
}

// Time complexity: O(2^n*n)