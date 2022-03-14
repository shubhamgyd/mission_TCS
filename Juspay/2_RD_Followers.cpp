#include <bits/stdc++.h>
using namespace std;

vector<pair<long long int, long long int>> a[100000];
vector<int>visited(100000, 0);
long long int mn = 999999999999999, res = 0, k = mn;
void dfs(long long int u, long long int v)
{
    if (u == v)
    {
        if (mn > res)
        {
            mn = res;
        }
    }
    visited[u] = 1;
    for (auto j : a[u])
    {
        if (visited[j.first] == 0)
        {
            res += j.second;
            visited[j.first] == 1;
            dfs(j.first, v);
            visited[j.first] == 0;
            res -= j.second;
        }
    }
    visited[u] = 0;
}
int main()
{
    long long int n, e, x, y, i, w;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> x;
    }
    cin >> e;
    for (i = 0; i < e; i++)
    {
        cin >> x >> y >> w;
        a[x].push_back({y, w});
    }
    cin >> x >> y;
    dfs(x, y);
    if (mn == k)
        cout << "-1";
    else
        cout << mn;
    return 0;
}