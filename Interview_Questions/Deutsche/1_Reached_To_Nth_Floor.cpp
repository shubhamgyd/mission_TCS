/*
Given a building with N floors in how many ways can you reach from the 0th floor to the Nth floor given at a time you can take 1 step , 2 steps or 3 steps. You can take 1 or 2 steps any number of times but you can take 3 steps at most K times.
Input N K
Output - Number of ways you can reach floor N
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    vector<vector<int>>dp(n+1,vector<int>(k+1,0));
    for(int i=0;i<=k;i++)
    {
        dp[1][i]=1;
        dp[2][i]=2;
    }
    for(int i=3;i<=n;i++)
    {
        dp[i][0]=dp[i-1][0]+dp[i-2][0];
    }
    for(int i=3;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            dp[i][k]=dp[i-1][k]+dp[i-2][k]+dp[i-3][j-1];
        }
    }
    cout<<dp[n][k]<<endl;
    return 0;
}