/*
Description
On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).

Once you pay the cost, you can either climb one or two steps. You need to find minimum cost to reach the top of the floor, and you can either start from the step with index 0, or the step with index 1.

1.cost will have a length in the range [2, 1000].
2.Every cost[i] will be an integer in the range [0, 999].

Example
Example 1:

Input: cost = [10, 15, 20]
Output: 15
Explanation: Cheapest is start on cost[1], pay that cost and go to the top.
Example 2:

Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
Output: 6
Explanation: Cheapest is start on cost[0], and only

*/





#include<bits/stdc++.h>
using namespace std;


class Solution {
    int solve(vector<int>&res,int n,vector<int>&dp)
    {
        if(n<0) return 0;
        if(n==0 || n==1) return res[n];
        if(dp[n]!=0) return dp[n];
        return dp[n]=res[n]+min(solve(res,n-1,dp),solve(res,n-2,dp));
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
       int n=cost.size();
        vector<int>DP(1005,0);
        return min(solve(cost,n-1,DP),solve(cost,n-2,DP));
        
        
        // solution 3:
        int n=cost.size();
        int dp[n];
        memset(dp,0,sizeof(dp));
        
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<n;i++)
        {
            dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
        }
        return min(dp[n-1],dp[n-2]);
        
        
        // solution : 4
        // space optimize
        int n=cost.size();
        int a=cost[0];
        int b=cost[1];
        int c;
        for(int i=2;i<n;i++)
        {
            c=cost[i]+min(a,b);
            a=b;
            b=c;
        }
        return min(a,b);
    }
};

int main()
{

}