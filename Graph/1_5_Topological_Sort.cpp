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
// #define mp make_pair
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

void precompute(unordered_map<int,int>&mp,int num)
{
    for(int n=1;n<=num;n++)
    {
        int temp=n;
        set<int>st;
        for(int i=2;i<=sqrt(temp);i++)
        {
            int count=0;
            while(temp%i==0)
            {
                temp=temp/i;
                count++;
            }
            st.insert(i);
        }
        if(temp!=1)
        {
            st.insert(temp);
        }
        mp[n]=st.size();
    }
}

void dfs(vector<int>adj[],vector<int>&nums,int src,int &sum,unordered_map<int,int>&mp,vector<bool>&visited)
{
    if(visited[src]) return;
    sum+=mp[nums[src-1]];
    for(auto it:adj[src])
    {
        dfs(adj,nums,it,sum,mp,visited);
    }
}

void solve()
{
    int n;
    cin>>n;
    vector<int>nums(n);
    int mx=0;
    unordered_map<int,int>values;
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
        mx=max(mx,nums[i]);
    }
    unordered_map<int,int>mp;
    precompute(mp,mx);

    vector<int>adj[n+1];
    map<int,int>parent;
    int outgoing[n+1];
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        parent[v]=u;
    }
    // vector<bool>visited(n+1,false);
    for(int i=1;i<=n;i++)
    {
        vector<bool>visited(n+1,false);
        int sum=0;
        dfs(adj,nums,i,sum,mp,visited);
        cout<<sum<<" ";
    }
    cout<<endl;


}
 

 
 
 
signed main()
{
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