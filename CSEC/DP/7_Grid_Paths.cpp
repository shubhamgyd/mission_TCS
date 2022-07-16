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
 
 
 
 
 
 
void solve()
{
    int64_t n;
    cin>>n;
    vector<vector<char>>res(n,vector<char>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>res[i][j];
        }
    }
    if(res[0][0]=='*')
    {
        cout<<0<<endl;
        return;
    }
    vector<int64_t>prev(n,0),curr(n,0);
    prev[0]=1;
    for(int i=1;i<n;i++)
    {
        if(res[0][i]=='*') prev[i]=0;
        else prev[i]=prev[i-1];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(j==0)
            {
                if(res[i][j]=='*') curr[j]=0;
                else curr[j]=prev[j];
            }
            else
            {
                if(res[i][j]=='*')
                {
                    curr[j]=0;
                }
                else
                {
                    curr[j]=(curr[j-1]%mod+prev[j]%mod)%mod;
                }
            }
        }
        prev=curr;
    }
    cout<<prev[n-1]%mod<<endl;
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