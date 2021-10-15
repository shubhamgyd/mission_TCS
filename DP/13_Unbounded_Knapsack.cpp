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
    int W=5;
    int val[] = {-1, -1, 4, 3, -1};
    int wt[] = {1,2,3,4,5};
    int n=sizeof(val)/sizeof(val[0]);
    cout<<" Maximum Value of Weight:" <<unboundedknapsac(W,n,val,wt);
    return 0;
}