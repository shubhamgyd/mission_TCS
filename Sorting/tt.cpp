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
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        if (nums[0] > 0)
        {
            cout << -1 << endl;
            continue;
        }
        int cnt = 0;
        vector<int> ans(n, 0);
        bool ok = true;
        for (int i = n - 1; i > 0; i--)
        {
            if (ans[i] != nums[i])
            {
                if (nums[i - 1] == 0 or nums[i] == nums[i - 1])
                {
                    cnt += (nums[i]);
                }
                else if (nums[i - 1] > nums[i])
                {
                    ok = false;
                    break;
                }
                else
                {
                    int num = (nums[i - 1] + 1);
                    if (nums[i] % num != 0)
                    {
                        ok = false;
                        break;
                    }
                    else
                    {
                        cnt += (nums[i] / num);
                    }
                }
            }
        }
        if (ok)
        {
            cout << cnt << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
}
