/*
You are given n days and for each day (di) you could either perform a high effort tasks (hi) 
or a low effort tasks (li) or no task with the constraint that you can choose a high-effort 
tasks only if you choose no task on the previous day. Write a program to find the maximum amount of tasks you can perform within these n days.
Examples: 

No. of days (n) = 5
Day      L.E.   H.E
1        1       3
2        5       6
3        4       8
4        5       7
5        3       6
Maximum amount of tasks 
        = 3 + 5 + 4 + 5 + 3 
        = 20
*/

#include<bits/stdc++.h>
using namespace std;


// Resursion
int Solve(int n,int high[],int low[])
{
    // base case
    if(n<=0)
    {
        return 0;
    }

     /* Determines which task to choose on day n,
    then returns the maximum till that day */
    return max(high[n-1]+Solve(n-2,high,low),low[n-1]+Solve(n-1,high,low));
}
// Time Complexity: 2^n
// Space Complexity: O(1)







// Top-Down
int dp[501];
int Profit(int n,int high[],int low[])
{
    // base case
    if(n<=0)
    {
        return 0;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }

    return dp[n]=max(high[n-1]+Solve(n-2,high,low),low[n-1]+Solve(n-1,high,low));
}
// Time Complexity :O(n*n)
// Space Complexity :O(n)





// Bottom UP DP
int Prof(int n,int high[],int low[])
{
    int dp[n+1];

    // if n==0 no solution exist
    dp[0]=0;

    // if number of days=1;
    dp[1]=high[0];

    for(int i=2;i<=n;i++)
    {
        dp[i]=max(high[i-1]+dp[i-2],low[i-1]+dp[i-1]);
    }
    return dp[n];
}
// Time Complaxity:O(n)
// Space Complexity :O(n)





// Space Optimise DP
// Fibonacci 

int Ways(int n,int high[],int low[])
{
    int b=max(high[0],low[0]);

    int a=0;
    int c;
    for(int i=1;i<n;i++)
    {
        c=max(high[i]+a,low[i]+b);
        a=b;
        b=c;
    }
    return c;
}
// Time Complexity:O(n)
// Space Complexity :O(1)




int main()
{
    int n;
    cin>>n;
    int high[n];
    int low[n];
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++)
    {
        cin>>high[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>low[i];
    }
    // cout<<Solve(n,high,low)<<endl;
    // cout<<Profit(n,high,low)<<endl;
    // cout<<Prof(n,high,low)<<endl;
    cout<<Ways(n,high,low)<<endl;
    return 0;
}