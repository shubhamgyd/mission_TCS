/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>res(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>res[i][j];
        }
    }

    // Solution 1: Brute Force
    // vector<vector<bool>>visited(n,vector<bool>(m,false));

    // for(int i=0;i<n;i++)
    // {
    //     // cout<<"dkf;sdf"<<endl;
    //     for(int j=0;j<m;j++)
    //     {
    //         if(res[i][j]==0 and visited[i][j]==false)
    //         {
    //             // set the row as 0
    //             visited[i][j]=true;
    //             for(int k=0;k<m;k++)
    //             {
    //                 res[i][k]=0;
    //                 visited[i][k]=true;
    //             }
                
    //             // set the column as 0
    //             for(int k=0;k<n;k++)
    //             {
    //                 res[k][j]=0;
    //                 visited[k][j]=true;
    //             }
    //         }
    //     }
    // }
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<m;j++)
    //     {
    //         cout<<res[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    

    // Time Complexity:O(n*m*max(n,m));
    // Space Complexity:O(n*m)


    // Solution 2: 
    // set<int>row,col;
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<m;j++)
    //     {
    //         if(res[i][j]==0)
    //         {
    //             row.insert(i);
    //             col.insert(j);
    //         }
    //     }
    // }
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<m;j++)
    //     {
    //         // whenever we encounter as this row no or col no 
    //         // then we need to set this cell as 0
    //         if(row.count(i) or col.count(j))
    //         {
    //             res[i][j]=0;
    //         }
    //     }
    // }
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<m;j++)
    //     {
    //         cout<<res[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // Time Complexity:O(n*m)
    // Space Complexity:O(n+m)

    

    // Solution 3: Space Optimize
    bool flag1=false;
    bool flag2=false;

    // pass 1 : we will set the end elements as zero
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(res[i][j]==0)
            {
                if(i==0) flag1=true;
                if(j==0) flag2=true;
                res[i][0]=res[0][j]=0;
            }
        }
    }

    // pass 2: we will set row and column as 0
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(res[i][0]==0 or res[0][j]==0)
            {
                res[i][j]=0;
            }
        }
    }

    // if  0th row contains any 0
    if(flag1)
    {
        for(int j=0;j<m;j++)
        {
            res[0][j]=0;
        }
    }

    // if 0th column contains any 0

    if(flag2)
    {
        for(int i=0;i<n;i++)
        {
            res[i][0]=0;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }

    // Time Complexity:O(n*m)
    // Space Complexity:O(1)
}