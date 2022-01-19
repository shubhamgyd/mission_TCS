#include<bits/stdc++.h>
using namespace std;


int solve(vector<pair<int,int>>adj[],int s,vector<bool>&city,int n)
{
    // int dist[n+1];
    vector<int>dist(n+1);
    // vector<bool>visited(n+1,false);
    bool visited[n+1];
    for(int i=1;i<=n;i++)
    {
        dist[i]=INT_MAX;
        visited[i]=false;
    }
    priority_queue<pair<int,int>>pq;
    dist[s]=0;
    pq.push({0,s});
    while(!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();
        if(visited[u])
        {
            continue;
        }
        else
        {
            visited[u]=true;
            for(auto it:adj[u])
            {
                int v=it.first;
                int w=it.second;
                if(dist[v]>dist[u]+w)
                {
                    dist[v]=dist[u]+w;
                    pq.push({-dist[v],v});
                }
            }
        }
    }

    // sort(dist,dist+n+1);
    // sort(dist.begin(),dist.end());
    cout<<"for vertex: "<<s<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<dist[i]<<endl;
    }
    cout<<endl;
    for(int i=1;i<=n;i++)
    {
        if(!city[i] && i!=s)
        {
            city[i]=true;
            cout<<"dist: "<<dist[i]<<endl;
            return dist[i];
        }
    }
    return 0;

}

int main()
{
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<pair<int,int>>adj[n+1];
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    int sum=0;
    vector<bool>city(n+1,false);
    for(int i=1;i<=n;i++)
    {
        sum+=solve(adj,i,city,n);
    }
    cout<<sum<<endl;
    return 0;
}