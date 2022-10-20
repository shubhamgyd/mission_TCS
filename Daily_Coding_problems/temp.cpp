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
// #define int long long
#define ff first
#define ss second
#define pb push_back
// #define mp make_pair
#define sz(v) (int)(v.size())
#define all(v) (v).begin(), (v).end()
// #define y cout<<"Yes"
// #define nn cout<<"No"
#define ll long long
#define limit1 30

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

const int N = (int)4e5 + 9;
int x[N], y[N], z[N];
void solve()
{
    string str;
    cin >> str;
    int n = str.length();
    x[0] = y[0] = z[0] = 0;
    for (int i = 0; i < n; ++i)
    {
        x[i + 1] = x[i] + (str[i] == 'x');
        y[i + 1] = y[i] + (str[i] == 'y');
        z[i + 1] = z[i] + (str[i] == 'z');
    }
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--;
        int a = x[r] - x[l];
        int b = y[r] - y[l];
        int c = z[r] - z[l];
        if (r - l <= 2 or max({a, b, c}) - min({a, b, c}) <= 1)
            cout << "YES\n";
        else
            cout << "NO\n";
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
    // while (t--)
    // {
    //     solve();
    // }
    solve();

    return 0;
}