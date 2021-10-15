#include<bits/stdc++.h>
using namespace std;

int solve(int N,string str)
{
    map<char,int>mp;
    for(int i=0;i<N;i++)
    {
        mp[str[i]]++;
    }

    int o1=INT_MAX;
    int o2=INT_MIN;

    int e1=INT_MAX;
    int e2=INT_MIN;

    for(auto it=mp.begin();it!=mp.end();++it)
    {
        if(it->second%2==0)
        {
            e1=min(e1,it->second);
            e2=max(e2,it->second);
        }
        else
        {
            o1=min(o1,it->second);
            o2=max(o2,it->second);
        }
    }
    return max({abs(o1-e1),abs(o1-e2),abs(o2-e1),abs(o2-e2)});
}

int findVal(string s)
{
    map<char,int>mp;

    int n=s.length();
    int x_r=0;
    for(int i=0;i<n;i++)
    {
        if(mp.find(s[i])==mp.end())
        {
            x_r^=(i+1);
        }
        mp[s[i]]++;
    }
    return x_r;
}

int main()
{
    // int n;
    // cin>>n;
    string str;
    cin>>str;
    // str.resize(n);
    // cout<<solve(n,str)<<endl;
    cout<<findVal(str);
    return 0;
}