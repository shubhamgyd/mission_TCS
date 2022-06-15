#include <bits/stdc++.h>
using namespace std;

bool ArePair(char opening, char closing)
{
    if (opening == '(' && closing == ')')
        return true;
    else if (opening == '{' && closing == '}')
        return true;
    else if (opening == '[' && closing == ']')
        return true;
    return false;
}

bool is_all_brackets_closed(string text)
{
    stack<char> s;
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] == '(' || text[i] == '{' || text[i] == '[')
        {
            s.push(text[i]);
        }
        else if (text[i] == ')' || text[i] == '}' || text[i] == ']')
        {
            if (s.empty() || !ArePair(s.top(), text[i]))
            {
                return false;
            }
            else
            {
                s.pop();
            }
        }
    }
    return s.empty() ? true : false;
}

string countVotes(vector<string>validCandidates, vector<string>voteCasted)
{
    unordered_map<string,int>mens;
    for(auto it:validCandidates)
    {
        mens[it]++;
    }
    map<string,int>mp;
    int invalidCount=0;
    int mx=0;
    for(auto it:voteCasted)
    {
        if(mens[it]==0) invalidCount++;
        else 
        {
            mp[it]++;
            mx=max(mx,mp[it]);
        }
    }
    bool isWinner=true;
    if(invalidCount>=mx or voteCasted.size()==0)
    {
        isWinner=false;
    }
    string winner="N/A";
    if(isWinner)
    {
        for(auto it:validCandidates)
        {
            if(mp[it]==mx)
            {
                winner=it;
                break;
            }
        }
    }
    string ans="";
    for(auto it:validCandidates)
    {
        ans+=it;
        ans+="=";
        ans+=to_string(mp[it]);
        ans+=" ";
    }
    ans+="invalidVotes=";
    ans+=to_string(invalidCount);
    ans+=" ";
    ans+="Winner=";
    ans+=winner;
    return ans;
}

int main()
{
    int n;
    cin >> n;
    // vector<string> res(n);
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> res[i];
    // }
    // int m;
    // cin>>m;
    // vector<string>voted(m);
    // for(int i=0;i<m;i++)
    // {
    //     cin>>voted[i];
    // }
    // string ans=countVotes(res,voted);
    // cout<<ans<<endl;
    vector<int>res(n);
    for(int i=0;i<n;i++)
    {
        cin>>res[i];
    }
    int sum=0;
    for(auto it:res)
    {
        int mx=min(10,it);
        int mn=min(mx,50);
        sum+=mn;
    }
    cout<<sum<<endl;
}