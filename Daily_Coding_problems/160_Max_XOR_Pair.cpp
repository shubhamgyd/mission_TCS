/*
This problem was asked by Salesforce.

Given an array of integers, find the maximum XOR of any two elements.
*/

#include <bits/stdc++.h>
using namespace std;

int solve(int n)
{
    vector<int>prime(n + 1, 0);
    for (int i = 0; i <= n; i++)
    {
        prime[i] = i;
    }
    for (int i = 2; i <= n; i++)
    {
        if (prime[i] != i)
            continue;
        for (int j = 2 * i; j <= n; j += i)
        {
            prime[j] = i;
        }
    }
    vector<int>dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == i)
        {
            dp[i] = dp[i - 1] + 1;
        }
        else
        {
            dp[i] = min(dp[prime[i]], dp[i - 1]) + 1;
        }
    }
    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    cout<<solve(n)<<endl;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    // Brute Force
    int mx = 0;
    for (int i = 0; i < n; i++)
    {

        for (int j = i + 1; j < n; j++)
        {
            mx = max(mx, (nums[i] ^ nums[j]));
        }
    }
    cout << mx << endl;
}