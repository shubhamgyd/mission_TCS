/*
Given a non-empty array nums containing only positive integers, find if the array can be 
partitioned into two subsets such that the sum of elements in both subsets is equal.

 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
*/


// Program to check wheather given arrya have equal sum partition or not
#include<bits/stdc++.h>
using namespace std;

bool subsetsum(int arr[],int n, int sum)
{
    //Declaration of array
    bool dp[n+1][sum+1];

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
            // If element is greater than given sum ,  then take the value from the previos iteration
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    // Final ans will get by usinng this block 
    // Either true or false
    vector<int>s1,s2;
    int i=n;
    int curr=sum;
    while(i>0 && sum>=0)
    {
        // if the current element does not contribute to the sum
        // then is is a part of set 2

        if(dp[i-1][sum])
        {
            i--;
            s2.push_back(arr[i]);
        }

        // if the current element contribute to the sum
        // then is must be the part of the set 1
        else if(dp[i-1][curr-arr[i-1]])
        {
            i--;
            curr-=arr[i];
            s1.push_back(arr[i]);
        }
    }
    cout<<"Set elements: "<<endl;
    for(auto it:s1)
    {
        cout<<it<<" ";
    }
    cout<<endl;
    for(auto it:s2)
    {
        cout<<it<<" ";
    }
    cout<<endl;
    return dp[n][sum];
}

bool findpartition(int arr[],int n,int sum)
{
    //int dp[n+1][sum+1]; // Declaration

    //base condition
    if(sum%2!=0)
    {
        return false;
    }
    // else if(sum%2==0)
    // {
    //     return subsetsum(arr,n/2,sum/2);
    // }
    return subsetsum(arr,n,sum/2);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int arr[]={1,3,3,2,3,2};
    int sum=0;
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    if(findpartition(arr,n,sum)==true)
    {
        cout<<"Yes , given array have equal partition"<<'\n';
    }
    else
    {
        cout<<"No, given array have no equal partition"<<'\n';
    }
    return 0;
}