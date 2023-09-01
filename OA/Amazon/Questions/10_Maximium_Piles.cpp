/*
Amazon Fresh is a new grocery store designed from the ground up to offer a seamless grocery
shopping experience to consumers. As part of a stock clearance exercise at the store, given
many piles of fresh products, follow the rules given below to stack the products in an orderly
manner. There are a total of n piles of products. The number of products in each pile is
represented by the array numProducts. Select any subarray from the array numProducts and pick up products from each pile. The number of products you pick from the i th pile is strictly less than the number of products you pick from the (i+1) th pile for all indices i of the subarray. Find the maximum number of products that can be picked. Example: The numbers of products in each pile are numProducts = [7, 4, 5, 2, 6, 5]. These are some ways strictly increasing subarrays can be chosen (1-based index). Choose subarray from indices (1, 3) and pick products [3, 4, 5] respectively from each.

input [7, 4, 5, 2, 6, 5] output should be 12 and for input [2,9,4,7,5,2] output should be 16, input [7, 4, 5, 2, 6, 5, 12, 13, 8, 20] output should be 53
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution
{
public:
    long long maximumBooks(vector<int> &books)
    {
        int n = books.size();
        vector<int> nums(n);
        for (int i = 0; i < n; ++i)
            nums[i] = books[i] - i;
        vector<int> left(n, -1);
        stack<int> stk;
        for (int i = 0; i < n; ++i)
        {
            while (!stk.empty() && nums[stk.top()] >= nums[i])
                stk.pop();
            if (!stk.empty())
                left[i] = stk.top();
            stk.push(i);
        }
        vector<ll> dp(n);
        dp[0] = books[0];
        ll ans = 0;
        for (int i = 0; i < n; ++i)
        {
            int v = books[i];
            int j = left[i];
            int cnt = min(v, i - j);
            int u = v - cnt + 1;
            ll s = 1ll * (u + v) * cnt / 2;
            dp[i] = s + (j == -1 ? 0 : dp[j]);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};