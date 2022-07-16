#include<bits/stdc++.h>
using namespace std;

int main()
{
    int s,t,q;
    cin>>s>>t>>q;
    unordered_map<int,int>mp;
    for(int i=0;i<t;i++)
    {
        int a;
        cin>>a;
        mp[a]++;
    }
    for(int i=0;i<q;i++)
    {
        int a;
        cin>>a;
        if(mp.find(a)!=mp.end())
        {
            cout<<"N"<<endl;
        }
        else
        {
            cout<<"Y"<<endl;
        }
    }
}