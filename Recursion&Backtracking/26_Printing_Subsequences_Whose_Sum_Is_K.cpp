#include<bits/stdc++.h>
using namespace std;


void solve(int i,int arr[],int &sum,int k,int n,vector<int>&ds)
{
    if(i==n)
    {
        if(sum==k)
        {
            for(auto it:ds)
            {
                cout<<it<<" ";
            }
            cout<<endl;
        }
        return;
    }
    ds.push_back(arr[i]);
    sum+=arr[i];
    solve(i+1,arr,sum,k,n,ds);
    ds.pop_back();
    sum-=arr[i];
    solve(i+1,arr,sum,k,n,ds);
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
    int k;
    cin>>k;
    int sum=0;
    vector<int>ds;
    solve(0,arr,sum,k,n,ds);
    return 0;
}