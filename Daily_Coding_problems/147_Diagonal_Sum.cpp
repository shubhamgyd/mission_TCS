/*
Given a two-dimensional NxN integer array, matrix, return the sum of all values along its two diagonals.
Note: If a value appears in both diagonals it should only be added to your sum once.

Ex: Given the following matrix…

matrix = [
  [1, 2],
  [2, 1]
], return 6 (1 + 1 + 2 + 2).
Ex: Given the following matrix…

matrix = [
  [1, 2, 3],
  [4, 5, 6],
  [7, 8, 9]
], return 25 (5 is only added to the sum once).
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
    int sum=0;
    int i=0;
    int j=0;
    while(i<n and j<m)
    {
        sum+=res[i][j];
        i++;
        j++;
    }
    i=0;
    j=m-1;
    while(i<n and j>=0)
    {
        if(i!=j)
        {
            sum+=res[i][j];
        }
        i++;
        j--;
    }
    cout<<sum<<endl;
    return 0;
}