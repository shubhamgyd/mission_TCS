/*
Given a N X N matrix Mat[N][N] of positive integers. There are only three possible moves 
from a cell (i, j) 
 

(i+1, j)
(i+1, j-1)
(i+1, j+1)
Starting from any column in row 0, return the largest sum of any of the paths up to row N-1.
Examples: 
 

Input : mat[4][4] = { {4, 2, 3, 4},
                      {2, 9, 1, 10},
                      {15, 1, 3, 0},
                      {16, 92, 41, 44} };
Output :120
path : 4 + 9 + 15 + 92 = 120 
*/

#include<bits/stdc++.h>
using namespace std;

int solve(int i,int j,int mat[4][4],int n,vector<vector<int>>&res)
{
    if(i>=n || i<0 || j>=n || j<0)
    {
        return  0;
    }
    if(res[i][j]!=-1)
    {
        return res[i][j];
    }
    int s1=solve(i+1,j,mat,n,res);
    int s2=solve(i+1,j-1,mat,n,res);
    int s3=solve(i+1,j+1,mat,n,res);
    res[i][j]=mat[i][j]+max({s1,s2,s3});
    return res[i][j];
}
// Time coplexity:Exponential




// Optimize solution DP Bottom-Up
void MaxSum(int mat[][4],int n)
{
    int dp[n][n+2];
    memset(dp,0,sizeof(dp));

    // Push all the zero's th row element into the dp th zero row
    for(int i=0;i<1;i++)
    {
        for(int j=0;j<n;j++)
        {
            dp[i][j]=mat[i][j];
        }
    }


    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dp[i][j]=max(dp[i-1][j-1],max(dp[i-1][j],dp[i-1][j+1]))+mat[i][j-1];
        }
    }
    int result=0;
    for(int i=0;i<=n;i++)
    {
        result=max(result,dp[n-1][i]);
    }
    cout<<result<<endl;
}
// Time complexity:O(n*n)
// Space Complexity:O(n*n)


int main()
{
   int mat[4][4] = { {4, 2, 3, 4},
                      {2, 9, 1, 10},
                      {15, 1, 3, 0},
                      {16, 92, 41, 44}};
    
    int val=0;
    vector<vector<int>>res(4,vector<int>(4,-1));
    for(int i=0;i<1;i++)
    {
        for(int j=0;j<4;j++)
        {
            val=max(val,solve(i,j,mat,4,res));
        }
    }
    cout<<val<<endl;
    MaxSum(mat,4);
    return 0;
}