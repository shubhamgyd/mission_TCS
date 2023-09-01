#include <bits/stdc++.h>
using namespace std;

bool solve(vector<vector<bool>> &dp, int i, int j, string &s)
{
    if (i == j)
    {
        return dp[i][j] = true;
    }
    if (j - i == 1)
    {
        if (s[i] == s[j])
        {
            return dp[i][j] = true;
        }
        else
        {
            return dp[i][j] = false;
        }
    }
    if (s[i] == s[j] && dp[i + 1][j - 1] == true)
    {
        return dp[i][j] = true;
    }
    else
    {
        return dp[i][j] = false;
    }
}

int scoreString(string s)
{
    int n = s.size();
    int startIndex = 0;
    int cnt = 0;
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    for (int g = 0; g < n; g++)
    {
        for (int i = 0, j = g; j < n; i++, j++)
        {
            solve(dp, i, j, s);
            if (dp[i][j] == true)
            {
                if (j - i + 1 == 4)
                {
                    startIndex = i;
                    cnt += 5;
                }
                if (j - i + 1 == 5)
                {
                    cnt += 10;
                    startIndex = i;
                }
            }
        }
    }
    return cnt;
}

int main()
{
    string str;
    cin >> str;
    int result;
    result = scoreString(str);
    cout << result << endl;
    return 0;
}