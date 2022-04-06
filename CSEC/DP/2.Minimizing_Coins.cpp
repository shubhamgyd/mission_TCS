//Min number of coins required to make given sum
#include<bits/stdc++.h>
using namespace std;
 
 
 
int CountCoin(int coin[] ,int sum,int n)
{
    int dp[n+1][sum+1];  // Initialization f array  
 
    for(int i=0;i<=n;i++)  // Filling the every row of first column as 0
    {
        dp[i][0]=0;                    // zero sum chahiye to min 0 ways hi lagenge
    }
    for(int i=1;i<=sum;i++)  // Filling the evry column first row as INT_MAX-1 
    {
        dp[0][i]=INT_MAX-1;     // coin zero hai to infinite number of zero coins chahiye honge tbhi not possible
    }
 
 
 
    for(int j=1;j<=sum;j++)  
    {
        
        if(j%coin[0]==0)
            dp[1][j]=j/coin[0];
        else
            dp[1][j]=INT_MAX-1;
    }
 
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(coin[i-1]<=j)
            {
                // Here we have to choose the minimum number of coins between maximum number of ways
                // to make the given sum
                dp[i][j]=min((dp[i][j-coin[i-1]]+1),dp[i-1][j]); 
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
 
    }
    // If coins array contains only limited coins
    //i.e of array contains 2 as a coins and we want 3 as a sum then that time 
    // we returned -1 as ans.
    if(dp[n][sum]==INT_MAX-1) return -1; 
    // Otherwise rest of things same as previous
    return dp[n][sum];
}
 
 
 
 
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	int n;
	cin>>n;
	int sum;
	cin>>sum;
    int coin[n];
	for(int i=0;i<n;i++)
	{
		cin>>coin[i];
	}
    cout<<CountCoin(coin,sum,n)<<"\n";
    return 0; 
}