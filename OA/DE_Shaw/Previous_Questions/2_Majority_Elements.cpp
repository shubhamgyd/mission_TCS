/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times.
You may assume that the majority element always exists in the array.
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
    // Solution 1: Brute Force
    /*
        1. Sort array
        2. Count each elements frequencey
        3. Check with the given condition
        4. Display element
        Time Complexity:O(n*logn)
        Space Complexity:O(1)
    */

    // Solution 2: Hashing
    /*
        1. Put all element into hashMap and count their frequency
        2. Iterate hashMap and if any element have their frequency greater than n/2
        3. If yes, then print that element
        Time Complexity:O(n+logn)
        Space Complexity:O(n)
    */

    // Solution 3: Linear counting
    /*
        int counter = 0, majority;
        for (int num : nums) {
            if (!counter) {
                majority = num;
            }
            counter += num == majority ? 1 : -1;
        }
        return majority;
    */
}