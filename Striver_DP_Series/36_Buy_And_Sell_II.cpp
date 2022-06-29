/*
Problem Statement
You have been given stock values/prices for N number of days. Every i-th day signifies the price of a stock on that day. Your task is to find the maximum profit which you can make by buying and selling the stocks.
 Note :
You may make as many transactions as you want but can not have more than one transaction at a time i.e, if you have the stock, you need to sell it first, and then only you can buy it again.
Input Format :
The first line contains an integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains an integer 'N' representing the total number of days for which you have stock prices.

The second line contains 'N' single space-separated integers representing the price of the stock on i-th day.
Output Format :
For each test case, print the maximum profit that you can earn.

Output for every test case will be printed in a separate line.
Note :
You are not required to print anything explicitly. Just implement the function.
Constraints :
1 <= t <= 10^2
0 <= N <= 10^5
Time Limit: 1 sec
Sample Input 1 :
1
7
1 2 3 4 5 6 7
Sample Output 1 :
6
*/

#include<bits/stdc++.h>
using namespace std;



long solve(int i,int buy,long *value,int n,vector<vector<long>>&dp)
{
    if(i==n) return 0;
    if(dp[i][buy]!=-1) return dp[i][buy];
    long profit=0;
    // want to buy
    if(buy)
    {
        profit=max(-value[i]+solve(i+1,0,value,n,dp),solve(i+1,1,value,n,dp));
    }
    // already buy and want to sell
    else
    {
        profit=max(value[i]+solve(i+1,1,value,n,dp),solve(i+1,0,value,n,dp));
    }
    return dp[i][buy]=profit;
}
// T:O(n*2)
// S:O(n*2)+O(n)




long getMaximumProfit(long *values, int n)
{
    //Write your code here
//     vector<vector<long>>dp(100005,vector<long>(2,-1));
//     long ans=solve(0,n,values,0,false,dp);
//     long dp[100005][2];
//     memset(dp,-1,sizeof(dp));
//     return solve(0,1,values,n,dp);
//     return ans;
       long dp[n+1][2];
       memset(dp,0,sizeof(dp));
       dp[n][0]=0;
       dp[n][1]=0;
       for(int i=n-1;i>=0;i--)
       {
           for(int buy=0;buy<=1;buy++)
           {
               long profit=0;
               if(buy)
               {
                   profit=max(-values[i]+dp[i+1][0],dp[i+1][1]);
               }
               else
               {
                   profit=max(values[i]+dp[i+1][1],dp[i+1][0]);
               }
               dp[i][buy]=profit;
           }
       }
    return dp[0][1];
}
// Time Complexity:O(n*2)
// Space Complexity:O(n*2)



// Space Optimize
long getMaximumProfit(long *values, int n)
{
    // Space optimize
    vector<long>ahead(2,0),curr(2,0);
    ahead[0]=ahead[1]=0;
    for(int i=n-1;i>=0;i--)
    {
        for(int buy=0;buy<=1;buy++)
        {
            long profit=0;
            if(buy)
            {
                profit=max(-values[i]+ahead[0],ahead[1]);
            }
            else
            {
                profit=max(values[i]+ahead[1],ahead[0]);
            }
            curr[buy]=profit;
        }
        ahead=curr;
    }
    return ahead[1];
}
// Time Complexity:O(n)
// Space Complexity:O(2)