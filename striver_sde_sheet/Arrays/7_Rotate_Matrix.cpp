/*
Rotate Image by 90 degree
Problem Statement: Given a matrix, your task is to rotate the matrix by 90 degrees.
*/

#include<bits/stdc++.h>
using namespace std;


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

    // Approach 1: Brute Force
    // By observation
    for(int j=0;j<m;j++)
    {
        for(int i=n-1;i>=0;i--)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    // Time Complexity:O(n*n)
    // Space Complexity:O(1)



    // Approach 2: Optimal Solution / Transpose of the matrix
    /*
    Intuition: By observation, we see that the first column of the original matrix is the 
    reverse of the first row of the rotated matrix, so that’s why we transpose the matrix and 
    then reverse each row, and since we are making changes in the matrix itself space complexity gets reduced to O(1).

    Approach:
    Step1: Transpose of the matrix. (transposing means changing columns to rows and rows to columns)
    Step2: Reverse each row of the matrix.
    */

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            swap(res[i][j],res[j][i]);
        }
    }

    // reversing each row
    for(int i=0;i<n;i++)
    {
        reverse(res[i].begin(),res[i].end());
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    // Time Complexity:O(n*n)
    // Space Complexity:O(1)
}