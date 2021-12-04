#include<bits/stdc++.h>
using namespace std;


int main()
{
    unordered_map<string,vector<string>>mp;
    for(int i=0;i<4;i++)
    {
        string name,mail;
        cin>>name>>mail;
        mp[name].push_back(mail);
    }
    for(auto it:mp)
    {
        cout<<it.first<<"->";
        for(auto ele:it.second)
        {
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}