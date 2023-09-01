#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    int maxTime;
    cin >> maxTime;
    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, 0});
    int dir_x[4] = {0, 0, 1, -1};
    int dir_y[4] = {1, -1, 0, 0};
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        int x = it.first.first;
        int y = it.first.second;
        int steps = it.second;
        if (x == n - 1 and y == m - 1 and steps <= maxTime)
        {
            cout << "Yes\n";
            return 0;
        }
        for (int i = 0; i < 4; i++)
        {
            int new_x = x + dir_x[i];
            int new_y = y + dir_y[i];
            if (new_x < n and new_x >= 0 and new_y < m and new_y >= 0 and grid[new_x][new_y] != '#' and !visited[new_x][new_y])
            {
                visited[new_x][new_y] = true;
                q.push({{new_x, new_y}, steps + 1});
            }
        }
    }
    cout << "No\n";
    return 0;
}