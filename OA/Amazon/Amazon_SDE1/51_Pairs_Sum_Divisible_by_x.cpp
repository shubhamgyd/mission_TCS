/*
you are given an array of numbers and an integer x. you have to find all the possible pairs whose sum is divisible by x in NlogN time complexity.
*/

#include <bits/stdc++.h>
using namespace std;

int get(unordered_map<int, int> &mp, int x)
{
    if (mp.find(x) != mp.end())
    {
        return mp[x];
    }
    return 0;
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
    int x;
    cin >> x;
    unordered_map<int, int> mp;
    int ans = 0;
    for (int num : nums)
    {
        num %= x;
        ans += get(mp, num == 0 ? 0 : (x - num));
        ++mp[num];
    }
    cout << ans << endl;
}