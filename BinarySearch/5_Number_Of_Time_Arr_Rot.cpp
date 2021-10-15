// We are going to see , how many times original array rotated so that we are get given array
#include<bits/stdc++.h>
using namespace std;

// int Search(int arr[],int low,int high)
// {
//     while(low<=high)
//     {
//         int mid=low+(high-low)/2;
//         if(arr[mid]<=arr[mid+1]&&arr[mid]<=arr[mid-1])
//         {
//             return mid;
//         }
//         else if(arr[low]<=arr[mid])
//         {
//             low=mid+1;
//         }
//         else
//         {
//             high=mid-1;
//         }
//     }
// }

int countRotations(int arr[], int low, int high)
{
	// This condition is needed to handle the case
	// when the array is not rotated at all
	if (high < low)
		return 0;

	// If there is only one element left
	if (high == low)
		return low;

	// Find mid
	int mid = low + (high - low)/2; /*(low + high)/2;*/

	// Check if element (mid+1) is minimum element.
	// Consider the cases like {3, 4, 5, 1, 2}
	if (mid < high && arr[mid+1] < arr[mid])
	return (mid+1);

	// Check if mid itself is minimum element
	if (mid > low && arr[mid] < arr[mid - 1])
	return mid;

	// Decide whether we need to go to left half or
	// right half
	if (arr[high] > arr[mid])
	    return countRotations(arr, low, mid-1);

	return countRotations(arr, mid+1, high);
}

int main()
{
    int arr[]={5,4,3,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Arra totated "<<countRotations(arr,0,n-1)<<" Times"<<endl;
    return 0;
}