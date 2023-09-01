#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int k;
    cin >> k;
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int diff = k - nums[i];
        if (mp.find(diff) != mp.end())
        {
            cout << mp[diff] << " " << i + 1 << endl;
            return 0;
        }
        mp[nums[i]] = i + 1;
    }
}