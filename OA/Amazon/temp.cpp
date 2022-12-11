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
#define f first
#define s second
// #define mp make_pair
#define sz(v) (int)(v.size())
#define all(v) (v).begin(), (v).end()
// #define y cout<<"Yes"
// #define nn cout<<"No"
#define ll long long
#define limit1 30
#define int long long

// const long long N = 200005, INF = 2000000000000000000;

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

void testCases()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    int neg = 0;
    int pos = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        if (nums[i] > 0)
            pos++;
        else
            neg++;
        sum += nums[i];
    }
    if ((neg == 0 and n % 2 == 0) or (pos == 0 and n % 2 == 0))
    {
        cout << 1 << endl;
        cout << 1 << " " << n << endl;
        return;
    }
    if ((neg == 0 and n % 2 == 1) or (pos == 0 and n % 2 == 1))
    {
        cout << -1 << endl;
        return;
    }
    int cnt1 = 0;
    int cnt2 = 0;
    vector<int> temp;
    vector<pair<int, int>> res;
    for (int i = 0; i < n; i++)
    {
        bool isEmpty = temp.size() == 0 ? true : false;
        int num = 0;
        int size = 0;
        if (!isEmpty)
        {
            num = temp.back();
            size = temp.size();
        }
        if (isEmpty or num == nums[i])
            temp.push_back(nums[i]);
        else
        {
            if (size % 2 == 0)
                res.push_back({i - size, i - 1});
            else
            {
                if (size == 1)
                {
                    int ind = i - 1;
                    res.push_back({ind, ind});
                }
                else
                {
                    int num1 = i - size;
                    int num2 = i - 2;
                    int ind = i - 1;
                    res.push_back({num1, num2});
                    res.push_back({ind, ind});
                }
                int last = temp.back();
                if (last == -1)
                    cnt1++;
                else
                    cnt2++;
            }
            temp.clear();
            temp.push_back(nums[i]);
        }
    }

    bool empty = (temp.size() == 0 ? true : false);
    if (!empty)
    {
        int size = temp.size();
        if (size % 2 == 0)
        {
            int num1 = n - size;
            int num2 = n - 1;
            res.push_back({num1, num2});
        }
        else
        {
            if (size == 1)
            {
                int ind = n - 1;
                res.push_back({ind, ind});
            }
            else
            {
                int num1 = n - size;
                int num2 = n - 2;
                int ind = n - 1;
                res.push_back({num1, num2});
                res.push_back({ind, ind});
            }
        }
        int last = temp.back();
        if (last == -1)
            cnt1++;
        else
            cnt2++;
    }
    if (cnt1 != cnt2)
        cout << -1 << endl;
    else
    {
        int sz = res.size();
        cout << sz << endl;
        for (auto it : res)
            cout << it.first + 1 << " " << it.second + 1 << endl;
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