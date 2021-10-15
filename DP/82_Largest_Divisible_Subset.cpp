// In this problem we are going to find the largest possible subset in which all greater element is 
// divisible by smallest number

/*
Intuition behind this problem is: 
    we have to check the number is multiple of next element or not
    is yes then we take the maximum and finally increment the maximum
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[]={5,3,10,15,20};
    int n=sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+n);
    int val=0;
    int dp[n];
    // since last always elemet is always greater
    dp[n-1]=1;

    for(int i=n-2;i>=0;i--)
    {
        // keep track on maximum length of sub-array
        int mx=0;

        // check elements for next to the current element
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]%arr[j]==0 || arr[j]%arr[i]==0)
            {
                mx=max(mx,dp[j]);
            }
        }

        // finally increase the count by one by considering the element itself
        dp[i]=1+mx;
    }

    // find the maximum in dp[]
    for(int i=0;i<n;i++)
    {
        val=max(val,dp[i]);
    }
    cout<<"Largest subarray length is: "<<val<<endl;
    return 0;
}

/*
Time complexity :O(n*n)
Space Complexity :O(n)
*/