/*
This problem was asked by Atlassian.

MegaCorp wants to give bonuses to its employees based on how many lines of codes
they have written. They would like to give the smallest positive amount to each worker
consistent with the constraint that if a developer has written more lines of code than
their neighbor, they should receive more money.

Given an array representing a line of seats of employees at MegaCorp,
determine how much each one should get paid.

For example, given [10, 40, 200, 1000, 60, 30], you should return [1, 2, 3, 4, 2, 1]
*/

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
    vector<int> ans(n, 1);
    for (int i = 1; i < n; i++)
    {
        if (nums[i] > nums[i - 1])
            ans[i] = ans[i - 1] + 1;
    }
    int totalBonus = ans[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] > nums[i + 1])
        {
            ans[i] = max(ans[i], ans[i + 1] + 1);
        }
        totalBonus += ans[i];
    }
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
    cout << totalBonus << endl;
    return 0;
}