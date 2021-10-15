// In this problem we aree going to find the k closest numbers of a given number from the given array

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[]={0,2,1,-3};
    int x=1;
    int k=3;
    int n=sizeof(arr)/sizeof(arr[0]);
    priority_queue<pair<int,int>>pq;
    for(int i=0;i<n;i++)
    {
        pq.push({abs(x-arr[i]),arr[i]});
        if(pq.size()>k)
        {
            pq.pop();
        }
    }

    cout<<"K closest element to the given number are: "<<endl;
    while(!pq.empty())
    {
        pair<int,int>ele=pq.top();
        cout<<ele.second<<" ";
        pq.pop();
    }
    return 0;
}