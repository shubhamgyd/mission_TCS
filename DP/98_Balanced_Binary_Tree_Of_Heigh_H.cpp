/*
Given a height h, count and return the maximum number of balanced binary trees possible with 
height h. A balanced binary tree is one in which for every node, the difference between heights 
of left and right subtree is not more than 1.
Examples : 
 

Input : h = 3
Output : 15

Input : h = 4
Output : 315



Since the difference between the heights of left and right subtree is not more than one,
possible heights of left and right part can be one of the following: 
 

(h-1), (h-2)
(h-2), (h-1)
(h-1), (h-1)
 

count(h) = count(h-1) * count(h-2) + 
           count(h-2) * count(h-1) + 
           count(h-1) * count(h-1)
        = 2 * count(h-1) * count(h-2) +  
          count(h-1) * count(h-1)
       = count(h-1) * (2*count(h - 2) + 
                          count(h - 1))

*/

#include<bits/stdc++.h>
using namespace std;

int solve(int h)
{

    // base case 
    // one tree is possible with height 0 or 1
    if(h==0 || h==1)
    {
        return 1;
    }

    return solve(h-1)*(2*solve(h-2)+solve(h-1));
}
// Time complexity:Exponential



// Optimise Memoization
// Top Down
int dp[10001];
int Count(int h)
{
    if(h==1|| h==0)
    {
        return 1;
    }
    if(dp[h]!=-1)
    {
        return dp[h];
    }
    return dp[h]=solve(h-1)*(2*solve(h-2)+solve(h-1));
}
// Time Complexity: O(n^2)




// Bottom UP DP : Optimise
int Tree(int h)
{
    int dp[h+1];
    dp[0]=dp[1]=1;
    for(int i=2;i<=h;i++)
    {
        dp[i]=dp[i-1]*(2*(dp[i-2])+dp[i-1]);
    }
    return dp[h];
}
// Time Complexity:O(h)
// Space Complexity :O(h)




int main()
{
    int h;
    cin>>h;
    memset(dp,-1,sizeof(dp));
    // cout<<solve(h)<<endl;
    // cout<<Count(h)<<endl;
    cout<<Tree(h)<<endl;
    return 0;
}