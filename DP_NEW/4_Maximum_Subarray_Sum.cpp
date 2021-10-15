/*
In this problem we are going to find the maximum sum of subarray
*/

#include<bits/stdc++.h>
using namespace std;

int MaxSum(int arr[],int n)
{
    int dp[n+1]={0};
    dp[0]=arr[0]>0?arr[0]:0;
    int mx=dp[0];
    for(int i=1;i<n;i++)
    {
        dp[i]=dp[i-1]+arr[i];
        if(dp[i]<0)
        {
            dp[i]=0;
        }
        mx=max(mx,dp[i]);
    }
    return mx;
}
/*
DP 
Time Complexity: O(n)
Space Complexity: O(n)
*/


/*
Space Oprimise
Kadane Solution
Time Complexity: O(n)
Space Complexity: O(1)
*/

int Kadane(int arr[],int n)
{
    int sum=0;
    int base=0;
    for(int i=0;i<n;i++)
    {
        sum=max(arr[i],sum+arr[i]);
        if(sum>base)
        {
            base=sum;
        }
        if(sum<0)
        {
            sum=0;
        }
    }
    return base;
}

int main()
{
    int arr[]={1,5,-2,4,-4,9,0,-1};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<Kadane(arr,n)<<endl;
    return 0;
}