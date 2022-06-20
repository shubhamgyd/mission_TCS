/*
Problem Statement
You have been given two strings 'STR1' and 'STR2'. You have to find the length of the longest common substring.
A string “s1” is a substring of another string “s2” if “s2” contains the same characters as in “s1”, in the same order and in continuous fashion also.
For Example :
If 'STR1' = “abcjklp” and 'STR2' = “acjkp”  then the output will be 3.

Explanation: The longest common substring is “cjk” which is of length 3.
Input Format:
The first line contains an integer ‘T’ which denotes the number of test cases.

The first and only line of each test case contains two space-separated strings 'STR1' and 'STR2', respectively.
Output Format:
For each test case, return the length of the longest common substring among the two strings.

Print the output of each test case in a separate line.
Note:
You don't need to print anything, it has been already taken care of. Just implement the given function.
*/


#include<bits/stdc++.h>
using namespace std;


int solve(int n,int m,string s,string t,int count,vector<vector<int>>&dp)
{
    if(n==0 or m==0)
    {
        return dp[n][m]=count;
    }
    if(dp[n-1][m-1]!=-1) return dp[n][m];
    if(s[n-1]==t[m-1])
    {
        count=solve(n-1,m-1,s,t,count+1,dp);
    }
    count=max({count,solve(n-1,m,s,t,0,dp),solve(n,m-1,s,t,0,dp)});
    return dp[n][m]=count;
}

int lcs(string &str1, string &str2){
	//	Write your code here.
    int n=str1.length();
    int m=str2.length();
//     vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
//     memset(dp,-1,sizeof(dp));
//     return solve(n,m,str1,str2,0,dp);
//     int dp[n+1][m+1];
//     int mx=0;
//     for(int i=0;i<=n;i++)
//     {
//         for(int j=0;j<=m;j++)
//         {
//             if(i==0 or j==0)
//             {
//                 dp[i][j]=0;
//             }
//         }
//     }
  
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=m;j++)
//         {
//             if(str1[i-1]==str2[j-1])
//             {
//                 dp[i][j]=1+dp[i-1][j-1];
//                 mx=max(mx,dp[i][j]);
//             }
//             else
//             {
//                 dp[i][j]=0;
//             }
//         }
//     }
 
//     return mx;
    
    // Space Optimize
     vector<int>prev(max(n,m)+1,0),curr(max(n,m)+1);
    int len=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            
                if(str1[i-1]==str2[j-1])
                {
                    curr[j]=1+prev[j-1];
                    len=max(len,curr[j]);
                }
                else
                {
                    curr[j]=0;
                }
            
        }
        prev=curr;
    }
    return len;
}