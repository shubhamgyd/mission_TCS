/*
 an array is given, find avg .
 If avg is present in arr, which is a whole number return true, else false!
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    long long int sum = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        sum += nums[i];
        mp[nums[i]]++;
    }
    double avg = sum / n;
    if (mp.find(avg) != mp.end() and avg >= 0)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
    return 0;
}