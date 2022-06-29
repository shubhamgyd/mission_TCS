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
#define y cout << "Yes"
#define nn cout << "No"

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

vector<int> v;
vector<vector<int>> result;
void subset(int arr[], int k, int n, int idx)
{
    if (idx == n)
        return;

    if (k == 1)
    {
        for (int i = idx; i < n; i++)
        {
            v.push_back(arr[i]);
            result.push_back(v);
            v.pop_back();
        }
    }

    for (int j = idx; j < n; j++)
    {
        v.push_back(arr[j]);
        subset(arr, k - 1, n, j + 1);
        v.pop_back();
    }
}

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    const int mod11 = 999244353;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int q;
    cin >> q;
    while (q--)
    {
        v.clear();
        result.clear();
        int cnt = 0;
        int k;
        cin >> k;
        subset(arr, k, n, 0);
        for (int i = 0; i < result.size(); i++)
        {
            int x_or = 0;
            for (int j = 0; j < result[i].size(); j++)
            {
                x_or ^= result[i][j];
            }
            if (x_or % 2 == 1)
            {
                cnt=(cnt+1)%mod11;
            }
        }
        cout << cnt << endl;
    }
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