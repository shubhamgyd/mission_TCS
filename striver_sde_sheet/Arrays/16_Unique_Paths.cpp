/*
Problem Statement: Given a matrix m X n, count paths from left-top to the right bottom of a matrix with the constraints that from each cell you can either only move to the rightward direction or the downward direction.

Example 1:

Input Format: m = 2, n= 2
Output: 2
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
        // int ans=0;
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
    cout<<obj.uniquePaths(n,m)<<endl;
    return 0;
}