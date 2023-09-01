/*
Uber HR is looking to book hotel rooms for an incoming 2023 batch of hired College Graduates. She is allowed to spend anywhere between B and C (both inclusive) for these bookings. She needs to book rooms consecutively as the new joinees would prefer to stay as close to each other as possible.

She has been given the pricing of the rooms in order in the form of array A (Needless to say, the prices are non-negative integers). You need to find out the number of consecutive rooms options available for booking. Note that there is no restriction on the number of rooms she can book. (She can book as less as one or she can book the entire hotel if budget constraints are satisfied)

Constraints:
1 <= size of A <= 10^6
B and C fit in a 32 bit signed integer

Example:

Given A = [10, 5, 1, 0, 2], B = 6, C = 8
Output: 3
Explanation: Possible solutions are [5,1], [5,1,0], [5,1,0,2]

[execution time limit] 0.5 seconds (cpp)

[memory limit] 1 GB

[input] array.integer arr

pricing of the rooms

[input] integer b

lower bound of budget

[input] integer c

Upper bound of budget

[output] integer

possible ways to book rooms within budget
*/

#include <bits/stdc++.h>
using namespace std;

// Function to find number of subarrays having
// sum less than or equal to x.
int countSub(vector<int> &arr, int n, int x)
{

    // Starting index of sliding window.
    int st = 0;

    // Ending index of sliding window.
    int end = 0;

    // Sum of elements currently present
    // in sliding window.
    int sum = 0;

    // To store required number of subarrays.
    int cnt = 0;

    // Increment ending index of sliding
    // window one step at a time.
    while (end < n)
    {

        // Update sum of sliding window on
        // adding a new element.
        sum += arr[end];

        // Increment starting index of sliding
        // window until sum is greater than x.
        while (st <= end && sum > x)
        {
            sum -= arr[st];
            st++;
        }

        // Update count of number of subarrays.
        cnt += (end - st + 1);
        end++;
    }

    return cnt;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int b, c;
    cin >> b >> c;
    // Intuition :
    // Decompose into subarrays with budget less than or equal to C minus subarrays with budget less
    // than B. For each budget bound use sliding window to find the longest valid subarray ending at
    // each index. The total number of subarrays is the sum of lengths of these subarrays.

    // Number of subarrays having sum less
    // than or equal to R.
    int Rcnt = countSub(nums, n, c);

    // Number of subarrays having sum less
    // than or equal to L-1.
    int Lcnt = countSub(nums, n, b - 1);

    cout << Rcnt - Lcnt << endl;
    return 0;
}