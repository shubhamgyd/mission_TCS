/*
Given a 2D array of integers with ones representing land and zeroes representing water, return the number of islands in the grid. Note: an island is one or more ones surrounded by water connected either vertically or horizontally. Ex: Given the following grid…

11000
11010
11001
return 3.
Ex: Given the following grid…

00100
00010
00001
00001
00010
return 4.
*/




#include<bits/stdc++.h>
using namespace std;


void DFS(int i,int j,int n,int m,vector<vector<int>>&res)
{
    if(i>=n || i<0 || j>=m || j<0 || res[i][j]==0)
    {
        return;
    }
    res[i][j]=0;
    DFS(i+1,j,n,m,res);
    DFS(i-1,j,n,m,res);
    DFS(i,j+1,n,m,res);
    DFS(i,j-1,n,m,res);
}


int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>res(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>res[i][j];
        }
    }
    int ct=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(res[i][j]==1)
            {
                ct++;
                DFS(i,j,n,m,res);
            }
        }
    }
    cout<<ct<<endl;
    return 0;
}