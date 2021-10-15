#include <iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod =1003;



int main() {

	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	   string s;
	   cin>>s;
	  long long  dp[n][n][2]; // 0 for true 1 for false
	  for(int width=0;width<n;width+=2)
	  {
	      for(int left=0,right=width;right<n;left+=2,right+=2)
	      {
	          if(left ==right)
	          {
	              if(s[left]=='T')
	                dp[left][right][0]=1,dp[left][right][1]=0;
	               else
	               dp[left][right][0]=0,dp[left][right][1]=1;

	          }
	          else
	          {

                 dp[left][right][0]=0,dp[left][right][1]=0;
	              for(int k=left+1;k<right;k+=2)
	              {
	                  if(s[k]=='|')
	                  {
	                      dp[left][right][0]=(dp[left][right][0]+(dp[left][k-1][0]*dp[k+1][right][1])%mod+(dp[left][k-1][1]*dp[k+1][right][0])%mod+(dp[left][k-1][0]*dp[k+1][right][0])%mod)%mod;
	                        dp[left][right][1]=(dp[left][right][1]+dp[left][k-1][1]*dp[k+1][right][1])%mod;

	                  }
	                  else if(s[k]=='&')
	                  {
	                       dp[left][right][0]=(dp[left][right][0]+dp[left][k-1][0]*dp[k+1][right][0])%mod;
	                       dp[left][right][1]=(dp[left][right][1]+(dp[left][k-1][0]*dp[k+1][right][1])%mod+(dp[left][k-1][1]*dp[k+1][right][0])%mod+(dp[left][k-1][1]*dp[k+1][right][1])%mod)%mod;

	                  }
	                  else
	                  {
	                      dp[left][right][0]=(dp[left][right][0]+(dp[left][k-1][0]*dp[k+1][right][1])%mod+(dp[left][k-1][1]*dp[k+1][right][0]%mod))%mod;
	                      dp[left][right][1]=(dp[left][right][1]+(dp[left][k-1][0]*dp[k+1][right][0])%mod+(dp[left][k-1][1]*dp[k+1][right][1])%mod)%mod;

	                  }
	              }
	              

	          }
	      }
	  }
	  cout<<dp[0][n-1][0]<<"\n";

	}

	return 0;
}
