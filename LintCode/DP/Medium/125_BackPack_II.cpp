/*
Description
There are n items and a backpack with size m. Given array A representing the size of each item and array V representing the value of each item.

What's the maximum value can you put into the backpack?

A[i], V[i], n, m are all integers.
You can not split an item.
The sum size of the items you want to put into backpack can not exceed m.
Each item can only be picked up once
m <= 1000m<=1000\
len(A),len(V)<=100len(A),len(V)<=100

Example
Example 1:

Input:

m = 10
A = [2, 3, 5, 7]
V = [1, 5, 2, 4]
Output:

9
Explanation:

Put A[1] and A[3] into backpack, getting the maximum value V[1] + V[3] = 9

Example 2:

Input:

m = 10
A = [2, 3, 8]
V = [2, 5, 8]
Output:

10
Explanation:

Put A[0] and A[2] into backpack, getting the maximum value V[0] + V[2] = 10

Challenge
O(nm) memory is acceptable, can you do it in O(m) memory?
*/


#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param a: Given n items with size A[i]
     * @param v: Given n items with value V[i]
     * @return: The maximum value
     */
    int solve(int n,int m,vector<int>&a,vector<int>&v,vector<vector<int>>&dp)
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
            include=v[n-1]+solve(n-1,m-a[n-1],a,v,dp);
        }
        exclude=solve(n-1,m,a,v,dp);
        return dp[n][m]=max(include,exclude);
    }
    int backPackII(int m, vector<int> &a, vector<int> &v) {
        // write your code here

        // Solution 1+ 2: Recursion + Memoization
        int n=a.size();
        // vector<vector<int>>dp(1001,vector<int>(1001,-1));
        // return solve(n,m,a,v,dp);

        // Solution 3: Tabulation
        int arr[n+1][m+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0 || j==0)
                {
                    arr[i][j]=0;
                }
            }
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[i-1]<=j)
                {
                    arr[i][j]=max(v[i-1]+arr[i-1][j-a[i-1]],arr[i-1][j]);
                }
                else
                {
                    arr[i][j]=arr[i-1][j];
                }
            }
        }
        return arr[n][m];
    }
};