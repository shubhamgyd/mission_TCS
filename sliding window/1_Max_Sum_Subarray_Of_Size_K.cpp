// In this problem we are going to find the maximum sum of subarray of size k

#include<bits/stdc++.h>
using namespace std;

int SubArraySum(int arr[],int k,int n)
{
    // Base condition, wheather the size of k is  greater than n
    if(k>n)
    {
        return -1;
    }

    // First find the sum of given size of window

    int max_sum=0;
    for(int i=0;i<k;i++)
    {
        max_sum+=arr[i];
    }

    // Now we are going to check other windows sum of size k , 
    //  by adding the next element of k and substracting the arr[i-k] element from the given sum to check , wheater it is max or not
    int window_sum=max_sum;
    for(int i=k;i<n;i++)
    {
        window_sum+=arr[i]-arr[i-k];
        max_sum=max(window_sum,max_sum);
    }
    return max_sum;
}

int main()
{
    int arr[]={1,2,3,4,5,6,-7,-8,-9};
    int k=3;
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Max sum of given subarray of size K: "<<SubArraySum(arr,k,n)<<endl;
    return 0;
}