/*
This question is asked by Facebook. Given two strings s and t return whether or not s 
is an anagram of t.
Note: An anagram is a word formed by reordering the letters of another word.

Ex: Given the following strings...

s = "cat", t = "tac", return true
s = "listen", t = "silent", return true
s = "program", t = "function", return false
*/

#include<bits/stdc++.h>
using namespace std;

bool solve(string s,string t)
{
    int sz1=s.length();
    int sz2=t.length();
    if(sz1!=sz2)
    {
        return false;
    }
    vector<bool>visited(sz2,false);
    for(int i=0;i<sz1;i++)
    {
        char ch=s[i];
        bool ok=false;
        for(int j=0;j<sz2;j++)
        {
            if(ch==t[j] && !visited[j])
            {
                visited[j]=true;
                ok=true;
                break;
            }
            else if(ch==t[j] && visited[j])
            {
                continue;
            }
        }
        if(!ok)
        {
            return false;
        }
    }
    return true;
}
// Time Complexity:O(|s|*|t|)
// Space Complexity:O(|t|)



bool Anagram(string s,string t)
{
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    if(s!=t)
    {
        return false;
    }
    return true;
}
// Time Complexity: max(|s|*log|s|,|t|*log|t|)
// Space Complexity:O(1)

bool Ana(string s,string t)
{
    if(s.length()!=t.length())
    {
        return false;
    }
    map<char,int>mp1;
    map<char,int>mp2;
    for(int i=0;i<s.length();i++)
    {
        mp1[s[i]]++;
    }
    for(int i=0;i<t.length();i++)
    {
        mp2[t[i]]++;
    }
    for(int i=0;i<s.length();i++)
    {
        if(mp2.find(s[i])==mp2.end())
        {
            return false;
        }
        else if(mp2.find(s[i])!=mp2.end())
        {
            if(mp1[s[i]]!=mp2[s[i]])
            {
                return false;
            }
        }
    }
    return true;
}
// Time Complexity:O(|s|)
// Space Complexity:O(|s|+|t|)


int main()
{
    cout<<(-20%10)<<endl;
    string s,t;
    cin>>s>>t;
    bool ok=solve(s,t);
    if(ok)
    {
        cout<<"True"<<endl;
    }
    else
    {
        cout<<"False"<<endl;
    }
    cout<<Anagram(s,t)<<endl;
    cout<<Ana(s,t)<<endl;
    return 0;
}