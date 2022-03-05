/*
You are given an integer array nums of 2 * n integers. You need to partition nums 
into two arrays of length n to minimize the absolute difference of the sums of the arrays. 
To partition nums, put each element of nums into one of the two arrays.

Return the minimum possible absolute difference.

*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>res(n);
    int sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>res[i];
        sum+=res[i];
    }
    int dp[n+1][sum+1];
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=1;
    }
    for(int i=1;i<=sum;i++)
    {
        dp[0][0]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(res[i-1]<=j)
            {
                dp[i][j]=dp[i-1][j] || dp[i][j-1];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    int required=sum/2;
    int mn=INT_MAX;
    for(int i=0;i<=required;i++)
    {
        if(dp[n][i])
        {
            mn=min(mn,sum-2*i);
        }
    }
    cout<<mn<<endl;
}
// Time Complexity:O(n*n)
// Auxilary Complexity:O(n*m)