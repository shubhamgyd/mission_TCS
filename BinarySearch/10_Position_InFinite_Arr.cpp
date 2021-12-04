// In this problem we are going to see, how to find the position of an element in an infinite array

// Basically idea is same , like the binary search

#include<bits/stdc++.h>
using namespace std;



// Simply BS to fing the key in the given interval
int BS(int arr[],int low,int high,int key)
{
    while(low<=high)
    {
    int mid=low+(high-low)/2;
    if(arr[mid]==key)
    {
        return mid;
    }
    else if(arr[mid]>key)
    {
        high=mid-1;
    }
    else
    {
        low=mid+1;
    }

    }
    return -1;

}

int findPos(int arr[],int key)
{
    int low=0;
    int high=1;
    //int val=arr[0];
    while(key>arr[high]) // iterating until the key is greater than array of high
    {
        low=high;
        high=2*high;
        //val=arr[high];   // Incrementing the high by 2 time to its right , if key is not found in its interval
    }

    // After getting key , apply BS in the given range
    return BS(arr,low,high,key);
}

int main()
{
    int arr[]={3, 5, 7, 9, 10, 90, 100, 130,140, 160, 170};
    int n=sizeof(arr)/sizeof(arr[0]);
    int target=3;
    int ans=findPos(arr,target);
    if(ans==-1)
    {
        cout<<"Element is not present in the array"<<'\n';
    }
    else
    {
        cout<<"Element is present at the index "<<ans<<'\n';
    }
    return 0;

}