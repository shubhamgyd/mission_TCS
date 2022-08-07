#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
         int value, operations = 0, temp = -1;
        for (int i = 0; i < n; i++)
        {
            cin >> value;
            if (temp != value)
            {
                operations++;
                temp = value;
            }
        }
        cout << operations << '\n';
    }
    return 0;
}