
#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
class Solution {
    int dp[501][501];
    int dfs(int i,int j,int n,int m,vector<vector<int>>&grid)
    {
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]==-1)
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
        grid[i][j]=-1;
        int s1=dfs(i+1,j,n,m,grid);
        int s2=dfs(i,j+1,n,m,grid);
        grid[i][j]=0;
        return dp[i][j]=(s1%mod+s2%mod)%mod;   
    }
public:
    int FindWays(int n, int m, vector<vector<int>>grid){
        memset(dp,-1,sizeof(dp));
        vector<vector<int>>res(n,vector<int>(m,0));
        int a=grid.size();
        for(int i=0;i<a;i++)
        {
            int u=grid[i][0];
            int v=grid[i][1];
            res[u-1][v-1]=-1;
        }
        return dfs(0,0,n,m,res);
    }
};
// Time Complexity :O(n*m)
// Space Complexity O(n*m)






void SpecialMatri(int n,int m,vector<vector<int>>res)
{
    int dp[n][m];
    // memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            dp[i][j] = 0;
        }
    }
    for(int i=0;i<m;i++)
    {
        if(res[0][i]==0)
        {
            dp[0][i]=1;
        }
        else break;
    }

    for(int i=0;i<n;i++)
    {
        if(res[i][0]==0)
        {
            dp[i][0]=1;
        }
        else break;
    }

    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(res[i][j]==0 && dp[i-1][j]>=0 && dp[i][j-1]>=0)
            {
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
    }

    cout<<"Matrix Path: "<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"Total Paths: "<<dp[n-1][m-1]<<endl;
}
// Time Complexity :O(n*m)
// Space Complexity :O(n*m)



int main()
{
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.out", "w", stdout);
#endif
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
    SpecialMatri(n,m,res);
	return 0;
}