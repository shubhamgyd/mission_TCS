// It must be contineous .
// Length of longest common substring 
#include<bits/stdc++.h>
using namespace std;

int LongSubStr(string X,string Y,int m,int n)
{
    int dp[m+1][n+1];
    // Initialization
    for(int i=0;i<=m;i++) 
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0||j==0)
            {
                dp[i][j]=0;
            }
        }
    }

    int res=0;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(X[i-1]==Y[j-1])
            {
                //If match then add one to upper left cross block number
                // and add this sum to the present block.
                dp[i][j]=1+dp[i-1][j-1];  
                res=max(res,dp[i][j]);

            }
            else
            {
                dp[i][j]=0;      //If character doesn't match then fill respective block as zero
            }
        }
    }
    //return dp[m][n];
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string X="sea";
    string Y="eat";
    int m=X.length();
    int n=Y.length();
    cout<<"Length of longest common substring via DP: "<<LongSubStr(X,Y,m,n)<<'\n';
    return 0;
}



// Space Optimise Solution
/*
As we see while iterating the dp column we need only required last row so that we predict the 
current cell 

so intuition is: instead of declaring the [n+1]*[n+1] dp array just initialise [2]*[n+1] array 
means we keeping the previous row and updating the current row
*/

int LongestSubstr(string X,string Y,int n,int m)
{
    int dp[2][n];
    int curr=0;
    
    int ans=0;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0)
            {
                dp[curr][j]=0;
            }
            else if(X[i-1]==Y[j-1])
            {
                dp[curr][j]=1+dp[1-curr][j-1];
                ans=max(ans,dp[curr][j]);
            }
            else
            {
                dp[curr][j]=0;
            }
        }
        // Make current row as previous row and previous
        // row as new current row.
        curr = 1 - curr;
    }
    return ans;
}