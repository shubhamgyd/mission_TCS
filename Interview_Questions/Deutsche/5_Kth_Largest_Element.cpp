/*
You are given an array arr containing N distinct integers. You must perform the following operations on the array:

For each pair of integers of the array, you must find the absolute difference D between these integers and insert D into the array. If D is already an element of the array, then you are not required to insert D into the array
You repeat task 1 until the array cannot be modified further. This implies that the absolute difference between any two elements in the array is already an element of the array.
Write a program to find the Kth the largest element of the final array after the array cannot be modified further. If there is no such element then print -1.
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
    int k;
    cin>>k;
    int gcdAll=nums[0];
    int mx=nums[0];
    for(int i=1;i<n;i++)
    {
        mx=max(mx,nums[i]);
        gcdAll=__gcd(gcdAll,nums[i]);
    }
    int ans=mx-(k-1)*gcdAll;
    cout<<ans<<endl;
    return 0;
}