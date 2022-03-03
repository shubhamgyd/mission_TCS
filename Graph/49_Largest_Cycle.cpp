/*
Problem Statement
You are given a maze consisting of N cells numbered from 0 to N - 1 and an array ‘arr’ of N 
integers in which arr[i] contains the cell number that can be reached from ‘i’th cell in one 
step. You are supposed to find the length of the largest cycle in the maze, given that each 
cell has less than or equal to 1 exit but can have multiple entry points.
Note:
The maze may contain self-cycles.
arr[i] = -1 means the ‘i’th cell doesn’t have an exit.
Input Format:
The first line of input contains an integer ‘T’, denoting the number of test cases. 
The test cases follow.

The first line of each test case contains integer ‘N’, which denotes the number of 
cells in the maze.

The second line contains N integers,  denoting the elements of the array ‘arr’.
Output Format:
For each test case, print the length of the largest cycle in the maze and -1 if 
there are no cycles.

Print the output of each test case in a separate line.
Constraints:
1<= T <= 50
1 <= N <= 10,000
-1 <= arr[i] <= N-1

Where ’T’ is the number of test cases, and N denotes the number of cells in the 
maze and arr[i] is the cell that can be reached from ‘i’th cell.

Time Limit: 1 sec
Sample Input 1:
2
5
-1 2 3 4 1
10
-1 4 -1 -1 6 -1 7 8 9 1
Sample Output 1:
4
6
*/

#include<bits/stdc++.h>
using namespace std;


void dfs(vector<int>&res,vector<int>&visited,vector<int>&positions,int currentCell,int totalLengthCovered,int &res1)
{
    // if current cell is visited
    if(visited[currentCell])
    {
        return;
    }

    // if there is no exit from the currentcell
    if(res[currentCell]==-1)
    {
        visited[currentCell]=1;
        return;
    }

    // we have found the cycle
    if(positions[currentCell]!=-1)
    {
        // Update the maximum length.
        res1 = max(res1, totalLengthCovered - positions[currentCell]);
        visited[currentCell] = 1;
        return;
    }

    positions[currentCell] = totalLengthCovered;
    dfs(res,visited,positions,res[currentCell],totalLengthCovered+1,res1);
    visited[currentCell]=1;
    positions[currentCell]=-1;


}

int LargestCycle(vector<int>&res)
{
    int n=res.size();
    vector<int>visited(n,0);
    vector<int>positions(n,-1);

    int res1=0;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            dfs(res,visited,positions,i,0,res1);
        }
    }
    return res1;
}

int main()
{
    int n;
    cin>>n;
    vector<int>res(n);
    for(int i=0;i<n;i++)
    {
        cin>>res[i];
    }
    cout<<LargestCycle(res)<<endl;
    return 0;
}
// Time Complexity:O(n)
// Space Complexity:O(n)