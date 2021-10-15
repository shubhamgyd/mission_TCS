// In this problem we are going to see , find the kth largest element from the given array

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[]={3,1,4,6,9,8,2,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    priority_queue<int,vector<int>,greater<int>>minheap;
    int k=3;
    for(int i=0;i<n;i++)
    {
        minheap.push(arr[i]);
        if(minheap.size()>k)
        {
            minheap.pop();
        }
    }
    cout<<"K largest element from the given array is:"<<endl;
    while(!minheap.empty())
    {
        cout<<minheap.top()<<" ";
        minheap.pop();
    }
    return 0;
}


/*

          [1]----->[2]<------[5]
           ^ 
           |
           |
           |
           [3]----->[4]


*/