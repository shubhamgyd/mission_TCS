#include<bits/stdc++.h>
using namespace std;

int minBullets(int i,int j,int n,int m,vector<vector<int>>&res,vector<vector<bool>>&visited,vector<vector<int>>&dp)
{
    if(i<0 || i>=n || j<0 || j>=m || visited[i][j])
    {
        return 1e9;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    if( i==0||i==n-1 || j==0 || j==m-1)
    {
        return res[i][j];
    }
    visited[i][j]=true;
    int a=minBullets(i+1,j,n,m,res,visited,dp);
    int b=minBullets(i-1,j,n,m,res,visited,dp);
    int c=minBullets(i,j+1,n,m,res,visited,dp);
    int d=minBullets(i,j-1,n,m,res,visited,dp);
    int e=minBullets(i-1,j+1,n,m,res,visited,dp);
    int f=minBullets(i+1,j+1,n,m,res,visited,dp);
    int g=minBullets(i+1,j-1,n,m,res,visited,dp);
    int h=minBullets(i-1,j-1,n,m,res,visited,dp);
    visited[i][j]=false;
    return dp[i][j]=res[i][j]+min({a,b,c,d,e,f,g,h});
}


int main()
{
    int n,m;
    cin>>n>>m;
    int row=-1,col=-1;
    vector<vector<int>>res(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>res[i][j];
            if(res[i][j]==0)
            {
                row=i;
                col=j;
            }
        }
    }
    // cout<<row<<" "<<col<<endl;
    vector<vector<int>>dp(n,vector<int>(m,-1));
    vector<vector<bool>>visited(n,vector<bool>(m,false));
    int ans=minBullets(row,col,n,m,res,visited,dp);
    cout<<ans;
    return 0;
}