// count elements occurs more than ones
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mp[arr[i]]++;
    }
    int cnt = 0;
    for (auto it : mp)
    {
        if (it.second > 1)
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}