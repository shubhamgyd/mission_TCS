/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')

*/


#include<bits/stdc++.h>
using namespace std;



class Solution {
    int NotLCS(string X,int m,string Y,int n)
    {
        int dp[m+1][n+1];

        //If length of b= 0 , number of operations required = a.length();
        for(int i=0;i<=m;i++)
        {
            dp[i][0]=i;
        }

        // If length of a=0 , number of operations required=b.length();
        for(int j=0;j<=n;j++)
        {
            dp[0][j]=j;
        }

        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                // If the char of string a is similar to char of string b , then we don't need to do any kind of modification
                // We have just go with previous modified value  i.e row-1 , col-1 in dp table.
                if(X[i-1]==Y[j-1])
                {
                    dp[i][j]=dp[i-1][j-1];
                }

                // If the char of string a is not equal to char of string b , then we have to find the the minimum
                // i.e. min(dp[row-1][col-1],min(dp[row-1][col],dp[row][col-1])) +1 of current row,col 
                // +1 for new operation , means current char doesn't match so any operation will done either insert,delete or replace 
                else
                {
                    dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                }
            }
        }
        return dp[m][n];
    }
    
    int dp[501][501];
    int Distance(string x,string y,int n,int m)
    {
        if(n==0 )
        {
            return m;
        }
        if(m==0) return n;
        if(dp[n][m]!=-1)
        {
            return dp[n][m];
        }
        if(x[n-1]==y[m-1])
        {
            return dp[n][m]=Distance(x,y,n-1,m-1);
        }
        else
        {
            return dp[n][m]=1+min({Distance(x,y,n-1,m),Distance(x,y,n,m-1),Distance(x,y,n-1,m-1)});
        }
    }
public:
    int minDistance(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        
        // solution 1 and 2: Recursion + Memoization
        // memset(dp,-1,sizeof(dp));
        // return Distance(s1,s2,n,m);
        
        
        // Solution 3: Tabulation
        // return NotLCS(s1,n,s2,m);


        // Solution 4: Space Optimize
        vector<int>pre(m+1,0),curr(m+1,0);
        for(int i=0;i<=m;i++)
        {
            pre[i]=i;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(j==0)
                {
                    curr[j]=i;
                }
                else if(s1[i-1]==s2[j-1])
                {
                    curr[j]=pre[j-1];
                }
                else
                {
                    curr[j]=1+ min({pre[j-1],pre[j],curr[j-1]});
                }
            }
            pre=curr;
        }
        return pre[m];
    }
};