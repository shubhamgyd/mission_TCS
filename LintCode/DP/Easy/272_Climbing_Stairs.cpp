/*
Description
A child is running up a staircase with n steps, and can hop either 1 step, 2 steps, or 3 steps at a time. Implement a method to count how many possible ways the child can run up the stairs.

For n=0, we think the answer is 1.

Example
Example 1:

Input: 3
Output: 4
Explanation: 1 + 1 + 1 = 2 + 1 = 1 + 2 = 3 = 3 , there are 4 ways.
Example 2:

Input: 4
Output: 7
Explanation: 1 + 1 + 1 + 1 = 1 + 1 + 2 = 1 + 2 + 1 =
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * @param n: An integer
     * @return: An Integer
     */
    int dp[5005];
    int solve(int n)
    {
        if(n==0) return 1;
        if(n<0) return 0;
        if(dp[n]!=-1) return dp[n];
        int a=solve(n-1);
        int b=solve(n-2);
        int c=solve(n-3);
        return dp[n]=a+b+c;
    }
    int climbStairs2(int n) {
        // solution 1 and 2: Recursive Memoization
        memset(dp,-1,sizeof(dp));
        return solve(n);

        // Solution 3: Tabulation
        int table[n];
        table[0]=1;
        table[1]=1;
        table[2]=2;
        for(int i=3;i<=n;i++)
        {
            table[i]=table[i-1]+table[i-2]+table[i-3];
        }
        return table[n];

        // Solution 4: Space Optimize
        int a=1;
        int b=1;
        int c=2;
        int d;
        if(n==0) return 1;
        if(n==1) return 1;
        if(n==2) return 2;

        for(int i=3;i<=n;i++)
        {
            d=a+b+c;
            a=b;
            b=c;
            c=d;
        }
        return d;
    }
};

int main()
{
    int n;
    cin>>n;
    Solution obj;
    int ans=obj.climbStairs2(n);
    cout<<ans<<endl;
    return 0;
}