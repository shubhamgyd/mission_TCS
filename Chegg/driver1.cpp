#include <bits/stdc++.h>
using namespace std;
#define int long long

int sum(int start, int end, vector<int> &v)
{

    unordered_map<int, int> prevSum;
    int res = 0, currSum = 0;
    for (int i = start; i < end; i++)
    {
        currSum += v[i];
        if (currSum == 0)
            res++;
        if (prevSum.find(currSum - 0) != prevSum.end())
            res += (prevSum[currSum - 0]);
        prevSum[currSum]++;
    }

    return res;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    vector<int> smaller(n, 0), bigger(n, 0), d(n, 0);
    k -= 1;
    for (int i = 0; i < n; i++)
    {
        smaller[i] = nums[i] < nums[k];
    }

    for (int i = 0; i < n; i++)
    {
        bigger[i] = nums[i] > nums[k];
    }
    for (int i = 0; i < n; i++)
    {
        d[i] = smaller[i] - bigger[i];
    }
    int ans = sum(0, n, d) - sum(0, k, d) - sum(k + 1, n, d);
    cout << ans << endl;
    return 0;
}