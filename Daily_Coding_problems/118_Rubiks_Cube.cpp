// You are given a special Rubik’s cube that only contains black and white panels. 
// The side of the Rubik’s cube that is facing you is given as a two-dimensional matrix, cube. 
// Each value in cube is either a zero or a one where zero represents a black panel and one 
// represents a white panel. Given the cube, invert it and return the modified cube. 
// Inverting the cube consists of reversing the values in each row and flipping black values to 
// white and white values to black.

// Ex: Given the following cube…

// cube = [[1, 0], [0, 1], [1, 1]], return [[1,0],[0,1],[0,0]].

#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>nums(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>nums[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m/2;j++)
        {
            swap(nums[i][j],nums[i][m-j-1]);
            nums[i][j]=1-nums[i][j];
            nums[i][m-j-1]=1-nums[i][m-j-1];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<nums[i][j]<<" ";
        }
        cout<<endl;
    }

}
