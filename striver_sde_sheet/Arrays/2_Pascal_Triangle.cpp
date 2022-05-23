/*
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<vector<int>>res(n);
    for(int i=0;i<n;i++)
    {
        res[i].resize(i+1);
        res[i][0]=res[i][i]=1;
        for(int j=1;j<i;j++)
        {
            res[i][j]=res[i-1][j-1]+res[i-1][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(auto it:res[i])
        {
            cout<<it<<" ";
        }
        cout<<endl;
    }
    return 0;
}

/*
Time Complexity: We are creating a 2D array of size (numRows * numCols) (where 1 <= numCols <= numRows), and we are traversing through each of the cells to update it with its correct value, so Time Complexity = O(numRows2).

Space Complexity: Since we are creating a 2D array, space complexity = O(numRows2).
*/