/*
This question is asked by Amazon. Given an integer array, two players take turns picking the 
largest number from the ends of the array. First, player one picks a number (either the left 
end or right end of the array) followed by player two. Each time a player picks a particular 
numbers, it is no longer available to the other player. This picking continues until all 
numbers in the array have been chosen. Once all numbers have been picked, the player with 
the larger score wins. Return whether or not player one will win.
Note: You may assume that each player is playing to win (i.e. both players will always choose 
the maximum of the two numbers each turn) and that there will always be a winner.

Ex: Given the following integer array...

nums = [1, 2, 3], return true
Player one takes 3
Player two takes 2
Player one takes 1
3 + 1 > 2 and therefore player one wins
*/


// This problem is similiar to the optimal strategy of a game

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&res,int i,int j)
{
    if(i>j) return 0;
    int left=res[i]+min(solve(res,i+2,j),solve(res,i+1,j-1));
    int right=res[j]+min(solve(res,i,j-2),solve(res,i+1,j-1));
    return max(left,right);
}
// Time Complexity:Exponential(2^n)
// Auxilary Space:O(1) if we don't consider stack space recursion






// memoozation
int dp[10000][10000];
int solve1(vector<int>&res,int i,int j)
{
    if(i>j) return 0;
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int left=res[i]+min(solve1(res,i+2,j),solve1(res,i+1,j-1));
    int right=res[j]+min(solve1(res,i,j-2),solve1(res,i+1,j-1));
    return dp[i][j]=max(left,right);
}

int main()
{
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    vector<int>res(n);
    int sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>res[i];
        sum+=res[i];
    }
    int ans=solve(res,0,n-1);
    int temp=solve1(res,0,n-1);
    cout<<ans<<" "<<temp<<endl;
    int rem=sum-ans;
    if(ans>rem)
    {
        cout<<"One"<<endl;
    }
    else
    {
        cout<<"Two"<<endl;
    }
    // cout<<ans<<endl;
    return 0;
}