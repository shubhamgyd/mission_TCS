#include<bits/stdc++.h>
using namespace std;


string findOdd(vector<string>series)
{
    int n=series.size();
    map<string,vector<string>>mp;
    for(int i=0;i<n;i++)
    {
       string patt="";
        string str=series[i];
        int length=str.length();
        for(int j=0;j<length-1;j++)
        {
            if(str[j]<str[j+1])
            {
                patt.push_back('I');
            }
            else
            {
                patt.push_back('D');
            }
        }
        mp[patt].push_back(str);
        
    }
    for(auto it:mp)
    {
        if(it.second.size()==1)
        {
            return it.second[0];
        }
    }
    return "";
}

int main()
{
    int n;
    cin>>n;
    vector<string>res(n);
    for(int i=0;i<n;i++)
    {
        cin>>res[i];
    }
    string ans=findOdd(res);
    cout<<ans<<endl;
    return 0;
}