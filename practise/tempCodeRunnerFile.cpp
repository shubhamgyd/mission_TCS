#include<bits/stdc++.h>
using namespace std;

int maxGroups(int input1,int input2[])
{
    unordered_map<int,int>mp;
    long long groups=0;
    for(int i=0;i<input1;i++)
    {
        mp[input2[i]]++;
        if( mp[input2[i]] == 2 ) 
        {
            groups++;
            mp.clear();
        }
    }
    return groups;
}


int main()
{
    int n;
    cin>>n;
    vector<int>res(n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>res[i];
        arr[i]=res[i];
    }
    cout<<maxGroups(n,arr)<<endl;
    map<int,int>mp;
    for(auto it:res)
    {
        mp[it]++;
    }
    int groups=0;
    for(auto it:mp)
    {
        groups+=(it.second/2);
    }
    cout<<groups<<endl;
    // int arr[6]={1,2,3,4};
    // for(int i=0;i<6;i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    return 0;
}