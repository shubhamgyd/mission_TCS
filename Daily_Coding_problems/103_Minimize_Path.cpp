/*
This question is asked by Google. Given an NxM matrix, grid, where each cell in the matrix
 represents the cost of stepping on the current cell, return the minimum cost to traverse 
 from the top-left hand corner of the matrix to the bottom-right hand corner.
Note: You may only move down or right while traversing the grid.

Ex: Given the following grid…

grid = [
    [1,1,3],
    [2,3,1],
    [4,6,1]
], return 7.
The path that minimizes our cost is 1->1->3->1->1 which sums to 7.

*/

#include<bits/stdc++.h>
using namespace std;


int solve(int i,int j,int n,int m,vector<vector<int>>&res,vector<vector<bool>>&visited)
{
    if(i>=n || i<0 || j>=m || j<0 )
    {
        return INT_MAX;
    }
    if(i==n-1 && j==m-1)
    {
        return res[i][j];
    }
    // visited[i][j]=true;
    int right=solve(i,j+1,n,m,res,visited);
    int down=solve(i+1,j,n,m,res,visited);
    // visited[i][j]=false;
    return res[i][j]+min({right,down});
}
// Time Complexity : Exponential
// Auxiliary Space :O(1)



// Memoize Solution

int minPath(int i,int j,int n,int m,vector<vector<int>>&res,vector<vector<int>>&DP)
{
    if(i>=n || j>=m)
    {
        return INT_MAX;
    }
    if(DP[i][j]!=-1)
    {
        return DP[i][j];
    }
    if(i==n-1 && j==m-1)
    {
        return res[i][j];
    }

    int down=minPath(i+1,j,n,m,res,DP);
    int right=minPath(i,j+1,n,m,res,DP);

    return DP[i][j]=res[i][j]+min(down,right);
}
// Time Complexity:O(n*m)
// Space Complexity:O(n*m)




// Tabulation Method
int tabulation(vector<vector<int>>&res,int n,int m)
{
    int dp[n][m];
    memset(dp,0,sizeof(dp));
    dp[0][0]=res[0][0];
    for(int i=1;i<n;i++)
    {
        dp[i][0]+=dp[i-1][0]+res[i][0];
    }
    for(int j=1;j<m;j++)
    {
        dp[0][j]+=dp[0][j-1]+res[0][j];
    }

    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            dp[i][j]=min(dp[i-1][j],dp[i][j-1])+res[i][j];
        }
    }
    // cout<<endl;
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<m;j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<dp[n-1][m-1]<<endl;
    return dp[n-1][m-1];
}
// Time Complexity:O(n*m)
// Auxilary Space :O(n*m)





// Space Optimize Solution
int minCost(vector<vector<int>>&res,int n,int m)
{
    vector<int>upper(m),current(m);
    upper[0]=res[0][0];
    for(int i=1;i<m;i++)
    {
        upper[i]+=upper[i-1]+res[0][i];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(j==0)
            {
                current[j]=upper[0]+res[i][j];
            }
            else
            {
                current[j]=min(current[j-1],upper[j])+res[i-1][j-1];
            }
            
        }
        upper=current;
        // current.clear();
    }
    cout<<"Min Cost: "<<upper[m-1]<<endl;
    return upper[m-1];
}
// Time Complexity:O(n*m)
// Space :O(m)

int main()
{
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
    vector<vector<int>>DP(n,vector<int>(m,-1));
    vector<vector<bool>>visited(n,vector<bool>(m,false));
    int ans=solve(0,0,n,m,res,visited);
    int temp=minPath(0,0,n,m,res,DP);
    tabulation(res,n,m);
    minCost(res,n,m);
    cout<<"Minimum Path Sum: "<<ans<<endl;
    cout<<"Minimum Path Sum: "<<temp<<endl;
}