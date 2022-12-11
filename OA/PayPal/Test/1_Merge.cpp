#include <bits/stdc++.h>
using namespace std;
pair<int, vector<int>> merge1(pair<int, vector<int>> &a, pair<int, vector<int>> &b)
{
    int i = 0;
    int j = 0;
    vector<int> ans;
    int cnt = a.first + b.first;
    while (i < a.second.size() and j < b.second.size())
    {
        if (a.second[i] > b.second[j])
        {
            ans.push_back(b.second[j]);
            j++;
            cnt += a.second.size() - i;
        }
        else
        {
            ans.push_back(a.second[i]);
            i++;
        }
    }
    while (i < a.second.size())
    {
        ans.push_back(a.second[i]);
        i++;
    }
    while (j < b.second.size())
    {
        ans.push_back(b.second[j]);
        j++;
    }
    pair<int, vector<int>> res = {cnt, ans};
    return res;
}

pair<int, vector<int>> mergeSort(pair<int, vector<int>> &p)
{
    if (p.second.size() == 1)
    {
        return p;
    }
    int mid = p.second.size() / 2;
    vector<int> left1, right1;
    int cnt = p.first;
    for (int i = 0; i < mid; i++)
    {
        left1.push_back(p.second[i]);
    }
    for (int i = mid; i < p.second.size(); i++)
    {
        right1.push_back(p.second[i]);
    }
    pair<int, vector<int>> left = {cnt, left1};
    pair<int, vector<int>> right = {cnt, right1};
    auto l1 = mergeSort(left);
    auto l2 = mergeSort(right);
    pair<int, vector<int>> res = merge1(l1, l2);
    return res;
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
    int count = 0;
    pair<int, vector<int>> p = {count, nums};
    auto it = mergeSort(p);
    cout << it.first << endl;
    return 0;
}