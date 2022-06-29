/*
Problem Statement: Given a sorted array of N integers, where every element except one appears exactly twice and one element appears only once. Search Single Element in a sorted array.

Example 1:

Input: N = 9, array[] = {1,1,2,3,3,4,4,8,8}

Output: 2

Explanation: Every element in this sorted array except 2
appears twice, therefore the answer returned will be 2.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> res(n);
    for (int i = 0; i < n; i++)
    {
        cin >> res[i];
    }
    // using xor
    int element = 0;
    for (int i = 0; i < n; i++)
    {
        element ^= res[i];
    }
    cout << element << endl;
    // T:O(n)
    // s:O(1)

    // using binary seach
    int low = 0;
    int high = n - 2;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (mid % 2 == 0)
        {
            if (res[mid] != res[mid + 1])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if (res[mid] == res[mid + 1])
            {
                high = mid - 1;
            }
            else
            {
                low=mid+1;
            }
        }
    }
    cout<<res[low]<<endl;
    // T:O(logn)
    // S:O(1)
}