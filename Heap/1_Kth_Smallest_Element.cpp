// In this problem we are going to find out the kth largest element from the given array

#include<bits/stdc++.h>
using namespace std;

#define minheap priority_queue<int,vector<int>,greater<int>>

int main()
{
    int arr[]={7,10 ,4 ,20 ,15};
    priority_queue<int>maxheap;
    int k=4;
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++)
    {
        maxheap.push(arr[i]);
        if(maxheap.size()>k)
        {
            maxheap.pop();
        }
    }
    cout<<"kth min element is: "<<maxheap.top()<<endl;
    // while(!maxheap.empty())
    // {
    //     cout<<maxheap.top()<<" ";
    //     maxheap.pop();
    // }
    return 0;
}


/*
If we use MaxHeap, we have O(k) space and O(nLogk) time.
If we use MinHeap, we have O(1) space and O(n + klogn) time.

If k is small such that k~logk, 
MinHeap gets reduced to ~O(n + logn)
MaxHeap gets reduced to ~O(n)

If k is of the order n,<=n:
Min gives O(n + nlogn)
Max gives O(nlogn)

So always prefer max for kth smallest and min for kth largest.
Side note: if it's explicitly given all elements are distinct, then and only then go for quickselect method.
*/