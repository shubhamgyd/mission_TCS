#include <bits/stdc++.h>
using namespace std;


int main()
{
    // Input of test cases
    int t;
    cin >> t;
    int test=1;
    while (t--)
    {
        cout << endl;
        // Input of three strings
        string x, y, z;
        cin >> x;
        cin >> y;
        cin >> z;

        // Finding the length of three strings
        int m = x.length();
        int n = y.length();
        int o = z.length();

        // Dp table which fills bottom up manner
        int dp[m + 1][n + 1][o + 1];
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                for (int k = 0; k <= o; k++)
                {
                    // if i=0 or j=0 or k=0
                    // then fill dp[i][j][k]=0
                    if (i == 0 || j == 0 || k == 0)
                    {
                        dp[i][j][k] = 0;
                    }
                    
                    // If we found same char in all three substring then increment 
                    // counter plus previous commoon subsequece length
                    else if (x[i - 1] == y[j - 1] && x[i - 1] == z[k - 1])
                    {
                        dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                    }
                    
                    // Else fetch the previous maximum length of common subsequence
                    else
                    {
                        dp[i][j][k] = max(max(dp[i - 1][j][k],dp[i][j - 1][k]),dp[i][j][k - 1]);
                    }
                }
            }
        }
        // Print the common subsequence length
        cout<<"Case "<<test++<<": "<<dp[m][n][o]<<endl;
    }
}