// In this problem we are going to set the N queens in the given chess board

#include<bits/stdc++.h>
using namespace std;






class Solution {
    int count=0;
    void solve(vector<vector<bool>>&res,int n,int row,int cols,int ndia,int rdia)
    {
        if(row==n)
        {
            count++;
            return;
        }
        for(int col=0;col<n;col++)
        {
            if( ((cols&(1<<col))==0) &&  ((ndia&(1<<(row+col)))==0) && ((rdia&(1<<(row-col+n-1)))==0))
            {
                res[row][col]=true;
                cols^=(1<<col);
                ndia^=(1<<(row+col));
                rdia^=(1<<(row-col+n-1));
                solve(res,n,row+1,cols,ndia,rdia);
                res[row][col]=false;
                cols^=(1<<col);
                ndia^=(1<<(row+col));
                rdia^=(1<<(row-col+n-1));
            }
        }
    }
public:
    int totalNQueens(int n) {
        int cols=0;
        int ndia=0;
        int rdia=0;
        vector<vector<bool>>res(n,vector<bool>(n,false));
        solve(res,n,0,cols,ndia,rdia);
        return count;
    }
};

bool isSafe(vector<vector<int>>&chess,int row,int col)
{
    for(int i=row-1,j=col;i>=0;i--)
    {
        if(chess[i][j]==1)
        {
            return false;
        }
    }

    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--)
    {
        if(chess[i][j]==1)
        {
            return false;
        }
    }


    for(int i=row-1,j=col+1;i>=0 && j<chess.size();i-- && j++)
    {
        if(chess[i][j]==1)
        {
            return false;
        }
    }

    return true;
}
void PrintQueens(vector<vector<int>>&chess,string res,int row)
{
    if(row==chess.size())
    {
        cout<<res<<endl;
        return;
    }
    for(int i=0;i<chess.size();i++)
    {
        if(isSafe(chess,row,i)==true)
        {
            chess[row][i]=1;
            PrintQueens(chess,res+to_string(row)+""+to_string(i)+" ",row+1);
            chess[row][i]=0;
        }
    }
}



int main()
{
    int n;
    cin>>n;
    vector<vector<int>>chess(n,vector<int>(n,0));
    PrintQueens(chess,"",0);
}


/*
class Solution{
bool isSafe(int row, int col, vector<vector<int>> &board){
    for(int i=0; i<col; i++)
        if(board[row][i] == 1)
            return false;
    for(int i=row, j=col; i>=0 && j>=0; i--, j--)
        if(board[i][j] == 1)
            return false;
    for(int i=row, j=col; i<board.size() && j>=0; i++, j--)
        if(board[i][j] == 1)
            return false;
    return true;
}

bool mcQueen(int col, int n, vector<vector<int>> &board, vector<vector<int>> &res){
    if(col == n) {
        vector<int> v;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(board[i][j])
                    v.push_back(j+1);
        res.push_back(v);
        return true;
    }
    
    for(int row=0; row<n; row++){
        if(isSafe(row, col, board)){
            board[row][col] = 1;
            mcQueen(col+1, n, board, res);
            board[row][col] = 0;
        }
    }
    return false;
}
public:
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> board(n, vector<int> (n, 0));
        vector<vector<int>> res;
        mcQueen(0, n, board, res);
        sort(res.begin(), res.end());
        return res;
    }
};
*/