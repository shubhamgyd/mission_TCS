/*
Given an array of integers where each element represents the max number of steps that 
can be made forward from that element. Write a function to return the minimum number of 
jumps to reach the end of the array (starting from the first element). If an element is
0, they cannot move through that element. If the end isn’t reachable, return -1.

Examples: 

Input: arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}
Output: 3 (1-> 3 -> 8 -> 9)
Explanation: Jump from 1st element 
to 2nd element as there is only 1 step, 
now there are three options 5, 8 or 9. 
If 8 or 9 is chosen then the end node 9 
can be reached. So 3 jumps are made.

*/

#include <bits/stdc++.h>
using namespace std;

// Recursive Method
int minJumps(int arr[], int n)
{
    //base case
    // when source and destination are the same
    if (n == 1)
    {
        return 0;
    }
    // Traverse through all the points
    // reachable from arr[l]
    // Recursively, get the minimum number
    // of jumps needed to reach arr[h] from
    // these reachable points
    int res = INT_MAX;
    for (int i = n - 2; i >= 0; i--)
    {
        if (i + arr[i] >= n - 1)
        {
            int sub_res = minJumps(arr, i + 1);
            if (sub_res != INT_MAX)
            {
                res = min(res, sub_res + 1);
            }
        }
    }
    return res;
}
// Time Complexity:O(n^n)
// Space Complexity:O(1)













// Memoization
int dp[101];
int minJumps1(int arr[], int n)
{
    //base case
    // when source and destination are the same
    if (n == 1)
    {
        return 0;
    }
    // Traverse through all the points
    // reachable from arr[l]
    // Recursively, get the minimum number
    // of jumps needed to reach arr[h] from
    // these reachable points
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int res = INT_MAX;
    for (int i = n - 2; i >= 0; i--)
    {
        if (i + arr[i] >= n - 1)
        {
            int sub_res = minJumps1(arr, i + 1);
            if (sub_res != INT_MAX)
            {
                res = min(res, sub_res + 1);
            }
        }
    }
    return dp[n] = res;
}
// This solution is little bit optimise , i.e we avoid revursive calls
// Time Complexity:O(n*n)
// Space complexity(n)

















// DP Optimise Solution
int minJumps2(int A[], int n)
{
    long long jumps[n + 1];
    jumps[0] = 0LL;
    const long long N = 1e12 + 9;
    for (int i = 1; i < n; i++)
    {
        jumps[i] = N;
        for (int j = 0; j < i; j++)
        {
            if (i <= (j + A[j]) && jumps[i] > (jumps[j] + 1))
            {
                jumps[i] = jumps[j] + 1;
            }
        }
    }
    return (jumps[n - 1] == N ? -1 : jumps[n - 1]);
}

int jump(vector<int> &A)
{
    long long jumps[A.size() + 1];
    jumps[0] = 0LL;
    const long long N = 1e12 + 9;
    for (int i = 1; i < A.size(); i++)
    {
        jumps[i] = N;
        for (int j = 0; j < i; j++)
        {
            if (i <= (j + A[j]) && jumps[i] > (jumps[j] + 1))
            {
                jumps[i] = jumps[j] + 1;
                //break;
            }
        }
    }
    return (jumps[A.size() - 1] == N ? -1 : jumps[A.size() - 1]);
}
// Time complexity:O(n*n)
// space complexity:O(n)
















int minJumps3(int arr[], int n)
{
    if (arr[0] <= 0)
    {
        return -1;
    }
    if (n <= 1)
    {
        return 0; // jump 0
    }
    pair<int, int> interval{0, 0}; //  Initial interval to jump .......for checking the interval max value
    int jump = 0;                  // Initial jump i.e. we are at -1 th position ( not in array )

    // Loop run infinite , until any brek/return come
    while (true)
    {
        jump++;             // Whenever we proceed forward , jump increases
        int can_reach = -1; //
        // For finding the maximum reached_position , by using this loop and interval of previously declares
        for (int i = interval.first; i <= interval.second; ++i)
        {
            can_reach = max(can_reach, i + arr[i]); // Here i+arr[i] means i is the number of steps we have
                                                    // already jump and arr[i] means we can jump more this num
        }

        // If maximum can_reached position greater than equal to number of elements
        // then return the jumps
        // It means if we are at the last position or beyond the stairs
        if (can_reach >= n - 1)
        {
            return jump;
        }

        // Next interval is  previous internal.second + 1 to can_reached position,
        // and we have to again check the maximum can reached position in
        // newly created intevrval
        // i.e 2,4 we have to check the check the maxumum int between index 2 to 4
        interval = {interval.second + 1, can_reach};

        // condition like 1,0 so in this case we can return -1
        // Means no further move is possible
        if (interval.first > interval.second)
        {
            return -1;
        }
    }
    return -1;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int arr[] = {1, 3, 6, 3, 2,
                 3, 6, 8, 9, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> v(arr, arr + n);
    cout << "Minimum number of jumps to";
    cout << " reach the end is " << minJumps3(arr, n);
    // cout << "Minimum number of jumps to";
    // cout << " reach the end is " << jump(v);
    return 0;
}