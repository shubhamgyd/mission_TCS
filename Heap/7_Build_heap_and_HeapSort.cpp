#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[],int n,int i)
{
    int large=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<n && arr[left]>arr[large])
    {
        large=left;
    }

    if(right<n && arr[right]>arr[large])
    {
        large=right;
    }

    if(large!=i)
    {
        swap(arr[i],arr[large]);
        heapify(arr,n,large);
    }

}

void buildheap(int arr[],int n)
{
    int index=(n/2)-1;

    // Building heap
    for(int i=index;i>=0 ;i--)
    {
        heapify(arr,n,i);
    }

    //Sorting arr by using heapsort
    for(int i=n-1;i>0;i--)
    {
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}

int main()
{
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    int arr[]={6, 8, 4, 5, 2, 3};
    int n=sizeof(arr)/sizeof(arr[0]);
    //make_heap(arr,arr+n);
    priority_queue<int,vector<int>,greater<int>>pq(arr,arr+n);
    while(!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
    buildheap(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}