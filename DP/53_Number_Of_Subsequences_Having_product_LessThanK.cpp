// In this program we are going to find the number of subsequences having product less than k

#include<bits/stdc++.h>
using namespace std;


int CountSubSeq(int arr[],int n,int k)
{
    // int dp[n+1][k+1];
    // for(int i=0;i<=n;i++)
    // {
    //     for(int j=0;j<=k;j++)
    //     {
    //         if(i==0 || j==0)
    //         {
    //             dp[i][j]=0;
    //         }
    //     }
    // }

    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=k;j++)
    //     {
    //         // Here we have to check , the number of terms having product less than i by uisng the first j terms of an array
    //         if(arr[i-1]>j)  
    //         {
    //             dp[i][j]=dp[i-1][j];
    //         }
    //         else
    //         {
    //             dp[i][j]=1+dp[i-1][j]+dp[i-1][j/arr[i-1]];
    //         }
    //     }
    // }
    // return dp[n][k];

    // Alternative Approach
    int dp[k+1][n+1];
    memset(dp,0,sizeof(dp));
    
    for(int i=1;i<=k;i++)          // Product Array
    {
        for(int j=1;j<=n;j++)      // number array 
        {
            dp[i][j]=dp[i][j-1];               //  store the previous product value
            if(arr[j-1]<=i)           // Product less than equal to number is
            {
                dp[i][j]+=dp[i/arr[j-1]][j-1]+1;             // Checking the porduct block of i/arr[j-1] 
                                                             // Means here checking previously multiplied block of desired number
            }
        }
    }
    return dp[k][n];
}

int main()
{
    int arr[4]={1,2,3,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=10;
    cout<<"Number of subsequences having product less than k are: "<<CountSubSeq(arr,n,k)<<endl;
    return 0;
}