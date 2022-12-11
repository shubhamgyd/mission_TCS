/*
Given an integer array, nums, return whether or not you can make the array strictly non-decreasing by modifying at most one element.
Note: A non-decreasing array is an array in which nums[i] <= nums[i + 1] for every i.

Ex: Given the following nums…

nums = [3, 1, 2], return true (you could modify three to one).
Ex: Given the following nums…

nums = [4, 2, 1, 3], return false.
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    int countFlits = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        if (arr[i] > arr[i + 1])
        {
            countFlits++;
        }
    }
    if (countFlits > 1)
    {
        cout << "False\n";
    }
    else
    {
        cout << "True\n";
    }
    return 0;
}