/*
Given two integer arrays nums1 and nums2.
Arrays can possibly have one or more 0s.
The task is to replace each 0 with a positive integer such that sum of both arrays is equal.

Return the minimum sum possible.
Return -1 if its not possible to make the sums equal.

Example 1:
nums1: [1, 0, 2]
nums2: [1, 3, 0, 0]

Return: 6 because nums1 -> [1, 3, 2] and nums2 -> [1, 3, 1, 1]

Example 2:
nums1: [0, 0, 0]
nums2: [1, 1]

Return: -1, because there is no way to make array sums equal.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    int a0 = 0, b0 = 0;
    int sa = 0, sb = 0;
    for (int num : a)
    {
        if (num == 0)
        {
            a0++;
            sa += 1;
        }
        else
        {
            sa += num;
        }
    }
    for (int num : b)
    {
        if (num == 0)
        {
            b0++;
            sb += 1;
        }
        else
        {
            sb += num;
        }
    }
    if (sa == sb)
    {
        cout << sa << endl;
        return 0;
    }
    if (sa < sb)
    {
        if (a0)
        {
            cout << sb << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    else
    {
        if (b0)
        {
            cout << sa << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
}