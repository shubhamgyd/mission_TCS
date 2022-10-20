#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string str;
        cin >> str;
        if (n == 0)
        {
            cout << 0 << endl;
            continue;
        }
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            sum += arr[i];
        }
        unordered_map<char, int> mp;
        for (int i = 0; i < n; i++)
        {
            if (mp.find(str[i]) != mp.end())
            {
                mp[str[i]] = max(mp[str[i]], arr[i]);
            }
            else
            {
                mp[str[i]] = arr[i];
            }
        }
        for (auto it : mp)
        {
            sum -= it.second;
        }
        cout << sum << endl;
    }
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     int n, k;
//     cin >> n >> k;
//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     unordered_map<int, int> mp;
//     for (int i = 0; i < n; i++)
//     {
//         mp[arr[i]]++;
//     }
//     int cnt = 0;
//     int ans = 0;
//     vector<int> res;
//     for (auto i : mp)
//     {
//         res.push_back(i.second);
//     }
//     sort(res.begin(), res.end(), greater<int>());
//     for (int i = 0; i < res.size(); i++)
//     {
//         if (ans >= k)
//             break;
//         ans += res[i];
//         cnt++;
//     }
//     cout << cnt << endl;
//     return 0;
// }