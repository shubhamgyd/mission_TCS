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
    vector<int> even, odd;
    for (auto it : nums)
    {
        if (it % 2 == 0)
            even.push_back(it);
        else
            odd.push_back(it);
    }
    sort(even.rbegin(), even.rend());
    sort(begin(odd), end(odd));
    vector<int> ans;
    int i = 0;
    int j = 0;
    int sz1 = even.size();
    int sz2 = odd.size();
    while (i < sz1 and j < sz2)
    {
        ans.push_back(odd[j]);
        ans.push_back(even[i]);
        i++;
        j++;
    }
    while (j < sz2)
    {
        ans.push_back(odd[j]);
        j++;
    }
    while (i < sz1)
    {
        ans.push_back(even[i]);
        i++;
    }
    for (auto it : ans)
    {
        cout << it << ' ';
    }
    return 0;
}