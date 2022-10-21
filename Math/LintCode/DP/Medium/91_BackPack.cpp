/*
Description
Given n items with size A_{i}A 
i
​
  an integer m denotes the size of a backpack. How full you can fill this backpack?
(Each item can only be selected once and the size of the item is a positive integer)

You can not divide any item into small pieces.
n \lt 1000n<1000
m \lt 1e9m<1e9
Example
Example 1:

Input:

array = [3,4,8,5]
backpack size = 10
Output:

9
Explanation:

Load 4 and 5.

Example 2:

Input:

array = [2,3,5,7]
backpack size = 12
Output:

12
Explanation:

Load 5 and 7.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param a: Given n items with size A[i]
     * @return: The maximum size
     */
    int solve(int n,vector<int>&a,int m,vector<vector<long long int>>&dp)
    {
        if(m==0 || n==0)
        {
            return 0;
        }
        if(dp[n][m]!=-1)
        {
            return dp[n][m];
        }
        int include=0;
        int exclude=0;

        if(a[n-1]<=m)
        {
            include=a[n-1]+solve(n-1,a,m-a[n-1],dp);
        }
        exclude=solve(n-1,a,m,dp);
        return dp[n][m]=max(include,exclude);
    }
    int backPack(int m, vector<int> &a) {
        // solution 1+2: Recursion + Memoization
        int n=a.size();
        // vector<vector<long long int>>dp(n+1,vector<long long int>(m+1,-1));
        // return solve(n,a,m,dp);



        // Solution 3: Tabulation
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0 || j==0)
                {
                    dp[i][j]=0;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[i-1]<=j)
                {
                    dp[i][j]=max(a[i-1]+dp[i-1][j-a[i-1]],dp[i-1][j]);
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][m];

    }
};

int main()
{

}