#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums, int low, int high, int rating)
{
    if (low > high)
    {
        return -1;
    }
    if (rating >= nums[high])
    {
        return high;
    }
    int mid = (low + high) / 2;
    if (nums[mid] == rating)
    {
        return mid;
    }
    if (mid > 0 and nums[mid - 1] <= rating and rating < nums[mid])
    {
        return mid - 1;
    }
    if (rating < nums[mid])
        return solve(nums, low, mid - 1, rating);
    return solve(nums, mid + 1, high, rating);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int rating;
    cin >> rating;
    int index = solve(nums, 0, n - 1, rating);
    if (index < 0)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << (index + 1) << endl;
    }
    return 0;
}
