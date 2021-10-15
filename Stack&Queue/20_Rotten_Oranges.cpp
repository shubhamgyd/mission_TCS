#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    bool safe(vector<vector<int>>& grid ,int n,int m,int i,int j)
    {
        return (i>=0 && i<n && j>=0 && j<m && grid[i][j]==1);
    }
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        queue<pair<int,int>>pq;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    pq.push({i,j});
                    grid[i][j]=3;
                }
            }
        }
        int ct=-1;
        while(!pq.empty())
        {
            int size=pq.size();
            
            for(int k=0;k<size;k++)
            {
                auto curr=pq.front();
                int i=curr.first;
                int j=curr.second;
                if(safe(grid,n,m,i,j+1)==true)
                {
                    pq.push({i,j+1});
                    grid[i][j+1]=3;
                }
                if(safe(grid,n,m,i,j-1)==true)
                {
                    pq.push({i,j-1});
                    grid[i][j-1]=3;
                }
                if(safe(grid,n,m,i-1,j)==true)
                {
                    pq.push({i-1,j});
                    grid[i-1][j]=3;
                }
                if(safe(grid,n,m,i+1,j)==true)
                {
                    pq.push({i+1,j});
                    grid[i+1][j]=3;
                }
                pq.pop();
            }
            ct++;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    return -1;
                }
            }
        }
        return ct;
    }
};