/*
This problem was asked by Google.

On our special chessboard, two bishops attack each other if they share the same diagonal.
 This includes bishops that have another bishop located between them, i.e. bishops can attack 
 through pieces.

You are given N bishops, represented as (row, column) tuples on a M by M chessboard. 
Write a function to count the number of pairs of bishops that attack each other. 
The ordering of the pair doesn't matter: (1, 2) is considered the same as (2, 1).

For example, given M = 5 and the list of bishops:

(0, 0)
(1, 2)
(2, 2)
(4, 0)
The board would look like this:

[b 0 0 0 0]
[0 0 b 0 0]
[0 0 b 0 0]
[0 0 0 0 0]
[b 0 0 0 0]
You should return 2, since bishops 1 and 3 attack each other, as well as bishops 3 and 4.
*/

#include<bits/stdc++.h>
using namespace std;


int  isAttack(int i1,int j1,vector<vector<int>>&res,vector<vector<int>>&visited)
{
    int n=res.size();
    int count=0;
    for(int i=i1-1,j=j1-1;i>=0 && j>=0;i--,j--)
    {

        if(res[i][j]==1 && !visited[i][j])
        {
            count++;
        }
    }

    for(int i=i1-1,j=j1+1;i>=0 && j<n;i--,j++)
    {
        if(res[i][j]==1 && !visited[i][j])
        {
          count++;
        }
    }
    for(int i=i1+1,j=j1-1;i<n && j>=0;i++,j--)
    {
        if(res[i][j]==1 && !visited[i][j])
        {
            count++;
        }
    }

    for(int i=i1+1,j=j1+1;i<n && j<n;i++,j++)
    {
        if(res[i][j]==1 && !visited[i][j])
        {
          count++;
        }
    }
    return count;
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>>res(n,vector<int>(n,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>res[i][j];
        }
    }
    int attack=0;
    vector<vector<int>>visited(n,vector<int>(n,0));
    for(int i=n-1;i>=0;i--)
    {
        for(int j=n-1;j>=0;j--)
        {
            if(res[i][j]==1)
            {
                attack+=isAttack(i,j,res,visited);
                cout<<attack<<endl;
                visited[i][j]=1;
            }
        }
    }
    cout<<attack<<endl;
    return 0;
}
// Time Complexity:O(n^3)
// Space Complexity:O(1)

// Time complexity can be reduced further , by adding the bishops position into the queue and
// do bfs , then it will reduced to :O(n^2)


