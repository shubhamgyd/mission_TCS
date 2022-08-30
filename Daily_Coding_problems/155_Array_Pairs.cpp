/*
You are given an integer array, nums, that contains 2N integers. 
Return the maximum sum you can create by pairing integers together and summing the 
minimum values in each of the pairs.

Ex: Given the following nums…

nums = [1, 3, 2, 4], return 4 (min(1, 2) + min(3, 4) = 4).
Ex: Given the following nums…

nums = [2, 4, 2, 8, 4, 3], return 9.
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    sort(nums.rbegin(),nums.rend());
    // for(auto it:nums)
    // {
    //     cout<<it<<" ";
    // }
    // cout<<endl;
    int sum=0;
    for(int i=1;i<n;i+=2)
    {
        sum+=nums[i];
    }
    cout<<sum<<endl;
    return 0;
}