#include <bits/stdc++.h>
using namespace std;

int jump(vector<int> &arr, int finish)
{
    int n = arr.size();
    if (arr[0] == 0 and n > 1)
    {
        return -1;
    }
    if (n <= 1)
    {
        return 0;
    }
    pair<int, int> interval = {0, 0};
    int jump = 0;
    int last = 0;
    while (1)
    {
        int can_reach = -1;
        for (int i = interval.first; i <= interval.second; i++)
        {
            can_reach = max(can_reach, 10 + arr[i]);
        }
        cout << "can_reach: " << can_reach << endl;
        if (can_reach > finish)
        {
            jump += (finish - last);
        }
        else
        {
            jump += (can_reach - last);
            last = can_reach;
        }
        if (can_reach >= n - 1)
        {
            return jump;
        }
        interval = {interval.second + 1, can_reach};
        if (interval.first > interval.second)
        {
            return -1;
        }
    }
    return -1;
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
    int finish;
    cin >> finish;
    sort(begin(nums), end(nums));
    cout << jump(nums, finish) << endl;
    return 0;
}