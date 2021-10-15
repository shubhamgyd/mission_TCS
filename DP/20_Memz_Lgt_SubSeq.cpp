// Memoization of longest common subsequence problem
#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001]; // Global  declaration of matrix , so that it can accessible everywhere

int LCS(string X,string Y,int m,int n)
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
        return dp[m][n]=LCS(X,Y,m-1,n-1)+1;
    }
    else
    {
        return dp[m][n]=max(LCS(X,Y,m,n-1),LCS(X,Y,m-1,n));
    }
    //return dp[m][n];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string X="abc";
    string Y="def";
    int m=X.length();
    int n=Y.length();
    memset(dp,-1,sizeof(dp));   //Initializing all value -1 of declared array
    cout<<"Longest common subsequence by using memoization: "<<LCS(X,Y,m,n)<<"\n";
    return 0;
}
