/*
Problem Statement: Given is a 2D adjacency list representation of a graph.
Check whether the graph is Bipartite graph. (Note: In a Bipartite graph,
one can color all the nodes with exactly 2 colors such that no two adjacent
nodes have the same color)
*/

#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<int> &color, int node, vector<int> adj[])
{
    if (color[node] == -1)
        color[node] = 1;

    for (auto nbr : adj[node])
    {
        if (color[nbr] == -1)
        {
            color[nbr] = 1 - color[node];
            if (!dfs(color, nbr, adj))
                return false;
        }
        else if (color[nbr] == color[node])
            return false;
    }
    return true;
}

bool isGraphBirpatite(vector<vector<int>> &edges)
{
    // Write your code here.
    int n = edges.size();
    int V = n;
    vector<int> adj[n + 1];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (edges[i][j] == 1)
            {
                if (i != j)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
    }
    vector<int> color(V, -1);
    for (int i = 0; i < V; i++)
    {
        if (!dfs(color, i, adj))
        {
            return false;
        }
    }
    return true;
}
/*
Time Complexity: O(V + E), since in its whole, it is a DFS implementation, V – vertices; E – edges;
Space Complexity: O(V), because, apart from the graph, we maintain a color array.
*/

int main()
{
}