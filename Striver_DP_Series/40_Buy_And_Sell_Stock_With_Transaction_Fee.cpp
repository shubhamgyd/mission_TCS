// Same as Q.36
// just we have to deduct the transaction fee from profit

#include<bits/stdc++.h>
using namespace std;



long solve(int i,int buy,vector<int>&value,int fee,int n,vector<vector<long>>&dp)
{
    if(i==n) return 0;
    if(dp[i][buy]!=-1) return dp[i][buy];
    long profit=0;
    // want to buy
    if(buy)
    {
        profit=max(-value[i]-fee+solve(i+1,0,value,fee,n,dp),solve(i+1,1,value,fee,n,dp));
    }
    // already buy and want to sell
    else
    {
        profit=max(value[i]+solve(i+1,1,value,fee,n,dp),solve(i+1,0,value,fee,n,dp));
    }
    return dp[i][buy]=profit;
}
int maximumProfit(int n, int fee, vector<int> &prices) {
    // Write your code here.
    vector<vector<long>>dp(n+2,vector<long>(2,-1));
    return solve(0,1,prices,fee,n,dp);
}