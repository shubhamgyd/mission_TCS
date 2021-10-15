#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin>>str;
    int ct=0;
    int n=str.length();
    for(int i=0;i<n-2;i++)
    {
        if(str[i]==str[i+1] &&str[i+1]!=str[i+2])
        {
            str[i+2]=str[i];
            ct++;
        }
    }
    cout<<ct<<endl;
    return 0;
}