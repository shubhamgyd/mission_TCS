// In this algorithm we are looking towards the modified DFS of cyclic directed grpah
#include<bits/stdc++.h>
using namespace std;

// Class represent the graph
class Graph
{
    int V; //Represent the number of vertices

    list<int>*adj; //  adjacency list To store the the vertices 
    void topologicalSortUtil(int v,bool visited[],stack<int>&Stack);
public:
    Graph(int V); //Constructor

    void addEdge(int v,int w); //Function to add the edge to graph

    void topologicalSort();// Print the topological sort of the graph
};

Graph::Graph(int V)
{
    this->V=V;
    adj=new list<int>[V];
}

void Graph::addEdge(int v,int w)
{
    //add w to v's list
    adj[v].push_back(w);
}

void Graph::topologicalSortUtil(int v,bool visited[],stack<int>&Stack)
{
    visited[v]=true; // Mark the current vertes true;

    //Recursive call to all the adjacency children
    list<int>::iterator it;
    for(it=adj[v].begin();it!=adj[v].end();it++)
    {
        if(!visited[*it])
        {
            topologicalSortUtil(*it,visited,Stack);
        }
    }

    // Pushing the current vertes into the stack ..if it have no childern either all its children 
    // are already marked/pushed.
    Stack.push(v);

}

void Graph::topologicalSort()
{
    stack<int>Stack;

    // Mark all the vertices as not visited
    bool* visited= new bool[V];
    for(int i=0;i<V;i++)
    {
        visited[i]=false;
    }
    

    // Call the recursive helper function
    // to store Topological
    // Sort starting from all
    // vertices one by one
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            topologicalSortUtil(i, visited, Stack);
 
    // Print contents of stack
    while (Stack.empty() == false) {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}

int main()
{
    Graph g(6); // Object initialization

    // Adding the edges int the graph 
    g.addEdge(5,2);
    g.addEdge(4, 5);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    // g.addEdge(3, 6);
    // g.addEdge(1, 2);
    // g.addEdge(5, 3);
 
    cout << "Following is a Topological Sort of the given "
            "graph \n";
 
    // Function Call
    g.topologicalSort();
 
    return 0;
}