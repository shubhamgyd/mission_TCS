/*
Description
John wants to build a back garden on the empty space behind his home. There are two kinds of bricks now, one is 3 dm high and the other is 7 dm high. John wants to enclose a high x dm wall. If John can do this, output YES, otherwise NO.

X is an integer, and it's range is [3, 1000].

Example
Example 1:

Input : x = 10
Output : "YES"
Explanation :
x = 3 + 7:That is, you need one batch of 3 dm height bricks and one batch of 7 dm height bricks.
Example 2:

Input : x = 5
Output : "NO"
Explanation:
John can not enclose a high 5 dm wall with 3 dm height bricks and 7 dm height bricks.
Example 3:

Input : x = 13
Output : "YES"
Explanation :
x = 2 * 3 + 7:That is, you need two batch of 3 dm he



problem is similar to the coin change problem

*/

#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    /**
     * @param x: the wall's height
     * @return: YES or NO
     */
    int dp[1001][1001];
    int solve(int arr[],int sum,int n)
    {
        // is sum==0 , then no need to add any coin
        if(sum==0)
        {
            return dp[n][sum]=1;
        }

        // is sum is not possible
        if(n==0)
        {
            return 0;
        }


        // if we have already find the ways for this particular coin
        if(dp[n][sum]!=-1)
        {
            return dp[n][sum];
        }
        // We have two choices
        //Either 1. Include the current coin 
        //       2. Exlude the current coint
        if(arr[n-1]<=sum)
        {
            return dp[n][sum]=solve(arr,sum-arr[n-1],n)+solve(arr,sum,n-1);
        }
        return dp[n][sum]=solve(arr,sum,n-1);
    }
    string isBuild(int x) {
        // Solution 1 and 2: Recursion + Memoization
        memset(dp,-1,sizeof(dp));
        int brick[2]={3,7};
        int sum=x;
        int ans=solve(brick,x,2);
        return ans>=1?"YES":"NO";




        // Solution 3: Tabulation
        int n=2;
        int table[n+1][sum+1];
        for(int i=0;i<=n;i++)
        {
            table[i][0]=1;
        }
        for(int j=1;j<=sum;j++)
        {
            table[0][j]=0;
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(brick[i-1]<=j)
                {
                    table[i][j]=table[i-1][j]+table[i][j-brick[i-1]];
                }
                else{
                    table[i][j]=table[i-1][j];
                }
            }
        }

        return table[n][sum]>=1?"YES":"NO";


        // Solution 4: DP Space optimze
        vector<bool>DP(x,false);
        DP[3]=true;
        DP[7]=true;

        for(int i=8;i<=x;i++)
        {
            DP[i]=DP[i-3]||DP[i-7];
        }
        return DP[x]==true?"YES":"NO";


        // Solution 5: Space Optimize
        int res=x%7;
        int ans=res%3;
        int res1=x%3;
        int ans1=res1%7;
        int ans2=x%10;
        if(ans==0||ans1==0||ans2==0) return "YES";
        else return "NO";
    }
};


int main()
{
    int n;
    cin>>n;
    Solution obj;
    string str=obj.isBuild(n);
    cout<<str<<endl;
    return 0;
}