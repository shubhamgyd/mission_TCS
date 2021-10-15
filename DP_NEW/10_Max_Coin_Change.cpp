// Maximum number of way to make given sum
#include<bits/stdc++.h>
using namespace std;



// Inspired By Aditya Verma
int CountCoin(int coin[] ,int sum,int n)
{
    int dp[n+1][sum+1];
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=1;
    }
    for(int i=1;i<=sum;i++)
    {
        dp[0][i]=0;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(coin[i-1]<=j)
            {
                dp[i][j]=dp[i-1][j]+dp[i][j-coin[i-1]];
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }

    }
    
    return dp[n][sum];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int coin[] = {1,2,3,4,5,6};
    int sum= 3;
    int n=sizeof(coin)/sizeof(coin[0]);
    cout<<"Maximum ways to change coin :"<<CountCoin(coin,sum,n)<<"\n";
    return 0; 
}