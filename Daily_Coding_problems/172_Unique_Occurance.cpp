#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    map<int, int> mp;
    map<int, int> occr;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        mp[nums[i]]++;
    }
    for (auto it : mp)
    {
        if (occr.find(it.second) != occr.end())
        {
            cout << 0 << endl;
            return 0;
        }
        occr[it.second]++;
    }
    cout << 1 << endl;
    return 0;
}