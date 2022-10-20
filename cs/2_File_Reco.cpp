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

// const int mod = 1e9 + 7;

void testCases()
{
    string str;
    cin >> str;
    map<char, int> mp;
    for (auto it : str)
    {
        mp[it]++;
    }
    priority_queue<int> pq;
    for (auto it : mp)
    {
        pq.push(it.second);
    }
    int len = 0;
    bool isOneTaken = false;
    while (!pq.empty())
    {
        int n = pq.top();
        pq.pop();
        if (n % 2 == 0)
        {
            len += n;
        }
        else
        {
            if (!isOneTaken)
            {
                len += n;
                isOneTaken = true;
            }
            else
            {
                if (n > 1)
                {
                    len += n - 1;
                }
            }
        }
    }
    cout << len << endl;
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
    //     testCases();
    // }
    testCases();
    return 0;
}