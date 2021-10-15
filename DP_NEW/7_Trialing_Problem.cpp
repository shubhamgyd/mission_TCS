/*
Given a floor of size n x m and tiles of size 1 x m. The problem is to count the number of ways to 
tile the given floor using 1 x m tiles. A tile can either be placed horizontally or vertically. 
Both n and m are positive integers and 2 < = m.
*/


#include<bits/stdc++.h>
using namespace std;

//this question have tile size 1xm
class Solution{
	public:
		int countWays(int n, int m)
	{
	    // Code here.
	    int dp[n+1];
	    dp[0]=0;
	    for(int i=1;i<=n;i++)
	    {
	        if(i>m)
	        {
	            dp[i]=(dp[i-1]%1000000007+dp[i-m]%1000000007)%1000000007;
	        }
	        else if(i<m || i==1)
	        {
	            dp[i]=1;
	        }
	        else
	        {
	            dp[i]=2;
	        }
	    }
	    return dp[n]%1000000007;
	}
};