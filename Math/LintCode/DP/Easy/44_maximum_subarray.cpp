/*
Description
Given an array of integers, find a contiguous subarray which has the largest sum.

The subarray should contain at least one number.

Example
Example 1:

Input:

nums = [−2,2,−3,4,−1,2,1,−5,3]
Output:

6
Explanation:

the contiguous subarray [4,−1,2,1] has the largest sum = 6.
Example 2:

Input:

nums = [1,2,3,4]
Output:

10
Explanation:

the contiguous subarray [1,2,3,4] has the largest sum = 10.

Challenge
Can you do it in time complexity O(n)?
*/

#include<bits/stdc++.h>
using namespace std;


// function which finds the maximum sum as mid is a part of it
int midCrossingSum(vector<int>&res,int l,int mid,int h)
{
    // Include elements on left of mid.
    int sum=0;
    int left_sum=INT_MIN;
    for(int i=mid;i>=l;i--)
    {
        sum+=res[i];
        if(left_sum<sum)
        {
            left_sum=sum;
        }
    }

    // Include elements on right of mid.
    sum=0;
    int right_sum=INT_MIN;
    for(int i=mid+1;i<=h;i++)
    {
        sum+=res[i];
        if(right_sum<sum)
        {
            right_sum=sum;
        }
    }

     // Return sum of elements on left and right of mid
    // returning only left_sum + right_sum will fail for
    // [-2, 1]
    return max({left_sum,right_sum,left_sum+right_sum});
}


int maxSubarraySum(vector<int>&res,int l,int h)
{
    // base case
    if(l==h)
    {
        return res[l];
    }

    // find the mid;
    int mid=(h+l)/2;

    /* Return maximum of following three possible cases
            a) Maximum subarray sum in left half
            b) Maximum subarray sum in right half
            c) Maximum subarray sum such that the subarray
       crosses the midpoint */

    return max({maxSubarraySum(res,l,mid),maxSubarraySum(res,mid+1,h),midCrossingSum(res,l,mid,h)});
}
// time Complexity:O(nlogn)







// Dynmaic Programming Approach
int solve(vector<int>&res,int n)
{
    int mx=res[0];
    int sum=res[0];
    for(int i=1;i<n;i++)
    {
        sum=max(res[i],sum+res[i]);
        mx=max(mx,sum);
    }
    return mx;
}
// Time Complexity:O(n)
// Space complexity:O(1)

int main()
{
    int n;
    cin>>n;
    vector<int>res(n);
    for(int i=0;i<n;i++)
    {
        cin>>res[i];
    }
    int ans=maxSubarraySum(res,0,n-1);
    cout<<ans<<endl;


    int temp=solve(res,n);
    cout<<temp<<endl;
    return 0;
}