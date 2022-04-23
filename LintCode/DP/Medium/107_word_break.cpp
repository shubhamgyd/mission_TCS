/*
Description
Given a string s and a dictionary of words dict, determine if s can be broken into a space-separated sequence of one or more dictionary words.
Because we have used stronger data, the ordinary DFS method can not pass this question now.

s.length <= 1e5
dict.size <= 1e5

Example
Example 1:

Input:

s = "lintcode"
dict = ["lint", "code"]
Output:

true
Explanation:

Lintcode can be divided into lint and code.

Example 2:

Input:

s = "a"
dict = ["a"]
Output:

true
Explanation:

a is in the dict.

*/


#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    /**
     * @param s: A string
     * @param wordSet: A dictionary of words dict
     * @return: A boolean
     */
    bool solve(string s,unordered_set<string>&wordSet)
    {
        int sz=s.length();
        if(sz==0)
        {
            return true;
        }
        for(int i=1;i<=sz;i++)
        {
            if(wordSet.find(s.substr(0,i))!=wordSet.end() && wordBreak(s.substr(i,sz-i),wordSet))
            {
                return true;
            }
        }
        return false;
    }
    bool wordBreak(string s, unordered_set<string> &wordSet) {
        // write your code here
        // Solution 1: Recursion
        // return solve(s,wordSet);


        // Solution 2: Tabulation
        int sz=s.size();
        if(wordSet.size()==0  and sz) return false;
        if(wordSet.size()==0 and sz==0) return true;
        vector<bool>dp(sz+1,false);
        dp[0]=true;  // zero length substring is always present
        for(int i=1;i<=sz;i++)
        {
            // mark if valid word is find into the dictionary
            for(int j=0;j<i;j++)
            {
                if(dp[j] and wordSet.find(s.substr(j,i-j))!=wordSet.end())
                {
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[sz];
    }
};



