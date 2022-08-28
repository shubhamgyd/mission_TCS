#include <bits/stdc++.h>
using namespace std;


string solve(string str,int n)
{
    while(true)
    {
        int cnt=0;
        string ans="";
        int close=0;
        int open=0;
        int start=-1;
        int end=-1;
        for(int i=0;i<str.length();i++)
        {
            if(str[i]=='(')
            {
                open++;
                if(start==-1)
                {
                    start=i;
                }
            }
            if(str[i]==')')
            {
                close++;
                end=i;
            }
            if(close==n and open>=n)
            {
                break;
            }
        }
        if(close!=n)
        {
            return str;
        }
        else
        {
            int next=end+1;
            int target=2*n;
            while(target>0)
            {
                end--;
                target--;
            }
            for(int i=0;i<target;i++)
            {
                ans.push_back(str[i]);
            }
            for(int i=next;i<str.length();i++)
            {
                ans.push_back(str[i]);
            }
            str=ans;
        }
    }
    return str;
}

int main()
{
    // // int n;
    // // cin>>n;
    // // vector<int>nums(n);
    // // for(int i=0;i<n;i++)
    // // {
    // //     cin>>nums[i];
    // // }
    // // int mxElement=0;
    // // int mxFreq=0;
    // // map<int,int>mp;
    // // for(auto it:nums)
    // // {
    // //     mp[it]++;
    // // }
    // // for(auto it:mp)
    // // {
    // //     if(it.second>mxFreq)
    // //     {
    // //         mxFreq=it.second;
    // //         mxElement=it.first;
    // //     }
    // // }
    // // cout<<mxElement<<endl;
    // string str;
    // cin>>str;
    // int n;
    // cin>>n;
    // cout<<solve(str,n)<<endl;
    int x=0;
    int &y=x;
    y=5;
    while(x<=5)
    {
        cout<<y++<<" ";
        x++;
    }
    cout<<x<<" ";
    return 0;
}