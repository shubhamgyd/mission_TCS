#include<bits/stdc++.h>
using namespace std;

void solve(int i,int j,int n,vector<vector<int>>&maze,vector<vector<int>>&ans,vector<vector<int>>&res, bool &ok)
{
    if(i<0 or i>=n or j<0 or j>=n or maze[i][j]==0) return;
    if(i==n-1 and j==n-1)
    {
        res[i][j]=1;
        vector<int>temp;
        for(auto it:res)
        {
            for(auto ele:it)
            {
                temp.push_back(ele);
            }
        }
        ans.push_back(temp);
        ok=true;
    }
    res[i][j]=1;
    maze[i][j]=0;
    solve(i+1,j,n,maze,ans,res,ok);
    solve(i-1,j,n,maze,ans,res,ok);
    solve(i,j+1,n,maze,ans,res,ok);
    solve(i,j-1,n,maze,ans,res,ok);
    maze[i][j]=1;
    res[i][j]=0;
        
}
vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  // Write your code here.
    vector<vector<int>>ans;
    vector<vector<int>>ans1(n,vector<int>(n,0));
    vector<vector<int>>res(n,vector<int>(n));
    bool ok=false;
    if(maze[0][0]==1) solve(0,0,n,maze,ans,res,ok);
    if(!ok) return {{}};
    return ans;
}
/*
Time Complexity: O(4^(m*n)), because on every cell we need to try 4 different directions.
Space Complexity:  O(m*n) ,Maximum Depth of the recursion tree(auxiliary space).
*/