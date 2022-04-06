#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    int u, v;
};

class Vertex
{
public:
    int V;
};




void ShortestPath(int s,int n,vector<int>adj[])
{
    int dist[n+1];
    priority_queue<pair<int,int>>pq;
    vector<bool>visited(n+1,false);
    for(int i=0;i<=n;i++)
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
            // int v=ele.first;
            // if(dist[u]+1<dist[v])
            // {
            //     dist[v]=dist[u]+1;
            //     pq.push({-dist[v],v});
            // }
            
        }
        }
    }


    cout<<"Distances of nodes from the source node are : "<<endl;
    cout<<"Source node is: "<<s<<endl;
    // for(int i=0;i<=nodes;i++)
    // {
    //     cout<<i<<"   "<<dist[i]<<endl;
    // }
}

int main()
{
    ifstream inFile("graph.txt");
    vector<int>adj[51];
    int u,v;
    
    // Task 1: Reading graph
    while (inFile >> u>> v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    inFile.close();


    // Task 2: Printing Graph
    // we have store the given graph in adjaceny list
    // print the graph
    for(int i=0;i<51;i++)
    {
        // means this vertex have adjacent nodes
        if(adj[i].size()>0)
        {
            cout<<i<<":->";
            vector<int>vertices;
            for(auto it:adj[i])
            {
                // store the adjacent vertices into the vector
                vertices.push_back(it);
            }

            // now print the adjacent vertices
            for(int j=0;j<vertices.size();j++)
            {
                if(j<vertices.size()-1)
                {
                    cout<<vertices[j]<<"->";
                }
                else
                {
                    cout<<vertices[j];
                }
            }
            cout<<endl;
        }
    }


    // Task 3: Shorted distance of all nodes from the vertex
    cout<<"Please Enter a starting node: ";
    int node;
    cin>>node;

}