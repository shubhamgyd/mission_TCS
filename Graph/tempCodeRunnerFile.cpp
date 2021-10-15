#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> findOriginalArray(vector<int>& arr) {
        int n=arr.size();
        map<int,int>mp;
        for(auto it:arr)
        {
            mp[it]++;
        }
        vector<int>res;
        for(auto it:mp)
        {
            if(mp.find(2*(it.first))!=mp.end())
            {
                res.push_back(it.first);
                mp[it.first]--;
                if(mp[it.first]==0)
                {
                    mp.erase(it.first);
                }
                
                mp[2*(it.first)]--;
                if(mp[2*(it.first)]==0)
                {
                    mp.erase(2*(it.first));
                }
            }
        }
        if(res.size()!=n/2)
        {
            return {};
        }
        return res;
    }
};

int main()
{
    int ct=0;
    for(int i=100000;i<=999999;i++)
    {
        string str=to_string(i);
        int t=count(str.begin(),str.end(),'3');
        int z=count(str.begin(),str.end(),'0');
        if(t==3 && z==3)
        {
            ct++;
        }
    }
    cout<<ct<<endl;
    return 0;
    
}