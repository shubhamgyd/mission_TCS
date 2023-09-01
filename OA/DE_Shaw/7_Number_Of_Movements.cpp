/*
Given an array of N numbers greater than or equal to zero corresponding to the number of stones at each position, find the minimum number of moves to distribute these stones such that each position has one stone at the end.

The total sum of the given array is equal to N.

A move consists of moving any number of stones from one index to the adjacent one.

Example:-
Input – [0 2 1 3 0 0]
Expected Output – 3

Explanation – Step 1: Shift 1 stone from index 1 to index 0 [1 1 1 3 0 0]
Step 2: Shift 2 stones from index 3 to index 4 [1 1 1 1 2 0]
Step 3: Shift 1 stone from index 4 to index 5 [1 1 1 1 1 1]
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
    int cnt = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        if (sum != i + 1)
        {
            ++cnt;
        }
    }
    cout << cnt << endl;
    return 0;
}