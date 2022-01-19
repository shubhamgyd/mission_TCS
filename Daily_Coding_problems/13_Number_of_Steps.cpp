/*
There exists a staircase with N steps, and you can climb up either 1 or 2 steps at a time. Given N, write a function that returns the 
number of unique ways you can climb the staircase. The order of the steps matters.

For example, if N is 4, then there are 5 unique ways:

1, 1, 1, 1
2, 1, 1
1, 2, 1
1, 1, 2
2, 2
What if, instead of being able to climb 1 or 2 steps at a time, you could climb any number from a set of positive integers X? 
For example, if X = {1, 3, 5}, you could climb 1, 3, or 5 steps at a time.
*/

#include<bits/stdc++.h>
using namespace std;


int solve(int n)
{
    if(n==0|| n==1)
    {
        return 1;
    }
    int x=solve(n-1);
    int y=solve(n-2);
    return x+y;
}
// Time Complexity :Exponential
// Space Complexity:O(1)




int arr[501];


int Steps(int n)
{
    if(n==0 || n==1)
    {
        return arr[n]=1;
    }
    if(arr[n]!=-1)
    {
        return arr[n];
    }
    return arr[n]=Steps(n-1)+Steps(n-2);
}
// Time Complexity:O(n*n)
// Space Complexity:O(n);



int Ways(int n)
{
    int dp[n];
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




int SpaceOptimize(int n)
{
    if(n==1 || n==0)
    {
        return 1;
    }
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
// Time Complexity:O(n)
// Space Complexity:O(1)


int main()
{
    int n;
    cin>>n;
    cout<<solve(n)<<endl;
    memset(arr,-1,sizeof(arr));
    cout<<Steps(n)<<endl;
    cout<<Ways(n)<<endl;
    cout<<SpaceOptimize(n)<<endl;
    return 0;
}