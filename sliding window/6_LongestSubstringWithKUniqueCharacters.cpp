#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int longestKSubstr(string str, int k) {
    // your code here
    int n=str.length();
    //int k=3;
    int mx=-1;
    int i=0,j=0;
    unordered_map<char,int>mp;
    while(j<n)
    {
        mp[str[j]]++;
        if(mp.size()<k)
        {
            j++;
        }
        else if(mp.size()==k)
        {
            mx=max(mx,j-i+1);
            j++;
        }
        else if(mp.size()>k)
        {
            while(mp.size()>k)
            {
                mp[str[i]]--;
                if(mp[str[i]]==0)
                {
                    mp.erase(str[i]);
                }
                i++;
            }
            j++;
        }
    }
    return mx;
    }
};