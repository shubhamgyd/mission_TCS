#include <bits/stdc++.h>
using namespace std;

int findmissing(int ar[], int N)
{
    int l = 0, r = N - 1;
    while (l <= r)
    {

        int mid = (l + r) / 2;

        // If this is the first element
        // which is not index + 1, then
        // missing element is mid+1
        if (ar[mid] != mid + 1 &&
            ar[mid - 1] == mid)
            return mid + 1;

        // if this is not the first missing
        // element search in left side
        if (ar[mid] != mid + 1)
            r = mid - 1;

        // if it follows index+1 property then
        // search in right side
        else
            l = mid + 1;
    }

    // if no element is missing
    return -1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
    }
    int low = 1;
    int high = n;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        cout << mid << endl;
        if (mid + 1 <= n and nums[mid] == mid and mid + 1 == nums[mid + 1])
        {
            low = mid + 1;
        }
        else if (mid + 1 <= n and nums[mid] == mid and mid + 1 < nums[mid])
        {
            cout << mid + 1 << endl;
            return 0;
        }
        else if (mid + 1 <= n and nums[mid] == mid and nums[mid + 1] == mid + 1)
        {
            high = mid - 1;
        }
        else if (mid + 1 <= n and nums[mid + 1] == mid + 1 and nums[mid] > mid)
        {
            cout << mid << endl;
            return 0;
        }
    }
    return 0;
}