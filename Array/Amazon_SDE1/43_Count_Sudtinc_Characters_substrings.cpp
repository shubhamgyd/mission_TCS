#include<bits/stdc++.h>
using namespace std;


class Solution {
    unsigned long long  TotalWays(char ch, string str)
    { 
        unsigned long long ans=0; unsigned long long int len=str.length();unsigned long long temp=0;
        for(int i=0;i<len;i++){
            if(str[i]==ch) {temp+=(ans)*(ans+1)/2; ans=0;}
            else ans++;
        }
        temp+=(ans)*(ans+1)/2; return len*(len+1)/2 - temp;
    }
public:
    long long appealSum(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        transform(s.begin(),s.end(),s.begin(),::toupper);
        long long int res=0;
        for(char ch='A';ch<='Z';ch++)
        {
            res+=TotalWays(ch,s);
        }
        return res;
    }
};