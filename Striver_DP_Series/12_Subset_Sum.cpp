#include<bits/stdc++.h>
using namespace std;

bool solve(vector<int>&res,int n,int target)
{
    if(n==0) return res[n]==target;
    bool nontake=solve(res,n-1,target);
    bool take=false;
    if(res[n]<=target) take=solve(res,n-1,target-res[n]);
    return nontake|take;
}
// Time Complexity: Exponential
// Space Complexity:O(1)



vector<bool>dp(1000,0);
bool solve1(vector<int>&res,int n,int target)
{
    if(n==0) return res[n]==target;
    if(dp[n]!=0)
    {
        return dp[n];
    }
    bool nontake=solve1(res,n-1,target);
    bool take=false;
    if(res[n]<=target) take=solve1(res,n-1,target-res[n]);
    return dp[n]=nontake|take;
}
// Time complexity:O(n*n)
// Space Complexity:(n)




// Dp optimize
bool subsetsum(vector<int>&arr,int n, int sum)
{
    //Declaration of array
    int dp[n+1][sum+1];

    //Initialization of array 
    //dp[0][0]=true;
    //first col =true
    //first row = false;
    // Think about it.
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=true;
    }

    for(int i=1;i<=sum;i++)
    {
        dp[0][i]=false;
    }


    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            // If element if less than or equal to given sum , then we have two choices
            // Either taken or not taken
            if(arr[i-1]<=j)
            {
                dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
            // If element is greater than given sum ,  then take the value from the previos 
            // upper array block
            // Discard it , store the previous valid flag
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    // Final ans will get by usinng this block 
    // Either true or false
    return dp[n][sum];
}

int main()
{
    int n;
    cin>>n;
    vector<int>res(n);
    for(int i=0;i<n;i++)
    {
        cin>>res[i];
    }
    int target;
    cin>>target;
    cout<<solve(res,n-1,target)<<endl;
    cout<<solve1(res,n-1,target)<<endl;
    return 0;
}