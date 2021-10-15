/*
Given a N*N board with the Knight placed on the first block of an empty board. 
Moving according to the rules of chess knight must visit each square exactly once.
 Print the order of each the cell in which they are visited.
*/

#include<bits/stdc++.h>
using namespace std;


bool isSafe(int i,int j,vector<vector<int>>&mat,int n)
{
    return (i>=0 && i<n && j>=0 && j<n && mat[i][j]==-1);
}

int KnightTour(vector<vector<int>>&mat,int x,int y,int movei,int xMove[],int yMove[],int n)
{
    // If all blocks are visited
    if(movei==n*n)
    {
        return 1;
    }

    // Trying all the possible moves
    for(int i=0;i<8;i++)
    {
        int next_x=x+xMove[i];
        int next_y=y+yMove[i];
        if(isSafe(next_x,next_y,mat,n))
        {
            mat[next_x][next_y]=movei;
            if(KnightTour(mat,next_x,next_y,movei+1,xMove,yMove,n)==1) return 1;

            // Backtracking
            mat[next_x][next_y]=-1;
        }
    }
    return 0;
}


void solve(vector<vector<int>>&mat,int n)
{
    /* xMove[] and yMove[] define next move of Knight.
    xMove[] is for next value of x coordinate
    yMove[] is for next value of y coordinate */
    int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

    if(KnightTour(mat,0,0,1,xMove,yMove,n)==0)
    {
        cout<<"Solution doesn't exit..!!"<<endl;
    }
    else
    {
        cout<<"Solution Exist..!!"<<endl;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<mat[i][j]<<"      ";
            }
            cout<<endl;
        }
    }
    
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>>mat(n,vector<int>(n,-1));

    // Since the knight initially at the first block
    mat[0][0]=0;
    solve(mat,n);
    return 0;
}


/*
Time Complexity : 
There are N2 Cells and for each, we have a maximum of 8 possible moves to 
choose from, so the worst running time is O(8N^2).
*/