/*
This problem was asked by Google.

You are given an M by N matrix consisting of booleans that represents a board. Each 
True boolean represents a wall. Each False boolean represents a tile you can walk on.

Given this matrix, a start coordinate, and an end coordinate, return the minimum number 
of steps required to reach the end coordinate from the start. If there is no possible path, 
then return null. You can move up, left, down, and right. You cannot move through walls. 
You cannot wrap around the edges of the board.

For example, given the following board:

[[f, f, f, f],
[t, t, f, t],
[f, f, f, f],
[f, f, f, f]]
and start = (3, 0) (bottom left) and end = (0, 0) (top left), the minimum number of steps 
required to reach the end is 7, since we would need to go through (1, 2) because there is a 
wall everywhere else on the second row.
*/


#include<bits/stdc++.h>
using namespace std;

// Check if it is possible to go to (x, y) from the current position. The
// function returns false if the cell has value 0 or already visited
bool isSafe(vector<vector<char>> &mat, vector<vector<bool>> &visited, int x, int y)
{
    return (x >= 0 && x < mat.size() && y >= 0 && y < mat[0].size())&& !visited[x][y] && mat[x][y]=='f';
}
 
// Find the shortest possible route in a matrix `mat` from source cell (i, j)
// to destination cell (x, y).
 
// `min_dist` is passed by reference and stores the length of the longest path
// from source to a destination found so far, and `dist` maintains the length
// of the path from a source cell to a current cell (i, j).
 
void findShortestPath(vector<vector<char>> &mat, vector<vector<bool>> &visited,int i, int j, int x, int y, int &min_dist, int dist)
{
    // if the destination is found, update `min_dist`
    if (i == x && j == y)
    {
        min_dist = min(dist, min_dist);
        return;
    }
 
    // set (i, j) cell as visited
    visited[i][j] = true;
 
    // go to the bottom cell
    if (isSafe(mat, visited, i + 1, j)) {
        findShortestPath(mat, visited, i + 1, j, x, y, min_dist, dist + 1);
    }
 
    // go to the right cell
    if (isSafe(mat, visited, i, j + 1)) {
        findShortestPath(mat, visited, i, j + 1, x, y, min_dist, dist + 1);
    }
 
    // go to the top cell
    if (isSafe(mat, visited, i - 1, j)) {
        findShortestPath(mat, visited, i - 1, j, x, y, min_dist, dist + 1);
    }
 
    // go to the left cell
    if (isSafe(mat, visited, i, j - 1)) {
        findShortestPath(mat, visited, i, j - 1, x, y, min_dist, dist + 1);
    }
 
    // backtrack: remove (i, j) from the visited matrix
    visited[i][j] = false;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>>res(n,vector<char>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>res[i][j];
        }
    }
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    vector<vector<bool>>visited(n,vector<bool>(m,false));
    int min_dist = INT_MAX;
    findShortestPath(res, visited, x1, y1, x2, y2,min_dist, 0);
    if (min_dist != INT_MAX) {
       cout<<"minimum distance is: "<<min_dist<<endl;
    }
    else
    {
        cout<<"Path is not possible.."<<endl;
    }
 
    return -1;
    return 0;
}