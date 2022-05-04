/*
Description
Find the consecutive subsequence (containing at least one number) in a sequence of integers with the largest product.

It is guaranteed that the length of nums doesn't exceed 20000
The product of the subsequence with maximum product, less than 2147483647

Example
Example 1:

Input:[2,3,-2,4]
Output:6
Example 2:

Input:[-1,2,4,1]
Output:8

*/


#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An integer
     */
     int mx=INT_MIN;
    int solve(int i,int prod,vector<int>&res,map<int,map<int,long long>>&dp)
    {
        if(i==res.size()-1)
        {
            return max(mx,prod*res[i]);
        }
        if(dp[prod][i]!=0)
        {
            return dp[prod][i];
        }
        int p1=solve(i+1,prod*res[i],res,dp);
        int p2=solve(i+1,1,res,dp);
        return dp[prod][i]=max({mx,p1,p2,prod*res[i]});
    }
    int maxProduct(vector<int> &nums) {
        // we have two choices for particular index
        // either we multiply given number with resultant  product
        // or we can ignore it
        
        // Solution 1 + 2: Recursion + Memoization
        // int prod=1;
        // map<int,map<int,long long>>dp;
        // return solve(0,prod,nums,dp);


        // Solutuion 3: Two pointer approach
        // we will take the mximum product from start to ith index
        // or we can take from n-i-1th index

        int start=0;
        int end=0;
        int mm=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            start=(start?start:1)*nums[i];
            end=(end?end:1)*nums[n-i-1];
            mm=max({mm,start,end});
        }
        return mm;
        
    }
};