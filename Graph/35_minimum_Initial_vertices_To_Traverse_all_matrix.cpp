
#include<bits/stdc++.h>
using namespace std;



int n,m;

bool isSafe(int x,int y,int n ,int m,vector<vector<int>>&graph,vector<vector<bool>>&visited)
{
    if(x<0 || x>=n || y<0 || y>=m || visited[x][y] )
    {
        return false;
    }
    return true;
}

void DFS(int x,int y,vector<vector<int>>&graph,vector<vector<bool>>&visited,int n,int m,int val)
{
    
    if(graph[x][y]>val)
    {
        return;
    }
    visited[x][y]=true;
    if(isSafe(x+1,y,n,m,graph,visited))
    {
        DFS(x+1,y,graph,visited,n,m,graph[x][y]);
    }
    if(isSafe(x-1,y,n,m,graph,visited))
    {
        DFS(x-1,y,graph,visited,n,m,graph[x][y]);
    }
    if(isSafe(x,y+1,n,m,graph,visited))
    {
        DFS(x,y+1,graph,visited,n,m,graph[x][y]);
    }
    if(isSafe(x,y-1,n,m,graph,visited))
    {
        DFS(x,y-1,graph,visited,n,m,graph[x][y]);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.out", "w", stdout);
#endif
    cin>>n>>m;
    vector<vector<int>>res(n,vector<int>(m,0));
    priority_queue<pair<int,pair<int,int>>>pq;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>res[i][j];
            pq.push({res[i][j],{i,j}});
        }
    }

    vector<vector<bool>>visited(n,vector<bool>(m,false));
    vector<pair<int,int>>ans;
    while(!pq.empty())
    {
        auto curr=pq.top();
        pq.pop();
        int x=curr.second.first;
        int y=curr.second.second;
        if(!visited[x][y])
        {
            ans.push_back({x,y});
            int val=res[x][y];
            DFS(x,y,res,visited,n,m,val);
        }
    }

    for(auto it:ans)
    {
        cout<<it.first<<" "<<it.second<<endl;
    }
    return 0;
}