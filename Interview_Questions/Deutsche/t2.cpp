#include <bits/stdc++.h>
using namespace std;
#define int long long

bool cmp(pair<int,int>a,pair<int,int>b)
{
    if(a.first==b.first) return a.second<b.second;
    return a.first<b.first;
}

signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,w;
        cin>>n>>k>>w;
        vector<pair<int,int>>nums(n);
        map<pair<int,int>,int>mp;
        for(int i=0;i<n;i++)
        {
            cin>>nums[i].first>>nums[i].second;
            mp[{nums[i].first,nums[i].second}]=i;
        }
        sort(nums.begin(),nums.end(),cmp);
        
        vector<int>ans(n);
        int prep=0;
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                int cost=k*nums[i].second-w*0;
                pair<int,int>p={nums[i].first,nums[i].second};
                prep=nums[i].first+nums[i].second;
                ans[mp[p]]=cost;
            }
            else
            {
                if(nums[i].first>=prep)
                {
                    int cost=k*nums[i].second-w;
                    pair<int,int>p={nums[i].first,nums[i].second};
                    ans[mp[p]]=cost;
                    prep=nums[i].first+nums[i].second;
                }
                else
                {
                    int diff=prep-nums[i].first;
                    int cost=k*nums[i].second-w*diff;
                    pair<int,int>p={nums[i].first,nums[i].second};
                    ans[mp[p]]=cost;
                    prep+=nums[i].second;

                }
            }
        }
        for(int i=0;i<n;i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}