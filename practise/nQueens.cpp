#include<bits/stdc++.h>
using namespace std;


class Solution
{
    bool isValid(int row,int col,vector<string>&nQueens,int n)
    {
        // now check in same column is already placed queen or not
        for(int i=0;i<row;i++)
        {
            if(nQueens[i][col]=='Q')
            {
                return false;
            }
        }

        // now check 45° diagonal had a queen before 
        for(int i=row-1,j=col-1;i>=0 and col>=0;i--,j--)
        {
            if(nQueens[i][j]=='Q')
            {
                return false;
            }
        }

        // now check 135° digonal had a queen before
        for(int i=row-1,j=col+1;i>=0 and j<n;i--,j++)
        {
            if(nQueens[i][j]=='Q')
            {
                return false;
            }
        }
        return true;
    }

    void solveNQueens(vector<vector<string>>&res,vector<string>&nQueens,int row,int &n)
    {
        // base case: all rows are traversed
        if(row==n)
        {
            res.push_back(nQueens);
            return;
        }

        // Now check for all other columns valid positions
        for(int col=0;col<n;col++)
        {
            if(isValid(row,col,nQueens,n))
            {
                nQueens[row][col]='Q';
                solveNQueens(res,nQueens,row+1,n);
                nQueens[row][col]='.';
            }
        }
    }
public:
    vector<vector<string>> solve(int n)
    {
        vector<vector<string>>res;
        vector<string>nQueens(n,string(n,'.'));
        solveNQueens(res,nQueens,0,n);
        return res;
    }
};


int main()
{
    int n;
    cin>>n;
    Solution obj;
    vector<vector<string>>res=obj.solve(n);
    for(auto it:res)
    {
        for(auto ele:it)
        {
            cout<<fixed<<setprecision(3)<<ele<<endl;
        }
        cout<<endl;
        cout<<endl;
        cout<<endl;
    }
    return 0;
}