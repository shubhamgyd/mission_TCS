/*
This problem was asked by Yelp.

You are given an array of integers, where each element represents the maximum number of steps
that can be jumped going forward from that element. Write a function to return the minimum number
of jumps you must take in order to get from the start to the end of the array.

For example, given [6, 2, 4, 0, 5, 1, 1, 4, 2, 9], you should return 2, as the optimal solution
involves jumping from 6 to 5, and then from 5 to 9.
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> dp;

int recurs(vector<int> &nums, int i)
{
    if (i >= nums.size())
        return 10000000;

    if (i == nums.size() - 1)
        return 0;

    if (dp[i] != -1)
        return dp[i];

    int a = 10000000;

    for (int k = 1; k <= nums[i] && k + i < nums.size(); k++)
    {
        a = min(a, recurs(nums, k + i) + (1));
    }

    return dp[i] = a;
}

int jump(vector<int> &nums)
{
    dp.resize(20001, -1);
    return recurs(nums, 0);
}

int main()
{
    int n;
    cin >> n;
    vector<int> jumps(n);
    for (int i = 0; i < n; i++)
    {
        cin >> jumps[i];
    }

    int ans = jump(jumps);
    cout << ans << endl;

    // Solution 2:
    vector<int>arr=jumps;
    int n = arr.size();
    if (arr[0] == 0 and n > 1)
    {
        cout<<-1<<endl;
        return 0;
    }
    if (n <= 1)
    {
        cout<<0<<endl;
        return 0;
    }

    pair<int, int> interval = {0, 0};
    int jump1 = 0;
    while (1)
    {
        jump1++;
        int can_reach = -1;
        for (int i = interval.first; i <= interval.second; i++)
        {
            can_reach = max(can_reach, i + arr[i]);
        }
        if (can_reach >= n - 1)
        {
            cout<<jump1<<endl;
            return 0;
        }
        interval = {interval.second + 1, can_reach};
        if (interval.first > interval.second)
        {
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}