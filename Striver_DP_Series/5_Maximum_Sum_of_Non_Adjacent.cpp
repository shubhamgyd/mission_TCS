/*
Given an array of positive numbers, find the maximum sum of a 
subsequence with the constraint that no 2 numbers in the sequence 
should be adjacent in the array. So 3 2 7 10 should return 13 (sum of 3 and 10) or 3 2 5 10 7 
should return 15 (sum of 3, 5 and 7).Answer the question in most efficient way.

Examples : 

Input : arr[] = {5, 5, 10, 100, 10, 5}
Output : 110

Input : arr[] = {1, 2, 3}
Output : 4

Input : arr[] = {1, 20, 3}
Output : 20
*/


#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&res,int n)
{
    if(n==0)
    {
        return res[n];
    }
    if(n<0)
    {
        return 0;
    }
    int pick=res[n]+solve(res,n-2);
    int nonPick=solve(res,n-1);
    return max(pick,nonPick);
}
// Time Complexity:O(2^n) Exponential
// Space Complexity:O(1)



int dp[10001];
int Memoization(vector<int>&res,int n)
{
    if(n==0)
    {
        return res[n];
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    if(n<0)
    {
        return 0;
    }
    int pick=res[n]+Memoization(res,n-2);
    int nonPick=Memoization(res,n-1);
    return dp[n]=max(pick,nonPick);
}
// Time Complexity:O(n)
// Space ComplexityO(n)


int SpaceOptimize(vector<int>&res,int n)
{
    int prev=res[0];
    int nextPrev=0;
    for(int i=1;i<n;i++)
    {
        int take=res[i];
        if(i>1)
        {
            take+=nextPrev;
        }
        int nonTake=prev;
        int curr=max(take,nonTake);
        nextPrev=prev;
        prev=curr;
    }
    return prev;
}
// Time Complexity:O(n)
// Space Complexity:O(1)

int main()
{
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    vector<int>res(n);
    for(int i=0;i<n;i++)
    {
        cin>>res[i];
    }
    cout<<solve(res,n-1)<<endl;
    cout<<Memoization(res,n-1)<<endl;
    cout<<SpaceOptimize(res,n)<<endl;
    return 0;
}
