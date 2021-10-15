// In this programm we are going to see the floor of an element in the given array

#include<bits/stdc++.h>
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
        return floorSearch(arr, low, mid - 1, x);
 
    // If mid-1 is not floor and x is
    // greater than arr[mid],
    return floorSearch(arr, mid + 1, high, x);
}

int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9,12,14,18,23};
    int n=sizeof(arr)/sizeof(arr[0]);
    int x=17;
    int result=floorSearch(arr,0,n-1,x);
    if(result<0)
    {
        cout<<"Floor of an element doesn't exists in the given array";
    }
    else
    {
        cout<<"Floor of the "<<x<<" is: "<<arr[result]<<endl;
    }
    return 0;
}