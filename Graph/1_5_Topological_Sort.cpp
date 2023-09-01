#include <bits/stdc++.h>
using namespace std;

void topoSort(int src, stack<int> &st, vector<bool> &visited, vector<int> adj[])
{
    visited[src] = true;
    for (auto it : adj[src])
    {
        if (!visited[it])
        {
            topoSort(it, st, visited, adj);
        }
    }
    st.push(src);
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    stack<int> st;
    vector<bool> visited(n + 1, false);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            topoSort(i, st, visited, adj);
        }
    }
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}