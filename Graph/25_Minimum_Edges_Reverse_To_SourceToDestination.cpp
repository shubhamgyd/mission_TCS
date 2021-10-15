// In this program we are going to find the shortest distances of each nodes form the source point

#include<bits/stdc++.h>
using namespace std;



const int N=100;
vector<pair<int,int>>adj[N];
int dist[N];
priority_queue<pair<int,int>>pq;
bool visited[N];

int nodes;
int edges;


void addEdge(int u,int v)
{
    adj[u].push_back({v,0});
    adj[v].push_back({u,1});
}


void Dijaktras(int s)
{
    for(int i=0;i<edges;i++)
    {
        dist[i]=INT_MAX;
    }
    dist[s]=0;
    pq.push({0,s});
    while(!pq.empty())
    {
        int u=pq.top().second;pq.pop();
        if(visited[u]) continue;
        else
        {
        visited[u]=true;
        for(auto ele:adj[u])
        {
            int v=ele.first,w=ele.second;
            if(dist[u]+w<dist[v])
            {
                dist[v]=dist[u]+w;
                pq.push({-dist[v],v});
            }
            
        }
        }
    }


    cout<<"Distances of nodes from the source node are : "<<endl;
    cout<<"Source node is: "<<s<<endl;
    for(int i=0;i<nodes;i++)
    {
        cout<<s<<"-->"<<i<<"="<<dist[i]<<endl;
    }
}

int main()
{
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    // nodes=6;
    // edges=8;
    //cout<<"Enter number of vertex and edges: ";
    int src,dest;
    cin>>nodes>>edges>>src>>dest;
    for(int i=0;i<edges;i++)
    {
        int u,v,w;
        cin>>u>>v;
        addEdge(u,v);
    }
    Dijaktras(src);
    if(dist[dest]==INT_MAX)
    {
        cout<<"Not Possible"<<endl;
    }
    else
    {
        cout<<"Inversion of edges are possible "<<endl;
        cout<<"Minimum number of edges required to flip is: ";
        cout<<dist[dest]<<endl;
    }
    return 0;
}