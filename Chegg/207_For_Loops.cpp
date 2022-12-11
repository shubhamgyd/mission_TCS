#include <bits/stdc++.h>
using namespace std;

// int countPalindrome(string s)
// {
//     int n = s.length();
//     int dp[n][n];
//     int count = 0;
//     for (int i = n - 1; i >= 0; i--)
//     {
//         for (int j = i; j < n; j++)
//         {
//             if (i == j)
//             {
//                 dp[i][j] = 1;
//             }
//             else if (i + 1 == j)
//             {
//                 dp[i][j] = s[i] == s[j] ? 1 : 0;
//             }
//             else
//             {
//                 dp[i][j] = s[i] == s[j] ? dp[i + 1][j - 1] : 0;
//             }
//             count += dp[i][j];
//         }
//     }
//     return count;
// }

long getMaximumSumOfHeights(vector<int> &maxHeights)
{
    int n = maxHeights.size();
    long cnt = 0;
    for (int i = 0; i < n; i++)
    {
        bool okLeft = true;
        bool okRight = true;
    }
}

int main()
{
    string str;
    cin >> str;
    // cout << countPalindrome(str) << endl;
    return 0;
}