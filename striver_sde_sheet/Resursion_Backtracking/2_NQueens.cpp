#include<bits/stdc++.h>
using namespace std;


bool isValid(int row,int col,int n,vector<vector<int>>&ans)
{
    // check , same coulmn have another queen or not
    for(int i=0;i<row;i++)
    {
        if(ans[i][col]==1) return false;
    }
    
    // Check 35 degree left side any other queen or not
    for(int i=row,j=col;i>=0 and j>=0; i--,j--)
    {
        if(ans[i][j]==1) return false;
    }
    
    for(int i=row-1,j=col+1;i>=0 and j<n; i--,j++)
    {
        if(ans[i][j]==1) return false;
    }
    return true;
}
void solveNQueens(int row,int n,vector<vector<int>>&res,vector<vector<int>>&ans)
{
    if(row==n)
    {
        vector<int>temp;
        for(auto it:ans)
        {
            for(auto ele:it)
            {
                temp.push_back(ele);
            }
        }
        res.push_back(temp);
        return;
    }
    for(int col=0;col!=n;col++)
    {
        if(isValid(row,col,n,ans))
        {
            ans[row][col]=1;
            solveNQueens(row+1,n,res,ans);
            ans[row][col]=0;
        }
    }
}
vector<vector<int>> solveNQueens(int n) {
    // Write your code here.
    vector<vector<int>>res;
    vector<vector<int>>ans(n,vector<int>(n,0));
    solveNQueens(0,n,res,ans);
    
    return res;
    
}