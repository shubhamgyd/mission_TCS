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
*/

#include<bits/stdc++.h>
using namespace std;


int LCS(string X,string Y,int n,int m)
{
    //Condition if any one of the strings will be zero , then no common sequence 
    // will generate , simply return zero in this case
    // Basically this is base condition
    if(n==0 || m==0) return 0;  

    //If last char of string matched , then simply remove last char of both strings and add 1
    //and If last char of strings don't matched , then that case we have two cases
    //1. Either remove last char of firsst string { decreasing the length by 1} 
    //and take second string as it is 
    //2. Remove last char of second string {decreasing the lenght by 1}
    // and take first string as it is . 
    // Recursive call both conditions .
    if(X[n-1]==Y[m-1])
    {
        return LCS(X,Y,n-1,m-1)+1;
    }
    else
    {
        return max(LCS(X,Y,n,m-1),LCS(X,Y,n-1,m));
    }
}
// Time Complexity:Exponential
// Space Complexity:O(min(n,m))




// Memoization
int dp[1001][1001]; // Global  declaration of matrix , so that it can accessible everywhere

int LCS1(string X,string Y,int m,int n)
{
    if(m==0 || n==0) return 0;  // Base condition 
    
    //If any function call again and again  , then this function check 
    // the value present in given block , if it is -1 then call of function granted ,
    // otherwise return the value present in that block . Means this function already call by some funciton
    // and store its value there.
    if(dp[m][n]!=-1)
    {
        return dp[m][n];
    }

    //If last char of string matched , then simply remove last char of both strings and add 1
    //and If last char of strings don't matched , then that case we have two cases
    //1. Either remove last char of firsst string { decreasing the length by 1} 
    //and take second string as it is 
    //2. Remove last char of second string {decreasing the lenght by 1}
    // and take first string as it is . 
    // Recursive call both conditions . 
    // But main things is before recursive call store this value in respective block
    // so that none of the main function will call again
    if(X[m-1]==Y[n-1])
    {
        return dp[m][n]=LCS1(X,Y,m-1,n-1)+1;
    }
    else
    {
        return dp[m][n]=max(LCS1(X,Y,m,n-1),LCS1(X,Y,m-1,n));
    }
    //return dp[m][n];
}
// Time Complexity:O(n*m)
// Space Complexity:O(n*m)




// Tabulation Method
int LCS2(string X,string Y,int m,int n)
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

/*
Time Complexity: O(m*n)
Space Complecity :(m*n)
*/




// Space Optimization
int LCS_Optimize(string s,string t,int n,int m)
{
    vector<int>prev(m+1,0),curr(m+1,0);
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(j==0) curr[j]=0;
                else
                {
                    if(s[i-1]==t[j-1]) curr[j]=1+prev[j-1];
                    else curr[j]=max(curr[j-1],prev[j]);
                }
            }
            prev=curr;
        }
        return prev[m];
}



int main()
{
    string s,t;
    cin>>s>>t;
    int n=s.length();
    int m=t.length();

    cout<<"Longest Common Subsequence: "<<LCS(s,t,n,m)<<endl;
    memset(dp,-1,sizeof(dp));

    cout<<"Longest Common Subsequence: "<<LCS1(s,t,n,m)<<endl;


    cout<<"Longest Common Subsequence: "<<LCS2(s,t,n,m)<<endl;

    cout<<"Longest Common Subsequence: "<<LCS_Optimize(s,t,n,m)<<endl;

    return 0;


}