#include<bits/stdc++.h>
using namespace std;

int main()
{
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    //fast();
    int n;
    cin>>n;
    int arr[n+1];
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
    long long int ans=0;
    int start=0;
    int end=0;
    int mn=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(visited[i] || num[i].second==i)
        {
            continue;
        }
        long long int cycle=0;
        int j=i;
        while(!visited[j])
        {
            visited[j]=1;
            j=num[j].second;
            cycle++;
        }
        if(cycle>0)
        {
            ans+=(cycle-1); // Total Number of cycles -1 , means total number of nodes evolved in cycle -1
            //ans+=(n-cycle);
        }
    }
    cout<<"total number of swaps by using graph approach : "<<ans<<endl;
    return 0;
}