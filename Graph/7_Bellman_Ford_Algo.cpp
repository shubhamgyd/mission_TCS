// In this program we are going to see the shortest path from the source to destination

// Variation of Dijaktras Algorithm


#include<bits/stdc++.h>
using namespace std;

struct Edge 
{
    int src,dest,weight;
};

struct Graph
{
    // V-> Number of vertices, E-> Number of edges
    int V,E;

    //Structure to represent an array of graph
    struct Edge* edge;
};

struct subset
{
    int parent,rank;
};

struct Graph* createGraph(int V,int E)
{
    struct Graph* graph=(struct Graph*)malloc(sizeof(struct Graph));
    graph->V=V;
    graph->E=E;
    graph->edge=(struct Edge*)malloc(graph->E*sizeof(struct Edge));
    return graph;
}



void printArr(int des[],int n)
{
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < n; ++i)
        printf("%d \t\t %d\n", i, des[i]);
}

// The main function that finds shortest distances from src to
// all other vertices using Bellman-Ford algorithm.  The function
// also detects negative weight cycle
void BellmanFord(struct Graph* graph,int src)
{
    int V=graph->V;
    int E=graph->E;
    int des[V];

     // Step 1: Initialize distances from src to all other vertices
    // as INFINITE
    for(int i=0;i<V;i++)
    {
        des[i]=INT_MAX;
    }
    des[src]=0;
    


    // Step 2: Relax all edges |V| - 1 times. A simple shortest
    // path from src to any other vertex can have at-most |V| - 1
    // edges
    for(int i=1;i<V;i++)
    {
        for(int j=0;j<E;j++)
        {
            int u=graph->edge[j].src;
            int v=graph->edge[j].dest;
            int weight=graph->edge[j].weight;
            if(des[u]!=INT_MAX&&des[v]>des[u]+weight)
            {
                des[v]=des[u]+weight;
            }
        }
    }

    
    // Step 3: check for negative-weight cycles.  The above step
    // guarantees shortest distances if graph doesn't contain
    // negative weight cycle.  If we get a shorter path, then there
    // is a cycle.

    for(int j=0;j<E;j++)
    {
        int u=graph->edge[j].src;
            int v=graph->edge[j].dest;
            int weight=graph->edge[j].weight;
            if(des[u]!=INT_MAX&&des[v]>des[u]+weight)
            {
                cout<<"Graph Contains negative cycle: "<<endl;
                return; // If negative cycle is detected, simply return
            }
    }
    printArr(des,V);
}

int main()
{
    int V=5;
    int E=8;
    struct Graph* graph = createGraph(V, E);

    // Add edge 0-1 or A-B 
    graph->edge[0].src=0;
    graph->edge[0].dest=1;
    graph->edge[0].weight=-1;

    // add edge 0-2 or A-C

    graph->edge[1].src=0;
    graph->edge[1].dest=2;
    graph->edge[1].weight=4;

    // add edge 1-2 (or B-C in above figure)
    graph->edge[2].src = 1;
    graph->edge[2].dest = 2;
    graph->edge[2].weight = 3;
  
    // add edge 1-3 (or B-D in above figure)
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 2;
  
    // add edge 1-4 (or A-E in above figure)
    graph->edge[4].src = 1;
    graph->edge[4].dest = 4;
    graph->edge[4].weight = 2;
  
    // add edge 3-2 (or D-C in above figure)
    graph->edge[5].src = 3;
    graph->edge[5].dest = 2;
    graph->edge[5].weight = 5;
  
    // add edge 3-1 (or D-B in above figure)
    graph->edge[6].src = 3;
    graph->edge[6].dest = 1;
    graph->edge[6].weight = 1;
  
    // add edge 4-3 (or E-D in above figure)
    graph->edge[7].src = 4;
    graph->edge[7].dest = 3;
    graph->edge[7].weight = -3;
  
    BellmanFord(graph, 0);
  
    return 0;

}


// Notes
// 1) Negative weights are found in various applications of graphs. 
// For example, instead of paying cost for a path, we may get some advantage if we follow the path.

// 2) Bellman-Ford works better (better than Dijksra’s) for distributed systems. 
// Unlike Dijkstra’s where we need to find the minimum value of all vertices, in Bellman-Ford, 
// edges are considered one by one.