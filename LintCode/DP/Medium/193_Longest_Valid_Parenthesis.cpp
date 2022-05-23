/*
Description
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

Example
Example 1:

Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"
Example 2:

Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring

*/

#include <bits/stdc++.h>
using namespace std;

// Solution: 2
class Solution
{
public:
    /**
     * @param s: a string
     * @return: return a integer
     */
    int longestValidParentheses(string &s)
    {
        // write your code here
        int open = 0;
        int close = 0;
        int n = s.length();
        int ct = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
                open++;
            else if (s[i] == ')')
                close++;
            if (open == close)
            {
                ct = max(ct, 2 * open);
                // open=0;
                // close=0;
            }
            else if (close > open)
            {
                close = 0;
                open = 0;
            }
        }
        int ct1 = 0;
        open = 0;
        close = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == ')')
                close++;
            else if (s[i] == '(')
                open++;
            if (open == close)
            {
                ct1 = max(ct1, 2 * close);
                // open=0;
                // close=0;
            }
            else if (open > close)
            {
                close = 0;
                open = 0;
            }
        }
        return max(ct, ct1);
    }
};

// Time Complexity:O(n)
// Space Complexity:O(1)

// Solution: 3
// Dp Solution
int solve(string str)
{
    int n = str.length();

    int dp[n][2];
    // dp[i][0]-> for open parenthesis
    // dp[i][1]-> for close parenthesis
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 0;
        dp[i][1] = 0;
    }
    int ct = 0;
    int ct1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            if (str[i] == '(')
            {
                dp[i][0] = 1;
                dp[i][1] = 0;
            }
            else
            {
                dp[i][0] = 0;
                dp[i][1] = 1;
            }
            if (dp[i][1] > dp[i][0])
            {
                dp[i][0] = 0;
                dp[i][1] = 0;
            }
            continue;
        }
        if (str[i] == '(')
        {
            dp[i][0] = dp[i - 1][0] + 1;
            dp[i][1] = dp[i - 1][1];
        }
        else if (str[i] == ')')
        {
            dp[i][1] = dp[i - 1][1] + 1;
            dp[i][0] = dp[i - 1][0];
        }
        if (dp[i][0] == dp[i][1])
        {
            ct = max(ct, 2 * dp[i][0]);
        }
        else if (dp[i][1] > dp[i][0])
        {
            dp[i][0] = 0;
            dp[i][1] = 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 0;
        dp[i][1] = 0;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (i == n - 1)
        {
            if (str[i] == '(')
            {
                dp[i][0] = 1;
                dp[i][1] = 0;
            }
            else
            {
                dp[i][0] = 0;
                dp[i][1] = 1;
            }
            if (dp[i][0] > dp[i][1])
            {
                dp[i][0] = 0;
                dp[i][1] = 0;
            }
            continue;
        }
        if (str[i] == '(')
        {
            dp[i][0] = dp[i + 1][0] + 1;
            dp[i][1] = dp[i + 1][1];
        }
        else if (str[i] == ')')
        {
            dp[i][1] = dp[i + 1][1] + 1;
            dp[i][0] = dp[i + 1][0];
        }
        if (dp[i][0] == dp[i][1])
        {
            ct1 = max(ct1, 2 * dp[i][0]);
        }
        else if (dp[i][0] > dp[i][1])
        {
            dp[i][0] = 0;
            dp[i][1] = 0;
        }
    }
    return max(ct, ct1);
}

int main()
{
    string str;
    cin >> str;
    int n = str.length();

    // Solution 1: Brute Force
    int mx = 0;
    for (int len = 1; len < n; len++)
    {
        for (int i = 0; i <= n - len; i++)
        {
            int j = i + len - 1;
            int open = 0;
            int close = 0;
            for (int k = i; k <= j; k++)
            {
                if (str[k] == '(')
                    open++;
                else
                    close++;
            }

            if (open == close)
            {
                mx = max(mx, 2 * close);
            }
        }
    }
    // Time Complexity:O(n^3)
    // Space Complxity:O(1)
    cout << mx << endl;

    // int ans=solve()
}