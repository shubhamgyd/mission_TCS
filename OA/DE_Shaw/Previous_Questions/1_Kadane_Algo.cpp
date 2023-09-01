

#include <bits/stdc++.h>
using namespace std;

int main()
{
    /*
    Solution 1: Brute Force
    Calculate sum of every subarray and find maximum
    Time Complexity:O(n*n)
    Space Complexity:O(1)
    */

    /*
    Solution 2:
    Define two-variable currSum which stores maximum sum ending here and maxSum which stores maximum sum so far.
    Initialize currSum with 0 and maxSum with INT_MIN.
    Now, iterate over the array and add the value of the current element to currSum and check
    If currSum is greater than maxSum, update maxSum equals to currSum.
    If currSum is less than zero, make currSum equal to zero.
    Finally, print the value of maxSum.
    Time Complexity:O(n)
    Space Complexity:O(1)
    */
    vector<int> a = {1, 3, 8, -2, 6, -8, 5};
    int mx_Sum = 0;
    int curr_Sum = 0;
    for (int i = 0; i < a.size(); i++)
    {
        curr_Sum += a[i];
        if (curr_Sum > mx_Sum)
        {
            mx_Sum = curr_Sum;
        }
        if (curr_Sum < 0)
        {
            curr_Sum = 0;
        }
    }
    cout << mx_Sum << endl;
    return 0;
}