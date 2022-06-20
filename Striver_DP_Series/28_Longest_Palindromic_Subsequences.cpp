/*
Problem Statement
Given two strings, 'S' and 'T' with lengths 'M' and 'N', find the length of the 'Longest Common Subsequence'.
For a string 'str'(per se) of length K, the subsequences are the strings containing characters in the same relative order as they are present in 'str,' but not necessarily contiguous. Subsequences contain all the strings of length varying from 0 to K.
Example :
Subsequences of string "abc" are:  ""(empty string), a, b, c, ab, bc, ac, abc.
Input Format :
The first line of input contains the string 'S' of length 'M'.

The second line of the input contains the string 'T' of length 'N'.
Output Format :
Return the length of the Longest Common Subsequence.
Constraints :
0 <= M <= 10 ^ 3
0 <= N <= 10 ^ 3

Time Limit: 1 sec
Sample Input 1 :
adebc
dcadb
Sample Output 1 :
3
Explanation Of The Sample Output 1 :
Both the strings contain a common subsequence 'adb', which is the longest common subsequence with length 3. 
Sample Input 2 :
ab
defg
Sample Output 2 :
0

*/


// Just is the variation of LCS 
// Think one string is given what for other
// other is just the reverse of original one
// so just find the LCS 


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

    return dp[m][n];
}

int main()
{
    string s;
    cin>>s;
    string t=s;
    reverse(t.begin(),t.end());
    int n=s.length();
    int m=t.length();
    int ans=LCS(s,t,n,m);
    cout<<ans<<endl;
    return 0;
}