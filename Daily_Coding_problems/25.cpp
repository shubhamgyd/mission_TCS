/*
This question is asked by Microsoft. Given a string, return the index of its first unique 
character. If a unique character does not exist, return -1.

Ex: Given the following strings...

"abcabd", return 2
"thedailybyte", return 1
"developer", return 0
*/

#include<bits/stdc++.h>
using namespace std;

int solve(string str)
{
    map<char,pair<int,int>>mp;
    for(int i=0;i<str.length();i++)
    {
        mp[str[i]].first=i;
        mp[str[i]].second++;
    }
    for(int i=0;i<str.length();i++)
    {
        // cout<<mp[str[i]].second<<endl;
        if(mp[str[i]].second==1)
        {
            return mp[str[i]].first;
        }
    }
    return -1;
}
// Time Complexity:O(|s|)
// Space Complexity:O(|26|)

int main()
{
    string str;
    cin>>str;
    cout<<solve(str)<<endl;
    for(int i=0;i<str.length();i++)
    {
        bool ok=true;
        for(int j=0;j<str.length();j++)
        {
            if(str[i]==str[j] && i!=j)
            {
                ok=false;
                break;
            }
        }
        if(ok)
        {
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}
// Time Complexity:O(|s|*|s|)
// Space Complexity:O(|1|)
