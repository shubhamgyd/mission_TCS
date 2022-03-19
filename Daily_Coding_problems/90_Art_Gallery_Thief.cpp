/*
You’ve broken into an art gallery and want to maximize the value of the paintings you steal. 
All the paintings you steal you place in your bag which can hold at most W pounds. 
Given that the weight and value of the ith painting is given by weights[i] and values[i] 
respectively, return the maximum value you can steal.

Ex: Given the following W, weights array and values array…

W = 10, weights = [4, 1, 3], values = [4, 2, 7], return 13.

Ex: Given the following W, weights array and values array…

W = 5, weights = [2, 4, 3], values = [3, 7, 2], return 7.

Ex: Given the following W, weights array and values array…

W = 7, weights = [1, 3, 4], values = [3, 5, 6], return 11.
*/

#include<bits/stdc++.h>
using namespace std;


int Knapsack(int w,int n,vector<int>&weight,vector<int>&values)
{
    // base case
    if(n==0)
    {
        return 0;
    }
    int include=0;
    int exclude=0;

    // if current weight is less than rquired weight
    // then we have two choices
    // 1. we can include it in result
    // 2. or we can exlude it
    if(weight[n-1]<=w)
    {
        include=max(values[n-1]+Knapsack(w-weight[n-1],n-1,weight,values),Knapsack(w,n-1,weight,values));
    }
    else
    {
        // if current weight is greater than the required weiht
        // then we will exlude it
        exclude=Knapsack(w,n-1,weight,values);
    }
    // return the maximum weight
    return max(include,exclude);
}
// Time Complexity:Exponential
// Space Complexity:O(1)




// memoization
int table[1001][1001];
int knapsack(int w,int n,vector<int>&weight,vector<int>&values)
{
    // base case
    if(n==0)
    {
        return 0;
    }
    if(table[w][n-1]!=-1)
    {
        return table[w][n-1];
    }
    int include=0;
    int exclude=0;

    // if current weight is less than rquired weight
    // then we have two choices
    // 1. we can include it in result
    // 2. or we can exlude it
    if(weight[n-1]<=w)
    {
        include=max(values[n-1]+knapsack(w-weight[n-1],n-1,weight,values),knapsack(w,n-1,weight,values));
    }
    else
    {
        // if current weight is greater than the required weiht
        // then we will exlude it
        exclude=knapsack(w,n-1,weight,values);
    }
    // return the maximum weight
    return table[w][n-1]=max(include,exclude);
}
// Time complexity:O(w*n)
// Space Complexity:O(w*n)



// Dp
int knapSack(int w,int n,vector<int>&weight,vector<int>&values)
{
    int dp[n+1][w+1];
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=0;
    }
    for(int j=1;j<=w;j++)
    {
        dp[0][j]=0;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=w;j++)
        {
            if(weight[i-1]<=j)
            {
                dp[i][j]=max(dp[i-1][j],values[i-1]+dp[i-1][j-weight[i-1]]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][w]; 
}
// Time Complexity:O(n*w)
// Space Complexity:O(n*w)



int main()
{
    memset(table,-1,sizeof(table));
    int w;
    cin>>w;
    int n;
    cin>>n;
    vector<int>weights(n),values(n);
    for(int i=0;i<n;i++)
    {
        cin>>weights[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>values[i];
    }
    int ans=Knapsack(w,n,weights,values);
    cout<<ans<<endl;
    cout<<knapsack(w,n,weights,values)<<endl;
    cout<<knapSack(w,n,weights,values)<<endl;
    return 0;
}