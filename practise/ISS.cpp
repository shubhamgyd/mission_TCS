#include <bits/stdc++.h>
#define int long long
using namespace std;

int solve(int coin[], int sum, int n)
{
    int dp[n + 1][sum + 1];

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= sum; i++)
    {
        dp[0][i] = INT_MAX - 1;
    }
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
                dp[i][j] = min((dp[i][j - coin[i - 1]] + 1), dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    if (dp[n][sum] == INT_MAX - 1)
    {
        return -1;
    }
    return dp[n][sum];
}

class Float
{
public:
    int num;
    void getNum()
    {
        cout << num << endl;
    }
};

signed main()
{
    Float obj;
    obj.getNum();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int peebles;
    cin >> peebles;
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = solve(arr, peebles, n);
    cout << ans << endl;
    return 0;
}