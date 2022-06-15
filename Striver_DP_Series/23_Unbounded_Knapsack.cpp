/*
Problem Statement
You are given ‘N’ items with certain ‘PROFIT’ and ‘WEIGHT’ and a knapsack with weight capacity ‘W’. You need to fill the knapsack with the items in such a way that you get the maximum profit. You are allowed to take one item multiple times.
For Example
Let us say we have 'N' = 3 items and a knapsack of capacity 'W' =  10
'PROFIT' = { 5, 11, 13 }
'WEIGHT' = { 2, 4, 6 }

We can fill the knapsack as:

1 item of weight 6 and 1 item of weight 4.
1 item of weight 6 and 2 items of weight 2.
2 items of weight 4 and 1 item of weight 2.
5 items of weight 2.

The maximum profit will be from case 3 i.e ‘27’. Therefore maximum profit = 27.
*/
#include<bits/stdc++.h>
using namespace std;

// Recursion 
int unBounded(int n,int w,int weight[],int value[])
{
    // base case, if goes out of bound
    // or weight becomes zero
    if(n==0 or w==0)
    {
        return 0;
    }

    // if weight is greater than the remaining weight,
    // just ignore it
    if(weight[n-1]>w)
    {
        return unBounded(n-1,w,weight,value);
    }

    // now we have two choices , either we can include or 
    // exlude current weight to achieve maximum profit
    return max(value[n-1]+unBounded(n,w-weight[n-1],weight,value),unBounded(n-1,w,weight,value));
}
// Time Complexity:Exponential
// Space Complexity:O(W) ,for stack space 



// Memoization
int memoization(int n,int w,int weight[],int value[],vector<vector<int>>&dp)
{
    // base case, if goes out of bound
    // or weight becomes zero
    if(n==0 or w==0)
    {
        return 0;
    }
    if(dp[n][w]!=-1)
    {
        return dp[n][w];
    }

    // if weight is greater than the remaining weight,
    // just ignore it
    if(weight[n-1]>w)
    {
        dp[n][w]=memoization(n-1,w,weight,value,dp);
    }

    // now we have two choices , either we can include or 
    // exlude current weight to achieve maximum profit
    else
    { 
        dp[n][w]=max(value[n-1]+memoization(n,w-weight[n-1],weight,value,dp),memoization(n-1,w,weight,value,dp));
    }
    return dp[n][w];

}
// Time Complexity:O(n*w)
// Space Complexity:O(n*w)



// Tabulation Method

int Tabulation(int n,int w,int weight[],int value[])
{
    int dp[w+1];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<=w;i++)
    {
        for(int j=0;j<n;j++)
        {
            // if current wight is less than remaining weight
            // we have two choices , either we can add or we can ignore
            if(weight[j]<=i)
            {
                dp[i]=max(dp[i],value[j]+dp[i-weight[j]]);
            }
        }
    }
    return dp[w];
}
// Time Complexity:O(n*w)
// Space Complexity:O(W)



int main()
{
    int n=3;
    int value[3]={7,2,4};
    int weight[3]={5,10,20};
    int w=15;
    int ans=unBounded(n,w,weight,value);
    cout<<"Maximum Weight(Recursion): "<<ans<<endl;


    vector<vector<int>>dp(n+1,vector<int>(w+1,-1));
    int ans1=memoization(n,w,weight,value,dp);
    cout<<"Maximum Weight(Memoization): "<<ans1<<endl;

    int ans2=Tabulation(n,w,weight,value);
    cout<<"Maximum Weight(Memoization): "<<ans2<<endl;
    return 0;
}