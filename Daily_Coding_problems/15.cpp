/*
This problem was asked by Amazon.

Given an integer k and a string s, find the length of the longest substring that contains at most k distinct characters.

For example, given s = "abcba" and k = 2, the longest substring with k distinct characters is "bcb"
*/
// This is problem of sliding window

#include<bits/stdc++.h>
using namespace std;


int main()
{
    string str;
    cin>>str;
    int k;
    cin>>k;
    unordered_map<char,int>mp;
    int mx=INT_MIN;
    int i=0,j=0;
    int size=str.length();
    // string ans="";
    int start=0,end=0;
    while(j<size)
    {
        mp[str[j]]++;
        if(mp.size()<k)
        {
            j++;
        }
        else if(mp.size()==k)
        {
            mx=max(mx,j-i+1);
            start=i;
            end=j;
            // string s=str.substr(i,j+1);
            // cout<<s<<endl;
            // ans=s;
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
    for(int i=start;i<=end;i++)
    {
        cout<<str[i];
    }
    // cout<<ans<<endl;
    return 0;
}
// Time Complexity:O(n)
// Space Complexity:O(n)