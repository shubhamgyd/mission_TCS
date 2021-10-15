#include <bits/stdc++.h>
using namespace std;

int solve(int x, int y)
{
    // base case
    if (x == 0 || y == 0)
    {
        return 1;
    }

    //count the number of steps
    return solve(x - 1, y) + solve(x, y - 1);
}
// Time Complexity :Exponential

// Memoization Top Down
int dp[1001][1001];
int Count(int x, int y)
{
    // base case

    if (x == 0 || y == 0)
    {
        return 1;
    }

    if (dp[x][y] != -1)
    {
        return dp[x][y];
    }
    return dp[x][y] = Count(x - 1, y) + Count(x, y - 1);
}
// Time Complexity:O(n^2)
// Space Complexity :O(n*n)

//Bottom UP DP
// Optimise
int Paths(int x, int y)
{
    int dp[x+1][y+1];

    for(int i=0;i<=x;i++)
    {
        dp[i][0]=1;
    }
    for(int j=0;j<=y;j++)
    {
        dp[0][j]=1;
    }

    for(int i=1;i<=x;i++)
    {
        for(int j=1;j<=y;j++)
        {
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    return dp[x][y];
}
// Time Complexity :O(n*n)
// Space Complexity :O(n*n)

int main()
{
    int x, y;
    cin >> x >> y;
    // cout<<solve(x,y)<<endl;
    // memset(dp, -1, sizeof(dp));
    // cout << Count(x, y) << endl;
    cout<<Paths(x,y)<<endl;
    return 0;
}