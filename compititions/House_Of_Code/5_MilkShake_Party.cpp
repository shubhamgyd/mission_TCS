#include<bits/stdc++.h>
using namespace std;
#define int long long


int n, m, k;
vector<int>prices, protein;
int dp[1028][1028][8];

int recursion(int i, int m, int k) {
    if (i == n)
        return 0;

    int ans = 0;
    if (dp[i][m][k] != -1)
        return dp[i][m][k];

    if (m - prices[i] >= 0) {
        if (k) {
            ans = max(ans, protein[i] + recursion(i + 1, m - (prices[i] / 2), k - 1));
        }

        ans = max(ans, protein[i] + recursion(i + 1, m - prices[i], k));

    } else if (m - (prices[i] / 2) >= 0 && k) {
        ans = max(ans, protein[i] + recursion(i + 1, m - (prices[i] / 2), k - 1));
    }
    ans = max(ans, recursion(i + 1, m, k));

    return dp[i][m][k] = ans;
}

signed main() {
    cin >> n >> m >> k;
    memset(dp, -1, sizeof(dp));
    prices.resize(n);
    protein.resize(n);
    for (int i = 0 ; i < n; i++) cin >> prices[i];
    for (int i = 0 ; i < n; i++) cin >> protein[i];

    cout << recursion(0, m, k) << "\n";


    return 0;
}