#include <bits/stdc++.h>
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int  long long 
using namespace std;
#define endl '\n'
const int mod=1e9+7;
#define max_pq priority_queue<int>
#define min_pq priority_queue<int,vector<int>,greater<int>>
#define For(i,x,n) for(i=x; i<n; ++i)
#define pb push_back


void solve()
{
    string  lh1,lm1,th1,tm1;
    cin>>lh1>>lm1;
    cin>>th1>>tm1;
    int lh=stoi(lh1);
    int lm=stoi(lm1);
    int th=stoi(th1);
    int tm=stoi(tm1);
    int m=lm+tm;
    int carry=0;
    int rem=m;
    if(m>=60)
    {
        carry=m/60;
        rem=m%60;
    }
    int hour=lh+th+carry;
    hour%=24;
    // hour+=carry;
    string hr="";
    string tmin="";
    if(hour<10)
    {
        hr="0";
        hr+=to_string(hour);
    }
    else
    {
        hr=to_string(hour);
    }

    if(rem<10)
    {
        tmin="0";
        tmin+=to_string(rem);
    }
    else
    {
        tmin=to_string(rem);
    }
    cout<<hr<<" "<<tmin<<endl;
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
    // while (t--)
    // {
    //     solve();
    // }
    solve();
    
    return 0;
}