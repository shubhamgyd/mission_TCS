/*
Description
Given a m * nm∗n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

The robot can only move either down or right at any point in time.

Example
Example 1:

Input:

grid = [[1,3,1],[1,5,1],[4,2,1]]
Output:

7
Explanation:

Path is: 1 -> 3 -> 1 -> 1 -> 1

Example 2:

Input:

grid = [[1,3,2]]
Output:

6
Explanation:

Path is: 1 -> 3 -> 2
*/

#include <bits/stdc++.h>
using namespace std;

int solve(int i, int j, int n, int m, vector<vector<int>> &A, vector<vector<int>> &dp)
{
    // if robot goes beyond grid
    if (i >= n || j >= m || j < 0 || i < 0)
    {
        return INT_MAX;
    }

    // if robot reached to the bottom right just return the value of cell
    if (i == n - 1 and j == m - 1)
    {
        return A[i][j];
    }

    // if we have already calculated minValue of cell, then don't calculate again, just
    // return it
    if (dp[i][j] != INT_MAX)
    {
        return dp[i][j];
    }

    // find the min value by going down and right of current cell
    // return min ( down, right)
    int a = solve(i + 1, j, n, m, A, dp);
    int b = solve(i, j + 1, n, m, A, dp);

    // return current cell +min(minDown,minRight)
    return dp[i][j] = A[i][j] + min({a, b});
}

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

    // Solution 1 + 2: Recursive + Memoization
    vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
    int minSum = solve(0, 0, n, m, res, dp);
    cout << minSum << endl;

    // solution 3: Tabulation
    int table[n][m];
    table[0][0] = res[0][0];

    // if we go right , then fill first row as the sum of cells before current cell
    for (int j = 1; j < m; j++)
    {
        table[0][j] = table[0][j - 1] + res[0][j];
    }

    // if robot goes down , then fill every cell with the sum to reach to current cell
    for (int i = 1; i < n; i++)
    {
        table[i][0] = table[i - 1][0] + res[i][0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            // fill the current cell with min path sum to reach from up and left + value of that cell
            table[i][j] = min(table[i - 1][j], table[i][j - 1]) + res[i][j];
        }
    }

    // return ans
    cout << table[n - 1][m - 1] << endl;






    // Solution 4: Space Optimize
    vector<int> prev(m, 0), curr(m);
    prev[0] = res[0][0];
    for (int j = 1; j < m; j++)
    {
        prev[j] += prev[j - 1] + res[0][j];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (j == 0)
                curr[j] = prev[j] + res[i][j];
            else
            {
                curr[j] = min(prev[j], curr[j - 1]) + res[i][j];
            }
        }
        swap(curr, prev);
    }
    cout << prev[m - 1] << endl;

    return 0;
}