/*
A stable tower of height n is a tower consisting of exactly n tiles of unit height 
stacked vertically in such a way, that no bigger tile is placed on a smaller tile. 
An example is shown below : 
 



We have an infinite number of tiles of sizes 1, 2, …, m. The task is to calculate the number of the different stable towers of height n that can be built from these tiles, with a restriction that you can use at most k tiles of each size in the tower.
Note: Two towers of height n are different if and only if there exists a height h (1 <= h <= n), such that the towers have tiles of different sizes at height h.
Examples: 
 

Input : n = 3, m = 3, k = 1.
Output : 1
Possible sequences: { 1, 2, 3}. 
Hence answer is 1.
*/

#include<bits/stdc++.h>
using namespace std;

int solve(int n,int m,int k)
{
    if(n<0 || m<0)
    {
        return 0;
    }
    if(n==0)
    {
        return 1;
    }
    int res=0;
    for(int i=0;i<=k;i++)
    {
        res+=solve(n-i,m-1,k);
    }
    return res;
}
// Time Complexity: (k+1)^(m+1)


int dp[1001][1001];
int Tailing(int n,int m,int k)
{
    if(n<0 || m<0)
    {
        return 0;
    }
    if(n==0)
    {
        return dp[n][m]=1;
    }
    if(dp[n][m]!=-1)
    {
        return dp[n][m];
    }
    int res=0;
    for(int i=0;i<=k;i++)
    {
        res+=Tailing(n-i,m-1,k);
    }
    return dp[n][m]=res;
}
// Time Complexity:O(k*n*m)
// Space Complexity :O(n*m)






int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    memset(dp,-1,sizeof(dp));
    // cout<<solve(n,m,k)<<endl;
    cout<<Tailing(n,m,k)<<endl;
    return 0;
}