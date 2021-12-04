#include<bits/stdc++.h>
using namespace std;



// Unbounded knapsack mai multiple occurances hai so ...kitni bhi baar knapsack mai dal sakte hai
int unboundedknapsac(int W,int n,int val[],int wt[])
{
    if(W>(n*(n+1)/2))
    {
        return -1;
    }
    int dp[W+1];
    memset(dp,0,sizeof dp);
    for(int i=0;i<=W;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(wt[j]<=i)
            {
                dp[i] = max(dp[i], dp[i-wt[j]] + val[j]);
            }
        }
    }
    return dp[W];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int W=40;
    int val[] = {60,50,20};
    int wt[] = {20,25,5};
    int n=sizeof(val)/sizeof(val[0]);
    cout<<" Maximum Value of Weight:" <<unboundedknapsac(W,n,val,wt);
    return 0;
}