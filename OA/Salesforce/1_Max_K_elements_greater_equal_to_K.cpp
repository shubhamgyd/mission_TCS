/*
Given an array of n non negative numbers find max k value where the array contains atleast k numbers greater than k.
Example: [1,3,4,4] here max k value is 3.
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
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] < n)
        {
            mp[nums[i]]++;
        }
        else
        {
            mp[n]++;
        }
    }
    int cnt = 0;
    for (int i = n; i > 0; i--)
    {
        cnt += mp[i];
        if (cnt >= i)
        {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}