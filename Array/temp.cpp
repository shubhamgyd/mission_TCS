#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;


class Solution
{
    void dfs(vector<vector<int>> &grid, int i, int j, int n, int m)
    {
        if (i >= n || i < 0 || j < 0 || j >= m || grid[i][j] == 0)
        {
            return;
        }
        grid[i][j] = 0;
        dfs(grid, i + 1, j, n, m);
        dfs(grid, i - 1, j, n, m);
        dfs(grid, i, j + 1, n, m);
        dfs(grid, i, j - 1, n, m);
    }

public:
    int numIslands(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int islands = 0;
        if (grid.empty())
        {
            return islands;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    islands++;
                    dfs(grid, i, j, n, m);
                }
            }
        }
        return islands;
    }
};

int main()
{
    FASTIO;
    cout << "Enter number of rows and column: ";
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    Solution obj;
    int number_of_Islands = obj.numIslands(grid);
    cout << "Total number of islands: " << number_of_Islands << endl;
    return 0;
}