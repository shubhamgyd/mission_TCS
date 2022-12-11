/*
Good morning! Here's your coding interview problem for today.

This problem was asked by Quantcast.

You are presented with an array representing a Boolean expression. The elements are of two kinds:

T and F, representing the values True and False.
&, |, and ^, representing the bitwise operators for AND, OR, and XOR.
Determine the number of ways to group the array elements using parentheses so that the entire expression evaluates to True.

For example, suppose the input is ['F', '|', 'T', '&', 'T']. In this case, there are two acceptable groupings: (F | T) & T and F | (T & T).
*/

#include <bits/stdc++.h>
using namespace std;

int dp[10001][10001];
// int solve(string str, int i, int j, int isTrue)
// {
//     // Base condition
//     if (i > j)
//         return true;
//     if (i == j)
//     {
//         if (isTrue)
//             return str[i] == 'T';
//         else
//             return str[i] == 'F';
//     }
//     int ans = 0;
//     if (dp[i][j] != -1)
//         return dp[i][j];
//     for (int k = i + 1; k <= j - 1; k += 2)
//     {
//         int leftTrue = solve(str, i, k - 1, 1);
//         int leftFalse = solve(str, i, k - 1, 0);
//         int rightTrue = solve(str, k + 1, j, 1);
//         int rightFalse = solve(str, k + 1, j, 0);
//         if (str[k] == '&')
//         {
//             if (isTrue)
//             {
//                 ans += leftTrue * rightTrue;
//             }
//             else
//             {
//                 ans += (leftFalse * rightTrue + leftTrue * rightFalse + leftFalse * rightFalse);
//             }
//         }
//         else if (str[k] == '|')
//         {
//             if (isTrue)
//             {
//                 ans += (leftTrue * rightTrue + leftTrue * rightFalse + leftFalse * rightTrue);
//             }
//             else
//             {
//                 ans += (leftFalse * rightFalse);
//             }
//         }
//         else if (str[k] == '^')
//         {
//             if (isTrue)
//             {
//                 ans += (leftFalse * rightTrue + leftTrue * rightFalse);
//             }
//             else
//             {
//                 ans += (leftFalse * rightFalse + leftTrue * rightTrue);
//             }
//         }
//     }
//     return dp[i][j] = ans;
// }

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
                ans += lt * rt;
            else
                ans += (lf * rt) + (rf * lt) + (lf * rf);
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
    string str;
    cin >> str;
    int n = str.length();
    cout << "Total ways: " << solve(str, 0, n - 1, 1);
    return 0;
}