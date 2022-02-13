#include <bits/stdc++.h>
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
// #define int long long
#define mod 1000000007
using namespace std;
#define endl '\n'
#define MOD 1000000007
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define yes cout << "yes" << endl
#define no cout << "no" << endl
#define Bob cout << "Bob" << endl
#define Alice cout << "Alice" << endl
#define sz(x) (int)(x).size()
#define newMOD 1000000006
const int MAX = 10000000;
const int size = 2 * 1e9;

int binpow(int a, int b)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

// Time complexity of below algorithm is O(sqrt(n))
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

int modpow(int x, int n, int m)
{
    if (n == 0)
        return 1 % m;
    // else if(n==1)
    // {
    //     return x%m;
    // }
    else
    {
        int u = modpow(x, n / 2, m);
        u = (u * u) % m; // this is for n is even
        if (n % 2 == 1)  // This is for n is odd
            u = (u * x) % m;
        return u;
    }
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

int mul(int a, int b)
{
    return (1LL * a * b) % MOD;
}

int ModPower(int x, int y, int p)
{
    int ans = 1;
    x = x % p;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
        {
            ans = (ans * x) % MOD;
        }
        y = y >> 1;
        x = (x * x) % p;
    }
    return ans;
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

string to_upper(string a)
{
    for (int i = 0; i < (int)a.size(); ++i)
        if (a[i] >= 'a' && a[i] <= 'z')
            a[i] -= 'a' - 'A';
    return a;
}

string to_lower(string a)
{
    for (int i = 0; i < (int)a.size(); ++i)
        if (a[i] >= 'A' && a[i] <= 'Z')
            a[i] += 'a' - 'A';
    return a;
}

bool cmp(pair<char, pair<int, int>> p, pair<char, pair<int, int>> p1)
{
    if (p.second.second != p1.second.second)
    {
        return p.second.second > p1.second.second;
    }
    else
    {
        return p.second.first < p1.second.first;
    }
}

bool cmp(int a, int b)
{
    return a > b;
}

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.first > b.first;
}
void fun(char *msg, ...);
void fun(char *msg, ...)
{
    va_list ptr;
    int num;
    va_start(ptr, msg);
    num = va_arg(ptr, int);
    num = va_arg(ptr, int);
    printf("%d", num);
}

void elemtnts(deque<int> &dq, int p, int n)
{
    for (int i = p + 1; i < n; ++i)
    {
        dq.push_front(i);
    }
}

void Ele1(deque<int> &dq, int p)
{
    for (int i = 0; i < p; ++i)
    {
        dq.push_back(i);
    }
}

void Display(int num)
{
    cout << num << endl;
}

void Print(int mxm)
{
    for (int i = mxm - 1; i >= 0; i--)
    {
        cout << i << " ";
    }
}

void Print1(int mxm, int n)
{
    for (int i = mxm; i < n; i++)
    {
        cout << i << " ";
    }
}
void Process(int n)
{
    if (n == 2)
    {
        cout << 1 << " " << 0 << endl;
        return;
    }
    int digan = log2(n - 1);
    int mxm = (1ll << digan);
    Print(mxm);
    Print1(mxm, n);
    cout << endl;
    // cout<<endl;
}
void Count(int a, int b, int &ct)
{
    while (a != b)
    {
        if ((a = (a | b)) == b)
        {
            a |= b;
            ct++;
        }
        else if (a < b)
        {
            a++;
            ct++;
        }
        else if (a > b)
        {
            b++;
            ct++;
        }
    }
}

int LongSubStr(string X, string Y, int m, int n)
{
    int dp[m + 1][n + 1];
    // Initialization
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }

    int res = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (X[i - 1] == Y[j - 1])
            {
                // If match then add one to upper left cross block number
                //  and add this sum to the present block.
                dp[i][j] = 1 + dp[i - 1][j - 1];
                res = max(res, dp[i][j]);
            }
            else
            {
                dp[i][j] = 0; // If character doesn't match then fill respective block as zero
            }
        }
    }
    // return dp[m][n];
    return res;
}

bool Winner(int hc, int dc, int hm, int dm, int k, int a, int w, int turn)
{
    if (hc <= 0)
    {
        return false;
    }
    if (hm <= 0)
    {
        return true;
    }
    if (k > 0)
    {
        if (turn == 0)
        {
            return (Winner(hc + w, dc, hm - dc, dm, k - 1, a, w, 1) || Winner(hc, dc + a, hm - dc, dm, k - 1, a, w, 1));
        }
        else if (turn == 1)
        {
            return (Winner(hc - dm, dc, hm, dm, k, a, w, 0));
        }
    }
    if (turn == 0)
    {
        return (Winner(hc, dc, hm - dc, dm, k, a, w, 1));
    }
     return (Winner(hc - dm, dc, hm, dm, k, a, w, 0));
}

void solve()
{
    int hc, dc;
    cin >> hc >> dc;
    int hm, dm;
    cin >> hm >> dm;
    int k, a, w;
    cin >> k >> a >> w;

    bool ans = Winner(hc, dc, hm, dm, k, a, w, 0);
    if (ans)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

int32_t main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("inputf.in", "r", stdin);
    //     freopen("outputf.out", "w", stdout);
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