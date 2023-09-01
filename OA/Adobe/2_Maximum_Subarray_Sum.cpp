/*
Given an integer array nums, find the
subarray
 with the largest sum, and return its sum.



Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
*/

#include <bits/stdc++.h>
using namespace std;

// TLE
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = size(nums), ans = INT_MIN;
        for (int i = 0; i < n; i++)
            for (int j = i, curSum = 0; j < n; j++)
                curSum += nums[j],
                    ans = max(ans, curSum);
        return ans;
    }
};

// Recursive TLE
class Solution1
{
public:
    int maxSubArray(vector<int> &nums)
    {
        return solve(nums, 0, false);
    }
    int solve(vector<int> &A, int i, bool mustPick)
    {
        // our subarray must contain atleast 1 element. If mustPick is false at end means no element is picked and this is not valid case
        if (i >= size(A))
            return mustPick ? 0 : -1e5;
        if (mustPick)
            return max(0, A[i] + solve(A, i + 1, true));                  // either stop here or choose current element and recurse
        return max(solve(A, i + 1, false), A[i] + solve(A, i + 1, true)); // try both choosing current element or not choosing
    }
};

// DP
class Solution3
{
public:
    int maxSubArray(vector<int> &nums)
    {
        vector<int> dp(nums);
        for (int i = 1; i < size(nums); i++)
            dp[i] = max(nums[i], nums[i] + dp[i - 1]);
        return *max_element(begin(dp), end(dp));
    }
};

// Kadanes Algo
class Solution4
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int curMax = 0, maxTillNow = INT_MIN;
        for (auto c : nums)
            curMax = max(c, curMax + c),
            maxTillNow = max(maxTillNow, curMax);
        return maxTillNow;
    }
};

// Divide and Conquer
class Solution5
{
public:
    int maxSubArray(vector<int> &nums)
    {
        return maxSubArray(nums, 0, size(nums) - 1);
    }
    int maxSubArray(vector<int> &A, int L, int R)
    {
        if (L > R)
            return INT_MIN;
        int mid = (L + R) / 2, leftSum = 0, rightSum = 0;
        // leftSum = max subarray sum in [L, mid-1] and starting from mid-1
        for (int i = mid - 1, curSum = 0; i >= L; i--)
            curSum += A[i],
                leftSum = max(leftSum, curSum);
        // rightSum = max subarray sum in [mid+1, R] and starting from mid+1
        for (int i = mid + 1, curSum = 0; i <= R; i++)
            curSum += A[i],
                rightSum = max(rightSum, curSum);
        // return max of 3 cases
        return max({maxSubArray(A, L, mid - 1), maxSubArray(A, mid + 1, R), leftSum + A[mid] + rightSum});
    }
};