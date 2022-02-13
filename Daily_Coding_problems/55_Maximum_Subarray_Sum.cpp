/*
This problem was asked by Amazon.

Given an array of numbers, find the maximum sum of any contiguous subarray of the array.

For example, given the array [34, -50, 42, 14, -5, 86], the maximum sum would be 137, 
since we would take elements 42, 14, -5, and 86.

Given the array [-5, -1, -8, -9], the maximum sum would be 0, 
since we would not take any elements.

Do this in O(N) time.
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int base=0;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum=max(arr[i],sum+arr[i]);
        base=max(base,sum);
    }
    cout<<base<<endl;
    return 0;
}
// Time Complexity:O(n)
// Space Complexity:O(1)