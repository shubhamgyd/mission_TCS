#include <bits/stdc++.h>
using namespace std;

vector<int> countFrequency(vector<vector<char>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    vector<int> ans(26, 0);
    for (int i = 0; i < n; i += 2)
    {
        for (int j = 0; j < m; j++)
        {
            ans[mat[i][j] - 'a']++;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<char>> mat(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }
    vector<int> ans = countFrequency(mat);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}