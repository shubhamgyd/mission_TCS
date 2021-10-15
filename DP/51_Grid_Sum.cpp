// In this problem we are going to find the maxumum sum if the grid.
// condition is , you can either move right or down

#include<bits/stdc++.h>
using namespace std;


// int MaxSumGrid(int arr[][],int n)
// {
//     int dp[n+1][n+1];
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<n;j++)
//         {
//             if(i==0||j==0)
//             {
//                 dp[i][j]=0;
//             }
//         }
//     }
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=n;j++)
//         {
//             dp[i][j]=max(dp[i][j-1],dp[i-1][j]+arr[i][j]);
//         }
//     }
//     return dp[n][n];
// }

// int main()
// {
//     int n=5;
//     int arr[n][n];
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<n;j++)
//         {
//             cin>>arr[i][j];
//         }
//     }
//     int dp[n+1][n+1];
    
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<n;j++)
//         {
//                 dp[i][j]=INT_MAX;
//         }
//     }
//     dp[0][1]=0;
//     dp[1][0]=0;
//     int res=0;
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=n;j++)
//         {
//             dp[i][j]=max(dp[i][j-1],dp[i-1][j])+arr[i-1][j-1];
//             //extern int res;
//             //res=dp[i][j];
//         }
//     }
//     cout<<"Maximum sum of the grid is: "<<dp[n][n]<<endl;
//     return 0;
// }

int MaxGridSum(vector<vector<int>>&grid)
{
    int n=grid.size();
    int m=grid[0].size();

    vector<vector<int>>sum;
    sum.resize(n+1,vector<int>(m+1));

   // for minimum sum , just initialise the sum vector as INT_MAX
   // and sum[0][1]=0
   //     sum[1][0]=0
   // and replace max with min in the main opertion 
   // i.e sum[i][j]=min(sum[i-1][j],sum[i][j-1])+grid[i-1][j-1];
   //rest of the things are similar

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            sum[i][j]=max(sum[i-1][j],sum[i][j-1])+grid[i-1][j-1];
        }
    }
    return sum[n][m];
}


int main()
{
    vector<vector<int>>grid={{3 ,7 ,9 ,2 ,7},
                            {9, 8 ,3 ,5 ,5},
                            {1 ,7 ,9 ,8 ,5},
                            {3 ,8, 6 ,4 ,10},
                            {6, 3 ,9 ,7 ,8}};
    cout<<"Maximum Sum of the grid according ti the condition: "<<MaxGridSum(grid)<<endl;
    return 0;
}