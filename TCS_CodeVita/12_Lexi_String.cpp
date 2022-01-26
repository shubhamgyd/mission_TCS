
/*
1
p= polikujmnhytgbvfredcxswqaz
s= abcd
ans= bdca
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        string s,p;
        cin>>p>>s;
        unordered_map<char,int>mp;
        for(auto ch:s)
        {
            mp[ch]++;
        }
        string ans="";
        for(auto it:p)
        {
            if(mp.find(it)!=mp.end())
            {
                ans.push_back(it);
            }
        }
        cout<<ans<<endl;
        return 0;
    }
}