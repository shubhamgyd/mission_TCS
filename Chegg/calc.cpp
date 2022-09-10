#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int curMax = 0, maxTillNow = INT_MIN;
    for (auto c : nums)
    {
        curMax = max(c, curMax + c),
        maxTillNow = max(maxTillNow, curMax);
    }
    cout << maxTillNow << endl;
    return 0;
}