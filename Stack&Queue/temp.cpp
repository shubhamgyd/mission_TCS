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
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz(v) (int)(v.size())
#define all(v) (v).begin(), (v).end()
// #define y cout<<"Yes"
// #define nn cout<<"No"
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
int phi1(int n)
{
    int result = n;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}
tuple<int, int, int> extended_gcd(int a, int b)
{
    if (b == 0)
    {
        return {1, 0, a};
    }
    else
    {
        int x, y, g;
        tie(x, y, g) = extended_gcd(b, a % b);
        return {y, x - (a / b) * y, g};
    }
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
    int n,q;
    cin>>n>>q;
    vector<int>nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    // int matches=0;
    vector<int>pre(n),next(n);
    stack<int> s;
    s.push(nums[0]);
     
    pre[0]=-1;
 
    for (int i = 1; i < n; i++) {
        while (s.empty() == false && s.top() < nums[i]) s.pop();
        if(s.empty())
        {
            pre[i]=-1;
        }
        else
        {
            pre[i]=s.top();
        }
        // s.empty() ? cout << "-1, " : cout << s.top() << ", ";
 
        s.push(nums[i]);
    }
    while(!s.empty()) s.pop();
    map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        mp[nums[i]]=i+1;
    }
    s.push(nums[0]);

    for (int i = 1; i < n; i++) 
    {
  
        if (s.empty()) {
            s.push(nums[i]);
            continue;
        }
        while (s.empty() == false && s.top() < nums[i]) 
        {
            next[mp[s.top()]]=nums[i];
            // cout << s.top() 
            //      << " --> " << arr[i] << endl;
            s.pop();
        }
        s.push(nums[i]);
    }
    while (s.empty() == false) {
        next[mp[s.top()]]=-1;
        // cout << s.top() << " --> " << -1 << endl;
        s.pop();
    }
    // for(int i=0;i<n;i++)
    // {
    //     cout<<pre[i]<<" ";
    // }
    // cout<<endl;
    // for(int i=0;i<n;i++)
    // {
    //     cout<<next[i]<<" ";
    // }
    // cout<<endl;
    deque<int>dq;
    for(auto it:nums)
    {
        dq.push_back(it);
    }

        // deque<int> D(n);
        // map<int, int> val;
        // for (int i = 0; i < n; i++) {
        //     cin >> D[i];
        //     val[D[i]] = i + 1;
        // }
    map<int,pair<int,int>>res;
    for(int i=1;;i++)
    {
        cout<<"h"<<endl;
        auto ele=dq.front();dq.pop_front();
        auto ele1=dq.front();dq.pop_front();
        if(ele==n or ele1==n)
        {
            int num1=i;
            int num2=INT_MAX;
            res[mp[n]]={num1,num2};
            // res[mp[n]].first=num1;
            // res[mp[n]].second=num2;
            break;
        }
        int temp=max(ele,ele1);
        int temp1=min(ele,ele1);
        if(res.find(mp[temp])==res.end())
        {
            res[mp[temp]]={i,i};
        }
        else
        {
            res[mp[temp]].second=i;
        }
        dq.push_back(temp1);
        dq.push_front(temp);
    }
    while(q--)
    {
        int ind,k;
        cin>>ind>>k;
        // cout<<ind<<" "<<k<<endl;
        if(res.find(ind)==res.end())
        {
            cout<<0<<endl;
        }
        else
        {
            auto it=res[ind];
            if(it.first<=k)
            {
                int ele=min(it.second,k);
                ele-=it.first;
                ele+=1;
                cout<<ele<<endl;
            }
            else
            {
                cout<<0<<endl;
            }
        }
    }
    // for (int ii = 0; ii < q; ii++) {
    //         int i, k;
    //         cin >> i >> k;

    //         if (mp.find(i) == mp.end()) {
    //             cout << 0 << '\n';
    //         } else {
    //             auto [l, r] = mp[i];
    //             if (l <= k) {
    //                 cout << min(k, r) - l + 1 << '\n';
    //             } else {
    //                 cout << 0 << '\n';
    //             }
    //         }
    //     }
        // map<int, pair<int, int>> mp;
        // for (int round = 1;; round++) {
        //     int f = D.front();
        //     D.pop_front();
        //     int s = D.front();
        //     D.pop_front();

        //     if (f == n || s == n) {
        //         mp[val[n]] = {round, INT_MAX};
        //         break;
        //     }
        //     if (mp.find(val[max(f, s)]) == mp.end()) {
        //         mp[val[max(f, s)]] = {round, round};
        //     } else {
        //         mp[val[max(f, s)]].second = round;
        //     }

        //     D.push_back(min(f, s));
        //     D.push_front(max(f, s));
        // }

        // for (int ii = 0; ii < q; ii++) {
        //     int i, k;
        //     cin >> i >> k;

        //     if (mp.find(i) == mp.end()) {
        //         cout << 0 << '\n';
        //     } else {
        //         auto [l, r] = mp[i];
        //         if (l <= k) {
        //             cout << min(k, r) - l + 1 << '\n';
        //         } else {
        //             cout << 0 << '\n';
        //         }
        //     }
        // }
}
 

signed main()
{
// #ifndef ONLINE_JUDGE
//         freopen("inputf.in", "r", stdin);
//         freopen("outputf.out", "w", stdout);
// #endif
    fast();
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    // solve();
 
    return 0;
}