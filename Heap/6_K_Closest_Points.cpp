// In this problem we are going to find the , k closest element to the origin

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[][2]={{3, 3}, {5, -1}, {-2, 4}};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=2;
    priority_queue<pair<int,pair<int,int>>>pq;
    for(int i=0;i<n;i++)
    {
        pq.push({arr[i][0]*arr[i][0]+arr[i][1]*arr[i][1],{arr[i][0],arr[i][1]}});
        if(pq.size()>k)
        {
            pq.pop();
        }
    }
    cout<<"K closest element to the origin are: "<<endl;
    while(!pq.empty())
    {
        cout<<pq.top().second.first<<" "<<pq.top().second.second<<endl;
        pq.pop();
    }
    return 0;
}