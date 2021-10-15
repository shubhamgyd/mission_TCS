#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // sort(days.begin(),days.end());
        int n = days.back();
        vector<int> dp(n + 1);

        // initialization
        for (int& day: days)
            dp[day] = numeric_limits<int>::max();

        // dynamic programming
        for (int i = 1; i <= n; i++) {
            if (dp[i] == 0)
                dp[i] = dp[i - 1];
            else
                dp[i] = min({dp[i - 1         ] + costs[0],
                             dp[max(0, i -  7)] + costs[1],
                             dp[max(0, i - 30)] + costs[2]});
        }

        return dp[n];
        
    }
};