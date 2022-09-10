/*
Tic-tac-toe is played by two players A and B on a 3 x 3 grid. The rules of Tic-Tac-Toe are:

Players take turns placing characters into empty squares ' '.
The first player A always places 'X' characters, while the second player B always places 'O' characters.
'X' and 'O' characters are always placed into empty squares, never on filled ones.
The game ends when there are three of the same (non-empty) character filling any row, column, or diagonal.
The game also ends if all squares are non-empty.
No more moves can be played if the game is over.
Given a 2D integer array moves where moves[i] = [rowi, coli] indicates that the ith move will be played
on grid[rowi][coli]. return the winner of the game if it exists (A or B). In case the game ends in a
draw return "Draw". If there are still movements to play return "Pending".

You can assume that moves is valid (i.e., it follows the rules of Tic-Tac-Toe), the grid is initially
empty, and A will play first.



Example 1:


Input: moves = [[0,0],[2,0],[1,1],[2,1],[2,2]]
Output: "A"
Explanation: A wins, they always play first.
*/

#include <bits/stdc++.h>
using namespace std;

/*
There are 8 ways to win for each player:

3 columns
3 rows
2 diagonals
Players make moves one by one so all odd moves are for player A, even for B.
Now we just need to track if we reach 3 in any line for any of the players.
One array keeps all ways to win for each player:

0,1,2 - for rows
3,4,5 - for cols
6 - for diagonal top left - bottom right
7 - for diagonal top right - bottom left
*/
string solve(vector<vector<int>> &moves)
{
    int n = moves.size();
    vector<int> A(8, 0), B(8, 0);
    for (int i = 0; i < n; i++)
    {
        int r = moves[i][0];
        int c = moves[i][1];
        vector<int> &player = (i % 2 == 0) ? A : B;
        // For rows
        // Row indices are 0,1,2
        player[r]++;
        // For columns
        // Columns indices are 3,4,5
        player[c + 3]++;
        // for left diagonal
        if (r == c)
            player[6]++;
        // for right diagonal
        if (r == c - 2)
            player[7]++;
    }
    // Now check at any index if there are 3 count or not
    for (int i = 0; i < 8; i++)
    {
        if (A[i] == 3)
            return "A";
        if (B[i] == 3)
            return "B";
    }
    return n == 9 ? "Draw" : "Pending";
}
// Time Complexity:O(1)
// Space :O(1)

int main()
{
    vector<vector<int>> moves = {{0, 0}, {2, 0}, {1, 1}, {2, 1}, {2, 2}};
    string ans = solve(moves);
    cout << ans << endl;
    return 0;
}