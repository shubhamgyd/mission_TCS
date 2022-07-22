/*
Problem Statement
You are Harshad Mehta’s friend. He told you the price of a particular stock for the next ‘N’ days. You can either buy or sell a stock. Also, you can only complete at most 2-transactions. Find the maximum profit that you can earn from these transactions. You can take help from Mr. Mehta as well.
Note
1. Buying a stock and then selling it is called one transaction.
2. You are not allowed to do multiple transactions at the same time. This means you have to sell the stock before buying it again.
Input Format:
The first line contains a single integer 'T' representing the number of test cases.
Then 'T' test cases follow:

The first line of each test case contains an integer 'N' denoting the number of days.

The second line of each test case contains 'N' space-separated integers, where the 'i-th' element is the price of the particular stock on the 'i-th' day.
Output Format :
For each test case, the first and only line of output contains an integer denoting the maximum profit.

The output of every test case is printed in a separate line.
Note:
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 10
1 <= N <= 5 * 10^4
0 <= price <= 10^3

Where ‘price’ is the price of the stock on each day.

Time Limit: 1 sec
Sample Input 1:
1
7
3 3 5 0 3 1 4
Sample Output 1:
6
*/

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
int dp[100005][2][3];
int solve(int i, int buy, int k, int n, vector<int> &prices)
{
    if (i == n)
        return 0;
    if (k < 0)
        return 0;
    if (dp[i][buy][k] != -1)
        return dp[i][buy][k];
    int profit = 0;
    if (buy)
    {
        profit = max(-prices[i] + solve(i + 1, 0, k - 1, n, prices), solve(i + 1, 1, k, n, prices));
    }
    else
    {
        profit = max(prices[i] + solve(i + 1, 1, k, n, prices), solve(i + 1, 0, k, n, prices));
    }
    return dp[i][buy][k] = profit;
}
// Time Complexity:O(n*2*2)
// Space Coomplexity:O(N*2*2+N)

int maxProfit(vector<int> &prices, int n)
{
    // Write your code here.
    //     int k=2;
    //     memset(dp,-1,sizeof(dp));
    //     return solve(0,1,k,n,prices);

    vector<vector<vector<int>>> dp(n + 2, vector<vector<int>>(2, vector<int>(3, 0)));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int k = 1; k <= 2; k++)
            {
                int profit = 0;
                if (buy == 1)
                {
                    profit = max(-prices[i] + dp[i + 1][0][k], dp[i + 1][1][k]);
                }
                else
                {
                    profit = max(prices[i] + dp[i + 1][1][k - 1], dp[i + 1][0][k]);
                }
                dp[i][buy][k] = profit;
            }
        }
    }
    return dp[0][1][2];
}
// Time Complexity:O(n*2*2)
// Space Complexity:O(n*2*n)

// Space optimize
int maxProfit(vector<int> &prices, int n)

{

    if (prices.size() == 0)
    {

        return 0;
    }

    int fb = INT_MIN, sb = INT_MIN;

    int fs = 0, ss = 0;

    for (int i = 0; i < prices.size(); i++)
    {

        fb = max(fb, -prices[i]);

        fs = max(fs, fb + prices[i]);

        sb = max(sb, fs - prices[i]);

        ss = max(ss, sb + prices[i]);
    }

    return ss;
}

int main()
{
    int n;
    cin >> n;
    vector<int> res(n);
    for (int i = 0; i < n; i++)
    {
        cin >> res[i];
    }
}