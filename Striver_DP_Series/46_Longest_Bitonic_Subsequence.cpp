/*
Problem Statement
You are given an array/list 'ARR' consisting of 'N' positive integers. A subsequence of 'ARR' is called bitonic if it is first increasing and then decreasing.
For Example:
An example of a bitonic sequence will be 1 < 2 < 3 < 4 > 2 > 1.
Your task is to return the length of the longest bitonic sequence of 'ARR'.
A subsequence of an array is an ordered subset of the array's elements having the same sequential ordering as the original array.
For Example:
Let ARR = [1, 2, 1, 2, 1]

One of the bitonic subsequences for this array will be [1, 2, 2, 1].
Input Format
The first line of input contains an integer ‘T’ denoting the number of test cases to run. Then the test case follows.

The first line of each test case contains a single integer ‘N’ denoting the number of integers in the array/list.

The second line of each test case contains ‘N’ single space-separated integers, denoting the elements of the array.
Output Format :
For each test case, print an integer denoting the length of the longest bitonic sequence.

Output for each test case will be printed in a new line. 
Note:
You don’t need to print anything; it has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 5
1 <= N <= 10^3
1 <= ARR[i] <= 10^5

Time Limit: 1sec
Sample Input 1 :
2
5 
1 2 1 2 1
5 
1 2 1 3 4
Sample Output 1:
4
4
*/


#include<bits/stdc++.h>
using namespace std;


int longestBitonicSequence(vector<int>& arr, int n) {
	  // Write your code here.	  
    vector<int> dp(n, 1),dp1(n,1);

    for (int i = 1; i < n; i++)
    {

        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] and dp[j] + 1 > dp[i])
            {
                dp[i] = dp[j] + 1;
            }
        }
    }
     for (int i = n-1; i >=0; i--)
    {
      
        for (int j = n-1; j>i; j--)
        {
            if (arr[i] > arr[j] and dp1[j] + 1 > dp1[i])
            {
                dp1[i] = dp1[j] + 1;
            }
        }
    }
    int mx=0;
    for(int i=0;i<n;i++)
    {
        mx=max(mx,dp[i]+dp1[i]-1);
    }
    return mx;
} 
