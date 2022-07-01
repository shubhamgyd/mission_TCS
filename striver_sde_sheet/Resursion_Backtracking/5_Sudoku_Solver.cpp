#include<bits/stdc++.h>
using namespace std;




bool isValid(int row,int col,int mat[9][9],int num)
{
    for(int i=0;i<9;i++)
    {
        if(mat[i][col]==num) return false;
        if(mat[row][i]==num) return false;
        if(mat[3*(row/3)+i/3][3*(col/3)+i%3]==num) return false;
    }
    return true;
}
bool isItSudoku(int matrix[9][9]) {
    // Write your code here.
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(matrix[i][j]==0)
            {
                for(int c=1;c<=9;c++)
                {
                    if(isValid(i,j,matrix,c))
                    {
                        matrix[i][j]=c;
                        if(isItSudoku(matrix)) return true;
                        else
                        {
                            matrix[i][j]=0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

// Time Complexity: O(9(n ^ 2)), in the worst case, for each cell in the n2 board, we have 9 possible numbers.
// Space Complexity: O(1), since we are refilling the given board itself, there is no extra space required, so constant space complexity.