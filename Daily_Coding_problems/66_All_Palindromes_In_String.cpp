/*
This question is asked by Google. Given a string s, return all possible 
partitions of s such that each substring is a palindrome.

Ex: Given the following string s…

s = "abcba",
return [
    ["a","b","c","b","a"],
    ["a","bcb","a"],
    ["abcba"]
]
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
    string expand(string str,int low,int high)
    {
    int len=str.length();
    while(low>=0 && high<len && (str[low]==str[high]))
    {
        low--;
        high++;
    }
    return str.substr(low+1,high-low-1);
    }
public:
   vector<string> longestPalindrome(string s) {
       vector<string>ans;
        if(s.length()==1)
        {
            ans.push_back(s);
            return ans;
        }
        string max_str="",curr_str;
        int max_len=0,curr_len;
        for(int i=0;i<s.length()-1;i++)
        {
            curr_str=expand(s,i,i);
            ans.push_back(curr_str);
            curr_str=expand(s,i,i+1);
            ans.push_back(curr_str);
        }
        return ans;
    }
};
void solve(vector<string>&res,string str)
{
    Solution obj;
    res=obj.longestPalindrome(str);
    // return ans;
}

int main()
{
    string str;
    cin>>str;
    vector<string>res;
    solve(res,str);
    for(auto it:res)
    {
        cout<<it<<" ";
    }
    return 0;
}