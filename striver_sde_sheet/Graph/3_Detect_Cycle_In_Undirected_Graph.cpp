#include <bits/stdc++.h>
using namespace std;

// Using DFS
bool DFS(int src, vector<int> adj[], vector<bool> &visited, int parent)
{
    visited[src] = true;
    for (auto it : adj[src])
    {
        if (!visited[it])
        {
            if (DFS(it, adj, visited, src))
                return true;
        }
        else if (it != parent)
        {
            return true;
        }
    }
    return false;
}
string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    // Write your code here.
    int incoming[n + 1];
    memset(incoming, 0, sizeof(incoming));
    vector<int> adj[n + 1];
    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            if (DFS(i, adj, visited, -1))
            {
                return "Yes";
            }
        }
    }
    return "No";
}

// Using BFS
bool checkForCycle(int s, int V, vector<int> adj[], vector<int> &visited)
{
    // Create a queue for BFS
    queue<pair<int, int>> q;
    visited[s] = true;
    q.push({s, -1});
    while (!q.empty())
    {
        int node = q.front().first;
        int par = q.front().second;
        q.pop();

        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                visited[it] = true;
                q.push({it, node});
            }
            else if (par != it)
                return true;
        }
    }
    return false;
}
bool isCycle(int V, vector<int> adj[])
{
    vector<int> vis(V - 1, 0);
    for (int i = 1; i <= V; i++)
    {
        if (!vis[i])
        {
            if (checkForCycle(i, V, adj, vis))
                return true;
        }
    }
}
/*
Time Complexity: O(N+E),  N is the time taken and E is for traveling through adjacent nodes overall. 
Space Complexity: O(N+E) +  O(N) + O(N) , space for adjacent list , array and queue
*/

int main()
{
    vector<vector<int>> arr = {{1, 2}, {1, 3}, {3, 4}, {2, 4}, {3, 5}};
    cycleDetection(arr, 5, 5);
}