/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.
*/

#include<bits/stdc++.h>
using namespace std;


bool isValid(vector<vector<char>>&board,int row,int col,char ch)
{
    // loop to check given character is present in the current row , col and the submatrix of the matix
    int subRow=3*(row/3);
    int subCol=3*(col/3);
    for(int i=0;i<9;i++)
    {
        if(board[i][col]==ch)
        {
            return false;
        }
        if(board[row][i]==ch)
        {
            return false;
        }

        if(board[subRow+i/3][subCol+i%3]==ch)
        {
            return false;
        }
    }
    return true;
}

bool Validate(vector<vector<char>>&board)
{
    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board[0].size();j++)
        {
            if(board[i][i]=='.')
            {
                for(int c='1';c<='9';c++)
                {
                    if(isValid(board,i,j,c))
                    {
                        board[i][j]=c;
                        if(Validate(board))
                        {
                            return true;
                        }
                        board[i][j]='.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solve(vector<vector<char>>&board)
{
    Validate(board);
}


/*
Complexity Analysis:  

Time complexity: O(9^(n*n)). 
For every unassigned index, there are 9 possible options so the time complexity is O(9^(n*n)). 
The time complexity remains the same but there will be some early pruning so the time taken will 
be much less than the naive algorithm but the upper bound time complexity remains the same.
Space Complexity: O(n*n). 
To store the output array a matrix is needed.
*/
