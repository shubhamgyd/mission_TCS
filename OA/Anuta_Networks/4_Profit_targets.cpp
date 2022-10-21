#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int n;
    cin >> n;
    int arr[n];
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mp[arr[i]]++;
    }
    int target;
    cin >> target;
    int cnt = 0;
    for (auto it : mp)
    {
        int num1 = it.first;
        int num2 = target - num1;
        if (num1 == num2)
        {
            if (it.second > 1)
            {
                cnt++;
            }
        }
        else
        {
            if (mp.find(num2) != mp.end() and mp[num2] > 0 and it.second > 0)
            {

                cnt++;
                mp[num1] = 0;
                mp[num2] = 0;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}

/*
Test 1:
9
5 7 9 13 11 6 6 3 3
12

Test 2:
6
1 3 46 1 3 9
47
*/