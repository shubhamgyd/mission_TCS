#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>res(n),res1(n);
    map<int,pair<int,int>>mp,mp1;
    for(int i=0;i<n;i++)
    {
        cin>>res[i];
        mp[res[i]].first++;
        mp[res[i]].second=i;
    }
    for(int i=0;i<n;i++)
    {
        cin>>res1[i];
        mp1[res1[i]].first++;
        mp1[res1[i]].second=i;
    }
    int total_ct=0;
    for(int i=0;i<n;i++)
    {
        if(mp1.find(res1[i])!=mp.end() and mp[res[i]].first==1 and mp1[res1[i]].first==1 and i!=mp1[res1[i]].second)
        {
            total_ct++;
        }
    }

    // int num1=
}