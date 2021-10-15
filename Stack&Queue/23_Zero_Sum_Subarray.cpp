#include<bits/stdc++.h>
using namespace std;
#define ll long long 


class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n ) {
        //code here
        unordered_map<ll,ll>mp;
        ll count=0;
        ll sum=0;
        mp[0]=1;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            if(mp.find(sum)!=mp.end())
            {
                count+=mp[sum];
                mp[sum]++;
            }
            else
            {
                mp[sum]++;
            }
        }
        return count;
    }
};