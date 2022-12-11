#include <bits/stdc++.h>
using namespace std;

void updateHash(vector<int> &nums, vector<int> &hashValue)
{
    map<int, vector<int>> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        int val;
        if (nums[i] % 2 == 0)
        {
            val = hashValue[i] + nums[i] % 10;
        }
        else
        {
            val = hashValue[i] - nums[i] % 10;
        }
        mp[val].push_back(nums[i]);
    }
    vector<vector<int>> ans;
    for (auto it : mp)
    {
        ans.push_back(it.second);
    }
    for (auto it : ans)
    {
        for (auto num : it)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> nums(n), hashValue(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> hashValue[i];
    }
    updateHash(nums, hashValue);
}

// 10
// 57 73 35 92 1 60 88 52 96 98
// 61 76 41 93 10 64 89 56 97 98