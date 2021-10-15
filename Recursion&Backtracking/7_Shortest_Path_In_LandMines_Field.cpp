#include <bits/stdc++.h>
using namespace std;
void preProcess(vector<vector<int>>&v)
{
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v[0].size();j++)
        {
            if(v[i][j]==0)
            {
                if(i-1>=0)
                {
                    v[i-1][j]=2;
                }
                if(i+1<v.size())
                {
                    v[i+1][j]=2;
                }
                if(j-1>=0)
                {
                    v[i][j-1]=2;
                }
                if(j+1<=v[0].size())
                {
                    v[i][j+1]=2;
                }
            }
        }
    }
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v[0].size();j++)
        {
            if(v[i][j]==2)
            {
                v[i][j]=0;
            }
        }
    }
}
void helper(vector<vector<int>>&v,int curr,int &ans,int row,int col)
{
    if(row<0 || col<0 || row>=v.size() || col>=v[0].size() || v[row][col]!=1)
    {
        return;
    }
    if(col==v[0].size()-1)
    {
        if(curr<ans)
        {
            ans=curr;
        }
        return;
    }
    v[row][col]=2;
    helper(v,curr+1,ans,row+1,col);
    helper(v,curr+1,ans,row-1,col);
    helper(v,curr+1,ans,row,col+1);
    helper(v,curr+1,ans,row,col-1);
    v[row][col]=1;
}
int shortestPathLength(vector<vector<int>>&v)
{
    // pre-process the matrix
    preProcess(v);
    
    // find the shortest path length
    int ans=INT_MAX;
    for(int i=0;i<v.size();i++)
    {
        helper(v,0,ans,i,0);
    }
    return ans;
}
int main() 
{
    dque
	vector<vector<int>>v={
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
        { 1, 0, 1, 1, 1, 1, 1, 1, 0, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 }};
    cout<<"The shortest path length is "<<shortestPathLength(v)<<endl;
	return 0;
}


// Time complexity:- O(n*m+n*4^(n*m))
// Space complexity:- O(4^(n*m))