/*
Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination
 at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. 
 The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). 
 Value 0 at a cell in the matrix represents that it is blocked and rat cannot move 
 to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time.

Example 1:

Input:
N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
Output:
DDRDRR DRDDRR
Explanation:
The rat can reach the destination at 
(3, 3) from (0, 0) by two paths - DRDDRR 
and DDRDRR, when printed in sorted order 
we get DDRDRR DRDDRR.
*/


#include<bits/stdc++.h>
using namespace std;

int dir_x[4]={1,0,0,-1};
int dir_y[4]={0,-1,-1,0};

void solve(int i,int j,int n,vector<vector<int>>&grid,string moves,vector<string>&ans,vector<vector<bool>>&visited)
{
    if(i==n-1 && j==n-1)
    {
        ans.push_back(moves);
        return;
    }

    string dir="DLRU";
    for(int k=0;k<4;k++)
    {
        int new_x=i+dir_x[k];
        int new_y=j+dir_y[k];
        if(new_x>=0 && new_x<n && new_y>=0 && new_y<n && !visited[new_x][new_y] && grid[new_x][new_y]==1)
        {
            visited[new_x][new_y]=true;
            solve(new_x,new_y,n,grid,moves+dir[k],ans,visited);
            visited[new_x][new_y]=false;
        }
    }
}

vector<string> findPaths(vector<vector<int>>grid,int n)
{
    vector<string>ans;
    vector<vector<bool>>visited(n,vector<bool>(n,false));
    if(grid[0][0]==1)
    {
        solve(0,0,n,grid,"",ans,visited);
    }
    sort(ans.begin(),ans.end());
    return ans;
} 
/*
Expected Time Complexity: O((3N^2)).
Expected Auxiliary Space: O(L * X), L = length of the path, X = number of paths.
*/

int main()
{

}