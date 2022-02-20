/*
Given a string s, partition s such that every substring of the partition is a palindrome. 
Return all possible palindrome partitioning of s.

A palindrome string is a string that reads the same backward as forward.

 

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]
*/

#include<bits/stdc++.h>
using namespace std;


bool isPalindrome(string str,int start,int end)
{
    while(start<end)
    {
        if(str[start]!=str[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

void solve(int ind,string str,vector<vector<string>>&res,vector<string>&ans)
{
    if(ind==str.length())
    {
        res.push_back(ans);
        return;
    }

    for(int i=ind;i<str.length();i++)
    {
        if(isPalindrome(str,ind,i))
        {
            ans.push_back(str.substr(ind,i-ind+1));
            solve(i+1,str,res,ans);
            ans.pop_back();
        }
    }
}
/*
Time Complexity :- O(n*(2^n)) [n=length of the string]
Space Complexity :- O(n) [beacause of recursion stack]
*/


int main()
{
    string str;
    cin>>str;
    vector<vector<string>>res;
    vector<string>ans;
    solve(0,str,res,ans);
    for(auto it:res)
    {
        for(auto ele:it)
        {
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    return 0;
}