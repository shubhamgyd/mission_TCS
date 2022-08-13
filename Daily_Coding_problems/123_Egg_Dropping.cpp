/*
This problem was asked by Goldman Sachs.

You are given N identical eggs and access to a building with k floors. 
Your task is to find the lowest floor that will cause an egg to break, 
if dropped from that floor. Once an egg breaks, it cannot be dropped again.
 If an egg breaks when dropped from the xth floor, you can assume it will also 
 break when dropped from any floor greater than x.

Write an algorithm that finds the minimum number of trial drops it will take, in the 
worst case, to identify this floor.

For example, if N = 1 and k = 5, we will need to try dropping the egg at every floor, 
beginning with the first, until we reach the fifth floor, so our solution will be 5.
*/

#include<bits/stdc++.h>
using namespace std;

// Recursive 
int solve(int eggs,int flors)
{
    // base case
    // if flors=0 or flors=1 then just return the flors value
    if(flors==0 or flors==1) return flors;

    // if eggs are only 1 and flors are greater than 1
    // then in worst scenario we need to return all the flors
    if(eggs==1) return flors;


    // now we need to find out the minimin number of steps to get the
    // kth flor where egg can break
    // for that iterate from the k=1 to the last floor.
    int mn=INT_MAX;
    for(int i=1;i<=flors;++i)
    {        // egg break before ith flor    // egg can't break till the ith flor
        int cnt=1+max(solve(eggs-1,i-1),solve(eggs,flors-i));
        mn=min(mn,cnt);
    }
    return mn;
}
// Time Complexity:Exponential



int static dp[11][51];

int EggDropping(int egg,int floor)
{
    // Base Case , if egg==0 or floor==1 , means in worst case scenario , we don't need to check anymore
    if(floor==0 || floor==1)
    {
        return floor;
    }
    if(egg==1) // This is worst case , means we haev to check floors from 1st to last i.e at every floor
    {
        return floor;
    }
    if(dp[egg][floor]!=-1)
    {
        return dp[egg][floor];
    }

    // we don't know where k'th floor belong ,so we check it from 1st floor till last
    int mn=INT_MAX; //gives the minimum number of attempts
    for(int k=1;k<=floor;k++)
    {
        int temp=1+max(EggDropping(egg-1,k-1),EggDropping(egg,floor-k)); // Here floor-k means for checking the floor above this value
        // This max for worst case , means maximum number of attempts to check the k'th floor
        // There are different attepmts.
        mn=min(mn,temp);
        // this mn for to find out the minimum form the worse case attepmts .
    }
    return dp[egg][floor]=mn;
}
// Time Complexity:O(eggs*floors)




// DP

int static dp[11][51];
int EggDropping(int egg,int floor)
{
    // Base Case , if egg==0 or floor==1 , means in worst case scenario , we don't need to check anymore
    if(floor==0 || floor==1)
    {
        return floor;
    }
    if(egg==1) // This is worst case , means we haev to check floors from 1st to last i.e at every floor
    {
        return floor;
    }
    if(dp[egg][floor]!=-1)
    {
        return dp[egg][floor];
    }

    // we don't know where k'th floor belong ,so we check it from 1st floor till last
    int mn=INT_MAX; //gives the minimum number of attempts
    for(int k=1;k<=floor;k++)
    {
        int low=INT_MAX;
        if(dp[egg-1][k-1]!=-1) // For previous checking of block
        {
            low=dp[egg-1][k-1];
        }
        else
        {
            low=EggDropping(egg-1,k-1);
            dp[egg-1][k-1]=low;
        }

        int high=INT_MAX;
        if(dp[egg][floor-k]!=-1)
        {
            high=dp[egg][floor-k];
        }
        else
        {
            high=EggDropping(egg,floor-k);
            dp[egg][floor-k]=high;
        }
        int temp=1+max(low,high); // Here floor-k means for checking the floor above this value
        // This max for worst case , means maximum number of attempts to check the k'th floor
        // There are different attepmts.
        mn=min(mn,temp);
        // this mn for to find out the minimum form the worse case attepmts .
    }
    return dp[egg][floor]=mn;
}
// Time Complexity:O(floors*eggs)
// Space Complexity:O(floors*eggs)

int main()
{
    int eggs,k;
    cin>>eggs>>k;
    int ans=solve(eggs,k);
    cout<<ans<<endl;
    return 0;
}