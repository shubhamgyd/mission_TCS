

#include<bits/stdc++.h>
using namespace std;



class Solution {
    int dp[1001][1001];
    
    int longestSequence(string x,string y,int n,int m)
    {
        if(n<=0 or m<=0)
        {
            return 0;
        }
        if(dp[n][m]!=-1)
        {
            return dp[n][m];
        }
        if(x[n-1]==y[m-1])
        {
            return dp[n][m]=1+longestSequence(x,y,n-1,m-1);
        }
        else return dp[n][m]=max(longestSequence(x,y,n-1,m),longestSequence(x,y,n,m-1));
    }
    
    
    int LCS(string X,string Y , int m,int n)
    {
        int dp[m+1][n+1]; // Initialazation of array to store the values
        for(int i=0;i<=m;i++) //Filling first row and column as zero
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0||j==0)
                {
                    dp[i][j]=0;
                }
            }
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(X[i-1]==Y[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
public:
    int longestCommonSubsequence(string x, string y) {
        
        // Solution 1 and 2: Recursion and memoization
        // memset(dp,-1,sizeof(dp));
        int n=x.length();
        int m=y.length();
        // return longestSequence(x,y,n,m);
        
        
        // Solution 3: Tabulation
        // int m=text1.length();
        // int n=text2.length();
        // return LCS(x,y,n,m);
        
        
        
        // solution 4: Space Optimze
        vector<int>prev(m+1,0),curr(m+1,0);
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(j==0) curr[j]=0;
                else
                {
                    if(x[i-1]==y[j-1]) curr[j]=1+prev[j-1];
                    else curr[j]=max(curr[j-1],prev[j]);
                }
            }
            prev=curr;
        }
        return prev[m];
        
    }
};