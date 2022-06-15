#include<iostream>
using namespace std;

int longestCommonSubsequence(int A[],int B[],int n,int m)
{
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=0;
    }

    for(int j=1;j<=m;j++)
    {
        dp[0][j]=0;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(A[i-1]==B[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=min(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}


int main()
{
    int n,m;
    cin>>n>>m;
    int A[n],B[m];
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>B[i];
    }
    int lcs_length=longestCommonSubsequence(A,B,n,m);
    cout<<lcs_length<<endl;
    return 0;
}