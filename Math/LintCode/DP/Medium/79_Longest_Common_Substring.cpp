/*
Description
Given two strings, find the longest common substring.

Return the length of it.

The characters in substring should occur continuously in original string. This is different with subsequence.

Example
Example 1:

Input:

stringA = "ABCD"
stringB = "CBCE"
Output:

2
Explanation:

Longest common substring is "BC"

Example 2:

Input:

stringA = "ABCD"
stringB = "EACB"
Output:

1
Explanation:

Longest common substring is 'A' or 'C' or 'B'

Challenge
O(n x m) time and memory.

*/

#include<bits/stdc++.h>
using namespace std;


class Solution
{
    int solve(string x,string y,int n,int m,int ans,vector<vector<int>>&dp)
    {
        if(n==0 || m==0)
        {
            return 0;
        }
        // if(dp[n-1][m-1]!=-1)
        // {
        //     return dp[n-1][m-1];
        // }
        if(x[n-1]==y[m-1])
        {
            ans=solve(x,y,n-1,m-1,ans+1,dp);
        }
        // else
        // {
            ans=max({ans,solve(x,y,n-1,m,0,dp),solve(x,y,n,m-1,0,dp)});
        // }
        return ans;
    }
public:
    int longestCommonSubstring(string x,string y)
    {
        int n=x.length();
        int m=y.length();
        int ans=0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(x,y,n,m,ans,dp);
    }
};


int main()
{
    string x,y;
    cin>>x>>y;
    Solution obj;
    // Method 1: Recursion
    int ans=obj.longestCommonSubstring(x,y);
    cout<<ans<<endl;


    // Method 2: Tabulation
    int n=x.length();
    int m=y.length();
    int dp[n+1][m+1];
    int mx=0;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
            }
            else if(x[i-1]==y[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
                mx=max(mx,dp[i][j]);
            }
            else
            {
                dp[i][j]=0;
            }
        }
    }
    cout<<mx<<endl;
    // Time Complexity:O(n*m)
    // Space Complexity:O(n*m)


    // Solution 3: Space Optimize
    vector<int>prev(m+1,0),curr(m+1,0);
    int mx1=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(j==0) curr[j]=0;
            else if(x[i-1]==y[j-1])
            {
                curr[j]=1+prev[j-1];
                mx1=max(mx1,curr[j]);
            }
            else
            {
                curr[j]=0;
            }
        }
        prev=curr;
    }
    cout<<mx1<<endl;
    // Time Complexity:O(n*m)
    // Space Complexity:O(n)
    return 0;


}