/*
Given an array of n positive integers. Initially we are at first position.
We can jump to position y (1 <= y <= n) from position x (1 <= x <= n) if x divides y and x < y. 
The task is to print maximum sum path ending at every position x.
Note : Since first element is at position 1, we can jump to any position from here as 1 divides 
all other position numbers.
Examples : 

Input :  arr[] = {2, 3, 1, 4, 6, 5}
Output : 2 5 3 9 8 10

max value is 10
so ans =10
*/


#include<bits/stdc++.h>
using namespace std;

void Max_Path_Sum(int arr[],int n)
{

    int dp[n],i,j;
    for(i=0;i<n;i++)
    {
        dp[i]=0;
    }
    for(i=0;i<n;i++)
    {
        dp[i]=arr[i];
        int ans=0;
        for(j=1;j<=sqrt(i+1);j++)
        {
            if((i+1)%j==0 && (i+1)!=j)
            {
                ans=max(ans,dp[j-1]);
                if(j!=1)
                {
                    ans=max(ans,dp[(i+1)/j-1]);
                }
            }
        }
        dp[i]+=ans;
    }
    cout<<dp[n-1]<<endl;
}

// Time Complexity:O(n*n)
// Space Complexity:O(n)

int main()
{
    int arr[]={ 2, 3, 1, 4, 6, 5 };
    int n=sizeof(arr)/sizeof(arr[0]);
    Max_Path_Sum(arr,n);
    return 0;
}