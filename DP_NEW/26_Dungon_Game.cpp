#include <bits/stdc++.h>
using namespace std;
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int long long


int mat[1001][1001];
int r,c;
int dp[501][501];
// Top Down DP 
int get_min_points(int x, int y){
 
    // base case
    if (x == r-1 && y == c-1){    
        dp[r-1][c-1] = mat[r-1][c-1]>0 ? 1 : abs(mat[r-1][c-1])+1;
        return dp[x][y];
    }
 
    if (x<0 || x>=r || y<0 || y>=c)
        return 9999;
 
    if (dp[x][y] != -1)
        return dp[x][y];
 
    int l1 = get_min_points(x+1,y);
    int l2 = get_min_points(x,y+1);
 
    int min_pts_exit = min(l1,l2);
 
    dp[x][y] = max(1LL,min_pts_exit-mat[x][y]);
    return dp[x][y];
 
}
// Time complexity :O(n*n)
// Space Complxity :O(n*n)






int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.out", "w", stdout);
#endif
    fast();
    int n;
    cin>>n;
    vector<vector<int>>res(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>res[i][j];
        }
    }
    int dp[n][n];
    for(int i=n-1;i>=0;i--)
    {
        for(int j=n-1;j>=0;j--)
        {
            if(i==n-1 && j==n-1)
            {
                dp[i][j]=min(0LL,res[i][j]);
            }
            else if(i==n-1)
            {
                dp[i][j]=min(0LL,res[i][j]+dp[i][j+1]);
            }
            else if(j==n-1)
            {
                dp[i][j]=min(0LL,res[i][j]+dp[i+1][j]);
            }
            else
            {
                dp[i][j]=min(0LL,res[i][j]+max(dp[i+1][j],dp[i][j+1]));
            }
        }
    }
    cout<<abs(dp[0][0])+1<<endl;
	return 0;
}
// Bottom UP DP
// Time Complexity :O(n*n)
// Space Complexity :O(n*n)