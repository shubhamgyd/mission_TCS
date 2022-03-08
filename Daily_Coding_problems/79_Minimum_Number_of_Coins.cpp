/*
This question is asked by Facebook. Given an array that represents different coin 
denominations and an amount of change you need to make, return the fewest number of 
coins it takes to make the given amount of change.
Note: If it is not possible to create the amount of change with the coins you’re given, 
 -1.

Ex: Given the following denominations and amount…

coins = [1,5, 10, 25], amount = 78, return 6
Take three 25 coins and three 1 coins for a total of 6 coins.
*/

#include<bits/stdc++.h>
using namespace std;


// Recursive
int minCount(vector<int>&res,int n,int target)
{
    if(n==0) return INT_MAX;
    if(target==0) return 0;

    if(res[n-1]>target)
    {
        return minCount(res,n-1,target);
    }
    return min(minCount(res,n-1,target),minCount(res,n,target-res[n-1])+1);
}
// Time Complexity:Exponential
// Space Complexity:O(1)



// Memoization
// Top Down
int dp[10001][10001];
int minCount1(vector<int>&res,int n,int target)
{
    if(n==0) return INT_MAX;
    if(target==0) return 0;
    if(dp[n][target]!=-1) return dp[n][target];
    if(res[n-1]>target)
    {
        return dp[n][target]= minCount1(res,n-1,target);
    }
    return dp[n][target]=min(minCount1(res,n-1,target),minCount1(res,n,target-res[n-1])+1);
}
// Time Complexity:O(n*sum)
// Space Complexity:O(n*sum)



// DP_Bottom UP
int minCoins(vector<int>&coins, int M, int V) 
	{ 
	    // Your code goes here
	    int dp[M+1][V+1];
	    for(int i=0;i<=M;i++)
	    {
	        dp[i][0]=0;
	    }
	    for(int j=1;j<=V;j++)
	    {
	        dp[0][j]=INT_MAX-1;
	    }
	    
	    for(int i=1;i<=M;i++)
	    {
	        for(int j=1;j<=V;j++)
	        {
	            if(coins[i-1]<=j)
	            {
	                dp[i][j]=min(dp[i-1][j],dp[i][j-coins[i-1]]+1);
	            }
	            else
	            {
	                dp[i][j]=dp[i-1][j];
	            }
	        }
	    }
	    return dp[M][V]==INT_MAX-1?-1:dp[M][V];
	} 
// Time Complexity:O(n*sum)
// Auxilary Space: O(n*sum)

int main()
{
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    vector<int>res(n);
    for(int i=0;i<n;i++)
    {
        cin>>res[i];
    }
    int target;
    cin>>target;
    cout<<minCount(res,n,target)<<endl;
    cout<<minCount1(res,n,target)<<endl;
    cout<<minCoins(res,n,target)<<endl;
    return 0;

}