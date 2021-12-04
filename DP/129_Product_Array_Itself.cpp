
#include <bits/stdc++.h>
using namespace std;
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int long long

vector<int> MaxProd(vector<int> res, int n)
{
    int beg = 1;
    int last = 1;
    vector<int> ans(n, 1);

    for (int i = 0; i < n; i++)
    {
        ans[i] *= beg;
        beg *= res[i];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        ans[i] *= last;
        last *= res[i];
    }

    return ans;
}

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.out", "w", stdout);
#endif
    fast();
    int n;
    cin >> n;
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        res.push_back(a);
    }

    int pre[n];
    int back[n];
    pre[0] = 1;
    back[0] = 1;

    for (int i = 1; i < n; i++)
    {
        pre[i] = pre[i - 1] * res[i - 1];
        back[i] = back[i - 1] * res[n - i];
    }

    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        ans.push_back(pre[i] * back[n - 1 - i]);
    }
    for (auto it : ans)
    {
        cout << it << " ";
    }

    cout << endl;
    vector<int> vec = MaxProd(res, n);
    for (auto it : vec)
    {
        cout << it << " ";
    }
    return 0;
}