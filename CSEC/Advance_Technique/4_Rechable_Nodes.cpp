// https://www.geeksforgeeks.org/find-all-reachable-nodes-from-every-node-present-in-a-given-set/

#include <bits/stdc++.h>
using namespace std;

const int maxN = 5e4 + 1;
bitset<maxN> ans[maxN];

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    vector<int> incoming(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);
        incoming[a]++;
    }
    queue<int> nodes;
    for (int i = 1; i <= n; i++)
    {
        if (incoming[i] == 0)
        {
            nodes.push(i);
            ans[i].set(i);
        }
    }

    while (!nodes.empty())
    {
        auto s = nodes.front();
        nodes.pop();
        for (auto it : adj[s])
        {
            ans[it] |= ans[s];
            incoming[it]--;
            if (incoming[it] == 0)
            {
                nodes.push(it);
                ans[it].set(it);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i].count() << " ";
    }
    return 0;
}