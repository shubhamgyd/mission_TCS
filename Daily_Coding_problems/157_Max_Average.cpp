/*
Given an array of integers, nums, and a value k, return the maximum average value from any 
contiguous subarray of size k in nums.

Ex: Given the following nums and k…

nums = [4, -1, 4, 2], k = 2, return 3.0 ((4 + 2) / 2 = 3.0).
Ex: Given the following nums and k…

nums = [5, 1, -3, 5, 2], k = 3, return 1.33.
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    double n;
    cin>>n;
    vector<double>nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    double k;
    cin>>k;
    double mx=INT_MIN;
    int i=0;
    int j=0;
    double sum=0;
    for(i;i<k;i++)
    {
        sum+=nums[i];
    }
    mx=max(mx,sum/k);
    while(i<n)
    {
        sum-=nums[j++];
        sum+=nums[i++];
        mx=max(mx,sum/k);
    }
    cout<<fixed<<setprecision(2)<<mx<<endl;
    return 0;
}