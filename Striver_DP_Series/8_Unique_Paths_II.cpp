/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. 
The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the 
diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and space is marked as 1 and 0 respectively in the grid.

*/


#include<bits/stdc++.h>
using namespace std;


int solve(int i,int j,int n,int m,vector<vector<int>>&res)
{
    if(i<0 || i>=n || j<0 || j>=m || res[i][j]==1)
    {
        return 0;
    }
    if(i==n-1 && j==m-1)
    {
        return 1;
    }
    return solve(i+1,j,n,m,res)+solve(i,j+1,n,m,res);
}
// Time Complexity: Exponential
// Space Complexity:O(1)



// Memoization Method
int  dp[10001][10001];
int solve1(int i,int j,int n,int m,vector<vector<int>>&res)
{
    if(i<0 || i>=n || j<0 || j>=m || res[i][j]==1)
    {
        return 0;
    }
    if(i==n-1 && j==m-1)
    {
        return 1;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    return dp[i][j]=solve1(i+1,j,n,m,res)+solve1(i,j+1,n,m,res);
}
// Time Complexity:O(n*m)
// Space Complexity:O(n*m)





// Iterative Method(DP)

int Optimize(vector<vector<int>>&res)
{
    int n=res.size();
    int m=res[0].size();
    int dp1[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(res[i][j]==1) dp1[i][j]=0;
            else if(i==0 || j==0) dp1[i][j]=1;
            else{
                int up=0;
                int left=0;
                if(i>0) up+=dp1[i-1][j];
                if(j>0) left+=dp1[i][j-1];
                dp1[i][j]=(up+left);
            }
        }
    }
    return dp1[n-1][m-1];
}
// Time complexity:O(n*m)
// Space Complexity:O(n*m)



// Space Optimize solution
int Space(vector<vector<int>>&res)
{
    int n=res.size();
    int m=res[0].size();
   vector<int>ans(m,0);
    for(int i=0;i<n;i++)
    {
        vector<int>temp(m,0);
        for(int j=0;j<m;j++)
        {
            if(res[i][j]==1) temp[j]=0;
            else if(i==0 || j==0) temp[j]=1;
            else{
                int up=0;
                int left=0;
                if(i>0) up+=ans[j];
                if(j>0) left+=temp[j-1];
                temp[j]=(up+left);
            }
        }
        ans=temp;
    }
    return ans[m-1];
}
// Time Complexity:O(n*m)
// Space Complexity:O(m)


int main()
{
    memset(dp,-1,sizeof(dp));
    int n,m;
    cin>>n>>m;
    vector<vector<int>>res(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>res[i][j];
        }
    }

    cout<<solve(0,0,n,m,res)<<endl;
    cout<<solve(0,0,n,m,res)<<endl;
    cout<<Optimize(res)<<endl;
     cout<<Space(res)<<endl;
    return 0;
}