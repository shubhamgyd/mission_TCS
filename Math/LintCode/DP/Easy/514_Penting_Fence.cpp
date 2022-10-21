/*
Description
There is a fence with n posts, each post can be painted with one of the k colors.
You have to paint all the posts such that no more than two adjacent fence posts have the same color.
Return the total number of ways you can paint the fence.

n and k are non-negative integers.

Example
Example 1:

Input: n=3, k=2  
Output: 6
Explanation:
          post 1,   post 2, post 3
    way1    0         0       1 
    way2    0         1       0
    way3    0         1       1
    way4    1         0       0
    way5    1         0       1
    way6    1         1       0
Example 2:

Input: n=2, k=2  
Output: 4
Explanation:
          post 1,   post 2
    way1    0         0       
    way2    0         1            
    way3    1         0          
    way4    1         1   
*/


#include<bits/stdc++.h>
using namespace std;


class Solution {
    vector<long>dp;
public:
    /**
     * @param n: non-negative integer, n posts
     * @param k: non-negative integer, k colors
     * @return: an integer, the total number of ways
     */
    
    int solve(int n,int k)
    {
        if(n<=0) return 0;
        if(n==1) return k;
        if(n==2) return k*k;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=(k-1)*solve(n-1,k)+(k-1)*solve(n-2,k);
    }
    int numWays(int n, int k) {
        // solution 1 and 2: Recursive + Memoization
        dp.resize(5000005,-1);
        return solve(n,k);


        // solution 3: Tabulation
        int table[n+1];
        memset(table,0,sizeof(table));
        table[0]=0;
        table[1]=k;
        table[2]=k*k;
        for(int i=3;i<=n;i++)
        {
            table[i]=(k-1)*table[i-1]+(k-1)*table[i-2];
        }
        return table[n];



        // Soution 4: Space Optimze
        if(n==0) return 0;
        if(n==1) return k;
        if(n==2) return k*k;
        int a=k;
        int b=k*k;
        int c;
        for(int i=3;i<=n;i++)
        {
            c=(k-1)*(a)+(k-1)*b;
            a=b;
            b=c;
        }
        return c;
    }
};

int main()
{

}