#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> updateHash(vector<int> &nums, vector<int> &hashValue)
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
    return ans;
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
    vector<vector<int>> ans = updateHash(nums, hashValue);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            if (j == ans[i].size() - 1)
            {
                cout << ans[i][j];
            }
            else
            {
                cout << ans[i][j] << " ";
            }
        }
        cout << endl;
    }
}
