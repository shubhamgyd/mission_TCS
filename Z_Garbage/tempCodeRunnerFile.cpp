#include<bits/stdc++.h>
using namespace std;


string solve(string str)
{
    stringstream ss(str);
    string word;
    string ans="";
    int lenAns=0;
    while(ss>>word)
    {
        int len=0;
        string temp="";
        for(auto it:word)
        {
            if(!ispunct(it))
            {
                temp.push_back(it);
                len++;
            }
        }
        if(len>lenAns)
        {
            lenAns=len;
            ans=temp;
        }
    }
    return ans;
}


string StringChallenge(int num)
{
    string str=to_string(num);
    string ans="";
    int n=str.length();
    for(int i=1;i<n-1;i+=2)
    {
        // cout<<i<<endl;
        int num0=str[i-1]-'0';
        int num1=str[i]-'0';
        int num2=str[i+1]-'0';
        if(num0%2==0 and num1%2==0 and num0!=0 and num1!=0)
        {
            ans.push_back(str[i-1]);
            ans.push_back('*');
            ans.push_back(str[i]);
        }
        if(num0%2==1 and num1%2==1 and num0!=0 and num1!=0)
        {
            ans.push_back(str[i-1]);
            ans.push_back('-');
            ans.push_back(str[i]);
        }
        if(num1%2==0 and num2%2==0 and num1!=0 and num2!=0)
        {
            ans.push_back(str[i]);
            ans.push_back('*');
        }
        if(num1%2==1 and num2%2==1 and num1!=0 and num2!=0)
        {
            if(num0!=0 and num0%2==1) ans.push_back('-');
            ans.push_back(str[i]);
            ans.push_back('-');
        }
        else
        {
            ans.push_back(str[i-1]);
            ans.push_back(str[i]);
        }
    }
    return ans;
}

int main()
{
    int str;
    cin>>str;
    // getline(cin,str);
    // string ans=solve(str);
    // cout<<ans<<endl;

    cout<<StringChallenge(str)<<endl;
    return 0;
}