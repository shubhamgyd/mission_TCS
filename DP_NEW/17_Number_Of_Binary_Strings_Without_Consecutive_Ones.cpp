// In this problem we are going to find the number of valid binary substring, without consecutive ones
#include<bits/stdc++.h>
using namespace std;



// Bottom Up
int ValidString(int n)
{
    int dp[n];
    dp[0]=0;
    dp[1]=2;
    dp[2]=3;
    for(int i=3;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
/*
Time Complexity: O(n)
space Complexity: O(n)
*/


// Space Optimise
int Strings(int n)
{
    if(n==1)
    {
        return 2;
    }
    if(n==2)
    {
        return 3;
    }
    int a=2;
    int b=3;
    int c;
    for(int i=3;i<=n;i++)
    {
        c=(a+b);
        a=b;
        b=c;
    }
    return c;
}
/*
Time Complexity: O(n)
Space Complexity: O(1)
*/



int main()
{
    int n;
    cin>>n;
    cout<<Strings(n)<<endl;
}