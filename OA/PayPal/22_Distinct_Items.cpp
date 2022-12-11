#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    int m;
    cin >> m;
    vector<int> arr(m);
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int low = 1;
    int high = n;
    int ans = 0;
    while (low <= high)
    {
        int mid = (high + low) / 2;
        int totalSum = (mid * (mid + 1) / 2);
        auto it = upper_bound(arr.begin(), arr.end(), mid);
        --it;
        int dist = it - arr.begin();
        int x = 0;
        for (int i = 0; i <= dist; i++)
        {
            x += arr[i];
        }
        if (totalSum - x <= k)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}