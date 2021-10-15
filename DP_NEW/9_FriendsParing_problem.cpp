/*
Given n friends, each one can remain single or can be paired up with some other friend.
Each friend can be paired only once. Find out the total number of ways in which friends can 
remain single or can be paired up.
*/

#include<bits/stdc++.h>
using namespace std;
int dp[101];





// Recursive Approach
int FriendsPairing(int n)
{
    // Base Case
    if(n<=2)
    {
        return n;
    }

    return FriendsPairing(n-1)+(n-1)*FriendsPairing(n-2);
}


// Top Down DP
/*
Time Complexity: O(n)
Space Complexity: O(n)
*/
int Top_Down(int n)
{
    if(n<=2)
    {
        return n;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    int ans=Top_Down(n-1)+(n-1)*Top_Down(n-2);
    return dp[n]=ans;
}


// Bottom_UP
/*
Time Complexity: O(n)
Space Somplexity:O(n)
*/
int Bottom_Up(int n)
{
    int dp_t1[n+1];

    dp_t1[0]=0;
    dp_t1[1]=1;
    dp_t1[2]=2;
    for(int i=3;i<=n;i++)
    {
        dp_t1[i]=dp_t1[i-1]+dp_t1[i-2]*(i-1);
    }
    return dp_t1[n];
}



// Space Optimise
/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
int Space_Optimize(int n)
{
    if(n<=2)
    {
        return n;
    }
    int a=1,b=2,c;
    for(int i=3;i<=n;i++)
    {
        c=b+(i-1)*a;
        a=b;
        b=c;
    }
    return c;
}

int main()
{
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    cout<<Space_Optimize(n)<<endl;
}
