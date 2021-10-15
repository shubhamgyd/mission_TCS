#include<bits/stdc++.h>
using namespace std;
int dp[501];


// Resursive Memoization
int CoinChange(int arr[],int n,int sum)
{
    if(n==0)
    {
        return 0;
    }
    if(dp[n]!=0)
    {
        return dp[n];
    }
    int ans=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(sum-arr[i]>=0)
        {
            ans=min(ans,CoinChange(arr,n-1,sum-arr[i])+1);
        }
    }
    //dp[n]=ans;
    return dp[n]=ans;
}

int main()
{
    memset(dp,0,sizeof(dp));
    int arr[]={1,7,10};
    int sum=15;
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<CoinChange(arr,n,sum)<<endl;
    return 0;
}