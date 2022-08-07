/*
Given a binary string S, and a number K, find out if it is possible to divide S into K substrings(or subsequences, I am not sure) such that the decimal value of each of the K substrings are equal. 
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin>>str;
    int k;
    cin>>k;
    int sum=0;
    for(auto it:str)
    {
        sum+=(it-'0');
    }
    if(sum%k!=0)
    {
        cout<<"No\n";
        return 0;
    }
    int n=str.length();
    int target=sum/k;
    int curr=0;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(curr<target)
        {
            curr+=(str[i]-'0');
            if(curr>target)
            {
                cout<<"No\n";
                return 0;
            }
            if(curr==target)
            {
                curr=0;
                cnt++;
            }
        }
    }
    cout<<"Yes\n";

}