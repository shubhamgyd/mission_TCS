// In this problem we are going to find the minimum number of operations to convert string a to string b
// Oprtation Like: 
//1.Insertion
//2.Deletion
//3.Replace


// Basically this problem is a avariation of LCS but , here we have to do opposite operation whatever we did in LCS Problem
#include <bits/stdc++.h>
using namespace std;


int NotLCS(string X,int m,string Y,int n)
{
    int dp[m+1][n+1];

    //If length of b= 0 , number of operations required = a.length();
    for(int i=0;i<=m;i++)
    {
        dp[i][0]=i;
    }

    // If length of a=0 , number of operations required=b.length();
    for(int j=0;j<=n;j++)
    {
        dp[0][j]=j;
    }
        
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            // If the char of string a is similar to char of string b , then we don't need to do any kind of modification
            // We have just go with previous modified value  i.e row-1 , col-1 in dp table.
            if(X[i-1]==Y[j-1])
            {
                dp[i][j]=dp[i-1][j-1];
            }

            // If the char of string a is not equal to char of string b , then we have to find the the minimum
            // i.e. min(dp[row-1][col-1],min(dp[row-1][col],dp[row][col-1])) +1 of current row,col 
            // +1 for new operation , means current char doesn't match so any operation will done either insert,delete or replace 
            else
            {
                              // Replace         Delete      Insert
                dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
            }
        }
    }
    return dp[m][n];
}
    
int editDistance(string s, string t) 
{
    int m=s.length();
    int n=t.length();
    return NotLCS(s,m,t,n);
        
}

int main() {
    int Test_Cases;
    cin>>Test_Cases;
    while (Test_Cases--) {
        string s,t;
        cin>>s>>t;
        int ans = editDistance(s, t);
        cout <<ans<<endl;
    }
    return 0;
}