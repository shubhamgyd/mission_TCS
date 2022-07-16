/*
There are some processes that need to be executed. Amount of a load that process causes on a 
server that runs it, is being represented by a single integer. Total load caused on a server 
is the sum of the loads of all the processes that run on that server. You have at your 
disposal two servers, on which mentioned processes can be run. Your goal is to distribute 
given processes between those two servers in the way that, absolute difference of their 
loads will be minimized.

Given an array of n integers, of which represents loads caused by successive processes, 
return the minimum absolute difference of server loads.

Example 1:

Input: [1, 2, 3, 4, 5]
Output: 1
Explanation:
We can distribute the processes with loads [1, 2, 4] to the first server and [3, 5] to 
the second one,
so that their total loads will be 7 and 8, respectively, and the difference of their loads 
will be equal to 1.
*/

#include<bits/stdc++.h>
using namespace std;

int solve(int j,int i,int currSum,int sum,vector<int>&nums)
{
    if(j==0)
    {
        if(i==0)
        {
            return abs(2*currSum-sum);
        }
        else
        {
            return INT_MAX;
        }
    }
    if(i==0)
    {
        return abs(2*currSum-sum);
    }
    int pick=solve(j-1,i-1,currSum+nums[j],sum,nums);
    int nonPick=solve(j-1,i,currSum,sum,nums);
    return min(pick,nonPick);

}


int main()
{
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    int sum=0;
    for(auto it:nums) sum+=it;
    int currSum=0;
    
    int ans=solve(n-1,n/2,0,sum,nums);
    cout<<ans<<endl;

    int temp=sum;
    sum/=2;
    int dp[n+1][sum+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            dp[i][j]=0;
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(nums[i-1]<=j)
            {
                dp[i][j]=max(dp[i-1][j],nums[i-1]+dp[i-1][j-nums[i-1]]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<temp-2*dp[n][sum]<<endl;
    // T:O(n*s/2)
    // S:O(n*s/2)
    

}