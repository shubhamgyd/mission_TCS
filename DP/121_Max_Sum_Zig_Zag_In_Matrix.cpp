#include<bits/stdc++.h>
using namespace std;

class Solution{
    int dp[1001][1001];
    int solve(vector<vector<int>>&res,int i,int j,int n)
    {
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(i==n-1)
        {
            return dp[i][j]=res[i][j];
        }
        
        int temp=0;
        for(int k=0;k<n;k++)
        {
            if(k!=j)
            {
                temp=max(temp,solve(res,i+1,k,n));
            }
        }
        return dp[i][j]=temp+res[i][j];
    }
public:
    int zigzagSequence(int n, vector<vector<int>>&res){
        // code here
       memset(dp,-1,sizeof(dp));
       int ans=0;
       for(int i=0;i<n;i++)
       {
           ans=max(ans,solve(res,0,i,n));
       }    
       return ans;
    }
};