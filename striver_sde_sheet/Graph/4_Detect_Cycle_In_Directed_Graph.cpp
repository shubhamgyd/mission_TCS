#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
bool DFS(int src, vector<int> adj[], vector<bool> &visited, vector<int> &dfsOrder)
{
    dfsOrder[src] = 1;
    visited[src] = true;
    for (auto it : adj[src])
    {
        if (!visited[it])
        {
            if (DFS(it, adj, visited, dfsOrder))
            {
                return true;
            }
        }
        else if (dfsOrder[it])
            return true;
    }
    dfsOrder[src] = 0;
    return false;
}
int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    // Write your code here.
    vector<int> adj[n + 1];
    for (auto it : edges)
    {
        int u = it.first;
        int v = it.second;
        adj[u].push_back(v);
    }
    vector<bool> visited(n + 1, false);
    vector<int> dfsOrder(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            if (DFS(i, adj, visited, dfsOrder))
            {
                return true;
            }
        }
    }
    return false;
}

/*
Time Complexity: O(V + E), since in its whole, it is a DFS implementation, V – vertices; E – edges;
Space Complexity: O(V), because, apart from the graph, we have 2 arrays of size V, to store the required information
*/