/* Read input from STDIN. Print your output to STDOUT*/
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include<bits/stdc++.h>
using namespace std;
int ans=0;



class QItem {
public:
    int row;
    int col;
    int dist;
    QItem(int x, int y, int w)
        : row(x), col(y), dist(w)
    {
    }
};

int minDistance(vector<vector<int>>&grid,int N,int M,int x,int y)
{
    QItem source(0, 0, 0);
 
    // To keep track of visited QItems. Marking
    // blocked cells as visited.
    source.row = 0;
    source.col = 0;
    grid[x][y]=2;
    bool visited[N][M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
        {
            if (grid[i][j] == 0)
                visited[i][j] = true;
            else
                visited[i][j] = false;
 
            // Finding source
        }
    }
 
    // applying BFS on matrix cells starting from source
    queue<QItem> q;
    q.push(source);
    visited[source.row][source.col] = true;
    while (!q.empty()) {
        QItem p = q.front();
        q.pop();
 
        // Destination found;
        if (grid[p.row][p.col] == 2)
            return p.dist;
 
        // moving up
        if (p.row - 1 >= 0 &&
            visited[p.row - 1][p.col] == false) {
            q.push(QItem(p.row - 1, p.col, p.dist + 1));
            visited[p.row - 1][p.col] = true;
        }
 
        // moving down
        if (p.row + 1 < N &&
            visited[p.row + 1][p.col] == false) {
            q.push(QItem(p.row + 1, p.col, p.dist + 1));
            visited[p.row + 1][p.col] = true;
        }
 
        // moving left
        if (p.col - 1 >= 0 &&
            visited[p.row][p.col - 1] == false) {
            q.push(QItem(p.row, p.col - 1, p.dist + 1));
            visited[p.row][p.col - 1] = true;
        }
 
         // moving right
        if (p.col + 1 < M &&
            visited[p.row][p.col + 1] == false) {
            q.push(QItem(p.row, p.col + 1, p.dist + 1));
            visited[p.row][p.col + 1] = true;
        }
    }
    return -1;
}

int main(int argc, char *a[])
{
    //Write code here
    int n,m;
    cin>>n>>m;
    vector<vector<int>>graph(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int a;
            cin>>a;
            graph[i][j]=a;
        }
    }
    int x,y;
    cin>>x>>y;
    cout<<minDistance(graph,n,m,x,y)<<endl;
    return 0;


}
