#include<bits/stdc++.h>
using namespace std;

// Space Optimise
// Kadae Algorithm
int Space_Optimise(int arr[],int n)
{
    int sum=0;
    int base=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
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
/*
Time Complexity:O(n)
Space Complexity : O(1)
*/






//  Bottom UP Approach
int MaximumSum(int arr[],int n)
{
    int dp[100];
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
Time Complexity: O(n)
Space Somplexity: O(n)
*/


int main()
{
    int arr[]={-3,2,1,-3,-4,5,6,-1,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<Space_Optimise(arr,n)<<endl;
}