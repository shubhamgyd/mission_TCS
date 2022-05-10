// In this program we are going to find the shotest distance between all nodes from the single soure of node

#include<bits/stdc++.h>
using namespace std;

vector<tuple<int,int,int>>edges;
const int n=100;
int dist[n];


void printPath(vector<int>&parent,int vertex,int src)
{
    if(vertex<0)
    {
        return;
    }
    printPath(parent,parent[vertex],src);
    if(src!=vertex)
    {
        cout<<"->";
    }
    cout<<vertex;
}

void addEdge(int u,int v,int w)
{
    edges.push_back({u,v,w});
    edges.push_back({v,u,w});
}

void BellmanFord(int s,int nodes)
{
    // Initialises all the points as infinite 
    for(int i=1;i<=nodes;i++)
    {
        dist[i]=INT_MAX;
    }
    dist[s]=0; // Source point at 0 distance

    vector<int>parent(nodes+1,-1);
    //In this graph each node visited n-1 times , so every iteration it calculate the minumum distance and update it
    // also this graph can help us to find any negative cycle is present or not
    for(int i=1;i<=nodes-1;i++)
    {
        // int u,v,w;
        for(auto ele:edges)
        {
            int u,v,w;
            tie(u,v,w)=ele;   // source , target , weight
            // dist[v]=min(dist[v],dist[u]+w);  // Update the distance of target from the source if it is less 
            if(dist[v]>dist[u]+w)
            {
                dist[v]=dist[u]+w;
                parent[v]=u;
            }
        }
    }

    for(auto it:edges)
    {
        int u,v,w;
        tie(u,v,w)=it;
        if(dist[u]+w<dist[v] and dist[u]!=INT_MAX)
        {
            cout<<"Contain Negative weight Cycle.."<<endl;
            return;
        }
    }
    cout<<"Below is the  shortest distance of a nodes from the single source of a node "<<endl;
    for(int i=1;i<=nodes;i++)
    {
        cout<<"Path from source to destination:-"<<endl;
        printPath(parent,i,s);
        cout<<endl;
        cout<<s<<"-->"<<i<<"="<<dist[i]<<endl;
        cout<<endl;
    }
}
// Time Complexity: O(n*m)
//Space Somplexity: O(n);


int main()
{
    int nodes;
    int edge;
    cin>>nodes>>edge;
    for(int i=1;i<=edge;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        addEdge(u,v,w);
    }
    BellmanFord(1,nodes);
}

/*
The time complexity of the Bellman–Ford algorithm is O(V × E), where V and E are the total number of vertices and edges in the graph, respectively.
*/