/*
Given three integer arrays, nums1, nums2, and nums3, sorted in ascending order, 
return a list containing all integers that are common to all three arrays.
Note: There are no duplicate values in any of the arrays.

Ex: Given the following nums1, nums2, and nums3…

nums1 = [1, 2, 3], nums2 = [1, 2], nums3 = [1], return [1].
Ex: Given the following nums1, nums2, and nums3…

nums1 = [4, 5, 6], nums2 = [7, 8, 9], nums3 = [10], return [].
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int m;
    cin>>m;
    int arr1[m];
    for(int i=0;i<m;i++) cin>>arr1[i];
    int k;
    cin>>k;
    int arr2[k];
    for(int i=0;i<k;i++) cin>>arr2[i];

    unordered_map<int,int>mp,mp1;
    for(int i=0;i<n;i++) mp[arr[i]]++;
    for(int i=0;i<m;i++) mp[arr1[i]]++;
    for(int i=0;i<k;i++)
    {
        if(mp.find(arr2[i])!=mp.end() and mp1.find(arr2[i])!=mp1.end())
        {
            cout<<arr[i]<<" ";
        }
    }
    return 0;
}