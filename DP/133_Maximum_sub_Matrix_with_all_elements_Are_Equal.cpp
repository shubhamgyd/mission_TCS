#include <bits/stdc++.h>
using namespace std;
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int long long

int solve(vector<vector<int>>&res,int n)
{
    vector<vector<int>>dp(n,vector<int>(n));
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            dp[i][j]=1;
            if(i>0 && j>0)
            {
                if(res[i-1][j-1]==res[i][j] && res[i][j-1]==res[i][j] && res[i-1][j]==res[i][j])
                {
                    dp[i][j]+=min({dp[i-1][j-1],dp[i][j-1],dp[i-1][j]});
                }
            }
            ans=max(ans,dp[i][j]);
        }
    }
    return ans;
}
// Time Complexity :O(n*m)
// Space Complexity ::O(n*m)

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
    cout<<solve(res,n)<<endl; 
	return 0;
}
