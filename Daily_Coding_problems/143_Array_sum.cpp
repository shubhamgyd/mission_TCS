/*
Given an integer array, nums, return an array containing its running sum at every index.

Ex: Given the following nums…

nums = [1, 2, 3], return [1, 3, 6].
Ex: Given the following nums…

nums = [10], return [10].
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
    int pref[n];
    pref[0]=nums[0];
    for(int i=1;i<n;i++)
    {
        pref[i]=pref[i-1]+nums[i];
    }
    for(int i=0;i<n;i++)
    {
        cout<<pref[i]<<" ";
    }
    return 0;
}