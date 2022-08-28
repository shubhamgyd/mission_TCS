/*
Given two strings s and t. Count the number of occurence of t in s as follows. Length of t is 3, increment count when t == s[i]s[i+2]s[i+4]
e.g s = aabbcc , t = abc . output = 2.
*/

#include<bits/stdc++.h>
using namespace std;


int solve(string a,string b)
{
    int m = a.length();
int n = b.length();

// Create a table to store
// results of sub-problems
int lookup[m+1][n+1];

// If first string is empty
for (int i = 0; i <= n; ++i)
    lookup[0][i] = 0;

// If second string is empty
for (int i = 0; i <= m; ++i)
    lookup[i][0] = 1;

// Fill lookup[][] in
// bottom up manner
for (int i = 1; i <= m; i++)
{
    for (int j = 1; j <= n; j++)
    {
        // If last characters are
        // same, we have two options -
        // 1. consider last characters
        //    of both strings in solution
        // 2. ignore last character
        //    of first string
        if (a[i - 1] == b[j - 1])
            lookup[i][j] = lookup[i - 1][j - 1] +
                           lookup[i - 1][j];
             
        else
            // If last character are
            // different, ignore last
            // character of first string
            lookup[i][j] = lookup[i - 1][j];
    }
}

return lookup[m][n];
}

void findMinAndMax(int arr[],int n)
{
    int mn=INT_MAX;
    int mx=INT_MIN;
    for(int i=0;i<n;i++)
    {
        mn=min(mn,arr[i]);
        mx=max(mx,arr[i]);
    }
    cout<<"Maximum Element : "<<mx<<endl;
    cout<<"Minimum Element : "<<mn<<endl;
}

void isPalindrome(int num)
{
    string str=to_string(num);
    int len=str.length();
    int i=0;
    int j=len-1;
    bool isPal=true;
    while(i<j)
    {
        if(str[i]!=str[j])
        {
            isPal=false;
            break;
        }
        i++;
        j--;
    }
    if(isPal)
    {
        cout<<"This number is palindrome!"<<endl;
    }
    else
    {
        cout<<"Not a palindrome!"<<endl;
    }
}

int main()
{
    int a=10;
    int b=25;
    int c=15;
    int res=0;
    while(b>0)
    {
        res+=(a%c)+(c%a);
        b-=a%c;
        swap(a,c);
    }
    cout<<res<<endl;
    string s,t;
    cin>>s>>t;
    unordered_map<char,int>mp1,mp2;
    for(int i=0;i<s.length();i++)
    {
        mp1[s[i]]++;
    }
    for(int i=0;i<t.length();i++)
    {
        mp2[t[i]]++;
    }
    int ct1=INT_MAX;
    for(int i=0;i<t.length();i++)
    {
        if(mp1.find(t[i])!=mp1.end())
        {
            // cout<<mp1[t[i]]<<" "<<mp2[t[i]]<<endl;
            ct1=min(ct1,mp1[t[i]]);
        }
        else
        {
            cout<<0<<endl;
            return 0;
        }
    }
    cout<<ct1<<endl;
    cout<<solve(s,t)<<endl;
    return 0;
}