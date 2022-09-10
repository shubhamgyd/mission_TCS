#include <bits/stdc++.h>
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;
#define endl '\n'
#define nline cout << "\n"
#define max_pq priority_queue<int>
#define min_pq priority_queue<int, vector<int>, greater<int>>
#define For(i, x, n) for (i = x; i < n; ++i)
#define pb push_back
#define yes cout << "YES"
#define no cout << "NO"
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

int binpow(int a, int b)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
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

string to_upper(string &a)
{
    for (int i = 0; i < (int)a.size(); ++i)
        if (a[i] >= 'a' && a[i] <= 'z')
            a[i] -= 'a' - 'A';
    return a;
}

string to_lower(string &a)
{
    for (int i = 0; i < (int)a.size(); ++i)
        if (a[i] >= 'A' && a[i] <= 'Z')
            a[i] += 'a' - 'A';
    return a;
}

const int mod = 1e9 + 7;
const int INF = 1e9;

int cnt = 0;
void dfs(int src, vector<int> adj[], int visited[])
{
    visited[src] = cnt;
    if (adj[src].size() > 0)
    {
        for (auto it : adj[src])
        {
            if (visited[it] == 0)
                dfs(it, adj, visited);
        }
    }
    return;
}

void solve()
{
    int n,m;
    cin>>n>>m;
    string s,t;
    cin>>s;
    cin>>t;
    bool ok=false;
    int i=0;
    int j=0;
    while(i<n and j<m)
    {
        if(isalpha(s[i]) and isalpha(t[j]))
        {
            if(s[i]!=t[j])
            {
                cout<<"NO\n";
                return;
            }
            i++;
            j++;
        }
        else
        {
            int sum=0;
            int cnt=0;
            while(j<m and isdigit(t[j]))
            {
                sum+=(t[j]-'0');
                j++;
                cnt++;
            }
			
            sum+=(i);
            if(sum>=n and j<m)
            {
                i+=cnt+1;
            }
			else if(sum>=n and j>=m)
			{
				cout<<"YES\n";
				return;
			}
            else
            {
                i=sum;
            }
        }
    }
    if(i>=n and j>=m)
    {
        cout<<"YES\n";
    }
    else
    {
        cout<<"NO\n";
    }
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