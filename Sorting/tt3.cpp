#include <bits/stdc++.h>
using namespace std;
#define int long long

int DFS(int src, vector<int> adj[], vector<int> &reachable, vector<bool> &visited)
{
    visited[src] = true;
    reachable[src] = adj[src].size();
    for (auto it : adj[src])
    {
        if (!visited[it])
        {
            reachable[src] += DFS(it, adj, reachable, visited);
        }
    }
    return reachable[src];
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> nums(n + 1);
        vector<int> adj[n + 1];
        vector<int> inde(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            cin >> nums[i];
            adj[i].push_back(nums[i]);
            inde[nums[i]]++;
        }
        vector<int> reachable(n + 1, 0);
        vector<bool> visited(n + 1, false);
        for (int i = 1; i <= n; i++)
        {
            if (inde[i] == 0)
            {
                DFS(i, adj, reachable, visited);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            cout << reachable[i] << " ";
        }
        cout << endl;
    }
}