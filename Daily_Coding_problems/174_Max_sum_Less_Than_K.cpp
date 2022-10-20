/*
Given an integer array, nums, return the maximum sum that exists between two elements that is less than k.

Ex: Given the following nums…

nums = [8, 2, 4, 9], k = 13, return 12 (8 + 12 = 12 < 13).
Ex: Given the following nums…

nums = [19, 10, 14, 23, 12], k = 39, return 37.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    sort(begin(nums), end(nums));
    int sum = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int num = k - nums[i];
        // num--;
        auto it = lower_bound(nums.begin(), nums.end(), num) - nums.begin();
        if (it - 1 >= 0 and it - 1 != i)
        {
            sum = max(sum, nums[it - 1] + nums[i]);
        }
    }
    cout << sum << endl;
}
// Time Complexity:O(nlogn)