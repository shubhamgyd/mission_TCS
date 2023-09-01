#include <bits/stdc++.h>
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;
#define int long long
#define endl '\n'
#define nline cout << "\n"
#define max_pq priority_queue<int>
#define min_pq priority_queue<int, vector<int>, greater<int>>
#define For(i, x, n) for (i = x; i < n; ++i)
#define pb push_back
#define ff first
#define ss second
#define pb push_back
#define f first
#define s second
#define sz(v) (int)(v.size())
#define all(v) (v).begin(), (v).end()
#define ll long long
#define limit1 30

const int mod = 1e9 + 7;

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

int floorSearch(vector<int> &arr, int low, int high, int x)
{
    if (low > high)
    {
        return -1;
    }
    if (x >= arr[high])
    {
        return high;
    }
    int mid = (low + high) / 2;
    if (arr[mid] == x)
    {
        return mid;
    }
    if (mid > 0 && arr[mid - 1] <= x && x < arr[mid])
    {
        return mid - 1;
    }
    if (x < arr[mid])
        return floorSearch(arr, low, mid - 1, x);
    return floorSearch(arr, mid + 1, high, x);
}

int ceilSearch(vector<int> &arr, int low, int high, int x)
{
    int mid;
    if (x <= arr[low])
        return low;
    if (x > arr[high])
        return -1;
    mid = (low + high) / 2;
    if (arr[mid] == x)
        return mid;
    else if (arr[mid] < x)
    {
        if (mid + 1 <= high && x <= arr[mid + 1])
            return mid + 1;
        else
            return ceilSearch(arr, mid + 1, high, x);
    }
    else
    {
        if (mid - 1 >= low && x > arr[mid - 1])
            return mid;
        else
            return ceilSearch(arr, low, mid - 1, x);
    }
}

void dfs(int i, vector<int> adj[], vector<bool> &visited, map<int, int> &mp, bool &ok, int parent = 0)
{
    for (auto it : adj[i])
    {
        if (it != parent)
        {
            if (!visited[it])
            {
                mp[it] = !mp[i];
                visited[it] = true;
                dfs(it, adj, visited, mp, ok, i);
            }
            else
            {
                if (mp[it] == mp[i])
                {
                    ok = false;
                }
            }
        }
    }
}

void testCases()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            cnt += 1;
        }
        else
        {
            cnt -= 1;
        }
    }
    if (cnt != 0)
    {
        cout << -1 << endl;
        return;
    }

    int cng = 0;
    int zr_CNT = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            zr_CNT += 1;
        }
        else
        {
            zr_CNT -= 1;
        }

        if (zr_CNT < 0)
        {
            cng += 1;
            break;
        }
    }

    zr_CNT = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == ')')
        {
            zr_CNT += 1;
        }
        else
        {
            zr_CNT -= 1;
        }

        if (zr_CNT < 0)
        {
            cng += 1;
            break;
        }
    }

    if (cng < 2)
    {
        cout << 1 << endl;
        for (int i = 0; i < n; i++)
        {
            cout << 1 << endl;
        }
        cout << endl;
    }
    else
    {
        vector<int> diff(n);
        int left = 0;
        int right = n - 1;

        while (left < right)
        {
            if (s[left] == ')' && s[right] == ')')
            {
                diff[left] = 2;
                diff[right] = 1;
                left += 1;
                right -= 1;
            }
            else if (s[left] == '(' && s[right] == '(')
            {
                diff[left] = 1;
                diff[right] = 2;
                left += 1;
                right -= 1;
            }
            else if (s[left] == ')' && s[right] == '(')
            {
                diff[right] = 2;
                diff[left] = 2;
                left += 1;
                right -= 1;
            }
            else
            {
                diff[left] = 1;
                diff[right] = 1;
                left += 1;
                right -= 1;
            }
        }

        cout << 2 << endl;
        for (int i = 0; i < n; i++)
        {
            cout << diff[i] << endl;
        }
        cout << endl;
    }
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

// CERTAIN STUFF to REMEMBER::
// 1.Check integer overflow
// 2.Check edge case n=1 probable <----------  don't take it lightly, if this will be the reason you'll collapse
// 3.If conditions can be checked without bits, then never check with bits, never try to be oversmart!
// 4.WA can come bcz of very silly things ->  base case, if with bits,bla bla
// 5. MLE? -> #define int long long
// 6. When it's getting too complex till C, consider starting afresh, you might be going in a wrong direction
// 7.long long!!
// 8.clear adj and visited vector declared globally after each test case
// 9.check for long long overflow
// 10.Mod wale question mein last mein if dalo ie. Ans<0 then ans+=mod;
// 11.Incase of close mle change language to c++17 or c++14
// 12.Check ans for n=1
// 13. Happy Coding