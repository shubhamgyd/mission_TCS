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
#define f first
#define s second
// #define mp make_pair
#define sz(v) (int)(v.size())
#define all(v) (v).begin(), (v).end()
// #define y cout<<"Yes"
// #define nn cout<<"No"
#define ll long long
#define limit1 30

const long long N = 200005, INF = 2000000000000000000;

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

void testCases()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }
    vector<int> ones, zeros;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        if (nums[i])
            ones.push_back(x);
        else
            zeros.push_back(x);
    }
    sort(begin(ones), end(ones));
    sort(begin(zeros), end(zeros));
    int sz1 = zeros.size();
    int sz2 = ones.size();
    if (sz1 == 0 and sz2)
    {
        // cout << "here" << endl;
        int sum = 0;
        for (auto it : ones)
            sum += it;
        cout << sum << endl;
        return;
    }
    if (sz1 and sz2 == 0)
    {
        cout << "here" << endl;
        int sum = 0;
        for (auto it : zeros)
            sum += it;
        cout << sum << endl;
    }
    if (sz1 > sz2)
    {
        int rem = sz1 - sz2;
        int sum = 0;
        int i = 0;
        while (rem--)
        {
            sum += zeros[i];
            i++;
        }
        int j = 0;
        while (i < sz1 and j < sz2)
        {
            sum += 2 * ones[j];
            sum += 2 * zeros[i];
            j++;
            i++;
        }
        cout << sum << endl;
        return;
    }
    if (sz1 < sz2)
    {
        // cout << "here" << endl;
        int rem = sz2 - sz1;
        int i = 0;
        int sum = 0;
        while (rem--)
        {
            sum += ones[i];
            i++;
        }
        // cout << sum << endl;
        int j = 0;
        while (i < sz2 and j < sz1)
        {
            sum += 2 * zeros[j];
            sum += 2 * ones[i];
            j++;
            i++;
        }
        cout << sum << endl;
        return;
    }
    if (zeros[0] < ones[0])
    {
        int sum = 0;
        sum = zeros[0] + 2 * ones[0];
        int i = 1, j = 1;
        while (i < sz1 and j < sz2)
        {
            sum += 2 * zeros[i];
            sum += 2 * ones[j];
            i++;
            j++;
        }
        cout << sum << endl;
        return;
    }
    int sum = 0;
    sum = ones[0] + 2 * zeros[0];
    int i = 1, j = 1;
    while (i < sz1 and j < sz2)
    {
        sum += 2 * zeros[i];
        sum += 2 * ones[j];
        i++;
        j++;
    }
    cout << sum << endl;
    return;
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.out", "w", stdout);
#endif
    fast();
    int t;
    cin >> t;
    while (t--)
    {
        testCases();
    }
    // testCases();
    return 0;
}