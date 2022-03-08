/*
This question is asked by Apple. Given a staircase where the ith step has a non-negative 
cost associated with it given by cost[i], return the minimum cost of climbing to the top of 
the staircase. You may climb one or two steps at a time and you may start climbing from either 
the first or second step.

Ex: Given the following cost array…

cost = [5, 10, 20], return 10.

Ex: Given the following cost array…

cost = [1, 5, 10, 3, 7, 2], return 10.
*/

#include<bits/stdc++.h>
using namespace std;

int minCost(vector<int>&res)
{
    int n=res.size();
    if(n==1)
    {
        return res[0];
    }
    if(n==2)
    {
        return min(res[0],res[1]);
    }
    int dp[n];
    dp[0]=res[0];
    dp[1]=res[1];

    for(int i=2;i<=n;i++)
    {
        dp[i]=res[i]+min(dp[i-1],dp[i-2]);
    }
    return dp[n];
}
// Time Complexity:O(n)
// Space Complexity:O(n)



// Space Optimize

int minCost1(vector<int>&res)
{
    int n=res.size();
    if(n==1)
    {
        return res[0];
    }
    if(n==2)
    {
        return min(res[0],res[1]);
    }

    int prevNext=0;
    int prev=0;
    for(int i=0;i<n;i++)
    {
        int curr=res[i]+min(prevNext,prev);
        prev=prevNext;
        prevNext=curr;
    }
    return min(prev,prevNext);
}
// Time complexity:O(n)
// Space Complexity:O(1)


int main()
{
    int n;
    cin>>n;
    vector<int>res(n);
    for(int i=0;i<n;i++)
    {
        cin>>res[i];
    }
    cout<<minCost(res)<<endl;
    cout<<minCost1(res)<<endl;
    return 0;

}