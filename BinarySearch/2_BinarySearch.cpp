// Binary Search

#include<bits/stdc++.h>
using namespace std;

void Display(int ct)
{
    cout<<ct<<endl;
}

int BinarySearch(int arr[],int l,int r,int target)
{
    int ct=0;
    while(l<=r)
    {
        ct++;
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
    cout<<"count: "<<ct<<endl;
    Display(ct);
    return -1;
}

int main()
{
    int arr[]={2,4,7,10,14,27,39,52,67};
    int n=sizeof(arr)/sizeof(arr[0]);
    int target=52;
    int res=BinarySearch(arr,0,n-1,target);
    (res==-1)?cout<<"Element Not Present \n": cout<<"Element is present at index: "<<res<<endl;
    return 0;

}