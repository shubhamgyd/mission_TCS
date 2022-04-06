/*
This question is asked by Amazon. Given two strings, passage and text return whether or not the characters in text can be used to form the given passage.
Note: Each character in text may only be used once and passage and text will only contain lowercase alphabetical characters.

Ex: Given the following passage and text…

passage = "bat", text = "cat", return false.
Ex: Given the following passage and text…

passage = "dog" text = "didnotgo", return true.

*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    string pat,str;
    cin>>pat>>str;
    map<char,int>mp;
    for(auto it:pat)
    {
        mp[it]++;
    }
    for(auto it:str)
    {
        if(mp.find(it)!=mp.end())
        {
            mp[it]--;
        }
    }
    for(auto it:mp)
    {
        if(it.second>0)
        {
            cout<<"false"<<endl;
            return 0;
        }
    }
    cout<<"true"<<endl;
    return 0;
}
// Time Complexity:O(n)
// Space complexity:O(n)