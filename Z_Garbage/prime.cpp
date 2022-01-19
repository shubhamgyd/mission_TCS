#include<bits/stdc++.h>
using namespace std;


int main()
{
    string str;
    cin>>str;
    stringstream ss(str);
    string word;
    vector<string>res;
    while(ss>>word,'.')
    {
        res.push_back(word);
    }
    int turn=0;
    for(int i=0;i<res.size();i++)
    {
        if(i%2==1)
        {
            reverse(res.begin(),res.end());
        }
    }
    string ans="";
    for(int i=0;i<res.size();i++)
    {
        ans+=res[i];
        ans+=".";
    }
    ans.pop_back();
    cout<<ans<<endl;
    return 0;
}