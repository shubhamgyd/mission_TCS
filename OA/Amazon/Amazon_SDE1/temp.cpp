#include <bits/stdc++.h>
using namespace std;

void dfs(int src, vector<int> graph[], vector<int> &visited)
{
    visited[src] = 1;
    for (auto ele : graph[src])
    {
        if (!visited[ele])
        {
            dfs(ele, graph, visited);
        }
    }
}

int minOperations(int comp_nodes, vector<int> comp_from, vector<int> comp_to)
{
    int nodes = comp_from.size();
    int n = comp_nodes;
    if (nodes < n - 1)
    {
        return -1;
    }
    vector<int> graph[n];
    for (int i = 0; i < nodes; i++)
    {
        int a = comp_from[i];
        int b = comp_to[i];
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> visited(n, 0);
    int ct = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            ct++;
            dfs(i, graph, visited);
        }
    }
    return ct - 1;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
        cin >> b[i];
    }
    cout << minOperations(n, a, b) << endl;
    return 0;
}