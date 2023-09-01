#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> res(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> res[i][j];
        }
    }
    unordered_map<int, pair<int, int>> row, col;
    for (int i = 0; i < n; i++)
    {
        int black = 0;
        int white = 0;
        for (int j = 0; j < m; j++)
        {
            if (res[i][j] == 1)
                black++;
            else
                white++;
        }
        row[i].first = black;
        row[i].second = white;
    }
    for (int j = 0; j < m; j++)
    {
        int black = 0;
        int white = 0;
        for (int i = 0; i < n; i++)
        {
            if (res[i][j] == 1)
                black++;
            else
                white++;
        }
        col[j].first = black;
        col[j].second = white;
    }
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int totalBlack = row[i].first + col[i].first;
            int totalWhite = row[j].second + col[j].second;
            mx = max(mx, abs(totalBlack - totalWhite));
        }
    }
    cout << mx << endl;
    return 0;
}