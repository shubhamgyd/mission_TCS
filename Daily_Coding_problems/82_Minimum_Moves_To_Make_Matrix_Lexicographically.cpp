/*
This problem was asked by Google.

You are given an N by M 2D matrix of lowercase letters. Determine the minimum number of 
columns that can be removed to ensure that each row is ordered from top to bottom 
lexicographically. That is, the letter at each column is lexicographically later as 
you go down each row. It does not matter whether each row itself is ordered lexicographically.

For example, given the following table:

cba
daf
ghi
This is not ordered because of the a in the center. We can remove the second column 
to make it ordered:

ca
df
gi
So your function should return 1, since we only needed to remove 1 column.

As another example, given the following table:

abcdef
Your function should return 0, since the rows are already ordered (there's only one row).

As another example, given the following table:

zyx
wvu
tsr
Your function should return 3, since we would need to remove all the columns to order it.
*/

#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>>res(n,vector<char>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>res[i][j];
        }
    }

    int minimumMoves=0;
    for(int j=0;j<m;j++)
    {
        char ch=res[0][j];
        for(int i=1;i<n;i++)
        {
            if(res[i][j]<=ch)
            {
                minimumMoves++;
                break;
            }
            else{
                ch=res[i][j];
            }
        }
    }
    cout<<minimumMoves<<endl;
    return 0;
}
// Time Complexity:O(n*m)
// Auxilary Space:O(1)