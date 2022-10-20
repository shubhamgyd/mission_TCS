#include <bits/stdc++.h>
using namespace std;

int solve(int source, int destination)
{
    // cout << source << destination << endl;
    int n = 8;
    map<int, pair<int, int>> mp;
    int num = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            mp[num] = {i, j};
            num++;
        }
    }
    int x1 = mp[source].first;
    int y1 = mp[source].second;

    int x2 = mp[destination].first;
    int y2 = mp[destination].second;
    if (x1 == x2 and y1 == y2)
    {
        return 0;
    }
    queue<pair<pair<int, int>, int>> q;
    vector<vector<int>> visited(n, vector<int>(n, 0));
    q.push({{x1, y1}, 0});
    visited[x1][y1] = 1;
    int dir_x[] = {-1, -2, -2, -1, 1, 1, 2, 2};
    int dir_y[] = {-2, -1, 1, 2, -2, 2, -1, 1};
    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int steps = q.front().second;
        q.pop();
        if (x == x2 && y == y2)
        {
            return steps;
        }
        for (int i = 0; i < 8; i++)
        {
            int newx = x + dir_x[i];
            int newy = y + dir_y[i];
            if (newx >= 0 && newx < n && newy >= 0 && newy < n && visited[newx][newy] == 0)
            {
                q.push({{newx, newy}, steps + 1});
                visited[newx][newy] = 1;
            }
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n = 8;
    int source, destination;
    cin >> source >> destination;
    int ans = solve(source, destination);
    cout << ans << endl;
    return 0;
}