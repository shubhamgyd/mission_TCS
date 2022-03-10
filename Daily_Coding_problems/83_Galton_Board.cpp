/*
This question is asked by Google. A ball is dropped into a special Galton board where at each 
level in the board the ball can only move right or down. Given that the Galton board has M rows 
and N columns, return the total number of unique ways the ball can arrive at the bottom right 
cell of the Galton board.

Ex: Given the following values of M and N…

M = 2, N = 2, return 2.
The possible paths are DOWN -> RIGHT and RIGHT -> DOWN 
Ex: Given the following values of M and N…

M = 4, N = 3, return 10.
*/

#include<bits/stdc++.h>
using namespace std;


void solve(vector<vector<int>>&res,int n,int m,int i,int j,int &ans)
{
    if(i<0 || i>=n || j<0 || j>=m ) return;
    if(res[i][j]==0) return;
    if(i==n-1 && j==m-1) ans++;
    res[i][j]=0;
    solve(res,n,m,i,j+1,ans);
    solve(res,n,m,i+1,j,ans);
    res[i][j]=1;
}
// Time complexity:O(Exponential)
// Auxilary Space :O(1)




// Tabulation
int countWays(int n,int m)
{
    vector<vector<int>> dp(n, vector<int>(m, 1));
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[n - 1][m - 1];
}
// Time Complexity:O(n*m)
// Auxilary Space: O(n*m)


// Space Optimize
int countWays1(int n,int m)
{
    vector<int>pre(m,1),curr(m,1);
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            curr[j]=pre[j]+curr[j-1];
        }
        swap(pre,curr);
    }
    return pre[m-1];
}
// Time Complexity:O(n*m)
// Auxilary Space:O(m+m)


// Space Optimize
int CountWays1(int n,int m)
{
    vector<int>curr(n,1);
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            curr[j]+=curr[j-1];
        }
    }

    return curr[m-1];
}
// Time Complexity:O(n*m)
// Auxilary Space: O(m)

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>res(n,vector<int>(m,1));
    int ans=0;
    solve(res,n,m,0,0,ans);
    cout<<"Total Nummber of ways is: "<<ans<<endl;
    cout<<countWays(n,m)<<endl;
    cout<<countWays1(n,m)<<endl;
    cout<<CountWays1(n,m)<<endl;
    return 0;
}