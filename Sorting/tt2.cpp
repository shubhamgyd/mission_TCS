#include <bits/stdc++.h>
using namespace std;
#define int long long

struct node
{
    int u;
    int v;
    int wt;
    node(int first, int second, int weight)
    {
        u = first;
        v = second;
        wt = weight;
    }
};

bool comp(node a, node b)
{
    return a.wt < b.wt;
}

int findPar(int u, vector<int> &parent)
{
    if (u == parent[u])
        return u;
    return findPar(parent[u], parent);
}

void unionn(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findPar(u, parent);
    v = findPar(v, parent);
    if (rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else if (rank[v] < rank[u])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;
        rank[u]++;
    }
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
        int n, m;
        cin >> n >> m;
        vector<int> A(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> A[i];
        }
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            pair<int, int> p = {a, b};
            mp[p]++;
        }
        vector<node> edges;
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                pair<int, int> p = {i, j};
                if (mp.find(p) == mp.end())
                {
                    int wt = A[i] * A[j];
                    edges.push_back(node(i, j, wt));
                }
            }
        }
        sort(edges.begin(), edges.end(), comp);
        vector<int> parent(n + 1);
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
        }

        vector<int> rank(n + 1, 0);

        int cost = 0;
        vector<pair<int, int>> mst;
        vector<bool> visited(n + 1, false);
        for (auto it : edges)
        {
            if (findPar(it.v, parent) != findPar(it.u, parent))
            {
                cost += it.wt;
                visited[it.u] = true;
                visited[it.v] = true;
                mst.push_back({it.u, it.v});
                unionn(it.u, it.v, parent, rank);
            }
        }
        bool ok = true;
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                cout << -1 << endl;
                ok = false;
                break;
            }
        }
        if (ok)
        {
            cout << cost << endl;
        }
    }
}