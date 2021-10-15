// In this program we are going to see , how to search in a nearly sorted array
#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[],int l,int r,int x)
{
    if(l<=r)
    {
        int mid=l+(r-l)/2;
        if(arr[mid]==x)
        {
            return mid;
        }
        if(mid>l&&arr[mid-1]==x)
        {
            return mid-1;
        }
        if(mid<r&&arr[mid+1]==x)
        {
            return mid+1;
        }
        if(arr[mid]>x)
        {
            return binarySearch(arr,l,mid-2,x);
        }
        return binarySearch(arr,mid+2,r,x);
    }
    return -1;
}

int main()
{
    int arr[]={3,2,10,4,40};
    int n=sizeof(arr)/sizeof(arr[0]);
    int x=4;
    int result=binarySearch(arr,0,n-1,x);
    if(result<0)
    {
        cout<<"Element is not presnt in an array";
    }
    else
    {
        cout<<"Element is present at the index: "<<result<<endl;
    }
    return 0;

}