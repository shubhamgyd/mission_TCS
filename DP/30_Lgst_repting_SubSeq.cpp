// Finding the length of longest repeating subsequences from the given two strings

// Basically this problem is the variation of LCS problem , but in this problem
// we have to pay attention on i==j ..means when i==j (char of the same position) is come then discard it
// is same char at different position is come then add it ...Rest code will remains same as of LCS

#include<bits/stdc++.h>
using namespace std;

string LCS(string X,int m)
{
    int dp[m+1][m+1]; // Initialazation of array to store the values
    for(int i=0;i<=m;i++) //Filling first row and column as zero
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0||j==0)
            {
                dp[i][j]=0;
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=m;j++)
        {
            // Here basically we have to pay attention on position on same chars ..if they are on same 
            // position then discard it ...otherwise take it.
            if(X[i-1]==X[j-1] && i!=j)
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    //return dp[m][m];

    // THIS PART OF CODE FINDS THE RESULT STRING USING DP[][]
    // Initialize result
    string res="";

    // Traverse dp[][] from bottom right
    int i=m,j=m;

    while(i>0 && j>0)
    {
        // If this cell is same as diagonally
        // adjacent cell just above it, then
        // same characters are present at
        // str[i-1] and str[j-1]. Append any
        // of them to result.
        if(dp[i][j]==dp[i-1][j-1]+1)
        {
            res=res+X[i-1];
            i--;
            j--;

        }

        // Otherwise we move to the side
        // that that gave us maximum result
        else if(dp[i][j-1]==dp[i-1][j])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    // Since we traverse dp[][] from bottom,
    // we get result in reverse order.
    //reverse(res.begin(),res.end());
    return string(res.rbegin(),res.rend());
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string X="letsleetcode";
    //string Y="ndckjdlfjl23";
    int m=X.length();
    //int n=Y.length();
    string sub=LCS(X,m);
    cout<<"Length of Longest Longest Repeated Sub Sequences: "<<sub<<" and its length is: "<<sub.length()<<"\n";
    return 0;
}