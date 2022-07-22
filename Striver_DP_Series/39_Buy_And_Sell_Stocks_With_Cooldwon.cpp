/*
Problem Statement
You are given a list of stock prices, ‘prices’. Where ‘prices[i]’ represents the price on ‘i’th day. Your task is to calculate the maximum profit you can earn by trading stocks if you can only hold one stock at a time. After you sell your stock on the ‘i’th day, you can only buy another stock on ‘i + 2’ th day or later.
For Example:
You are given prices = {4, 9, 0, 4, 10}, To get maximum profits you will have to buy on day 0 and sell on day 1 to make a profit of 5, and then you have to buy on day 3  and sell on day 4 to make the total profit of 11. Hence the maximum profit is 11.
Input Format:
The first line of input contains a single integer ‘T’, representing the number of test cases.

The first line of each test case contains, a single integer ‘N’ representing the length of the ‘prices’ array.

The second line of each test case contains ‘N’ space-separated integers representing the elements of the array ‘prices’.
Output Format:
For each test case, print a single integer representing the maximum possible profit you can get from the stocks.

Print a separate line for each test case.
Constraints:
1 <= T <= 10
1 <= N <= 10^6
1 <= |prices[i]| <= 10^8

Time Limit: 1 sec
Note :
You do not need to print anything. It has already been taken care of. Just implement the given function.
Sample Input 1:
2
5
4 9 0 4 10
4
1 2 3 4
Sample Output 1:
11
3
*/

#include <bits/stdc++.h>
using namespace std;

// Same as Q.36 Just One more condition we have to add that is
// cooldown period it means after selling on ith day
// we can't buy stock on (i+1)th day, but yes we can buy it on (i+2)th day

long solve(int i, int buy, vector<int> &value, int n, vector<vector<long>> &dp)
{
    if (i >= n)
        return 0;
    if (dp[i][buy] != -1)
        return dp[i][buy];
    long profit = 0;
    if (buy)
    {
        profit = max(-value[i] + solve(i + 1, 0, value, n, dp), solve(i + 1, 1, value, n, dp));
    }
    else
    {
        profit = max(value[i] + solve(i + 2, 1, value, n, dp), solve(i + 1, 0, value, n, dp));
    }
    return dp[i][buy] = profit;
}
int stockProfit(vector<int> &prices)
{
    // Write your code here.
    int n = prices.size();
    vector<vector<long>> dp(n + 5, vector<long>(2, -1));
    return solve(0, 1, prices, n, dp);
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
}