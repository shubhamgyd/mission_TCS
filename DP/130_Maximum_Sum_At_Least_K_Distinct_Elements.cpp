#include <bits/stdc++.h>
using namespace std;
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int long long

int dp[1001];
int solve(vector<int>res,int i,int n,int k)
{
    if(i>=n)
    {
        return 0;
    }
    if(dp[i]!=-1)
    {
        return dp[i];
    }

    int ans=-1;
    for(int j=i;j<n;j++)
    {
        ans=max(ans,solve(res,j+k+1,n,k)+res[j]);
    }
    return dp[i]=ans;
}

int maxSum(int arr[], int N, int k)
{
    // MS[i] is going to store maximum sum
    // subsequence in subarray from arr[i]
    // to arr[n-1]
    int MS[N];
  
    // We fill MS from right to left.
    MS[N - 1] = arr[N - 1];
    for (int i = N - 2; i >= 0; i--) {
        if (i + k + 1 >= N)
            MS[i] = max(arr[i], MS[i + 1]);
        else
            MS[i] = max(arr[i] + MS[i + k + 1], MS[i + 1]);
    }
  
    return MS[0];
}


int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.out", "w", stdout);
#endif
    fast();
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    vector<int>res;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        res.push_back(a);
    }
    int k;
    cin>>k;
    cout<<solve(res,0,n,k)<<endl;
	return 0;
}