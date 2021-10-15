/*
There is a m*n rectangular matrix whose top-left(start) location is (1, 1) and
bottom-right(end) location is (m*n). There are k circles each with radius r. 
Find if there is any path from start to end without touching any circle.
The input contains values of m, n, k, r and two array of integers X and Y, each of length k. 
(X[i], Y[i]) is the center of ith circle.
*/
#include<bits/stdc++.h>
using namespace std;

int x_dir[8]={-1,-1,0,1,1,1,0,-1};
int y_dir[8]={0,1,1,1,0,-1,-1,-1};

bool isValid(int i,int j,int n,int m,vector<vector<bool>>&res)
{
    return (i>=0 && i<n && j>=0 && j<m && res[i][j]);
}


bool DFS(int i,int j,int n,int m,vector<vector<bool>>&res)
{
    if(i==n-1 && j==m-1)
    {
        return true;
    }
    res[i][j]=false;
    for(int p=0;p<8;p++)
    {
        int x=i+x_dir[p];
        int y=j+y_dir[p];
        if(isValid(x,y,n,m,res))
        {
            bool temp=DFS(x,y,n,m,res);
            if(temp)
            {
                return true;
            }
        }
    }
    return false;

}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.out", "w", stdout);
#endif
    int n,m,k,r;
    cin>>n>>m>>k>>r;
    vector<vector<bool>>res(n,vector<bool>(m,true));

    int X[k]={1,3};
    int Y[k]={3,3};

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            for(int l=0;l<k;l++)
            {
                if(sqrt(pow(X[l]-i-1,2)+pow(Y[l]-j-1,2))<=r)
                {
                    res[i][j]=false;
                    // break;
                }
            }
        }
    }

    if(res[0][0]=false || res[n-1][m-1]==false)
    {
        cout<<"H"<<endl;
        cout<<"Path doesn't exist..!!!"<<endl;
    }
    bool ans=DFS(0,0,n,m,res);
    // cout<<ans<<endl;
    if(ans)
    {
        cout<<"Path Exist..!!!"<<endl;
    }
    else
    {
        cout<<"Path doesn't exist..!!!"<<endl;
    }
    return 0;
}