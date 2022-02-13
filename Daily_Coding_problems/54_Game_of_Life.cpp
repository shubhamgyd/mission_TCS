/*
This problem was asked by Dropbox.

Conway's Game of Life takes place on an infinite two-dimensional board 
of square cells. Each cell is either dead or alive, and at each tick, the following rules apply:

Any live cell with less than two live neighbours dies.
Any live cell with two or three live neighbours remains living.
Any live cell with more than three live neighbours dies.
Any dead cell with exactly three live neighbours becomes a live cell.
A cell neighbours another cell if it is horizontally, vertically, or diagonally adjacent.

Implement Conway's Game of Life. It should be able to be initialized with 
a starting list of live cell coordinates and the number of steps it should run for. 
Once initialized, it should print out the board state at each step. Since it's an 
infinite board, print out only the relevant coordinates, i.e. from the top-leftmost
 live cell to bottom-rightmost live cell.

You can represent a live cell with an asterisk (*) and a dead cell with a dot (.).
*/


#include<bits/stdc++.h>
using namespace std;

// Function to check if
// index are not out of grid
static bool save(vector<vector<int> > grid,int row, int col)
{
    return (grid.size() > row && grid[0].size() > col && row >= 0 && col >= 0);
}
    // Function to get New Generation
void solve(vector<vector<int> >& grid)
{
      int p = grid.size(),
        q = grid[0].size();
      int u[] = { 1, -1, 0, 1, -1, 0, 1, -1 };
      int v[] = { 0, 0, -1, -1, -1, 1, 1, 1 };
     for (int i = 0; i < p; i++)
     {
      for (int j = 0; j < q; j++)
      {
      // IF the initial value
      // of the grid(i, j) is 1
      if (grid[i][j] > 0)
      {
        for (int k = 0; k < 8; k++)
        {
          if (save(grid, i + u[k],
                   j + v[k]) &&
                   grid[i + u[k]][j + v[k]] > 0)
          {
            // If initial value > 0,
            // just increment it by 1
            grid[i][j]++;
          }
        }
      }
  
      // IF the initial value
      // of the grid(i, j) is 0
      else
      {
         for (int k = 0; k < 8; k++)
         {
           if (save(grid, i + u[k],
                   j + v[k]) &&
                   grid[i + u[k]][j + v[k]] > 0)
              {
                // If initial value <= 0
                // just decrement it by 1
                grid[i][j]--;
              }
           }
        }
      }
    }
  
    // Generating new Generation.
    // Now the magnitude of the
    // grid will represent number
    // of neighbours
    for (int i = 0; i < p; i++)
      {
          for (int j = 0; j < q; j++)
         {
        // If initial value was 1.
        if (grid[i][j] > 0)
        {
            // Since Any live cell with
          // < 2 live neighbors dies
           if (grid[i][j] < 3)
              grid[i][j] = 0;
  
             // Since Any live cell with
            // 2 or 3 live neighbors live
           else if (grid[i][j] <= 4)
            grid[i][j] = 1;
  
            // Since Any live cell with
             // > 3 live neighbors dies
            else if (grid[i][j] > 4)
              grid[i][j] = 0;
        }
       else
        {
        // Since Any dead cell with
        // exactly 3 live neighbors
        // becomes a live cell
         if (grid[i][j] == -3)
              grid[i][j] = 1;
         else
              grid[i][j] = 0;
            }
        }
     }
}
// Time Complexity:O(n*m)
// Space Complexity:O(1)

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>res(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>res[i][j];
        }
    }
    solve(res);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}
