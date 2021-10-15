// In this program we are going to find the shortest distances of each nodes form the source point

#include<bits/stdc++.h>
using namespace std;



const long long  N=100005;
vector<pair<long long ,long long >>adj[N];
long long dist[N];
priority_queue<pair<long long ,long long>>pq;
bool visited[N];
const long long INF=1e18L+5;
long long  parent[N];

long long  nodes;
long long  edges;


void addEdge(long long  u,long long v,long long w)
{
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
}

void printPath(long long  j)
{
    if(parent[j]==-1)
    {
        return ;
    }
    printPath(parent[j]);
    cout<<j<<" ";
}

void Dijaktras(long long  s)
{
    for(long long  i=1;i<=nodes;i++)
    {
        dist[i]=INF;
    }
    dist[s]=0;
    parent[s]=-1;
    pq.push({0,s});
    while(!pq.empty())
    {
        long long  u=pq.top().second;pq.pop();
        if(visited[u]) 
        {
            continue;
        }
        visited[u]=true;
        for(auto ele:adj[u])
        {
            long long  v=ele.first,w=ele.second;
            if(dist[u]+w<dist[v])
            {
                parent[v]=u;
                dist[v]=dist[u]+w;
                pq.push({-dist[v],v});
            }
            
        }
    }
    if(visited[nodes]==false)
    {
        cout<<-1<<endl;
        return;
    }


    // cout<<"Distances of nodes from the source node are : "<<endl;
    // cout<<"Source node is: "<<s<<endl;
    // for(int i=1;i<=nodes;i++)
    // {
    //     cout<<i<<"   "<<dist[i]<<" \t\t";
    //     cout<<s<<" ";
    //     printPath(i);
    //     cout<<endl;
    // }
    cout<<s<<" ";
    printPath(nodes);
    cout<<endl;


    //cout<<"Below is the paths of the nodes from source to vertex:"

}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    //cout<<"Enter number of vertex and edges: ";
    cin>>nodes>>edges;
    for(long long  i=0;i<edges;i++)
    {
        long long  u,v,w;
        cin>>u>>v>>w;
        addEdge(u,v,w);
    }
    Dijaktras(1);
}