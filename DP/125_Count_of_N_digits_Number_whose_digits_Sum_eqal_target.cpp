
#include <bits/stdc++.h>
using namespace std;




// Recursion Method
unsigned long long int countNum(int n,int sum)
{
    // base case
    if(n==0)
    {
        return sum==0;
    }

    // If we get desired sum then return 1
    if(sum==0)
    {
        return 1;
    }

    // Initialise ans
    unsigned long long ans=0;

    // Iterate to all numbers from 0 to 9 and count whose sum is exactly equal to given sum
    for(int i=0;i<=9;i++)
    {
        ans+=countNum(n-1,sum-i);
    }
    return ans;
}


unsigned long long  finalCount(int n,int sum)
{
    // Initialise ans
    unsigned long long ans=0;

    // Iterate from 1 to 9 and count all the digits starting with it
    for(int i=1;i<=9;i++)
    {
        // if starting element is less than equal to the sum
        if(sum-i>=0)
        {
            // Here we have to find the n-1 digit number with sum=sum-current number
            ans+=countNum(n-1,sum-i);
        }
    }
    return ans;
}
// Time Complexity :Exponential 2^n
// Space Complexity :O(1)












// Memoization
int dp[10001][10001];
unsigned long long int countNum1(int n,int sum)
{
    // base case
    if(n==0)
    {
        return sum==0;
    }

    // If we get desired sum then return 1
    if(sum==0)
    {
        return 1;
    }


    // If we have already found the value of this recursion tree
    if(dp[n][sum]!=-1)
    {
        return dp[n][sum];
    }

    // Initialise ans
    unsigned long long ans=0;

    // Iterate to all numbers from 0 to 9 and count whose sum is exactly equal to given sum
    for(int i=0;i<=9;i++)
    {
        ans+=countNum1(n-1,sum-i);
    }
    return ans;
}

int CountNum(int n,int sum)
{
    // Initialise ans
    unsigned long long ans=0;

    // Iterate from 1 to 9 and count all the digits starting with it
    for(int i=1;i<=9;i++)
    {
        // if starting element is less than equal to the sum
        if(sum-i>=0)
        {
            // Here we have to find the n-1 digit number with sum=sum-current number
            ans+=countNum(n-1,sum-i);
        }
    }
    return ans;
}
// Time Complexity :O(n)
// Space Complexity :O(n*sum)










// Optimise version DP
long int  BottomUP(int n,int sum)
{
    long int  dp[n+1][sum+1];
        memset(dp,0,sizeof dp);
        const int mod=1000000007;
        for(int i=1;i<=min(9,sum);i++)
        {
            dp[1][i]=1;
        }
        
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                for(int t=0;t<=9;t++)
                {
                    if(j-t>=0)
                    {
                        dp[i][j]+=dp[i-1][j-t]%mod;
                    }
                }
            }
        }
        return (dp[n][sum]+mod)%mod==0?-1:(dp[n][sum]+mod)%mod;
}
// time Complexity :O(n*sum)
// Space Complexity :O(n*sum)

int main()
{
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.out", "w", stdout);
#endif
    int n,sum;
    cin>>n>>sum;
    memset(dp,-1,sizeof(dp));
    cout<<finalCount(n,sum)<<endl;
    cout<<CountNum(n,sum)<<endl;
	return 0;
}