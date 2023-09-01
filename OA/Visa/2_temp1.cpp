#include <bits/stdc++.h>
using namespace std;

int main()
{
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
        bool ok = true;
        for (int i = 0; i < n - 1; i++)
        {
            if ((nums[i] % 2 == 0 and nums[i + 1] % 2 == 0) or (nums[i] % 2 != 0 and nums[i + 1] % 2 != 0))
            {
                ok = false;
            }
        }
        if (ok)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}