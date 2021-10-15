#include<bits/stdc++.h>
using namespace std;

class Solution {
    long dp[10001][10001];
    // vector<vector<long long>>dp(size,vector<long long>(size));
    long long  solve(vector<vector<int>>& grid,int i,int j,int n,int m,vector<vector<bool>>&visited)
    {
        if(i<0 || i>=n || j<0 || j>=m || visited[i][j]==true)
        {
            return 0;
        }
        if(i==1 && j==m-1)
        {
            return  grid[i][j];
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        visited[i][j]=true;
        long long s1=solve(grid,i+1,j,n,m,visited);
        long long  s2=solve(grid,i,j+1,n,m,visited);
        visited[i][j]=false;
        return dp[i][j]=grid[i][j]+max({s1,s2});
    }
    // long  long dp1[1000001][1000001];
    // long long  solve1(vector<vector<int>>& grid,int i,int j,int n,int m,vector<vector<bool>>&visited)
    // {
    //     if(i<0 || i>=n || j<0 || j>=m || visited[i][j])
    //     {
    //         return 0;
    //     }
    //     if(i==1 && j==m-1)
    //     {
    //         return  grid[i][j];
    //     }
    //     if(dp1[i][j]!=-1)
    //     {
    //         return dp1[i][j];
    //     }
    //     visited[i][j]=true;
    //     long long s1=solve1(grid,i+1,j,n,m,visited);
    //     long long  s2=solve1(grid,i,j+1,n,m,visited);
    //     visited[i][j]=false;
    //     return dp1[i][j]=grid[i][j]+max({s1,s2});
    // }
public:
    long long gridGame(vector<vector<int>>& grid) {
        cout<<"Hello"<<endl;
        int n=grid.size();
        int m=grid[0].size();
        memset(dp,-1,sizeof(dp));
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        long long temp=solve(grid,0,0,n,m,visited);
        cout<<temp<<endl;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(visited[i][j])
                {
                    visited[i][j]=false;
                    grid[i][j]=0;
                }
            }
        }
        memset(dp,-1,sizeof(dp));
        long long  temp1=solve(grid,0,0,n,m,visited);
        return temp1;
    }
};

int main()
{
    int n;
    cout<<"Hello"<<endl;
    cin>>n;
    int m;
    cin>>m;
    vector<vector<int>>grid(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int a;
            cin>>a;
            grid[i][j]=a;
        }
    }
    cout<<"Hello"<<endl;
    Solution obj;
    long long ans=obj.gridGame(grid);
    cout<<ans<<endl;
    return 0;
}
