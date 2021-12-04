// Pure DP of Longest common subsequence
#include<bits/stdc++.h>
using namespace std;

int LCS(string X,string Y,int m,int n)
{
    int dp[m+1][n+1]; // Initialazation of array to store the values
    for(int i=0;i<=m;i++) //Filling first row and column as zero
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0||j==0)
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

    cout<<"LCS Matrix: "<<endl;
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    return dp[m][n];
}

/*
Time Complexity: O(m*n)
Space Complecity :(m*n)
*/

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string X="cde";
    string Y="abc";
    int m=X.length();
    int n=Y.length();
    cout<<"Length of Longest common subsequence by using DP: "<<LCS(X,Y,m,n)<<"\n";
    return 0;
}