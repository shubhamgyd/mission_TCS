/*
You are given N cubes of wood aranged in increasing order.The length of side of ith 
cube is arr[i] and side lenghts are distinct. The first and last cubes cannot be moved.

We have minimize the maximum diff of cubes arrangement by removing exactly K cubes.

diff=max(arr[i+1]-arr[i]) for 1<i<-N-1

Input:
firs line single Integer N
second line N separated integer arr[i]
third line single Integer K

Example
5
1 2 3 7 8
2

output:
5
*/

#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<int>&res,int mid,int k)
{
    int n=res.size();
    int prev=res[0];
    int ct=0;
    for(int i=1;i<n-1;i++)
    {
        if(res[i+1]-prev<=mid)
        {
            ct++;
        }
        else
        {
            prev=res[i];
        }
    }
    return ct>=k;
}

int main()
{
    int n;
    cin>>n;
    vector<int>res(n);
    for(int i=0;i<n;i++)
    {
        cin>>res[i];
    }
    int k;
    cin>>k;
    int low=1;
    int high=res[n-1]-res[0];
    int ans=res[n-1]-res[0];
    while(low<=high)
    {
        // cout<<"Hello"<<endl;
        int mid=low+(high-low)/2;
        if(isValid(res,mid,k))
        {
            ans=mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
// Time Complexity: O(n*log(a[n-1]))
// Space Complexity:O(1)