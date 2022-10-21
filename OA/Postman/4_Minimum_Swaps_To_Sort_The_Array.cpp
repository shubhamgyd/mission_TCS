/*
we have to find the minimum number of swaps to sort the array
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    pair<int,int>num[n];
    for(int i=0;i<n;i++)
    {
        num[i].first=arr[i];
        num[i].second=i;
    }
    sort(num,num+n);
    vector<bool>visited(n,false);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(visited[i] || num[i].second==i)
        {
            continue;
        }
        int cycle=0;
        int j=i;
        while(!visited[j])
        {
            visited[j]=true;
            j=num[j].second;
            cycle++;
        }
        if(cycle>0)
        {
            ans+=(cycle-1);
        }
    }
    cout<<"Minimum Swaps to sort the array: "<<ans<<endl;
    return 0;
}
// Time Complexity:O(n*n)
// Space Complexity:O(n)
