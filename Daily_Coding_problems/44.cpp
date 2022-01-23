/*
The edit distance between two strings refers to the minimum number 
of character insertions, deletions, and substitutions required to 
change one string to the other. For example, the edit distance between
 “kitten” and “sitting” is three: substitute the “k” for “s”, substitute 
 the “e” for “i”, and append a “g”.

Given two strings, compute the edit distance between them.
*/

// Similiar to the minimum insertion and deletion to make the both stirng similiar

#include<bits/stdc++.h>
using namespace std;


int Distance(string X,string Y)
{
    int n=X.length();
    int m=Y.length();

    int dp[n+1][m+1];
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=i;
    }

    for(int i=0;i<=m;i++)
    {
        dp[0][i]=i;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(X[i-1]==Y[j-1])
            {
                dp[i][j]=dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=1+min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]});
            }
        }
    }
    return dp[n][m];
}


int main()
{
    string str1,str2;
    cin>>str1>>str2;
    cout<<Distance(str1,str2)<<endl;
    return 0;
}