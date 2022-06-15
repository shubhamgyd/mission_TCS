#include<bits/stdc++.h>
using namespace std;

// Recursiv approach
int Unbounded(int wt[],int value[],int n,int W)
{
    // base case
    if(n==0 || W==0)
    {
        return 0;
    }

    // If current weight is greater than the remaining knapsack weight
    // then proceed to the next item
    if(wt[n-1]>W)
    {
        return Unbounded(wt,value,n-1,W);
    }


    // if weight is less than or equal to the knapsack weight 
    // then we have two choices 
    // either we include it or we can exclude it
    return max(Unbounded(wt,value,n-1,W),value[n-1]+Unbounded(wt,value,n,W-wt[n-1]));
}

// Time Complexity: Exponential
// Space Complexity:O(1)






// Memoization
// Top Down
int dp[5001][5001];
int Knapsack(int wt[],int value[],int n,int W)
{
    // base case
    if(n==0 || W==0)
    {
        return 0;
    }

    if(dp[n][W]!=-1)
    {
        return dp[n][W];
    }
    if(W<wt[n-1])
    {
        dp[n][W]=Knapsack(wt,value,n-1,W);
    }
    else
    {
        dp[n][W]=max(Knapsack(wt,value,n-1,W),value[n-1]+Knapsack(wt,value,n,W-wt[n-1]));
    }
    return dp[n][W];
}
// Time Complexity:O(n*W)
// Space Complexity:O(n*W)


// Unbounded knapsack mai multiple occurances hai so ...kitni bhi baar knapsack mai dal sakte hai
int unboundedknapsac(int W,int n,int val[],int wt[])
{
    // if(W>(n*(n+1)/2))
    // {
    //     return -1;
    // }
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
    memset(dp,-1,sizeof(dp));
    int W=15;
    int val[] = {7,2,4};
    int wt[] = {5,10, 20};
    int n=sizeof(val)/sizeof(val[0]);
    cout<<" Maximum Value of Weight:" <<unboundedknapsac(W,n,val,wt)<<endl;
    cout<<" Maximum Value of Weight:" <<Unbounded(wt,val,n,W)<<endl;
    cout<<" Maximum Value of Weight:" <<Knapsack(wt,val,n,W);
    return 0;
}