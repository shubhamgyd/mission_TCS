/*
Your team wants to develop a service that takes in an array of integers where the ith element represents the category of the ith product viewed by the customer and returns the sum of the number of distinct categories on all contiguous segments of the array.

Given an array of n integers, categories, find the sum of the numbers of distinct integers over all of its subarrays.

Note: A subarray is a contiguous part of an array
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (auto &x : nums)
    {
        cin >> x;
    }
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++)
    {
        mp[nums[i]].push_back(i);
    }
    int cnt = 0;
    for (auto it : mp)
    {
        for (int j = 0; j < it.second.size(); j++)
        {
            if (j < it.second.size() - 1)
            {
                cnt += (it.second[j] + 1) * (mp[it.first][j + 1] - it.second[j]);
            }
            else
            {
                cnt += n - it.second[j];
            }
        }
    }
    cout << cnt << endl;
    return 0;
}

/*
Explanation:
for index i,
for subarrays starting from index i, it will be added n-i times
for those staring before index i, say the nearest same alphabet is at index j, it will be added n-i times i-j-1
in total i-j time n-i
*/