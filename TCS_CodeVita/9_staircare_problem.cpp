/*
There are n stairs, a person standing at the bottom wants to reach the top. 
The person can climb either 1 stair or 2 stairs at a time.

Count the number of ways, the person can reach the top.
*/
#include<bits/stdc++.h>
using namespace std;

int Recursion(int n)
{
    // base case
    if(n==0 || n==1)
    {
        return 1;
    }
    int step1=Recursion(n-1);
    int step2=Recursion(n-2);
    return step1+step2;
}
// Time Complexity: Exponential
// Space Complexity:O(1)

int dp[100001];
int Memoization(int n)
{
    //  base case
    if(n==0 || n==1)
    {
        return 1;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    return dp[n]=Memoization(n-1)+Memoization(n-2);
}
// Time Complexity:O(n)
// Space Compleixty:O(n)



// Dp
int Bottom_Up(int n)
{
    int dp[n+1];
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
// Time Complexity:O(n)
// Space Complexity:O(n)


int Space(int n)
{
    int a=1;
    int b=1;
    int c;
    for(int i=2;i<=n;i++)
    {
        c=a+b;
        a=b;
        b=c;
    }
    return c;
}
// Time Complexity :O(n)
// space Complexity :O(1)



int main()
{
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    cout<<"Total Ways by recursion: "<<Recursion(n)<<endl;
    cout<<"Total Ways by Memoization: "<<Memoization(n)<<endl;
    cout<<"Total Ways by Bottom Up: "<<Bottom_Up(n)<<endl;
    cout<<"Total Ways by Space: "<<Space(n)<<endl;
    return 0;
}