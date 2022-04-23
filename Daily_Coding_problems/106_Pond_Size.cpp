/*
You are given two-dimensional matrix that represents a plot of land. Within the matrix there exist two values: ones which represent land and zeroes which represent water within a pond. Given that parts of a pond can be connected both horizontally and vertically (but not diagonally), return the largest pond size.
Note: You may assume that each zero within a given pond contributes a value of one to the total size of the pond.

Ex: Given the following plot of land…

land = [
    [1,1,1],
    [1,0,1],
    [1,1,1]
], return 1.
Ex: Given the following plot of land…

land = [
    [1,0,1],
    [0,0,0],
    [1,0,1]
], return 5.

*/

#include<bits/stdc++.h>
using namespace std;


void DFS(int i,int j,int n,int m,vector<vector<int>>&res,int &temp)
{
    if(i<0 or i>=n or j<0 or j>=m or res[i][j]==1)
    {
        return;
    }
    temp++;
    res[i][j]=1;
    DFS(i+1,j,n,m,res,temp);
    DFS(i-1,j,n,m,res,temp);
    DFS(i,j+1,n,m,res,temp);
    DFS(i,j-1,n,m,res,temp);
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
            if(res[i][j]==0)
            {
                int temp=0;
                DFS(i,j,n,m,res,temp);
                ct=max(ct,temp);
            }
        }
    }
    cout<<ct<<endl;
    return 0;
}
// Time Complexity:O(n*m*(3^n))
// Space Complexity:O(1)