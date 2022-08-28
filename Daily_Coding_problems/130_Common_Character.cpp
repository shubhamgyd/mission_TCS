/*
Given a string array, words, return a list containing all the characters that are common to all 
the words.
Note: If a character appears multiple times in all the words it should also appear multiple times 
in your return list.

Ex: Given the following words…

words = ["abc", "ab", "a"], return ["a"].
Ex: Given the following words…

words = ["deef", "ddabee", "eebhk"], return ["e","e"].

*/


#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin>>n;
    vector<string>res(n);
    for(int i=0;i<n;i++)
    {
        cin>>res[i];
    }
    map<int,map<char,int>>mp;
    for(int i=0;i<n;i++)
    {
        for(auto ch:res[i])
        {
            mp[i][ch]++;
        }
    }
    vector<char>ans;
    for(char ch='a';ch<='z';ch++)
    {
        int mn=INT_MAX;
        bool ok=true;
        for(int i=0;i<n;i++)
        {
            if(mp[i].find(ch)==mp[i].end())
            {
                ok=false;
            }
            else
            {
                mn=min(mn,mp[i][ch]);
            }
        }
        if(ok)
        {
            for(int i=0;i<mn;i++) ans.push_back(ch);
        }
    }
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    return 0;
}