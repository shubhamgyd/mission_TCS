#include<bits/stdc++.h>
using namespace std;


string solve(string ans,unordered_map<char,int>&mp,int n,string language)
{
    unordered_map<char,int>mp1;
    int sz=ans.length();
    for(int i=0;i<sz;i++)
    {
        mp1[ans[i]]++;
    }
    string res="";
    for(int i=0;i<n;i++)
    {
        char ch=tolower(language[i]);
        char ch1=toupper(language[i]);
        if(mp1[ch]>0)
        {
            int len=mp1[ch];
            for(int j=0;j<len;j++)
            {
                res.push_back(language[i]);
            }
        }
        else if(mp1[ch1]>0)
        {
            int len=mp1[ch1];
            for(int j=0;j<len;j++)
            {
                res.push_back(language[i]);
            }
        }
    }
    return res;
}


int main()
{
    string language,str;
    getline(cin,language);
    getline(cin,str);
    transform(language.begin(), language.end(), language.begin(), ::tolower);
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    unordered_map<char,int>mp;
    int n=language.length();
    for(int i=0;i<n;i++)
    {
        char ch=language[i];
        if(mp[ch]>0)
        {
            cout<<"New Language Error";
            return 0;
        }
        else
        {
            mp[language[i]]++;
        }
    }
    int size=str.length();
    string ans="";
    unordered_map<char,int>afterSpace;
    for(int i=0;i<size;i++)
    {
        char ch=str[i];
        if(mp[ch]==0  && str[i]!=' ')
        {
            continue;
        }
        else if(str[i]==' ')
        {
            ans.push_back(str[i]);
        }
        else
        {
            ans.push_back(str[i]);
        }
    }
    stringstream ss(ans);
    string word;
    bool ok1=false;
    if(ans[ans.length()-1]==' ')
    {
        ok1=true;
    }
    string finAns="";
    while(ss>>word)
    {
        string temp=solve(word,mp,n,language);
        finAns+=temp+" ";
    }
    if(!ok1) finAns.pop_back();
    cout<<finAns;
    return 0;
}