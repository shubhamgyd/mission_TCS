// In this algorithm we are going to see .. the sortest path from source to vertices

#include<bits/stdc++.h>
using namespace std;

#define INF INT_MAX

class Graph
{
    int V; // Number of vertices

    //In a weighted graph, we need to store vertex 
    // and weight pair for every edge
    list<pair<int,int>>*adj;
public:
    Graph(int V); // Constructor

    // Function to add an edge to graph 
    void addEdge(int u,int v,int w);

    void  shortPath(int s); //Print shortest path from source

};

Graph::Graph(int V)
{
    this->V=V;
    adj=new list<pair<int,int>>[V];
}

// Utility function to add edge an graph 

void Graph::addEdge(int u,int v,int w)
{
    adj[u].push_back(make_pair(v,w));
    adj[v].push_back(make_pair(u,w));
}

// Utility Funciton to print path from the source to all the other vertices 
void Graph::shortPath(int src)
{
    // Create a set to store the vertices that are being proceed 
    set<pair<int,int>>setds;

    // Create a vrctor for distances and Inilialise all of them are infinite
    vector<int>dis(V,INF);

    // Insert source itself in the set and initialize it by 0
    setds.insert(make_pair(0,src));
    dis[src]=0;

    /* Looping till all shortest distance are finalized
       then setds will become empty */
    while(!setds.empty())
    {
        // The first vertex in Set is the minimum distance
        // vertex, extract it from set.
        pair<int, int> tmp = *(setds.begin());
        setds.erase(setds.begin());

        // As in the set first parth is for distances and the second part for the vertices 
        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted distance (distance must be first item
        // in pair)
        int u = tmp.second;

        // Initialising the iterator to get the all adjacent vertices of a vectex
        list<pair<int,int>>::iterator i;
        for(i=adj[u].begin();i!=adj[u].end();++i)
        {
            // get the vertex label and the weight of current adjacent vertex
            int v=(*i).first;
            int weight=(*i).second;
            
            // If there is a shortest path from u to v 
            if(dis[v]>dis[u]+weight)
            {
                /*  If distance of v is not INF then it must be in
                    our set, so removing it and inserting again
                    with updated less distance.  
                    Note : We extract only those vertices from Set
                    for which distance is finalized. So for them, 
                    we would never reach here.  */
                if(dis[v]!=INF)
                {
                    setds.erase(setds.find(make_pair(dis[v],v)));
                }
                dis[v]=dis[u]+weight;
                setds.insert(make_pair(dis[v],v));
            }
        }

    }

    // Printing the shortest distance stored in the dis[]
    cout<<"Printing the shortes distances from the source:"<<'\n';
    cout<<"Vertex \t  Distance from source: "<<'\n';
    for(int i=0;i<V;++i)
    {
        cout<<i<<"\t\t"<<dis[i]<<'\n';
    }
    
}

int main()
{
    int V=9;
    Graph g(V);
    g.addEdge(0,1,4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
  
    g.shortPath(0);

    return 0;
}