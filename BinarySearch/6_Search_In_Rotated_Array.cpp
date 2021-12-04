// Search an element in rotated array

// Concept is same like previous question
#include<bits/stdc++.h>
using namespace std;


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

int BS1(int arr[],int l,int r,int target)
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

int BS2(int arr[],int l,int r,int target)
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


int search(vector<int>& nums, int target) {
        
        int low=0;
        int high=nums.size()-1;
        
        
        while (low < high) {                       
            
            int mid = (low + high) / 2  ;             
            
            //just two elements
            if(low == mid) {                
                if (target == nums[high]) {
                    low++;
                }                
                break;
            }
            
            //right increasing
            if (nums[mid] < nums[high]) {            
                if( target > nums[mid] && target <= nums[high])  {
                    low = mid;
                }else {
                    //we can skip this part
                    high=mid;
                }
            }else {
                //left increasing
                if(target >= nums[low] && target <= nums[mid] ) {
                    high=mid;
                }else {
                     low = mid;
                }    
            }
        }
       
        if (nums[low] == target) return low;
        return -1;        
    } 

int search1(vector<int>&nums,int target)
{
     int low, high, mid;
        low = 0;
        high = nums.size() - 1;
                
        while(low < high) {        
            
            mid = (low + high) / 2;        
        
            //just two elements
            if (low == mid) {                 
                if (nums[high] == target) low++;
                break;
            }
            
            //if right increasing
            if (nums[mid] < nums[high]) {
                if (target > nums[mid] && target <= nums[high]) {
                    low = mid;
                }else {
                    //we can skip this
                    high = mid;
                }
            }else if (nums[low] < nums[mid]) { //if left increasing
                if (target >= nums[low] && target <= nums[mid]) {
                    high = mid;
                }else {
                    //we can skip this
                    low = mid ;
                }                
            }else {                
                //duplicates neither increase nor decrease
                while(low < mid && nums[low] == nums[low + 1]  ) {
                    low++;
                }
                
                while(high > mid && nums[high] == nums[high-1]) {
                    high--;
                }
            }
        }
        
        return nums[low] == target?low:-1;
}

int main()
{
    // int arr[]={3,1,1,1,1};
    // int n=sizeof(arr)/sizeof(arr[0]);
    // int target=3;
    // int index=countRotations(arr,0,n-1);
    // int a=BS1(arr,0,index-1,target);
    // int b=BS2(arr,index,n-1,target);
    // if(a<b)
    // {
    //     cout<<"Element is present at index:"<<b<<endl;
    // }
    // if(b<a)
    // {
    //     cout<<"Element is present at index: "<<a<<endl;
    // }
    // if(a<0&&b<0)
    // {
    //     cout<<"Element is not present in given array"<<endl;
    // }
    vector<int>v1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11 };
    int target=12;
    int a=search1(v1,target);
    if(a>=0)
    {
        cout<<"Element is present at index: "<<a<<endl;
    }
    else
    {
        cout<<"Element is not present in the given array "<<endl;
    }
    return 0;
}