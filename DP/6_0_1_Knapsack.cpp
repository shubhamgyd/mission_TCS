// 0/1 knapsack

// 0/1 knapsack main pieces repeated nhi hone chahiye

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Bottom Up DP
int knapSack(int W, int wt[], int val[], int n)
{
    // Your code here
    int dp[n + 1][W + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (wt[i - 1] <= j)
            {
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    vector<int> ans;
    int i = n;
    int j = dp[n][W];
    return dp[n][W];
}

ll dp[1005][1005];
// Recursive Approach
ll knapsack(int n, int w, int weights[], int prices[])
{
    // Base case
    if (n == 0 || w == 0)
    {
        return 0;
    }

    if (dp[n][w] != -1)
    {
        return dp[n][w];
    }

    ll include = 0;
    ll exclude = 0;

    if (weights[n - 1] <= w)
    {
        // Include the current index element
        include = prices[n - 1] + knapsack(n - 1, w - weights[n - 1], weights, prices);
    }

    // Exclude the current element
    exclude = knapsack(n - 1, w, weights, prices);

    dp[n][w] = max(include, exclude);

    return dp[n][w];
}
/*
Time Complexity: O(n*weight)
Space Somplexity: O(n*weight)
*/

int main()
{
    int wt[] = {5, 5, 5};
    int val[] = {1, 10, 100};
    int W = 5;
    int n = 3;
    memset(dp, -1, sizeof(dp));
    cout << "Maximum total Value of the given knapsack is: " << knapSack(W, wt, val, n) << endl;
    cout << "Maximum total Value of the given knapsack is: " << knapsack(n, W, wt, val) << endl;
    return 0;
}