/*

Description
Given a list of words, each word consists of English lowercase letters.
Let's say word1 is a predecessor of word2 if and only if we can add exactly one letter anywhere in word1 to make it equal to word2.  For example, "abc" is a predecessor of "abac".
A word chain is a sequence of words [word_1, word_2, ..., word_k] with k >= 1, where word_1 is a predecessor of word_2, word_2 is a predecessor of word_3, and so on.
Return the longest possible length of a word chain with words chosen from the given list of words.

1 <= words.length <= 1000
1 <= words[i].length <= 16
words[i] only consists of English lowercase letters.
Example
Exmple 1

Input: ["ba","a","b","bca","bda","bdca"]
Output: 4
Explanation: one of the longest word chain is "a","ba","bda","bdca".
*/

#include<bits/stdc++.h>
using namespace std;



class Solution {
    vector<vector<int>>graph;
    vector<int>maxChain;

    int getMaxChain(int src)
    {
        if(maxChain[src]>0)
        {
            return maxChain[src];
        }
        maxChain[src]=1;
        for(auto it:graph[src])
        {
            maxChain[src]=max(maxChain[src],1+getMaxChain(it));
        }
        return maxChain[src];
    }
public:
    /**
     * @param words: the list of word.
     * @return: the length of the longest string chain.
     */
    // static bool cmp(string a,string b)
    // {
    //     return (a.length()<b.length());
    // }
    // int LCS(string X,string Y,int m,int n)
    // {
    //     int dp[m+1][n+1]; // Initialazation of array to store the values
    //     for(int i=0;i<=m;i++) //Filling first row and column as zero
    //     {
    //         for(int j=0;j<=n;j++)
    //         {
    //             if(i==0||j==0)
    //             {
    //                 dp[i][j]=0;
    //             }
    //         }
    //     }
        
    //     for(int i=1;i<=m;i++)
    //     {
    //         for(int j=1;j<=n;j++)
    //         {
    //             if(X[i-1]==Y[j-1])
    //             {
    //                 dp[i][j]=1+dp[i-1][j-1];
    //             }
    //             else
    //             {
    //                 dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    //             }
    //         }
    //     }

    //     return dp[m][n];
    // }
    // int solve(vector<string>&words,int i,string str,int n,vector<int>&dp)
    // {
    //     if(i>=n) return 0;
    //     if(dp[i]!=-1) return dp[i];
    //     int include=0;
    //     int exclude=0;
    //     if(LCS(words[i],str,words[i].length(),str.length())==str.length())
    //     {
    //         include=1+solve(words,i+1,words[i],n,dp);
    //     }
    //     exclude=solve(words,i+1,str,n,dp);
    //     return dp[i]=max(include,exclude);
    // }
    int longestStrChain(vector<string> &words) {
        // sort(words.begin(),words.end(),cmp);
        // int ct=0;
        // int n=words.size();
        // vector<int>dp(n,-1);
        // for(int i=n-1;i>=0;i--)
        // {
        //     int ans=solve(words,i,words[i],n,dp);
        //     // dp[i]=ans;
        //     // ans++;
        //     // dp[i]=ans;
        //     ct=max(ct,ans);
        // }
        // return ct;



        
        int n=words.size();
        graph.clear();
        maxChain.clear();
        graph.resize(n);
        maxChain.resize(n);
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[words[i]]=i;
        }
        for(int i=0;i<n;i++)
        {
            string currStr=words[i];
            for(int j=0;j<currStr.length();j++)
            {
                string removeOneChar=currStr.substr(0,j)+currStr.substr(j+1);
                if(!mp.count(removeOneChar))
                {
                    continue;
                }
                graph[i].push_back(mp[removeOneChar]);
            }
        }

        int len=0;
        for(int i=0;i<n;i++)
        {
            len=max(len,getMaxChain(i));
        }
        return len;
    }
};