/*
Suppose you are given a grid of 1's and 0's. All adjacent 1's are connected components.
For example, in the following case you have 2 connected components because you have two "islands" of 1's.
1 1 0 0 1 1
1 0 0 0 1 1
1 0 0 0 0 0

Now you have a function called insertValue(coordinates) which takes in a row and column and inserts a 1. The function must return the updated number of connected components. So for example:
init:
1 1 0 0 1 1
1 0 0 0 1 1
1 0 0 0 0 0

insertValue(row=1, col=1) gives 2 connected components still because
grid is:
1 1 0 0 1 1
1 1 0 0 1 1
1 0 0 0 0 0

insertValue(row=1, col=2) gives 2 connected components still because
grid is:
1 1 0 0 1 1
1 1 1 0 1 1
1 0 0 0 0 0

insertValue(row=1, col=3) gives 3 connected components still because
grid is:
1 1 0 0 1 1
1 1 1 1 1 1
1 0 0 0 0 0
*/

#include <bits/stdc++.h>
using namespace std;

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

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> nums(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> nums[i][j];
        }
    }
    int row, col;
    cin >> row >> col;
    nums[row][col] = 1;
    int ct = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (nums[i][j] == 1)
            {
                ct++;
                dfs(nums, i, j, n, m);
            }
        }
    }
    cout << ct << endl;
    return 0;
}