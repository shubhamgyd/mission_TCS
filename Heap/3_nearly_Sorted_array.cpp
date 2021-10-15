// In this problem we are going to , sort the nearly sorted array by using priority_queue

#include<bits/stdc++.h>
using namespace std;

void sortArr(int arr[],int n,int k)
{
    // Insert first k+1 items in a priority queue (or min
    // heap)
    //(A O(k) operation). We assume, k < n.
    priority_queue<int,vector<int>,greater<int>>pq(arr,arr+k+1);




    // i is index for remaining elements in arr[] and index
    // is target index of for current minimum element in
    // Min Heap 'pq'.

    int index=0;
    for(int i=k+1;i<n;i++)
    {
        arr[index++]=pq.top();
        pq.pop();
        pq.push(arr[i]);
    }
    while(!pq.empty())
    {
        arr[index++]=pq.top();
        pq.pop();
    }
}

int main()
{
    //int n=5;
    int arr[]={2, 6, 3, 12, 56, 8};
    int k=3;
    int n=sizeof(arr)/sizeof(arr[0]);
    sortArr(arr,n,k);
    cout<<"K sorted alements are: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}

//The Min Heap based method takes O(n log k) time and uses O(k) auxiliary space.