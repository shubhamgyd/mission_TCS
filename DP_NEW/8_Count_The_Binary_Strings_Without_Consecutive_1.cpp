// In this problem we are going to find the number of binary strings without consecutive 1's
// Intuition behind this problwem is fibonacci series

#include<bits/stdc++.h>
using namespace std;
#define ll                    long long 



ll countStrings(int n)
{
	ll a[n], b[n];
	a[0] = b[0] = 1;
	for (int i = 1; i < n; i++)
	{
		a[i] = (ll)(a[i-1] + b[i-1]);
		b[i] = (ll)a[i-1];
	}
	return (ll)(a[n-1] + b[n-1]);
}

// Top Down
int Top_Down(int n,int pre[])
{
    if(n==0)
    {
        return 0;
    }
    if(n==1)
    {
        return 2;
    }
    if(n==2)
    {
        return 3;
    }
    if(pre[n]!=0)
    {
        return pre[n];
    }

    int ans=Top_Down(n-1,pre)+Top_Down(n-2,pre);
    return pre[n]=ans;
}

// Bottom up DP
int Bottom_UP(int n)
{
    int dp[n+1];
    dp[0]=0;
    dp[1]=2;
    dp[2]=3;
    for(int i=3;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
/*
Time Complexity: O(n);
Space Complexity: O(n)
*/


// Space Optimisez
int Optimize(int n)
{
	    if(n==1)
	    {
	        return 2;
	    }
	    if(n==2)
	    {
	        return 3;
	    }
	    int a=2;
	    int b=3;
	    int c;
	    for(int i=3;i<=n;i++)
	    {
	        c=(a%1000000007+b%1000000007)%1000000007;
	        a=b;
	        b=c;
	    }
	    return c%1000000007;
}
/*
Time Complexity: O(n)
Space Complexity :O(1)
*/

int main()
{
    int n;
    cin>>n;
    int pre[n+1];
    memset(pre,0,sizeof(pre));
    cout<<Top_Down(n,pre)<<endl;
}