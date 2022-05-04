/*
This problem was asked by Facebook.

Given an array of numbers representing the stock prices of a company in chronological order and an integer k, return the maximum profit you can make from k buys and sells. You must buy the stock before you can sell it, and you must sell the stock before you can buy it again.

For example, given k = 2 and the array [5, 2, 4, 0, 1], you should return 3.

*/

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&res,int k,int i,int n,int buy)
{
   if(k==0) return 0;
   if(k and n==0) return 0; 
   if(i>=n) return 0;
   int include=0;
   int exclude=0;
   if(res[i]<buy or buy==-1)
   {
       buy=res[i];
       include=solve(res,k,i+1,n,buy);
   }
   else
   {
       exclude=max(res[i]-buy+solve(res,k-1,i+1,n,-1),solve(res,k,i+1,n,buy));
   }
   return max(include,exclude);
}
// Time Complexity:2^n
// Space Complexity:O(2^n) if we consider stack space recursion



// Memoization
int dp[10001][10001];

int mxProfit(vector<int>&res,int k,int i,int n,int buy)
{
   if(k==0) return 0;
   if(k and n==0) return 0; 
   if(i>=n) return 0;
   if(dp[i][k]!=-1) return dp[i][k];
   int include=0;
   int exclude=0;
   if(res[i]<buy or buy==-1)
   {
       buy=res[i];
       include=mxProfit(res,k,i+1,n,buy);
   }
   else
   {
       exclude=max(res[i]-buy+mxProfit(res,k-1,i+1,n,-1),mxProfit(res,k,i+1,n,buy));
   }
   return dp[i][k]=max(include,exclude);
}
// Time Complexity:O(n*n)
// Space Complexity:O(n*n)



int main()
{
    int n,k;
    cin>>n>>k;
    vector<int>res(n);
    for(int i=0;i<n;i++)
    {
        cin>>res[i];
    }
    if(2*k>n)
    {
        cout<<0<<endl;
    }
    memset(dp,-1,sizeof(dp));
    int buy=res[0];
    int ans=solve(res,k,1,n,buy);
    cout<<ans<<endl;



    int sum=mxProfit(res,k,1,n,buy);
    cout<<sum<<endl;
    return 0;
}