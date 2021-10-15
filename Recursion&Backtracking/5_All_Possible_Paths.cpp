/*
The problem is to print all the possible paths from top left to bottom right of a mXn matrix 
with the constraints that from each cell you can either move only to right or down
*/

#include<bits/stdc++.h>
using namespace std;


// bool isSafe(vector<vector<int>>&graph,int n,int m,int r,int c)
// {
//     // if(r>=n || c>=m || r<0 || c<0 || graph[r][c]==-1)
//     // {
//     //     return false;
//     // }
//     // return true;
//     return (r<n and c<m and graph[r][c]!=-1);
// }

void FindPaths(vector<vector<int>>&graph,int r,int c,int n,int m,vector<int>&ans,vector<vector<int>>&res)
{
    if(r==n-1 && c==m-1)
    {
        ans.push_back(graph[r][c]);
        res.push_back(ans);
        ans.pop_back();
        return;
    }
    if(r>=n || c>=m)
    {
        return;
    }
    ans.push_back(graph[r][c]);
    FindPaths(graph,r+1,c,n,m,ans,res);
    FindPaths(graph,r,c+1,n,m,ans,res);
    ans.pop_back();    
}

vector<vector<int>> solve(vector<vector<int>>&graph,int n,int m)
{
    vector<vector<int>>res;
    vector<int>ans;
    FindPaths(graph,0,0,n,m,ans,res);
    return res;


}

int main()
{
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
    vector<vector<int>>res=solve(graph,n,m);
    for(auto it:res)
    {
        for(auto ele:it)
        {
            cout<<ele<<" ,";
        }
        cout<<endl;
    }
    return 0;
}