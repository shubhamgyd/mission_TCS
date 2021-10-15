/*
Given a string s, rearrange the characters of s so that any two adjacent characters are 
not the same.

Return any possible rearrangement of s or return "" if not possible.

 

Example 1:

Input: s = "aab"
Output: "aba"
Example 2:

Input: s = "aaab"
Output: ""
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        map<int,int>mp;
        int n=s.length();
        for(char c:s)
        {
            mp[c]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto it:mp)
        {
            if(it.second>(n+1)/2) return "";
            pq.push({it.second,it.first});
        }
        pair<int,int>top1,top2;
        string res;
        while(!pq.empty())
        {
            top1=pq.top();pq.pop();
            res+=top1.second;
            if(!pq.empty())
            {
                res+=pq.top().second;
                top2=pq.top();pq.pop();
                if(top2.first>1)
                {
                    pq.push({top2.first-1,top2.second});
                }
                
            }
            if(top1.first>1)
            {
                pq.push({top1.first-1,top1.second});
            }
        }
        return res;
    }
};