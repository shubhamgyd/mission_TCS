// Min number of coins required to make given sum
#include <bits/stdc++.h>
using namespace std;

int CountCoin(int coin[], int sum, int n)
{
    int dp[n + 1][sum + 1]; // Initialization f array

    for (int i = 0; i <= n; i++) // Filling the every row of first column as 0
    {
        dp[i][0] = 0; // zero sum chahiye to min 0 ways hi lagenge
    }
    for (int i = 1; i <= sum; i++) // Filling the evry column first row as INT_MAX-1
    {
        dp[0][i] = INT_MAX - 1; // coin zero hai to infinite number of zero coins chahiye honge tbhi not possible
    }

    // Optional twist
    // Twist
    // Here by filling second row of every column , we have to check wheather the given number is
    //     divided by coing[0] or not. If it is divided then we fill this block as the reminder \
    //of that division , Otherwise if this number is not divided by coin[0] , fill as INT_MAX-1
    /*
    It's not about gfg or leetcode. 2nd row initialization is actually not needed.
    If it's not possible to get the required sum using the denomination, the code will
     put INT_MAX - 1 in that cell from the above row.
    Note: it'll put INT_MAX-1 and not INT_MAX because it'll compare: min(1+(INTMAX-1), INT_MAX-1)
    here 1st INT_MAX is from the same row and 2nd one is from above row and same column.
    */
    for (int j = 1; j <= sum; j++)
    {

        if (j % coin[0] == 0)
            dp[1][j] = j / coin[0];
        else
            dp[1][j] = INT_MAX - 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (coin[i - 1] <= j)
            {
                // Here we have to choose the minimum number of coins between maximum number of ways
                // to make the given sum
                dp[i][j] = min((dp[i][j - coin[i - 1]] + 1), dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    // If coins array contains only limited coins
    // i.e of array contains 2 as a coins and we want 3 as a sum then that time
    // we returned -1 as ans.
    if (dp[n][sum] == INT_MAX - 1)
        return -1;
    // Otherwise rest of things same as previous
    return dp[n][sum];
}

/*
Bottom UP DP
Time Complexity :
T(n)=O(sum*n);

Space : O(sum*n)
*/

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int coin[] = {3, 5};
    int sum = 7;
    int n = sizeof(coin) / sizeof(coin[0]);
    cout << "Minimum number of coins required to make given sum: " << CountCoin(coin, sum, n) << "\n";
    return 0;
}

int mostWordsFound(vector<string> &sentences)
{
    int ct = 0;
    for (auto it : sentences)
    {
        stringstream ss(it);
        string word;
        int temp = 0;
        while (ss >> word)
        {
            temp++;
        }
        ct = max(ct, temp);
    }
    return ct;
}

/*
int minCoins(int coins[], int M, int V)
    {
        // Your code goes here
        int dp[M+1][V+1];
        for(int i=0;i<=M;i++)
        {
            dp[i][0]=0;
        }
        for(int j=1;j<=V;j++)
        {
            dp[0][j]=INT_MAX-1;
        }

        for(int i=1;i<=M;i++)
        {
            for(int j=1;j<=V;j++)
            {
                if(coins[i-1]<=j)
                {
                    dp[i][j]=min(dp[i-1][j],dp[i][j-coins[i-1]]+1);
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[M][V]==INT_MAX-1?-1:dp[M][V];
    }

*/