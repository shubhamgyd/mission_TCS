//Given a sorted array, find the element in the array which has minimum difference with the given number.
// Basically in this problem we have to apply three concepts
// 1. For checking if given key is present or not , of present then return the key
// 2. If not , then first we have to find the floor of the given key
// 3. After that we have to fins the ceil of the given key
// After take the abs diff of key and ceil and floor, and return the min among them.

// Binary Search

#include<bits/stdc++.h>
#include<chrono>
using namespace std;


int floorSearch(int arr[],int low,int high,int x)
{
    if(low>high)
    {
        return -1;
    }
    if(x>=arr[high])
    {
        return high;
    }
    int mid=(low+high)/2;
    if(arr[mid]==x)
    {
        return mid;
    }
    if(mid>0&&arr[mid-1]<=x&&x<arr[mid])
    {
        return mid-1;
    }

    // If x is smaller than mid, floor
    // must be in left half.
    if (x < arr[mid])
        return floorSearch(
            arr, low, mid - 1, x);
 
    // If mid-1 is not floor and x is
    // greater than arr[mid],
    return floorSearch(arr, mid + 1, high, x);
}


int ceilSearch(int arr[], int low, int high, int x)
{
	int mid;	
	
	/* If x is smaller than
	or equal to the first element,
	then return the first element */
	if(x <= arr[low])
		return low;
	
	/* If x is greater than the last element,
	then return -1 */
	if(x > arr[high])
		return -1;
	
	/* get the index of middle element of arr[low..high]*/
	mid = (low + high) / 2; /* low + (high - low)/2 */
	
	/* If x is same as middle element,
	then return mid */
	if(arr[mid] == x)
		return mid;
		
	/* If x is greater than arr[mid],
	then either arr[mid + 1] is ceiling of x
	or ceiling lies in arr[mid+1...high] */
	else if(arr[mid] < x)
	{
		if(mid + 1 <= high && x <= arr[mid + 1])
			return mid + 1;
		else
			return ceilSearch(arr, mid + 1, high, x);
	}
	
	/* If x is smaller than arr[mid],
	then either arr[mid] is ceiling of x
	or ceiling lies in arr[low...mid-1] */
	else
	{
		if(mid - 1 >= low && x > arr[mid - 1])
			return mid;
		else
			return ceilSearch(arr, low, mid - 1, x);
	}
}




int BinarySearch(int arr[],int l,int r,int target)
{
    while(l<=r)
    {
        int m=l+(r-l)/2;
        if(arr[m]==target)
        {
            return m;
        }
        if(target>arr[m])
        {
            l=m+1;
        }
        else
        {
            r=m-1;
        }
    }
    return -1;
}

int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9,12,14,18,23};
    int n=sizeof(arr)/sizeof(arr[0]);
    int target=17;
    int res=BinarySearch(arr,0,n-1,target);
    if(res==-1)
    {
        int floor=arr[floorSearch(arr,0,n-1,target)];
        //cout<<floor<<endl;
        int ceil=arr[ceilSearch(arr,0,n-1,target)];
        //cout<<ceil<<endl;
        if(abs(target-floor)<abs(target-ceil))
        {
            cout<<"Key with have min diff with target is : "<<floor<<endl;
        }
        else
        {
            cout<<"Key with have min diff with target is : "<<ceil<<endl;
        }
    }
    else
    {
        cout<<"Key with have min diff with target is : "<<arr[res]<<endl;
    }
    return 0;

}