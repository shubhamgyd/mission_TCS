// In this problem we are going to see , how to find the 1st occurance of 1 in an infinite sorted array
// which contains 0's and 1's only

#include<bits/stdc++.h>
using namespace std;

int first_pos(int arr[], int low, int high)
{
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
  
        // if true, then 'mid' is the index of first '1'
        if (arr[mid] == 1 && 
            (mid == 0 || arr[mid - 1] == 0))
            break;
  
        // first '1' lies to the left of 'mid'
        else if (arr[mid] == 1)
            high = mid - 1;
  
        // first '1' lies to the right of 'mid'
        else
            low = mid + 1;
    }
  
    // required index
    return mid;
}

int findPos(int arr[])
{
    int low=0;
    int high=1;
    //int val=arr[0];
    while(arr[high]==0) // iterating until the key is less than array of high
    {
        low=high;
        high=2*high;
        //val=arr[high];   // Incrementing the high by 2 time to its right , if key is not found in its interval
    }

    // After getting key , apply BS in the given range
    return first_pos(arr,low,high);
}

int main()
{
    int arr[]={0,0,0,0,0,0,0,1,1,1,1,1,1};
    //int target=1;
    int ans=findPos(arr);
    if(ans==-1)
    {
        cout<<"Element is not present in the given array\n";
    }
    else
    {
        cout<<"Element is present at the index of : "<<ans<<'\n';
    }
    return 0;
}