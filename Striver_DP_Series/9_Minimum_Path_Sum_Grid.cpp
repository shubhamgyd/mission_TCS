/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, 
which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

*/

#include<bits/stdc++.h>
using namespace std;

// Recursion
int minPaths(int i,int j,int n,int m,vector<vector<int>>&res)
{
    if(i==0 && j==0)
    {
        return res[i][j];
    }
    if(i<0 || j<0)
    {
        return 1e9;
    }
    int up=res[i][j]+minPaths(i-1,j,n,m,res);
    int left=res[i][j]+minPaths(i,j-1,n,m,res);
    return min(up,left);
}
// Time Complexity: Exponential
// Space Complexity:O(1)





// Memoization
int minPaths1(int i,int j,vector<vector<int>>&res,vector<vector<int>>&dp)
{
    if(i==0 && j==0)
    {
        return res[i][j];
    }
    if(i<0 || j<0)
    {
        return 1e9;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int up=res[i][j]+minPaths1(i-1,j,res,dp);
    int left=res[i][j]+minPaths1(i,j-1,res,dp);
    return dp[i][j]=min(up,left);
}
// Time Complexity:O(n*m)
// Space Complexity:O(n*m)




// Tabulation Method

int minPaths2(vector<vector<int>>&res)
{
    int n=res.size();
    int m=res[0].size();
    int dp[n][m]={0};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i==0 && j==0) dp[i][j]=res[i][j];
            else
            {
                int up=res[i][j];
                if(i>0) up+=dp[i-1][j];
                else up+=1e9;
                int left=res[i][j];
                if(j>0) left+=dp[i][j-1];
                else left+=1e9;
                dp[i][j]=min(up,left);
            }
        }
    }
    return dp[n-1][m-1];
}
// Time Complexity:O(n*m)
// Space Complexity:O(n*m)




// Space Optimization
//  we required only previous row to calculate the current min value


int minPaths3(vector<vector<int>>&res)
{
    int n=res.size();
    int m=res[0].size();
    vector<int>prev(m,0);
    for(int i=0;i<n;i++)
    {
        vector<int>curr(m,0);
        for(int j=0;j<m;j++)
        {
            if(i==0 && j==0) curr[j]=res[i][j];
            else{
                int up=res[i][j];
                if(i>0) up+=prev[j];
                else up+=1e9;

                int left=res[i][j];
                if(j>0) left+=curr[j-1];
                else left+=1e9;

                curr[j]=min(left,up);
            }
        }
        prev=curr;
    }
    return prev[m-1];
}
// Time Complexity:O(n*m)
// Space Complexity:O(m)


int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>res(n,vector<int>(m));
    vector<vector<int>>dp(n,vector<int>(m,-1));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>res[i][j];
        }
    }

    cout<<minPaths(n-1,m-1,n,m,res)<<endl;
    cout<<minPaths1(n-1,m-1,res,dp)<<endl;
    cout<<minPaths2(res)<<endl;
     cout<<minPaths3(res)<<endl;
    return 0;

}
