#include <bits/stdc++.h>
using namespace std;
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int long long

void solve(int a, int b)
{
    while(true)
    {
        while(b%a!=0)
        {
            b*=(b%a);
        }
    }
}

int32_t main()
{
    fast();
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        solve(a, b);
    }
    return 0;
}
