/*
This problem was asked by Facebook.

You are given an array of non-negative integers that represents a two-dimensional 
elevation map where each element is unit-width wall and the integer is the height. 
Suppose it will rain and all spots between two walls get filled up.

Compute how many units of water remain trapped on the map in O(N) time and O(1) space.

For example, given the input [2, 1, 2], we can hold 1 unit of water in the middle.

Given the input [3, 0, 1, 3, 0, 5], we can hold 3 units in the first index, 2 in the 
second, and 3 in the fourth index (we cannot hold 5 since it would run off to the left), 
so we can trap 8 units of water.
*/


// Problem is similiar to the rainwater trapping problem
#include<bits/stdc++.h>
using namespace std;


int Water(int arr[],int n)
{
    int left[n];
    left[0]=arr[0];
    for(int i=1;i<n;i++)
    {
        left[i]=max(left[i-1],arr[i]);
    }

    int right[n];
    right[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--)
    {
        right[i]=max(right[i+1],arr[i]);
    }

    int water[n];
    for(int i=0;i<n;i++)
    {
        water[i]=min(left[i],right[i])-arr[i];
    }
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=water[i];
    }
    return sum;
}
// Time Complexity:O(n)
// Space Complexity:O(n)




int Water1(int arr[],int n)
{
    int water=0;
    for(int i=1;i<n-1;i++)
    {
        int left=arr[i];
        for(int j=0;j<i;j++)
        {
            left=max(left,arr[j]);
        }

        int right=arr[i];
        for(int j=i+1;j<n;j++)
        {
            right=max(right,arr[j]);
        }

        water+=min(left,right)-arr[i];
    }
    return water;
}
// Time Complexity:O(n*n)
// Space Complexity:O(1)



int Water2(int arr[],int n)
{
    int l_val=0;
        int r_val=0;
        int l=0;
        int r=n-1;
        int ans=0;
        while(l<=r)
        {
            if(arr[l]<=arr[r])
            {
                if(arr[l]>=l_val)
                {
                    l_val=arr[l];
                }
                else
                {
                    ans+=(l_val-arr[l]);
                }
                l++;
            }
            else
            {
                if(arr[r]>=r_val)
                {
                    r_val=arr[r];
                }
                else
                {
                    ans+=(r_val-arr[r]);
                }
                r--;
            }
        }
        return ans;
}
// Time Complexity:O(n)
// Space Complexity:O(1)


int main()
{
    int  n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<Water(arr,n)<<endl;
    cout<<Water1(arr,n)<<endl;
    cout<<Water2(arr,n)<<endl;
    return 0;
}