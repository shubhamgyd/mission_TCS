#include <bits/stdc++.h>
using namespace std;

int findInsert(vector<int> &nums, int target)
{
    int l = 0;
    int h = nums.size() - 1;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] < target)
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }
    return h + 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int number;
    cin >> number;
    int index = findInsert(nums, number);
    cout << index << endl;
    return 0;
}