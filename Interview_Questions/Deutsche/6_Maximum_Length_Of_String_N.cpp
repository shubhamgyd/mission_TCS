/*

.The second question was to find the number of ways you can form a string on size N, 
given an unlimited number of 0s and 1s. But you cannot have D number of consecutive 0s 
and T number of consecutive 1s. N, D, T were given as inputs.
https://leetcode.com/discuss/interview-question/804581/Deutsche-bank-or-Interview-Question
*/

#include<bits/stdc++.h>
using namespace std;


int main()
{
    long long int n,d,t;
    cin>>n>>d>>t;
    long long dp[2][500001];
    for(long long i=0;i<=500000;i++)
    {
        dp[0][i]=0;
        dp[1][i]=0;
    }
    dp[0][n]=1;
    dp[1][n]=1;
    const long long int mod = 1e9 + 7;
    for(int i=n-1;i>=0;i--)
    {
        for(long long int j=i;j<min(i+t,n);j++)
        {
            dp[0][i]+=dp[1][j+1]%mod;
            dp[0][i]%=mod;
        }
        for(long long int j=i;j<min(i+d,n);j++)
        {
            dp[1][i]+=dp[0][j+1]%mod;
            dp[1][i]%=mod;
        }
    }
    cout<<dp[0][0]<<dp[1][0]<<endl;

    
}