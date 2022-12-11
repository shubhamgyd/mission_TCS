#include <iostream>
#include <map>
using namespace std;

int main()
{
    // Read number of nodes in graph and number of edges in a graph
    int n, m;
    cin >> n >> m;
    // store graph representation
    map<int, map<int, int>> graph;
    // Read m edges as direction from u to v
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        // put into graph,
        // u->v
        graph[u][v]++;
    }
    // keep track on all nodes are connected by birectional edges or not
    bool isAllEdge = true;
    // Iterate graph
    for (auto it : graph)
    {
        // get u
        int u = it.first;
        // iterate into adjacency list of u
        for (auto adj : it.second)
        {
            // get v
            int v = adj.first;
            // check there is a edge v->u is present in graph or not
            // is no then mark isAllEdge as false
            // and break the loop
            if (graph[v][u] == 0)
            {
                isAllEdge = false;
                break;
            }
        }
    }
    // is condition satisfied
    // print true
    if (isAllEdge)
    {
        cout << "True\n";
    }
    // else print false
    else
    {
        cout << "False\n";
    }
    return 0;
}