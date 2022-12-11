/*

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    long uniqueDigits(long L, long R)
    {
        return (L <= R ? unique(R) - unique(L - 1) : 0);
    }

    long unique(long n)
    {
        if (n < 10)
            return max(n + 1L, 0L);

        vector<long> dp(1024, 0);
        n = min(n, 9876543210L); // the largest number with unique digits
        int len = 0;
        long tmp = n, T = 1, ans = 0, fact = 9, mult = 10;

        while (tmp > 0)
        {
            tmp /= 10;
            len++;
            if (tmp == 0)
                break;
            T *= 10;
            ans += fact + (len == 1 ? 1 : 0);
            mult--;
            fact *= mult;
        }

        int offset = 0;
        bool test = true;
        for (len--; len >= 0; len--)
        {
            int digit = (n / T) % 10;
            T /= 10;

            vector<long> dp2(1024, 0);
            for (int e = 1023; e > 1; e--)
                for (int d = 0; d < 10; d++)
                    if ((e >> d) % 2 == 0)
                        dp2[e + (1 << d)] += dp[e];

            if (test)
            {
                int last = (len == 0 ? digit : digit - 1);
                for (int d = 0; d <= last; d++)
                    if ((offset >> d) % 2 == 0)
                        dp2[offset + (1 << d)]++;

                if ((offset >> digit) % 2 == 1)
                    test = false;
                offset += (1 << digit);
            }

            dp.swap(dp2);
        }
        for (int e = 0; e < 1024; e++)
            ans += dp[e];
        return ans;
    }
};

int main(void)
{

    Solution *s = new Solution;

    cout << s->uniqueDigits(0, 1000) << endl;
    cout << s->uniqueDigits(2552, 8722) << endl;
    cout << s->uniqueDigits(52120, 781177) << endl;
    cout << s->uniqueDigits(0, 10000000000L) << endl;
    return 0;
}