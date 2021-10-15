/*
In this problem we are generating binary number having more thant 1's than 0's
*/

#include<bits/stdc++.h>
using namespace std;

void solve(int one,int zero,int n,string op)
{
    if(n==0)
    {
        cout<<op<<endl;
        return;
    }
    string op1=op;
    op1.push_back('1');
    solve(one+1,zero,n-1,op1);
    if(one>zero)
    {
        string op2=op;
        op2.push_back('0');
        solve(one,zero+1,n-1,op2);
    }
    return;
}

int main()
{
    int n;
    cin>>n;
    string op="";
    int one=0,zero=0;
    solve(one,zero,n,op);
    return 0;
}

/*
Expected Time Complexity: O(|2N|)
Expected Auxiliary Space: O(2N)
*/