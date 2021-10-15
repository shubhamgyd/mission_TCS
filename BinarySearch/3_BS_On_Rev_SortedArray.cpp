// Same bianry search but we need to just change the direction of search

// Binary Search

#include<bits/stdc++.h>
using namespace std;

int BinarySearch(int arr[],int l,int r,int target)
{
    while(l<=r)
    {
        int m=l+(r-l)/2;
        if(arr[m]==target)
        {
            return m;
        }
        if(target<arr[m])
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
    //int n=6;
    int arr[]={9,8,7,6,5,4,3,2,1,0};
    int n=sizeof(arr)/sizeof(arr[0]);
    int target=1;
    int res=BinarySearch(arr,0,n-1,target);
    // if(res>0)
    // {
    //     cout<<"Element found at Index "<<res<<endl;
    // }
    // else
    // {
    //     cout<<"element not present"<<endl;
    // }
    (res==-1)?cout<<"Element Not Present \n": cout<<"Element is present at index: "<<res<<endl;
    return 0;

}