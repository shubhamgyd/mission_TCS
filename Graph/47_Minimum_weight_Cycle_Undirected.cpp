
#include<bits/stdc++.h>
using namespace std;



void DFS(int src,vector<pair<int,int>>adj[],vector<int>&len,vector<int>&visited,vector<int>&parent,int &cycle)
{
    for(auto it:adj[src])
    {
        int v=it.first;
        int w=it.second;
        if(visited[v]==0)
        {
            visited[v]=1;
            parent[v]=src;
            len[v]=len[src]+w;
            DFS(v,adj,len,visited,parent,cycle);
            visited[v]=0;
            parent[v]=-1;
        }
        else if(visited[v] && parent[src]!=v)
        {
            cycle=min(cycle,w+abs(len[v]-len[src]));
        }
    }
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.out", "w", stdout);
#endif
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>adj[n];
    for(int i=0;i<m;i++)
    {
        int a,b,w;
        cin>>a>>b>>w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }
    vector<int>len(n,0);
    vector<int>visited(n,0);
    vector<int>parent(n,-1);
    parent[0]=-2;
    visited[0]=1;
    int cycle=INT_MAX;
    DFS(0,adj,len,visited,parent,cycle);
    cout<<"Minimum Weight of cycle is: "<<cycle<<endl;
    return 0;

}
// Time Complexity :O(v+e)
// Application of DFS