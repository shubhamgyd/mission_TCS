/*
You are given an array A of N integers. You need to find two integers x and y such that the
 sum of the absolute difference between each element of the array to one of the two chosen
  integers is minimal.
Task
Determine the minimum value of the expression ∑i=1nmin(abs(a[i]−x),abs(a[i]−y))
if the chosen numbers are x and y.
Example1:
N = 4
A = [2, 3, 6, 7]
Approach
You can choose the two integers, 3 and 7.
The required sum = |2 - 3| + |3 - 3| + |6 - 7| + |7 - 7| = 1 + 0 + 0 + 1 = 2.
Example2:
Given
N = 3
A = [1, 3, 5]
Approach
You can choose the two integers, 1 and 4.
The required sum = |1 - 1| + |3 - 4| + |5 - 4| = 0 + 1 + 1 = 2.
The second test case
Example3:
Given
N = 4
A = [3, 2, 5, 11]
Approach
You can choose the two integers, 3 and 11.
The required sum = |2 - 3| + |3 - 3| + |5 - 3| + |11 - 11 |= 1 + 0 + 2 + 0 = 3.

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }
    sort(begin(nums), end(nums));
    int ind = 0;
    int mx = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int temp = nums[i + 1] - nums[i];
        if (temp >= mx)
        {
            ind = i;
            mx = temp;
        }
    }
    return 0;
}