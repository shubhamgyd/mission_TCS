#include <bits/stdc++.h>
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int  long long 
using namespace std;
#define endl '\n'
#define max_pq priority_queue<int>
#define min_pq priority_queue<int,vector<int>,greater<int>>
#define For(i,x,n) for(i=x; i<n; ++i)
#define pb push_back
const int mod=1e9+7;

 
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



void solve()
{
    vector<int>res={1,10,11,100,101,110,111,1000,1001,1010,1011,1100,1101,1110,1111,10000,10001,10010,10011,10100,10101,10110,10111,11000,11001,11010,11011,11100,11101,11110,11111,1000000};
    int n;
    cin>>n;

    int ct=0;
    vector<int>ans;
    while(n)
    {
        auto ele=lower_bound(res.begin(),res.end(),n);
        if(ele!=res.end())
        {
            // cout<<"n: "<<n<<endl;
            ct++;
            auto it=lower_bound(res.begin(),res.end(),n)-res.begin();
            // cout<<"it: "<<it<<endl;
            if(res[it]==n)
            {
                ans.push_back(res[it]);
                n=0;
            }
            else
            {
                ans.push_back(res[it-1]);
                n-=res[it-1];
            }
        }
        else
        {
            break;
        }
    }
    while(n--)
    {
        ct++;
        ans.push_back(1);
    }
    cout<<ct<<endl;
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
}



signed main()
{
// #ifndef ONLINE_JUDGE
//         freopen("inputf.in", "r", stdin);
//         freopen("outputf.out", "w", stdout);
// #endif
    fast();
    // int t;
    // cin >> t;
    // while(t--)
    // {
    //     solve();
    // }
    solve();
    
    return 0;
}