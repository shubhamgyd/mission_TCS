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



int CountCoin(vector<int>coin ,int sum,int n)
{
    
    vector<int> dp(sum+1,0);
    dp[0] = 1;
    for (int i = 1; i <= sum; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
           if (i-coin[j] >= 0) 
           {
             (dp[i] += dp[i-coin[j]]) %= mod;
           }
        }
    }
    return dp[sum];
}

void solve()
{
    int n;
    int sum;
    cin>>n;
    vector<int>coin={1,2,3,4,5,6};
    sum=n;
    cout<<CountCoin(coin,sum,6)<<"\n";


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