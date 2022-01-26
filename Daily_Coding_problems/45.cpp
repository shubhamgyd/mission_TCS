/*
This question is asked by Amazon. Given two strings s and t, which represents 
a sequence of keystrokes, where # denotes a backspace, return whether or 
not the sequences produce the same result.

Ex: Given the following strings...

s = "ABC#", t = "CD##AB", return true
s = "como#pur#ter", t = "computer", return true
s = "cof#dim#ng", t = "code", return false
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str1,str2;
    cin>>str1>>str2;
    string s1="",s2="";
    int i=str1.length()-1;
    while(i>=0)
    {
        if(isalpha(str1[i]))
        {
            s1.push_back(str1[i]);
            i--;
        }
        else
        {
            int j=i;
            int ct=0;
            while(j>=0 && str1[j]=='#')
            {
                j--;
                ct--;
            }
            i=j;
            i+=ct;

        }
    }
    i=str2.length()-1;
    while(i>=0)
    {
        if(isalpha(str2[i]))
        {
            s2.push_back(str2[i]);
            i--;
        }
        else
        {
            int j=i;
            int ct=0;
            while(j>=0 && str2[j]=='#')
            {
                j--;
                ct--;
            }
            i=j;
            i+=ct;
        }
    }
    if(!s1.empty()) reverse(s1.begin(),s1.end());
    else s1=str1;
    if(!s2.empty()) reverse(s2.begin(),s2.end());
    else s2=str2;
    cout<<s1<<endl;
    cout<<s2<<endl;
    if(s1==s2)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
    return 0;   
}
// Time Complexity:O(n)
// Space Complexity:O(n)
