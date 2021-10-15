#include<bits/stdc++.h>
using namespace std;

int solve(int n)
{
    if(n==0 || n==1)
    {
        return 1;
    }
    else if(n==2)
    {
        return 2;
    }
    else return solve(n-1)+solve(n-2)+solve(n-3);
}
// Time Complexity:O(3^n)




// TP Top Down
// Memoization
int dp[501];
int Stairs(int n)
{
    if(n==0 || n==1)
    {
        return 1;
    }
    else if(n==2)
    {
        return 2;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    else
    {
        return dp[n]=Stairs(n-1)+Stairs(n-2)+Stairs(n-3);
    }
}

// DP Bottom UP Approach
int Stair(int n)
{
    int dp[n+1];
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
    }
    return dp[n];
}
// time Complexity:O(n)
// Space Complexity:O(n)


// Space optimise Bottom Up
int Stair1(int n)
{
    int a=1,b=1,c=2;
    int d=0;
    if(n==0 || n==1)
    {
        return 1;
    }
    else if(n==2)
    {
        return 2;
    }
    for(int i=3;i<=n;i++)
    {
        d=a+b+c;
        a=b;
        b=c;
        c=d;
    }
    return d;
}
// Time Complexity :O(n)
// Space Complexity :O(1)





int main()
{
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    // cout<<solve(n)<<endl;
    // cout<<Stairs(n)<<endl;
    // cout<<Stair(n)<<endl;
    cout<<Stair1(n)<<endl;
    return 0;
}