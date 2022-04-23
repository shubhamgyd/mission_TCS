/*
This problem was asked by Google.

Given a string which we can delete at most k, return whether you can make a palindrome.

For example, given 'waterrfetawx' and a k of 2, you could delete f and x to get 'waterretaw'.
*/


// This problem is similar to the LCS,
// we need 2nd string so for that , jusr reverse the first string and find the lcs length
// wheather check lcs length is less than equal to k or not

#include<bits/stdc++.h>
using namespace std;


int main()
{
    string str;
    cin>>str;

    int k;
    cin>>k;

    string x=str;
    string y=string(x.rbegin(),x.rend());

    int n=x.length();
    int dp[n+1][n+1];
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=i;
    }
    for(int j=1;j<=n;j++)
    {
        dp[0][j]=j;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
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

    int lcs=dp[n][n];
    int deletion=n-lcs;   // total length- longest lcs length gives the characters need to delete
    if(deletion<=k)
    {
        cout<<"True"<<endl;
    }
    else
    {
        cout<<"False"<<endl;
    }


}