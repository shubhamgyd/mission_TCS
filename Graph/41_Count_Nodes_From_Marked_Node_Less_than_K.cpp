
#include<bits/stdc++.h>
using namespace std;


int bfs(int src,vector<int>graph[],vector<bool>&visited,vector<int>&dist)
{
    queue<int>q;
    q.push(src);
    dist[src]=0;
    int lastnode;
    while(!q.empty())
    {
        auto curr=q.front();
        q.pop();

        if(visited[curr])
        {
            lastnode=curr;
        }

        for(auto it:graph[curr])
        {
            if(dist[it]==-1)
            {
                dist[it]=dist[curr]+1;
                q.push(it);
            }
        }
    }
    return lastnode;
}
// Time Complexity :











int main()
{
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.out", "w", stdout);
#endif
    int n,m;
    cin>>n>>m;
    vector<int>graph[n+1];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // for(int i=0;i<n;i++)
    // {
    //     cout<<i<<" :";
    //     for(auto it:graph[i])
    //     {
    //         cout<<it<<" ";
    //     }
    //     cout<<endl;
    // }

    vector<bool>visited(n+1,false);
    int node;
    cin>>node;
    for(int i=0;i<node;i++)
    {
        int a;
        cin>>a;
        visited[a]=true;
    }

    int k;
    cin>>k;

    //  first bfs(from any random node) to get one
    // distant marked node
    vector<int>temp(n+1,-1);
    int u=bfs(0,graph,visited,temp);


    /*  second bfs to get other distant marked node
        and also dl is filled with distances from first
        chosen marked node */
    vector<int>dl(n+1,-1);
    int v=bfs(u,graph,visited,dl);


    //  third bfs to fill dr by distances from second
    // chosen marked node
    vector<int>dr(n+1,-1);
    bfs(v,graph,visited,dr);


    int ct=0;
    for(int i=0;i<n;i++)
    {
        if(dl[i]<=k && dr[i]<=k)
        {
            ct++;
        }
    }
    cout<<ct<<endl;
    return 0;

}
