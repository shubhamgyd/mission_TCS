/*
Minimum path sum from top of the traingle to the bottom base
*/

#include<bits/stdc++.h>
using namespace std;


int solve(int i,int j,vector<vector<int>>&res,int n)
{
    if(i==n-1)
    {
        return res[n-1][j];
    }
    int down=res[i][j]+solve(i+1,j,res,n);
    int downright=res[i][j]+solve(i+1,j+1,res,n);
    return min(down,downright);
}
// Time Complexity:Exponential
// Space Complexity:O(1)



// Memoization
int dp[10005][10005];
int minPaths(int i,int j,vector<vector<int>>&res,int n)
{
    if(i==n-1)
    {
        return res[n-1][j];
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int down=res[i][j]+minPaths(i+1,j,res,n);
    int downright=res[i][j]+minPaths(i+1,j+1,res,n);
    return dp[i][j]=min(down,downright);
}
// Time Complexity:O(n*n)
// Space Complexity:O(n*n)



// Tabulation method
int minPaths1(vector<vector<int>>&res)
{
    int n=res.size();
    int dp1[n][n];
    memset(dp1,0,sizeof(dp1));
    for(int i=0;i<n;i++) dp1[n-1][i]=res[n-1][i];
    for(int i=n-2;i>=0;i--)
    {
        for(int j=i;j>=0;j--)
        {
            int d=res[i][j]+dp1[i+1][j];
            int dg=res[i][j]+dp1[i+1][j+1];
            dp1[i][j]=min(d,dg);
        }
    }
    return dp1[0][0];
}
// Time Complexity:O(n*n)
// Space Complexity:O(n*n)



// Space Optimization
int minPaths2(vector<vector<int>>&res)
{
    int n=res.size();
    vector<int>pre(n,0),curr(n,0);
    for(int i=0;i<n;i++) pre[i]=res[n-1][i];
    for(int i=n-2;i>=0;i--)
    {
        for(int j=i;j>=0;j--)
        {
            int d=res[i][j]+pre[j];
            int dg=res[i][j]+pre[j+1];
            curr[j]=min(d,dg);
        }
        pre=curr;
    }
    return pre[0];
}
// Time Complexity::O(n*n)
// Space Complexity:O(n)


int main()
{
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    vector<vector<int>>res(n,vector<int>(n,INT_MAX));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            int a;
            cin>>a;
            res[i][j]=a;
        }
    }
    cout<<solve(0,0,res,n)<<endl;
    cout<<minPaths(0,0,res,n)<<endl;
    cout<<minPaths1(res)<<endl;
    cout<<minPaths2(res)<<endl;
}