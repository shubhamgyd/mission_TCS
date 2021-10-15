
#include<bits/stdc++.h>
using namespace std;



int main()
{
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.out", "w", stdout);
#endif
    int n;
    cin>>n;
    vector<int>res;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        res.push_back(a);
    }

    unordered_map<int,int>mp;
    int dp[n];
    memset(dp,0,sizeof(dp));

    int ind=-1;
    int mx=INT_MIN;

    for(int i=0;i<n;i++)
    {
        if(mp.find(res[i]-1)!=mp.end())
        {
            int last=mp[res[i]-1]-1;
            dp[i]=dp[last]+1;
        }
        else
        {
            dp[i]=1;
        }
        mp[res[i]]=i+1;

        if(mx<dp[i])
        {
            mx=dp[i];
            ind=i;
        }
    }
    // We know last element of sequence is
    // a[index]. We also know that length
    // of subsequence is "maximum". So We
    // print these many consecutive elements
    // starting from "a[index] - maximum + 1"
    // to a[index].

    for(int curr=res[ind]-mx+1;curr<=res[ind];curr++)
    {
        cout<<curr<<" ";
    }

    return 0;
}
// Time Complexity :O(nlogn)
// Space Complexity:O(n)