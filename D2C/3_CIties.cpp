#include<bits/stdc++.h>
using namespace std;

void dfs(int src,vector<int>graph[],vector<bool>&visited)
{
    if(visited[src])
    {
        return;
    }
    visited[src]=true;
    for(auto it:graph[src])
    {
        dfs(it,graph,visited);
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>graph[n+1];
        map<int,vector<int>>mp;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(abs(i-j)>1 && n%abs(i-j)==0)
                {
                    graph[i].push_back(j);
                }
            }
        }
        vector<bool>visited(n+1,false);
        int ct=0;
        for(int i=1;i<=n;i++)
        {
            if(!visited[i])
            {
                dfs(i,graph,visited);
                ct++;
            }
        }
        cout<<ct<<endl;
    }
}