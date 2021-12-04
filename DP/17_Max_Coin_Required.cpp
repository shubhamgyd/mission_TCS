// Same as the previous one i,e min coin required to make the given sum ..just little change
#include<bits/stdc++.h>
using namespace std;


int coin1(int coin[],int sum,int n)
{
    int dp[n+1][sum+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(i==0|| j==0)
            {
                if(i==0)
                {
                    dp[i][j]=INT_MIN;
                }
                else if(j==0)
                {
                    dp[i][j]=0;
                }
            }
            else if(coin[i-1]<=j)
            {
                dp[i][j]=max(1+dp[i][j-coin[i-1]],dp[i-1][j]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][sum]<0?0:dp[n][sum];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int coin[] = {1,5,6};
    int sum= 7;
    int n=sizeof(coin)/sizeof(coin[0]);
    cout<<"Maximum number of coins required to make given sum: "<<coin1(coin,sum,n)<<"\n";
    return 0; 
}