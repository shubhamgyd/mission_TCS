/*
Problem statement: Given two sorted arrays arr1[] and arr2[] of sizes n and m in
 non-decreasing order. Merge them in sorted order. Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.
*/

#include<bits/stdc++.h>
using namespace std;


// Approach :2
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0) return;
        int i=m-1,j=n-1,k=nums1.size()-1,tmp;
        while(k>=0){
            // std::cout<<"k:"<<k<<" i:"<<i<<" j:"<<j<<std::endl;
            if( i<0 or (j>=0 and nums2[j]>=nums1[i])){
                nums1[k--] = nums2[j];
                j--;
            }
            else{
                nums1[k--] = nums1[i];
                i--;
            }
        }
    }
};
// Time Complexity:O(n)



int main()
{
    // Approach :1
    int arr[5]={1,4,6,8,9};
    int arr1[7]={2,3,5,7,9,10,11};
    
    int i=4;
    int j=0;
    int n=5;
    int m=7;
    while(i>=0 and j<m)
    {
        if(arr[i]<arr1[j])
        {
            i--;
        }
        else
        {
            swap(arr[i],arr1[j]);
            i--;
            j++;
        }
    }
    sort(arr,arr+5);
    sort(arr1,arr1+7);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<m;i++)
    {
        cout<<arr1[i]<<" ";
    }
    return 0;
}
// Time Complexity:O(max(nlogn,mlogm))