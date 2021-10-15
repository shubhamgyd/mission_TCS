// Basically in this code we are goin to stor function value in table , so that 
// in future is any function call on the same value ..that time it can save our time
// means no more recursice tree call after this function

// Same as previous one ..jus some changes
#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];

// Primilinary function to check gievn string is palindrome or not to itself
bool isPalindrome(string str,int i,int j)
{
    while(i < j)
    {
      if(str[i] != str[j])
        return false; 
      i++;
      j--;
    }
    return true;
}

int MCM(string str,int i,int  j)
{
    // basse condition
    if(i>=j|| isPalindrome(str,i,j))
    {
        return 0;
    }

    // check the function value ..is it -1 or not ..means if any function store some value in this block
    // with some value...then no need to further check of recursive subtree ..direct return this value
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }

    int mn=INT_MAX;
    for(int k=i;k<j;k++)
    {
        int temp=MCM(str,i,k)+MCM(str,k+1,j)+1;
        mn=min(mn,temp);
    }

    //here before returning it ....it can store this value in respective block and then return.
    return dp[i][j]=mn;
}

int main()
{
    string str="nitik";
    int n=str.length();
    int i=0;
    int j=n-1;
    memset(dp,-1,sizeof(dp));
    cout<<"Minimum number of cuts required to make palindromic is: "<<MCM(str,i,j)<<'\n';
    return 0;
}