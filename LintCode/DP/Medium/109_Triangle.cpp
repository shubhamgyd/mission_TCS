/*
Description
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

Bonus point if you are able to do this using only O(n)O(n) extra space, where n is the total number of rows in the triangle.

Example
Example 1:

Input:

triangle = [
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
Output:

11
Explanation:

The minimum path sum from top to bottom is 11 (2 + 3 + 5 + 1 = 11).

Example 2:

Input:

triangle = [
     [2],
    [3,2],
   [6,5,7],
  [4,4,8,1]
]
Output:

12
Explanation:

The minimum path sum from top to bottom is 12 (2 + 2 + 7 + 1 = 12).
*/


#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    /**
     * @param triangle: a list of lists of integers
     * @return: An integer, minimum path sum
     */
    int solve(int i,int level,vector<vector<int>>&t,vector<vector<int>>&dp)
    {
        if(level>=t.size() || i>=t[level].size())
        {
            return 0;
        }
        if(dp[level][i]!=-1)
        {
            return dp[level][i];
        }
        return dp[level][i]=t[level][i]+min(solve(i,level+1,t,dp),solve(i+1,level+1,t,dp));
    }
    int minimumTotal(vector<vector<int>> &t) {
        // write your code here
        // Solution 1+2: Recursive + Memoization
        int sz=t.size();
        // vector<vector<int>>dp(sz,vector<int>(sz,-1));
        // return solve(0,0,t,dp);

        // solution 3: Iterative
        vector<int>res(t.back());
        for(int i=sz-2;i>=0;i--)
        {
            for(int j=0;j<=i;j++)
            {
                res[j]=min(res[j],res[j+1])+t[i][j];
            }
        }
        return res[0];
    }
};