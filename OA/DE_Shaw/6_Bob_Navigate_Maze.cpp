/*
Bob and Alice have teamed up on a game show. After winning the first round, they now have access to a maze with hidden gold. If Bob can collect all the gold coins and deliver them to Alice's position, they can split the gold. Bob can move horizontally or vertically as long as he stays in the maze, and the cell is not blocked.

The maze is represented by an n × m array. Each cell has a value, where 0 is open, 1 is blocked, and 2 is open with a gold coin. Bob starts at the top left in cell in (row, column) = (0, 0). Alice's position is given by (x,y).

Determine the shortest path Bob can follow to collect all gold coins and deliver them to Alice. If Bob can't collect and give all the gold coins, return -1.

Example: maze = [[0,2,1],[1,2,0],[1,0,0]] with Alice at (2,2) is represented as follows:
image

B represents Bob’s starting position at (0,0), and A represents Alice’s position (which will also be Bob’s final position). As Bob starts at (0,0), he has two possible paths to collect the gold and deliver to Alice: (0, 0) → (0, 1) → (1, 1) → (2, 1) → (2, 2) and (0, 0) → (0, 1) → (1, 1) → (1, 2) → (2,2). Both paths have a length of 4 and could represent the shortest path.

Function Description

Complete the function minMoves in the editor below. The function must return the integer length of Bob's shortest path, or -1 if it's not possible.

minMoves has the following parameter(s):

maze[maze[0][0],...maze[n-1][m-1]]:  a 2D array of integers

x:  an integer denoting Alice's row coordinate

y:  an integer denoting Alice's column coordinate
Constraints

1 ≤ n, m ≤ 100
0 ≤ the number of coins ≤ 10
1 ≤ x < n
1 ≤ y < m
Sample Input 0

STDIN Function Parameters

3 → maze[][] number of rows n = 3
3 → maze[][] number of columns m = 3
0 2 0 → maze[][] = [ [0 2 0], [0 0 1], [1 1 1] ]
0 0 1
1 1 1
1 → x = 1
1 → y = 1

Sample Output 0
2

Explanation 0
image

The shortest path Bob can take is (0, 0) → (0, 1) → (1, 1).

Sample Input 1

STDIN Function Parameters

3 → maze[][] number of rows n = 3
3 → maze[][] number of columns m = 3
0 1 0 → maze[][] = [ [0 1 0], [1 0 1], [0 2 2] ]
1 0 1
0 2 2
1 → x = 1
1 → y = 1

Sample Output 1
-1

Explanation 1
image

It is not possible for Bob to reach Alice, so return −1.

Sample Input 2

STDIN Function Parameters

3 → maze[][] number of rows n = 3
3 → maze[][] number of columns m = 3
0 2 0 → maze[][] = [ [0 2 0] , [1 1 2] , [1 0 0] ]
1 1 2
1 0 0
2 → x = 2
1 → y = 1

Sample Output 2
5

Explanation 2
image

The shortest path Bob can take is (0, 0) → (0, 1) → (0, 2) → (1, 2) → (2, 2) → (2, 1).
*/

#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int min_path = INT_MAX;

void DFS(vector<vector<int>> m, vector<vector<bool>> vis, int rows, int cols, int i, int j, int collected, int coins, int x, int y, int path_len)
{
    vis[i][j] = true;
    if (i == x and j == y)
    {
        if (collected == coins)
            min_path = min(min_path, path_len);
        vis[i][j] = false;
        return;
    }
    for (int k = 0; k < 4; ++k)
    {
        int a = i + dx[k], b = j + dy[k];
        if (a < 0 or a >= rows or b < 0 or b >= cols)
            continue;
        if (!vis[a][b])
        {
            if (m[a][b] == 2)
                DFS(m, vis, rows, cols, a, b, collected + 1, coins, x, y, path_len + 1);
            else if (m[a][b] == 0)
                DFS(m, vis, rows, cols, a, b, collected, coins, x, y, path_len + 1);
        }
    }
    vis[i][j] = false;
}

int main()
{
    int rows, cols, x, y, coins = 0, r = 0, c = 0;
    cin >> rows >> cols;
    vector<vector<int>> dp(rows, vector(cols, 0));
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cin >> dp[i][j];
            if (dp[i][j] == 2)
            {
                coins += 1;
                r = max(r, i);
                c = max(c, j);
            }
        }
    }
    cin >> x >> y;
    vector<vector<bool>> vis(rows, vector(cols, false));
    DFS(dp, vis, rows, cols, 0, 0, 0, coins, x, y, 0);
    if (min_path == INT_MAX)
        cout << -1;
    else
        cout << min_path;
    return 0;
}