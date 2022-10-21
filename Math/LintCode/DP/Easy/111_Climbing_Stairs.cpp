/*
Description
You are climbing a stair case. It takes n steps to reach to the top. Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example
Example 1:

Input:

n = 3
Output:

3
Explanation:

1, 1, 1
1, 2
2, 1
total 3.

Example 2:

Input:

n = 1
Output:

1
Explanation:

only 1 way.
*/

#include<bits/stdc++.h>
using namespace std;

vector<int>dp(46,-1);
class Solution {
    int solve(int n)
    {
        if(n<0)
        {
            return 0;
        }
        if(dp[n]!=-1) return dp[n];
        if(n==0) return 1;
        
        return dp[n]=solve(n-1)+solve(n-2);
    }
public:
    int climbStairs(int n) 
    {
        // solution 1 and 2 recursiona and memoization
        
        
        // solution 3: DP
        // int dp[46];
        // memset(dp,0,sizeof(dp));
        // dp[0]=1;
        // dp[1]=1;
        // for(int i=2;i<=n;i++)
        // {
        //     dp[i]+=dp[i-1]+dp[i-2];
        // }
        // return dp[n];
        
        // Soltuon : 4 Space Optimize
        
        int a=0;
        int b=1;
        int c;
        if(n==0) return 1;
        if(n==1) return 1;
        for(int i=2;i<=n;i++)
        {
            c=a+b;
            a=b;
            b=c;
        }
        return c;
        

    }
};


int main()
{
    int n;
    cin>>n;

}