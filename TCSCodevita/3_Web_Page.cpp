#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> adj[n + 1];
    for (int i = 1; i <= n; i++)
    {
        do {
            int v;
            char sep;
            auto code = scanf("%d%c", &v, &sep);
            if (code >= 1)
            {
                adj[i].push_back(v);
            }
            if (code < 2 || sep == '\n')
            {
                break;
            }
        } while(true);
    }
    int src, target;
    cin >> src >> target;
    vector<bool> visited(n + 1, false);
    int dist[n + 1];
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        dist[i] = INT_MAX;
    }
    visited[src] = true;
    dist[src] = 0;
    q.push(src);
    while (!q.empty())
    {
        int it = q.front();
        q.pop();
        for (auto ele : adj[it])
        {
            if (visited[ele])
            {
                continue;
            }
            else
            {
                visited[ele] = true;
                dist[ele] = dist[it] + 1;
                q.push(ele);
            }
        }
    }
    if (dist[target] == INT_MAX)
    {
        cout << -1;
    }
    else
    {
        cout << dist[target];
    }
    return 0;
}