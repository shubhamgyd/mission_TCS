/*
Problem Statement: There is an integer array nums sorted in ascending order 
(with distinct values). Given the array nums after the possible rotation and 
an integer target, return the index of target if it is in nums, or -1 if it is
 not in nums. We need to search a given element in a rotated sorted array.

Example 1:

Input: nums = [4,5,6,7,0,1,2,3], target = 0

Output: 7 

Explanation: Here, the target is 0. We can see that 0 is present in the given 
rotated sorted array, nums. Thus, we get output as 4, which is the index at which 0 is 
present in the array.
*/


#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>res(n);
    for(int i=0;i<n;i++)
    {
        cin>>res[i];
    }
    int target;
    cin>>target;

    // using linear search
    for(int i=0;i<n;i++)
    {
        if(res[i]==target)
        {
            cout<<i<<endl;
            break;
        }
    }
    // T:O(n)
    // S:O(1)



    // using linear search
    int low=0;
    int high=n-1;
    bool ok=false;
    while(low<=high)
    {
        int mid=(high+low)/2;
        if(res[mid]==target)
        {
            ok=true;
            cout<<mid<<endl;
            break;
        }
        if(res[low]<=res[mid])
        {
            if(res[low]<=target and res[mid]>=target)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        else
        {
            if(res[mid]<=target and res[high]>=target)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
    }
    if(!ok)
    {
        cout<<"-1"<<endl;
    }
    // T:O(logn)
    // S:O(1)
}