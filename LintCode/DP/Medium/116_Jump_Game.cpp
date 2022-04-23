/*
Description
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

The array A contains 𝑛 integers 𝑎1, 𝑎2, …, 𝑎𝑛 (1≤𝑎𝑖≤5000) (1≤n≤5000 )

Example
Example 1:

Input:

A = [2,3,1,1,4]
Output:

true
Explanation:

0 -> 1 -> 4 (the number here is subscript) is a reasonable scheme.

Example 2:

Input:

A = [3,2,1,0,4]
Output:

false
Explanation:

There is no solution that can reach the end.

Challenge
This problem have two method which is Greedy and Dynamic Programming.

The time complexity of Greedy method is O(n)O(n).

The time complexity of Dynamic Programming method is O(n^2)O(n 
2
 ).

We manually set the small data set to allow you pass the test in both ways. This is just to let you learn how to use this problem in dynamic programming ways. If you finish it in dynamic programming ways, you can try greedy method to make it accept again.
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * @param a: A list of integers
     * @return: A boolean
     */
    bool solve(int i,int n,vector<int>&arr,vector<int>&dp)
    {
        // base case
        if(i==n-1)
        {
            return dp[i]=true;
        }
        else if(i>n-1) return false;

        if(dp[i]!=-1)
        {
            return dp[i];
        }

        for(int j=1;j<=arr[i];j++)
        {
            if(solve(i+j,n,arr,dp))
            {
                return dp[i]=true;
            }
        }
        return dp[i]=false;

    }
    bool canJump(vector<int> &a) {
        // write your code here
        // Solution 1+2: Recusive  + Memoization
        // int n=a.size();
        // vector<int>dp(50001,-1);
        // return solve(0,n,a,dp);

        // solution :3
        int n=a.size();
        // int i=0;
        // for(int reach=0;i<n and i<=reach;i++)
        // {
        //     reach=max(i+a[i],reach);
        // }
        // return i==n;


        // Solution 4
        if(a[0]==0 and n>1) return false;
        if(n<=1) return true;
        
        pair<int,int>interval={0,0};
        int jump=0;
        while(1)
        {
            jump++;
            int can_reach=-1;
            for(int i=interval.first;i<=interval.second;i++)
            {
                can_reach=max(can_reach,i+a[i]);
            }
            if(can_reach>=n-1) return true;
            interval={interval.second+1,can_reach};
            if(interval.first>interval.second) return false;
        }
        return false;
    }
};