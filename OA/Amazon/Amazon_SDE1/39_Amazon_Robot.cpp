/*
To assemble an Amazon robot, we are given N components labeled from 0 ~ N-1.
There are order requirements to put some components given by an array of pair [pre, post]
which means pre must be installed before post. Write a solution to determine if all the components
can be assmbled successfully.
ex [[0,1],[1,2],[2,0]] returns false
Basically make sure there's no cyclical relationships.
*/

#include<bits/stdc++.h>
using namespace std;

bool DFS(int src,int parent,vector<int>adj[],vector<bool>&visited,vector<int>&order)
{
    visited[src]=true;
    order[src]=1;
    for(auto it:adj[src])
    {
        if(!visited[it])
        {
            if(DFS(it,src,adj,visited,order)) return true;
        }
        else if(order[it]) return true;
    }
    order[src]=0;
    return false;
}

int main()
{
    int n;
    cin>>n;
    vector<int>adj[10001];
    for(int i=0;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<bool>visited(10001,false);
    vector<int>order(10001,0);
    bool isCycle=DFS(0,-1,adj,visited,order);
    if(isCycle)
    {
        cout<<"False"<<endl;
    }
    else
    {
        cout<<"True"<<endl;
    }
    return 0;

}