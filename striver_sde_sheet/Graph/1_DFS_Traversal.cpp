/*
Problem Statement
Given an undirected and disconnected graph G(V, E), containing 'V' vertices and 'E' edges, the information about edges is given using 'GRAPH' matrix, where i-th edge is between GRAPH[i][0] and GRAPH[i][1]. print its DFS traversal.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.

E is the number of edges present in graph G.
Note :
The Graph may not be connected i.e there may exist multiple components in a graph.
Input Format :
The first line of input will contain two Integers V and E, separated by a single space.

From the second line onwards, the next 'E' lines will denote the undirected edge of the graphs.

Every edge is defined by two single space-separated integers 'a' and 'b', which signifies an edge between the vertices 'a' and 'b'.
Output Format :
The first line of output will contain the size of the connected components.

For every connected component in the graph, print the vertices of the component in the sorted order of the vertex values separated with a single space.

Print each component in on a different line by making sure that the first vertex of each component is also sorted on the vertex values.

A component having a smaller first vertex in sorted order will come first.
Constraints :
2 <= V <= 10^3
1 <= E <= (5 * (10^3))

Time Limit: 1sec
Sample Input 1:
5 4
0 2
0 1
1 2
3 4
Sample Output 1:
2
0 1 2
3 4
*/

#include <bits/stdc++.h>
using namespace std;

void DFS(int src, vector<int> adj[], vector<bool> &visited, vector<int> &node)
{
    if (visited[src])
        return;
    node.push_back(src);
    visited[src] = true;
    for (auto it : adj[src])
        DFS(it, adj, visited, node);
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<vector<int>> res;
    vector<int> adj[V];
    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(V, false);
    for (int i = 0; i <= V - 1; i++)
    {
        if (!visited[i])
        {
            vector<int> node;
            DFS(i, adj, visited, node);
            res.push_back(node);
        }
    }
    return res;
}