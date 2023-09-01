/*
Given an array of integers nums, find the maximum length of a subarray where the product of all its elements is positive.

A subarray of an array is a consecutive sequence of zero or more values taken out of that array.

Return the maximum length of a subarray with positive product.
*/

// Intuition:
/*
- we needs subarray having positive product means:
-subarray having even number of negatives
-and without zeros
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
    int startWindow = -1;
    int firstNeg = -2;
    int len = 0;
    int neg = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
        {
            // Reset all
            startWindow = i;
            firstNeg = -2;
            neg = 0;
        }
        else
        {
            if (nums[i] < 0)
            {
                // number of negatives in  current frame means (frame excluding zero)
                neg++;
            }
            if (neg == 1 and firstNeg == -2)
            {
                // init firstneg cnt neg;
                firstNeg = i;
            }
            if (neg % 2 == 0)
            {
                // if curr cnt neg is framestart;
                len = max(len, i - startWindow);
            }
            else
            {
                // first firstneg after last zero;
                len = max(len, i - firstNeg);
            }
        }
    }
    cout << len << endl;
    return 0;
}