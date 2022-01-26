/*
The task is to count all the possible paths from top left to bottom right of a m x n matrix with the constraints that from each cell you can either move only to right or down.

Input:

First line consists of T test cases. First line of every test case consists of N and M, denoting the number of rows and number of columns respectively.
Output:

Single line output i.e count of all the possible paths from top left to bottom right of a m x n matrix..
Constraints:

1<=T<=100
1<=N<=100
1<=M<=100
*/

#include <bits/stdc++.h>
using namespace std;

int ans=0;
void dfs(vector<vector<int>> &res, int i, int j, int m, int n)
{
    if (i < 0 || i >= m || j < 0 || j >= n)
    {
        return;
    }
    if (res[i][j] == 0)
    {
        return;
    }
    if (i == m - 1 && j == n - 1)
    {
        ans++;
    }
    // if(!visited[i][j])
    // {
    // visited[i][j]=true;
    res[i][j] = 0;
    dfs(res, i + 1, j, m, n);
    dfs(res, i, j + 1, m, n);
    res[i][j] = 1;
    // visited[i][j]=false;
    // }
}

int solve(int m,int n)
{
    // int ans=0;
    vector<vector<int>>res(m,vector<int>(n,1));
    dfs(res,0,0,m,n);
    return ans;
}
// Time Complexity:O(m*n)
// Space Complexity:O(m*n)




int Recursion(int m,int n)
{
    // base case
    if(m==1 || n==1)
    {
        return 1;
    }


     // If diagonal movements are allowed then the last
    // addition is required.

    return Recursion(m-1,n)+Recursion(m,n-1);
}
//Time Complexity:Exponential
// Space Complexity:O(1)


int dp[10001][10001];
int Memoization(int m,int n)
{
    // base case
    if(m==1 || n==1)
    {
        return 1;
    }

    if(dp[m][n]!=-1)
    {
        return dp[m][n];
    }

     // If diagonal movements are allowed then the last
    // addition is required.

    return dp[m][n]=Recursion(m-1,n)+Recursion(m,n-1);
}
//Time Complexity: :O(m*n)
// Space Complexity:O(m*n)



// Dp solution
int Paths(int m,int n)
{
    vector<vector<int>>dp(m,vector<int>(n,1));
    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}
// Time Complexity:O(m*n)
// Space Complexity:O(m*n)



// Optimize Dp
int Path(int m,int n)
{
    vector<int>curr(n,1),pre(n,1);
    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            curr[j]=pre[j]+curr[j-1];
        }
        swap(pre,curr);
    }
    return pre[n-1];
}
// Time Compleixity:O(m*n)
// Spac Compleixty:O(n)



int SpaceOptimize(int m,int n)
{
    vector<int> cur(n, 1);
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                cur[j] += cur[j - 1];
            }
        }
        return cur[n - 1];
}



int main()
{
    int n, m;
    cin >> m >> n;
    memset(dp,-1,sizeof(dp));
    cout<<"Ans by brute force = "<<solve(m,n)<<endl;
    cout<<"solution by recursion: "<<Recursion(m,n)<<endl;
    cout<<"solution by Memoization: "<<Memoization(m,n)<<endl;
    cout<<"solution by Dp bottom up: "<<Paths(m,n)<<endl;
    cout<<"solution by Optimize Dp bottom up: "<<Path(m,n)<<endl;
    cout<<"solution by Space  Dp bottom up: "<<SpaceOptimize(m,n)<<endl;
}