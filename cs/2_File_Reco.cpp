#include <iostream>
#include <vector>
using namespace std;
#define int long long

void testCases()
{
    int n, k, s;
    cin >> n >> k;
    string str;
    cin >> str;
    int ans = 0;
    const int mod = 1e9 + 7;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < min(i + 1, (long long)10); j++)
        {
            if (str[i - j] != '0' and stoi(str.substr(i - j, j)) <= k)
            {
                dp[i] = (dp[i] + dp[i - j]) % mod;
            }
        }
    }
    cout << dp[n];
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    testCases();
    return 0;
}

// Read n, k from input
// Read str from input
// Initialize ans = 0
// Initialize mod = 1e9 + 7
// Create a vector dp of size n+1, initialized with 0
// Set dp[0] = 1

// for i = 1 to n:
//     for j = 1 to min(i+1, 10):
//         if str[i-j] is not '0' and stoi(str.substr(i-j, j)) <= k:
//             dp[i] = (dp[i] + dp[i-j]) % mod

// Print dp[n]

A vector dp of size n + 1 is created.This vector will store the intermediate results of the dynamic programming approach.

                        The initial value of dp[0] is set to 1 since an empty subsequence can be formed in one way.

                        The outer loop iterates from i = 1 to n.This loop represents the position of the current character in the string.

                                                         Inside the outer loop,
                                                     the inner loop iterates from j = 1 to the minimum of i + 1 and 10. This loop represents the length of the subsequence being considered.

                                                                                                                        The condition str[i - j] != '0' checks if the current character is not '0'.This condition ensures that the subsequence doesn 't start with ' 0'.

                                                                                                                                                        The condition
                                                                                                                                                        stoi(str.substr(i - j, j)) <= k checks if the subsequence formed by taking j characters from the previous positions is less than or
                                                                                      equal to k.This condition ensures that the subsequence value is within the allowed range.

                                                                                      If both conditions are satisfied,
                                                     the value of dp[i] is updated by adding dp[i - j] and taking the modulo mod.This represents the number of ways to form the current subsequence.

                                                                                                           After the loops complete,
                                                     the final result is stored in dp[n], which represents the total number of ways to form a subsequence of length n with a sum less than or equal to k.