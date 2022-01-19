#include<bits/stdc++.h>
using namespace std;

int solve(int arr[],int n)
{
    if(n==1)
    {
        return arr[0];
    }
    if(n==2)
    {
        return max(arr[1],arr[0]);
    }
    int dp[n+1];
    dp[1]=arr[0];
    dp[2]=max(arr[0],arr[1]);
    for(int i=3;i<=n;i++)
    {
        dp[i]=max(dp[i-1],dp[i-2]+arr[i-1]);
    }
    return dp[n];
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<solve(arr,n)<<endl;
    return 0;
}