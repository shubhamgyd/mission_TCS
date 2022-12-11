#include <bits/stdc++.h>
using namespace std;

int kMaxDifference(vector<vector<int>> adj, int k, int n, int m)
{
    // cout << "here" << endl;
    int preInc[n], preOut[n];
    memset(preInc, 0, sizeof(preInc));
    memset(preOut, 0, sizeof(preOut));
    for (int i = 0; i < m; i++)
    {

        int a, b;
        a = adj[i][0];
        b = adj[i][1];

        preInc[b]++;
        preOut[a]++;
    }
    int afterInc[n], afterOut[n];
    memset(afterInc, 0, sizeof(afterInc));
    memset(afterOut, 0, sizeof(afterOut));
    for (int i = 0; i < m; i++)
    {
        int a, b;
        a = adj[i][0];
        b = adj[i][1];

        afterInc[a]++;
        afterOut[b]++;
    }
    int diff = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % k == 0)
        {
            diff = max(diff, abs(preOut[i] - preInc[i]));
        }
        else
        {
            diff = max(diff, abs(afterInc[i] - afterOut[i]));
        }
    }
    return diff;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> adj;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj.push_back({a, b});
    }
    int ans = kMaxDifference(adj, k, n, m);
    cout << ans << endl;
    return 0;
}