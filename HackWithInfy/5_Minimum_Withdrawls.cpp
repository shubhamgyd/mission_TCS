/*
There is a unique ATM in Wonderland. Imagine this ATM as an array of numbers. You can withdraw cash only from either ends of the array. Sarah wants to withdraw X amount of cash from the ATM. What are the minimum number of withdrawals Sarah would need to accumulate X amount of cash. If it is not possible for Sarah to withdraw X amount, return -1.

Input Format
The first line contains an integer, N, denoting the number of elements in ATM.
Each line i of the N subsequent lines (where 0 <= i < N) contains an integer describing the cash in ATM.
The next line contains an integer, X, denoting the total amount to withdraw.

Constraints
1 <= N <= 10^5
1 <= ATM[i] <= 10^5
1 <= X <= 10^5
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int soln(int start,int end,vector<int>res,int target,map<vector<int>,int>&mp)
{
    if(target==0)
    {
        return 0;
    }
    if(start>end || target<0)
    {
        return 1e9;
    }
    if(mp.find({start,end,target})!=mp.end())
    {
        return mp[{start,end,target}];
    }
    int takenFront=1+soln(start+1,end,res,target-res[start],mp);
    int takenEnd=1+soln(start,end-1,res,target-res[end],mp);
    return mp[{start,end,target}]=min(takenFront,takenEnd);
}


void solve(vector<int>&res,int n,int x)
{
    map<vector<int>,int>mp;
    ll l=1e9;
    int ans=soln(0,n-1,res,x,mp);
    if(ans>=l)
    {
        cout<<-1<<endl;
    }
    else{
        cout<<ans<<endl;
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int>res(n);
    for(int i=0;i<n;i++)
    {
        cin>>res[i];
    }
    int x;
    cin>>x;
    solve(res,n,x);

}