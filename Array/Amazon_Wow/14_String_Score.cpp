#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int x;
    cin>>x;
    string s,t;
    cin>>s>>t;
    int score1=0;
    int score2=0;
    unordered_map<char,int>mp1,mp2;
    for(auto it:s)
    {
        mp1[it]++;
    }
    for(auto it:t)
    {
        mp2[it]++;
    }
    for(auto it:mp1)
    {
        if(it.second>=x)
        {
            score1+=(it.second*it.second);
        }
    }
    for(auto it:mp2)
    {
        if(it.second>=x)
        {
            score2+=(it.second*it.second);
        }
    }
    if(score1>=score2)
    {
        cout<<s<<endl;
    }
    else
    {
        cout<<t<<endl;
    }
}