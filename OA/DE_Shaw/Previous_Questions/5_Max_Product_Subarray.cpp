
/*
Given an integer array nums, find a
subarray
 that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.



Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
*/
#include <bits/stdc++.h>
using namespace std;

// Solution 1: Brute Force
class Solution
{
    int mx = INT_MIN;
    int solve(vector<int> &nums, int i, int prod)
    {
        if (i == nums.size() - 1)
        {
            return max(mx, prod * nums[i]);
        }
        int p1 = solve(nums, i + 1, prod * nums[i]);
        int p2 = solve(nums, i + 1, 1);

        return max(max(prod * nums[i], p1), max(mx, p2));
    }

public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        int prod = 1;
        return solve(nums, 0, prod);
    }
};

// Solution 2: Memoization
class Solution
{
    int mx = INT_MIN;
    map<int, map<int, long int>> dp;
    int solve(vector<int> &nums, int i, int prod)
    {
        if (i == nums.size() - 1)
        {
            return max(mx, prod * nums[i]);
        }
        if (dp[prod][i] != 0)
            return dp[prod][i];
        int p1 = solve(nums, i + 1, prod * nums[i]);
        int p2 = solve(nums, i + 1, 1);

        return dp[prod][i] = max(max(prod * nums[i], p1), max(mx, p2));
    }

public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        int prod = 1;
        // vector<vector<int>>dp(1000,vector<int>(1000,0));
        return solve(nums, 0, prod);
    }
};

// Solution 3: Iterative
// solution : 3 variation of kadane's algorithm
int solve(vector<int> &A)
{

    int n = A.size();
    // store the result that is the max we have found so far
    int r = A[0];

    // imax/imin stores the max/min product of
    // subarray that ends with the current number A[i]
    for (int i = 1, imax = r, imin = r; i < n; i++)
    {
        cout << imax << " " << imin << endl;

        // multiplied by a negative makes big number smaller, small number bigger
        // so we redefine the extremums by swapping them
        if (A[i] < 0)
            swap(imax, imin);

        // max/min product for the current number is either the current number itself
        // or the max/min by the previous number times the current one
        imax = max(A[i], imax * A[i]);
        imin = min(A[i], imin * A[i]);

        // the newly computed max value is a candidate for our global result
        r = max(r, imax);
    }
    return r;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
}