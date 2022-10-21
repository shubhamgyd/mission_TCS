/*
Description
A robot is located at the top-left corner of a m x nmxn grid.

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid.

How many possible unique paths are there?

m and n will be at most 100.
The answer is guaranteed to be in the range of 32-bit integers

Example
Example 1:

Input:

n = 1
m = 3
Output:

1
Explanation:

Only one path to target position.

Example 2:

Input:

n = 3
m = 3
Output:

6
Explanation:

D : Down
R : Right

DDRR
DRDR
DRRD
RRDD
RDRD
RDDR

*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
    int ans;
    void dfs(vector<vector<int>>&res,int i,int j,int m,int n)
    {
        if(i<0 || i>=m || j<0 || j>=n )
        {
            return;
        }
        if(res[i][j]==0)
        {
            return;
        }
        if(i==m-1 && j==n-1)
        {
            ans++;
        }
        // if(!visited[i][j])
        // {
            // visited[i][j]=true;
            res[i][j]=0;
            dfs(res,i+1,j,m,n);
            dfs(res,i,j+1,m,n);
            res[i][j]=1;
            // visited[i][j]=false;
        // }
        
    }
public:
    int uniquePaths(int m, int n) {
        //Sol 1: Brute force
        vector<vector<int>>res(m,vector<int>(n,1));
        ans=0;
        // vector<vector<bool>>visited(m,vector<bool>(n,false));
        dfs(res,0,0,m,n);
        return ans;
        
        
        
        // Solution : 2 DP
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
        
        
        // Solution 3: DP Optimize
        vector<int> pre(n, 1), cur(n, 1);
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                cur[j] = pre[j] + cur[j - 1];
            }
            swap(pre, cur);
        }
        return pre[n - 1];
        
        
        // Solution 4:  Space Optimise
        vector<int> cur(n, 1);
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                cur[j] += cur[j - 1];
            }
        }
        return cur[n - 1];
    }
};


int main()
{
    int n,m;
    cin>>n>>m;
    Solution obj;
    int ans=obj.uniquePaths(n,m);
    cout<<ans<<endl;
    return 0;
}