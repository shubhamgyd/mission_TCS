/*
Given an array of n numbers. split the array into two equal halves such that sum of each array difference is minimum. If n is odd one array will have extra one number. Output the absolute minimum difference.
Example : [1,2,3,4] output: 0
*/

// For solution refer : https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/solutions/1513298/c-meet-in-middle/
//  Meet in the middle technique

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
}
