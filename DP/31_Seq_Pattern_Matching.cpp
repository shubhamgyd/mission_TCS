// Sequence pattern matching

//Variation of LCS

#include<bits/stdc++.h>
using namespace std;

int LCS(string X,string Y,int m,int n)
{
    int dp[m+1][n+1];

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==0|| j==0)
            {
                dp[i][j]=0;
            }
        }
    }

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(X[i-1]==Y[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string X="AXY";
    string Y="ABXCD";
    int m=X.length();
    int n=Y.length();
    if(LCS(X,Y,m,n)==m)
    {
        cout<<"Yes..!! Pattern Matched."<<'\n';
    }
    else
    {
        cout<<"No Pattern not matched"<<'\n';
    }
    return 0;

}