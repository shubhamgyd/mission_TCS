#include<bits/stdc++.h>
using namespace std;


string decodeString(string str)
{
    int even[26];
    int odd[26];
    memset(even,0,sizeof(even));
    memset(odd,0,sizeof(odd));
    for(int i=0;i<str.length();++i)
    {
        char ch=str[i];
        if((i+1)%2!=0)
        {
            odd[ch-'a']++;
        }
        else
        {
            even[ch-'a']++;
        }
    }
    string ans="";
    for(int i=0;i<26;++i)
    {
        string s1=to_string(even[i]);
        string s2="#";
        string s3=to_string(odd[i]);
        string s4="|";
        ans+=s1;
        ans+=s2;
        ans+=s3;
        ans+=s4;
    }
    return ans;
}

int solve(vector<string>&res)
{
    int n=res.size();
    int cnt=0;
    set<string>st;
    for(auto it:res)
    {
        string hash=decodeString(it);
        if(st.find(hash)==st.end())
        {
            st.insert(hash);
            cnt++;
        }
    }
    return cnt;
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
    int ans=solve(res);
    cout<<ans<<endl;
    return 0;
}