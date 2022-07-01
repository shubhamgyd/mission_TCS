/*
Problem Statement
A Directed Acyclic Graph (DAG) is a directed graph that contains no cycles.
Topological Sorting of DAG is a linear ordering of vertices such that for every directed edge from vertex ‘u’ to vertex ‘v’, vertex ‘u’ comes before ‘v’ in the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG.
Given a DAG consisting of ‘V’ vertices and ‘E’ edges, you need to find out any topological sorting of this DAG. Return an array of size ‘V’ representing the topological sort of the vertices of the given DAG.
For example, Consider the DAG shown in the picture.

In this graph, there are directed edges from 0 to 1 and 0 to 3, so 0 should come before 1 and 3. Also, there are directed edges from 1 to 2 and 3 to 2 so 1 and 3 should come before 2.
So, The topological sorting of this DAG is {0 1 3 2}.
Note that there are multiple topological sortings possible for a DAG. For the graph given above one another topological sorting is: {0, 3, 1, 2}

*/

#include <bits/stdc++.h>
using namespace std;

// Using DFS
void DFS(int src, vector<int> adj[], vector<bool> &visited, vector<int> &ans)
{
    if (visited[src])
        return;
    visited[src] = true;
    for (auto it : adj[src])
    {
        DFS(it, adj, visited, ans);
    }
    ans.push_back(src);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    // Write your code here
    vector<int> adj[v + 1];
    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        adj[u].push_back(v);
    }
    vector<bool> visited(v + 1, false);
    vector<int> ans;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            DFS(i, adj, visited, ans);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

// Using BFS
vector<int> topo(int N, vector<int> adj[])
{
    queue<int> q;
    vector<int> indegree(N, 0);
    for (int i = 0; i < N; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> topo;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
    return topo;
}

// Time Complexity: O(N+E)
// Space complexity: O(N)+O(N)