#include<bits/stdc++.h>
using namespace std;


int main()
{
    string x,y;
    cin>>x>>y;
    int n=x.length();
    int m=y.length();
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=0;
    }
    for(int j=0;j<=m;j++)
    {
        dp[0][j]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(x[i-1]==y[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    // for(int i=0;i<=n;i++)
    // {
    //     for(int j=0;j<=m;j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    int ind=dp[n][m];
    char lcs[ind+1];
    lcs[ind]='\0';
    int i=n;
    int j=m;
    while(i>0 and j>0)
    {
        if(x[i-1]==y[j-1])
        {
            lcs[ind-1]=x[i-1];
            i--;
            j--;
            ind--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    cout<<lcs<<endl;
    cout<<dp[n][m]<<endl;
    return 0;
}
// Time complexity:O(n*m)
// Space Complexity:O(n*m)