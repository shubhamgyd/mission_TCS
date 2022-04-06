#include<bits/stdc++.h>
using namespace std;

int CoinChangeWays(vector<int>&res,int target,int n)
{
    // base case
    // if sum remains 0 then no need to add anymore coin
    if(target==0)
    {
        return 1;
    }
    if(target<0)
    {
        return 0;
    }
    if(n<=0 and target>=1)
    {
        return 0;
    }

    // we have two conditions
    // either we pick up the coin or we can discard the coin
    return CoinChangeWays(res,target-res[n-1],n-1) + CoinChangeWays(res,target,n-1);
}
// Time Complexity:Exponential
// Space Complexity: O(n) stack space recursion


int main()
{
    int n;
    cin>>n;
    vector<int>res(n);
    for(int i=0;i<n;i++)
    {
        cin>>res[i];
    }
    int target;
    cin>>target;
    int ans=CoinChangeWays(res,target,n-1);
}