/*
Given a number n, count number of ways to fill a n x 4 grid using 1 x 4 tiles.
Examples: 
 

Input : n = 1
Output : 1

Input : n = 2
Output : 1
We can only place both tiles horizontally

Input : n = 3
Output : 1
We can only place all tiles horizontally.

Input : n = 4
Output : 2
The two ways are : 
  1) Place all tiles horizontally 
  2) Place all tiles vertically.

Input : n = 5
Output : 3
We can fill a 5 x 4 grid in following ways : 
  1) Place all 5 tiles horizontally
  2) Place first 4 vertically and 1 horizontally.
  3) Place first 1 horizontally and 4 horizontally.
*/

#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
#define mod 1000000007

int solve(int n,int m)
{
    //base case
    if(n<=0)
    {
        return 0;
    }
    else if(n<=3)
    {
        return 1;
    }
    else if(n==4)
    {
        return 2;
    }
    return solve(n-1,m)+solve(n-4,m);
}
// Time Complexity :Exponential


// Optimize Top Down DP 
// Memoization
int dp[501];
int Count(int n)
{
    if(n==0)
    {
        return 0;
    }
    else if(n<=3)
    {
        return 1;
    }
    else if(n==4)
    {
        return 2;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }

    return dp[n]=Count(n-1)+Count(n-4);
}
// Time Complexity :O(n^2)
// Space Complexity :O(n)



// Optimization Bottom UP DP
int Ways(int n)
{
    int dp[n+1];
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        if(i>=1 && i<=3)
        {
            dp[i]=1;
        }
        else if(i==4)
        {
            dp[i]=2;
        }
        else
        {
            // dp(i-1) : Place first tile horizontally
            // dp(n-4) : Place first tile vertically
            //         which means 3 more tiles have
            //         to be placed vertically.
            dp[i]=dp[i-1]+dp[i-4];
        }
    }
    return dp[n];
}
// Time Complexity:O(n)
// Space Complexity :O(n)


int Fibbo(int n)
{
    if(n<=0)
    {
        return 0;
    }
    if(n<=3 && n>=1)
    {
        return 1;
    }
    if(n==4)
    {
        return 2;
    }
    int a=1;
    int b=1;
    int c=1;
    int d=2;
    int e;
    for(int i=5;i<=n;i++)
    {
        e=(d%mod+a%mod)%mod;
        a=b%mod;
        b=c%mod;
        c=d%mod;
        d=e%mod;
    }
    return e;  
}
// Time Complexity:O(n)
// Space Complexity :O(1)

int32_t main()
{
    int n;
    cin>>n;
    int m=4;
    // memset(dp,-1,sizeof(dp));
    // cout<<solve(n,m)<<endl;
    // cout<<Count(n)<<endl;
    cout<<Ways(n)<<endl;
    // cout<<Fibbo(n)<<endl;
    return 0;
}