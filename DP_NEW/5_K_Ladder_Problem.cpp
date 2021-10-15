/*
In this problem we are going to find the number of ways to reach the top of the ladder
by using 1,2,3....k steps at a time.
*/

#include<bits/stdc++.h>
using namespace std;
int dp[100];


// Top Down DP
int CountWays(int n,int k)
{
    //Base Case
    if(n==0)
    {
        return 1;
    }
    
    // previous  Look up 
    if(dp[n]!=0)
    {
        return dp[n];
    }

    // Iterate all k steps with recursive
    int ways=0;
    for(int i=1;i<=k && i<=n;i++)
    {
        // if step between n and 0 by using the ith step
        if(n-i>=0)
        {
            ways+=CountWays(n-i,k);                // Count all the possible ways to reach to the top 
                                                   // by using ith step
        }
    }
    return dp[n]=ways;
}

/*
Time Complexity: O(n*k)
Space Complexity: O(k)
*/










// Bottom UP DP
int Bottom_Up(int n,int k)
{
    int dp[100]={0};

    // Base case
    dp[0]=1;

    // Iterate to all other possible steps
    for(int i=1;i<=n;i++)
    {
        // Minimum steps
        dp[i]=0;
        
        // For all k steps from the i the step
        for(int j=1;j<=k;j++)
        {
            // If n-i >=0 means no negaive steps
            if(i-j>=0)
            {
                // Add previous steps sum to current step
                // Means previous k steps sum to current step
                dp[i]+=dp[i-j];
            }
        }
    }
    return dp[n];
}
/*
Time Complexity: O(n*k)
Space Complexity: O(k)
*/






// Optimise DP
int Optimise_DP(int n,int k)
{
    int dp[100]={0};

    // Base case 
    dp[0]=dp[1]=1;

    for(int i=2;i<=k;i++)
    {
        dp[i]=2*dp[i-1];
    }

    for(int i=k+1;i<=n;i++)
    {
        dp[i]=2*dp[i-1]-dp[i-k-1];
    }

    return dp[n];
    
}
/*
Time Complexity: O(n)
Space Complexity: O(k)
*/


int main()
{
    memset(dp,0,sizeof(dp));
    int n=60;
    int k=3;
    // cout<<"Number of ways: "<<CountWays(n,k)<<endl;
    cout<<"Number of ways: "<<Optimise_DP(n,k)<<endl;
}