#include <bits/stdc++.h>
using namespace std;
int dp[501];

int Fibo(int n)
{
/*(1)*/    if(n==0 || n==1)
			{
				return n;
			}
/*(1)*/		if(dp[n]!=0)
			{
				return dp[n];
			}
/*(n)+(n-1)*/int ans=Fibo(n-1)+Fibo(n-2);
			  return dp[n]=ans;
}

/*
Top Down DP
Time Complexity:
T(n)=1+1+2n-1
T(n)=2n
T(n)=O(n)

Space = O(n)
*/






int Fib(int n)
{
	if(n==0 || n==1)
	{
		return n;
	}
	dp[1]=1;
	for(int i=2;i<=n;i++)
	{
		dp[i]=dp[i-1]+dp[i-2];
	}
	return dp[n];
}

/*
Bottom UP DP
Time Complexity:
T(n)=O(n)

Space = O(n)
*/





//Space optimise
int Fi(int n)
{
	if(n==0 || n==1)
	{
		return n;
	}

	int a=0;
	int b=1;
	int c;
	for(int i=2;i<=n;i++)
	{
		c=a+b;
		a=b;
		b=c;
	}
	return c;
}
/*
Bottom UP DP Space Optimise
Time Complexity:
T(n)=O(n)

Space = O(1)
*/





int main()
{
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    memset(dp,0,sizeof(dp));
    int n;
    cin>>n;
    cout<<"N'th Fibonacci Number is: "<<Fibo(n)<<endl;
    return 0;
}