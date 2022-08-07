// Basically the question is split the array into two parts with minium difference


#include<bits/stdc++.h>
using namespace std;




bool subsetsum(int arr[],int n, int sum)
{
    int total=sum;
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
    // Final ans will get by using this block 
    // Either true or false
    int range=total/2;
    vector<int>v;
    int mn=INT_MAX;
    for(int i=0;i<=range;i++)
    {
        if(dp[n][i])
        {
            mn=min(mn,total-2*i);
        }
    }
    //return dp[n][sum];
    cout<<mn<<endl;
    return mn;
}




// In first question,
// let k=(N+1)/2
// if k is even, means sum of numbers is even, minimum difference is 0.
// if k is odd, means sum of numbers is odd, minimum difference is 1.

int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>nums(n);
        for(int i=0;i<n;i++)
        {
            cin>>nums[i];
        }
        int sum=0;
        for(auto it:nums)
        {
            sum+=it;
        }
        int total=sum;
        bool dp[n+1][sum+1];
        for(int i=0;i<=n;i++) dp[i][0]=true;
        for(int j=1;j<=sum;j++) dp[0][j]=false;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(nums[i-1]<=j)
                {
                    dp[i][j]=dp[i-1][j-nums[i-1]] || dp[i-1][j];
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        int mn=INT_MAX;
        int target=total/2;
        for(int i=0;i<=target;i++)
        {
            if(dp[n][i])
            {
                mn=min(mn,total-2*i);
            }
        }
        cout<<mn<<endl;
    }
    return 0;
}