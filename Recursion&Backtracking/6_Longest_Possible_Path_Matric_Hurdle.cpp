#include<bits/stdc++.h>
using namespace std;

int res=0;

bool isSafe(int r,int c,int n,int m,vector<vector<bool>>&visited,vector<vector<int>>&graph)
{
    if(r<0 || r>=n || c<0 || c>=m || visited[r][c] || graph[r][c]==0)
    {
        return false;
    }
    return true;
}
void LongestPath(vector<vector<int>>&graph,int s,int e,int x,int y,int n,int m,int ans,vector<vector<bool>>&visited)
{
    if(s==x && e==y)
    {
        res=max(res,ans);
        return;
    }

    if(s<0 || s>=n || e<0 || e>=m || visited[s][e] || graph[s][e]==0)
    {
        return;
    }
    visited[s][e]=true;
    LongestPath(graph,s+1,e,x,y,n,m,ans+1,visited);
    LongestPath(graph,s-1,e,x,y,n,m,ans+1,visited);
    LongestPath(graph,s,e+1,x,y,n,m,ans+1,visited);
    LongestPath(graph,s,e-1,x,y,n,m,ans+1,visited);
    visited[s][e]=false;
    return;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>graph(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int a;
            cin>>a;
            graph[i][j]=a;
        }
    }
    int s,e;
    cin>>s>>e;
    int x,y;
    cin>>x>>y;
    int ans=0;
    vector<vector<bool>>visited(n,vector<bool>(m,false));
    LongestPath(graph,s,e,x,y,n,m,ans,visited);
    cout<<res<<endl;
    return 0;
}