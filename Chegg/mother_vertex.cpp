/* Priyansh Agarwal*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <unordered_set>
#include <cmath>
#include <numeric>
#include <iterator>
#include <set>
#include <unordered_map>
#include <map>
#include <queue>
#include <cstring>
#include <stdio.h>
#include <fstream>
#include <iomanip>
#include <functional>
#include <bitset>
#include <chrono>
#include <climits>
#include <assert.h>

using namespace std;

#define nline "\n"
#define pb push_back

string s;
int dp[300005][26];
int n, m;
bool dfs(int start, vector<int> *edges, bool *w, bool *g, bool *b)
{
    w[start] = false;
    g[start] = true;
    for (auto i : edges[start])
    {
        if (g[i])
            return false;
        if (w[i])
        {
            bool ans = dfs(i, edges, w, g, b);
            if (!ans)
                return false;
        }
    }
    g[start] = false;
    b[start] = true;
    return true;
}
bool cycle(vector<int> *edges)
{
    bool *white = new bool[n]();
    bool *grey = new bool[n]();
    bool *black = new bool[n]();
    for (int i = 0; i < n; i++)
        white[i] = true;
    for (int i = 0; i < n; i++)
    {
        if (white[i])
        {
            bool ans = dfs(i, edges, white, grey, black);
            if (!ans)
                return true;
        }
    }
    return false;
}
void dfs1(int start, vector<int> *edges, vector<int> &ans, bool *visited)
{
    visited[start] = true;
    for (auto i : edges[start])
    {
        if (!visited[i])
            dfs1(i, edges, ans, visited);
    }
    ans.pb(start);
}
vector<int> topo_sort(vector<int> *edges)
{
    bool *visited = new bool[n]();
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (visited[i])
            continue;
        dfs1(i, edges, ans, visited);
    }
    return ans;
}
void solve()
{
    cin >> n >> m;
    cin >> s;
    vector<int> *edges = new vector<int>[n];
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        edges[a - 1].pb(b - 1);
    }
    if (cycle(edges))
        cout << -1 << nline;
    else
    {
        vector<int> v1 = topo_sort(edges);
        for (auto i : v1)
        {
            for (int j = 0; j < 26; j++)
                dp[i][j] = 0;
            if (edges[i].size() == 0)
            {
                dp[i][s[i] - 'a'] = 1;
                continue;
            }
            for (int j = 0; j < 26; j++)
                dp[i][j] = 0;
            for (auto j : edges[i])
            {
                for (int k = 0; k < 26; k++)
                {
                    dp[i][k] = max(dp[i][k], (s[i] - 'a' == k) + dp[j][k]);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 26; j++)
                ans = max(ans, dp[i][j]);
        }
        cout << ans << nline;
    }
}

int main()
{
    solve();
    return 0;
}