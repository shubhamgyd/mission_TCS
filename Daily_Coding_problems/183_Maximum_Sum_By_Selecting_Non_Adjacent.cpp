#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        if (n == 1)
        {
            return arr[0];
        }
        if (n == 2)
        {
            return max(arr[0], arr[1]);
        }
        int dp[n + 1];
        dp[1] = arr[0];
        dp[2] = max(arr[0], arr[1]);
        for (int i = 3; i <= n; i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + arr[i - 1]);
        }
        return dp[n];
    }
};
// Time Complexity:O(n)
// Space :O(n)

class Solution
{
public:
    // calculate the maximum sum with out adjacent
    int findMaxSum(int *arr, int n)
    {
        // code here
        if (n == 1)
        {
            return arr[0];
        }
        if (n == 2)
        {
            return max(arr[0], arr[1]);
        }
        int a = arr[0];
        int b = max(arr[0], arr[1]);
        int c;
        for (int i = 2; i < n; i++)
        {
            c = max(b, a + arr[i]);
            a = b;
            b = c;
        }
        return c;
    }
};

// Time Complexity:O(n)
// Space Complexity:O(1)