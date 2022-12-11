#include <bits/stdc++.h>
using namespace std;
int uniquePathsWithObstacles(vector<vector<int>> &grid)
{
    const int mod = 1e9;
    int n = grid.size();
    int m = grid[0].size();

    vector<int> prev(m, 0), curr(m, 0);
    prev[0] = grid[0][0] == 0 ? 1 : 0;
    for (int i = 1; i < m; i++)
    {
        if (grid[0][i] == 1)
            prev[i] = 0;
        else
            prev[i] += prev[i - 1];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (j == 0)
            {
                if (grid[i][j] == 1)
                    curr[j] = 0;
                else
                    curr[j] = prev[j];
            }
            else
            {
                if (grid[i][j] == 1)
                {
                    curr[j] = 0;
                }
                else
                {
                    curr[j] = curr[j - 1] + prev[j];
                }
            }
        }
        prev = curr;
    }
    return prev[m - 1];
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << uniquePathsWithObstacles(arr) << endl;
    return 0;
}