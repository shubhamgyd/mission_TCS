#include <bits/stdc++.h>
using namespace std;
#define int long long int

int required_days(int sum, vector<int>&nums) 
{
    vector<vector<int>> dp(nums.size() + 1, vector<int>(sum + 1, 0));

    for (int i = 0; i <= sum; i++)
    {
        dp[0][i] = INT_MAX - 1; 
    }

    for (int i = 1; i <= nums.size(); i++)
    {
        for (int k = 1; k <= sum; ++k)
        {
            if (nums[i - 1] > k)
            {
                dp[i][k] = dp[i - 1][k];
            }
            else
            {
                dp[i][k] = min(dp[i - 1][k], dp[i][k - nums[i - 1]] + 1);
            }
        }
    }

    if (dp[nums.size()][sum] == INT_MAX - 1)
    {
        return -1;
    }

    else
    {
        return dp[nums.size()][sum]; 
    }
}

signed main()
{
    int target, k;
    cin >> target;
    cin >> k;
    vector<int>primes;
    int isPrime = 2;
    int cnt = k;
    while (true)
    {
        bool ok = false;
        for (int i = 2; i <= sqrt(isPrime ); i++)
        {
            if (isPrime % i == 0)
            {
                ok = true;
                break;
            }
        }
        if (!ok) 
        {
            primes.push_back(isPrime);
            cnt--;
        }
        isPrime++;
        if (cnt <= 0)
        {
            break;
        }
    }
    int days=required_days(target,primes);
    cout<<days<<endl;
    return 0;
}