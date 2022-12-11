#include <bits/stdc++.h>
using namespace std;

int dp[10001][10001];
int solve(string s, int i, int j, int isTrue)
{
    int k, ans = 0;
    if (i > j)
        return true;
    if (i == j)
    {
        if (isTrue == 1)
            return s[i] == 'T';
        else
            return s[i] == 'F';
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    for (k = i + 1; k <= j - 1; k += 2)
    {
        int lt = solve(s, i, k - 1, 1);
        int lf = solve(s, i, k - 1, 0);
        int rf = solve(s, k + 1, j, 0);
        int rt = solve(s, k + 1, j, 1);

        if (s[k] == '&')
        {
            if (isTrue == 1)
                ans = ans + lt * rt;
            else
                ans = ans + (lf * rt) + (rf * lt) + (lf * rf);
        }
        else if (s[k] == '|')
        {
            if (isTrue == 1)
                ans += lt * rt + lf * rt + rf * lt;
            else
                ans += lf * rf;
        }
        else if (s[k] == '^')
        {
            if (isTrue == 1)
                ans += lt * rf + rt * lf;
            else
                ans += lt * rt + lf * rf;
        }
    }
    return dp[i][j] = ans;
}
int main()
{
    memset(dp, -1, sizeof(dp));
    string s;
    cout << "Enter the string:" << endl;
    cin >> s;
    cout << "the string is:" << s << endl;
    int i = 0, j = s.size() - 1;
    int isTrue;
    cout << "If we want true result put 1 else put 0:";
    cin >> isTrue;
    cout << "The number of ways you get the ans in TRUE:" << solve(s, i, j, isTrue);
}