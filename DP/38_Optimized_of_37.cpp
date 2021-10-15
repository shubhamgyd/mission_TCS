// In this code we are goinng to see the optimization of previous code
/*
#include<bits/stdc++.h>
using namespace std;

int dp[501][501];

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

int MCM(string str,int i,int j)
{
    if(i>=j || isPalindrome(str,i,j))
    {
        dp[i][j]=0;
        return 0;
    }

    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }

    int mn=INT_MAX;
    for(int k=i;k<j;k++)
    {
        int right=0;
        if(isPalindrome(str,i,k))
        {
            right=MCM(str,k+1,j);
        }
        else
        {
            dp[i][k]=0;
            continue;
        }
        int count=1+right;
        mn=min(mn,count);
    }
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
*/


// Aother Optimized Approach

#include<bits/stdc++.h>
using namespace std;

int dp[2001][2001];

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

int MCM(string str,int i,int j)
{
    if(i>=j || isPalindrome(str,i,j))
    {
        return 0;
    }
    
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    
    int mn=INT_MAX;
    int left,right;
    for(int k=i;k<j;k++)
    {
        // Basically in this method we are going to see ..is any recursive call executed before or not 
        // is so then store its value in current block/variable 
        // this if..else for left recursive call ...means i to k;
        if(dp[i][k]!=-1)
        {
            left=dp[i][k];
        }
        else
        {
            left=MCM(str,i,k);
            dp[i][k]=left;
        }
        
        // And this for right recursive call
        if(dp[k+1][j]!=-1)
        {
            right=dp[k+1][j];
        }
        else
        {
            right=MCM(str,k+1,j);
            dp[k+1][j]=right;
        }
        // Last we add both sides min number parition 
        int temp=1+right+left;
        // taking the minimum number of partition
        mn=min(temp,mn);
    }
    // Before returning the value ...store it and then return;
    return dp[i][j]=mn;
    
}

int main()
{
    string str="baabb";
    int n=str.length();
    int i=0;
    int j=n-1;
    memset(dp,-1,sizeof(dp));
    cout<<"Minimum number of cuts required to make palindromic is: "<<MCM(str,i,j)<<'\n';
    return 0;
}



/*

another approach

int t[500][500];
int isPallindrome(string s,int i,int j){
    while(i<=j){
        if(s[i]!=s[j])
            return 0;
        i++;
        j--;
    }
    return 1;
}
int PP(string str,int i,int j){
    if(t[i][j]!=-1)
        return t[i][j];
    if(i>=j || isPallindrome(str,i,j)){
        t[i][j]=0;
        return 0;
    }
    int ans = INT_MAX,temp;
    //Loop from i to j-1 because if string is of length n then # of partitons could be n-1 only.
    for(int k=i;k<j;k++){
        //The thing is we don't need to call it for left portion of string
        //i.e PP for i to k because when the recursion backtrack it consider from i to k
        //We don't need to make call for it explicitly.
        //Just check weather left side is making pallindrome or not.
        if(isPallindrome(str,i,k)){
            temp = 1+PP(str,k+1,j);
            ans = min(ans,temp);
        }
    }
    return t[i][j] = ans;
}
int palindromicPartition(string str){
    memset(t,-1,sizeof(t));
    return PP(str,0,str.length()-1);
}

*/