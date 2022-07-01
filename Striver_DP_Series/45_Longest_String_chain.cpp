


#include<bits/stdc++.h>
using namespace std;


class Solution {
    static bool cmp(string a ,string b)
    {
        return (a.length()<b.length());
    }
    int mxLen;
    int DFS(string parent,map<string,vector<string>>&mp,map<string,bool>&visited,int ct,map<string,int>&dp)
    {
        if(dp[parent]==true )
        {
            return dp[parent];
        }
        ct++;
        // // if(dp[parent]) return dp[parent];
        cout<<parent<<"->";
        if(mp[parent].size()==0)
        {
            visited[parent]=true;
            return dp[parent]=max(dp[parent],ct);
        }
        visited[parent]=true;
        for(int i=0;i<mp[parent].size();i++)
        {
            DFS(mp[parent][i],mp,visited,ct,dp);
        }
        return dp[parent]=ct;
    }
    
    vector<vector<int>>graph;
    vector<int>maxChain;
    int getMaxChain(int src)
    {
        if(maxChain[src]>0)
        {
            return maxChain[src];
        }
        maxChain[src]=1;
        for(auto child:graph[src])
        {
            maxChain[src]=max(maxChain[src],1+getMaxChain(child));
        }
        return maxChain[src];
    }
    
    static bool checkPossible(string &s1,string &s2)
    {
        int n=s1.length();
        int m=s2.length();
        if(n!=m+1) return false;
        int first=0;
        int second=0;
        while(first<n)
        {
            if(second<m and s1[first]==s2[second])
            {
                first++;
                second++;
            }
            else
            {
                first++;
            }
        }
        if(first==n and second==m )return true;
        return false;
    }
    static bool comp(string &a,string &b)
    {
        return (a.size()<b.size());
    }
public:
    int longestStrChain(vector<string>& words) {
        // we have to find the longest path from root to leaf
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

        // int n=words.size();
        // unordered_map<string,int>mp;
        // for(int i=0;i<n;i++)
        // {
        //     mp[words[i]]=i;
        // }
        // graph.clear();
        // maxChain.clear();
        // graph.resize(n);
        // maxChain.resize(n);
        // for(int i=0;i<size(words);i++)
        // {
        //     string currStr=words[i];
        //     for(int j=0;j<size(currStr);j++)
        //     {
        //         string removeOnechar=currStr.substr(0,j)+currStr.substr(j+1);
        //         if(!mp.count(removeOnechar))
        //         {
        //             continue;
        //         }
        //         graph[i].push_back(mp[removeOnechar]);
        //     }
        // }
        // int maxChain=0;
        // for(int i=0;i<n;i++)
        // {
        //     maxChain=max(maxChain,getMaxChain(i));
        // }
        // return maxChain;
        



        
        // Solution 2: Using LCS with some variation
        sort(words.begin(),words.end(),comp);
        int n=words.size();
        int mx=1;
        vector<int>dp(n,1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(checkPossible(words[i],words[j]) and dp[i]<dp[j]+1)
                {
                    dp[i]=dp[j]+1;
                }
            }
            mx=max(mx,dp[i]);
        }
        return mx;
        
    }
};