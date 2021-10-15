// Minimum stpes to reach 1 by the condition of n/2 , n/3 and n-1
#include<bits/stdc++.h>
using namespace std;
int dp[501];

// Bottom Up
int Steps(int n)
{
    dp[1]=0;
    for(int i=2;i<=n;i++)
    {
        int x=INT_MAX,y=INT_MAX;
        if(i%3==0)
        {
            x=dp[i/3];
        }
        if(i%2==0)
        {
            y=dp[i/2];
        }
        int z=dp[i-1];
        dp[i]=min(x,min(y,z))+1;
    }
    return dp[n];
}
/*
Bottom Up DP
Time Complexity:
T(n)=(1+1+1+1)*(n+1);
T(n)=O(n);

Space Complexity: O(n)
*/




//Top Down
int Steps1(int n)
{
    if(n==1)
    {
        return 0;
    }

    if(dp[n]!=0)
    {
        return dp[n];
    }

    int x,y,z;
    x=y=z=INT_MAX;
    if(n%3==0)
    {
        x=Steps1(n/3)+1;
    }
    if(n%2==0)
    {
        y=Steps1(n/2)+1;
    }
    z=Steps1(n-1)+1;
    int ans=min({x,y,z});
    return dp[n]=ans;
}
/*
Time Complexity:
T(n) = O(n)

Space Complexity:
O(n)
*/


int main()
{
    int n;
    cin>>n;
    memset(dp,0,sizeof(dp));
    cout<<Steps1(n)<<endl;
}