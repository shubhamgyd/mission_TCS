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
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int mxFar = n;
        int mxRev = arr[n - 1] + (n - 1);
        int mxFarRev[n];
        mxFarRev[n - 1] = mxRev;
        for (int j = n - 2; j >= 1; j--)
        {
            mxRev = max(mxRev, arr[j] + j);
            mxFarRev[j] = mxRev;
        }
        int mx = 0;
        for (int i = 0; i < n - 1; i++)
        {
            mx = max(mx, arr[i] - i + mxFarRev[i + 1]);
        }
        cout << mx << endl;
    }
    return 0;
}