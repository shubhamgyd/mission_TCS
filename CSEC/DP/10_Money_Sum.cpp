#include <bits/stdc++.h>
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;
#define endl '\n'
#define nline cout<<"\n"
#define max_pq priority_queue<int>
#define min_pq priority_queue<int, vector<int>, greater<int>>
#define For(i, x, n) for (i = x; i < n; ++i)
#define pb push_back
#define yes cout<<"YES"
#define no cout<<"NO"
#define int long long
// #define y cout<<"Yes"
#define nn cout<<"No"
#define ll long long

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
 
int gcd(int a,int b) {
    if (b==0) return a;
    return gcd(b,a%b);
}
 
string to_upper(string &a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}
 
string to_lower(string &a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}


const int mod = 1e9 + 7;
const int INF = 1e9;


void moneySum(int i,int sum,int n,int arr[],set<int>&st)
{
    if(i==n)
    {
        if(sum!=0) st.insert(sum);
        return;
    }
    int sum1=sum;
    int sum2=sum;
    sum1+=arr[i];
    if(sum1!=0) st.insert(sum1);
    moneySum(i+1,sum1,n,arr,st);
    moneySum(i+1,sum2,n,arr,st);
    return;
}

void solve()
{
    int n;
    cin>>n;
    int arr[n];
    // set<int>st;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int mx=n*1000;
    vector<vector<bool>>dp(n+1,vector<bool>(mx+1,false));
    dp[0][0]=true;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=mx;j++)
        {
            /**
         * Loop through all coins and all possible sums.
         * 1. If it is possible to make the sum with less than i coins,
         * Then DP[i][sum] will be true.
         * 2. If it is possible to make a sum of (curSum - value[i])
         * DP[curSum] will also be true.
         */
            dp[i][j]=dp[i-1][j];
            int prevSum=j-arr[i-1];
            if(prevSum>=0 and dp[i-1][prevSum])
            {
                dp[i][j]=true;
            }
        }
    }
    vector<int>ans;
    for(int i=1;i<=mx;i++)
    {
        if(dp[n][i])
        {
            ans.push_back(i);
        }
    }
    cout<<ans.size()<<endl;
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    cout<<endl;


}




signed main()
{
#ifndef ONLINE_JUDGE
        freopen("inputf.in", "r", stdin);
        freopen("outputf.out", "w", stdout);
#endif
    fast();
    // int t;
    // cin >> t;
    // while (t--)
    // {
    //     solve();
    // }
    solve();

    return 0;
}