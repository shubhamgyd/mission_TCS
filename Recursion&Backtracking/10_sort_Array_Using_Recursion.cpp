// In this problem we are going sort array by using recursion only

#include<bits/stdc++.h>
using namespace std;


void Sort(int arr[],int n)
{
    if(n<=1)
    {
        return;
    }
    Sort(arr,n-1);
    int last=arr[n-1];
    int temp=n-2;
    while(temp>=0 && arr[temp]>last)
    {
        arr[temp+1]=arr[temp];
        temp=temp-1;
    }
    arr[temp+1]=last;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    Sort(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}


/*
Time complexity: O(2^n)
*/