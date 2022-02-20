#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > res;
        vector<string> nQueens(n, string(n, '.'));
        solveNQueens(res, nQueens, 0, n);
        return res;
    }
private:
    void solveNQueens(vector<vector<string> > &res, vector<string> &nQueens, int row, int &n) {
        if (row == n) {
            res.push_back(nQueens);
            return;
        }
        for (int col = 0; col != n; ++col)
            if (isValid(nQueens, row, col, n)) {
                nQueens[row][col] = 'Q';
                solveNQueens(res, nQueens, row + 1, n);
                nQueens[row][col] = '.';
            }
    }
    bool isValid(vector<string> &nQueens, int row, int col, int &n) {
        //check if the column had a queen before.
        for (int i = 0; i != row; ++i)
            if (nQueens[i][col] == 'Q')
                return false;
        //check if the 45° diagonal had a queen before.
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
            if (nQueens[i][j] == 'Q')
                return false;
        //check if the 135° diagonal had a queen before.
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
            if (nQueens[i][j] == 'Q')
                return false;
        return true;
    }
};

int main()
{
    int n;
    cin>>n;
    Solution obj;
    vector<vector<string>>res=obj.solveNQueens(n);
    for(auto it:res)
    {
        for(auto ele:it)
        {
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    return 0;
}




















/*
Practice Mode:

bool isValid(int row,int col,int n,vector<string<&nQeens)
{
    // if qeen is present in same column before
    for(int int i=0;i<row;i++)
    {
        if(nQeens[i][col]=='Q')
        {
            return false;
        }
    }


    // if queen is already present in left diagonal
    for(int i=row-1,j=col-1;i>=0,j>=0,i--,j--)
    {
        if(nQeens[i][j]=='Q')
        {
            return false;
        }
    }

    // if queen is already present in the left down diagonal
    for(int i=row+1,j=col-1;i<n,j>=0;i++,j--)
    if(nQeens[i][j]=='Q')
    {
        return false;
    }

    return true;
}


void Ways(vector<vector<string>>&ans,vector<string>&nQeens,int col,int n)
{
    if(col==n)
    {
        ans.push_back(nQeens);
        return;
    }
    for(int row=0;row<n;row++)
    {
        if(isValid(row,col,n,nQeens))
        {
            nQeens[row][col]='Q';
            Ways(as,nQeens,col+1,n);
            nQeens[row][col]='.';
        }
    }
}

vector<vector<string>> solve(int n)
{
    vector<vector<string>>ans;
    vector<string>nQeens(n,string('.'));
    Ways(ans,nQeens,0,n);
    return ans;
}

// Time Complexity:O(2^n)
// Space Complexity:O(n*n)

*/