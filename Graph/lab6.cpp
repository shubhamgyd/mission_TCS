#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> table;
    int solve1(vector<int> &nums, int pID, int i, int state)
    {
        if (i == nums.size())
            return 1;
        if (table[pID + 1][state] != -1)
            return table[pID + 1][state];
        int cnt = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (state & (1 << j))
                continue;
            if (pID == -1 || nums[pID] % nums[j] == 0 || nums[j] % nums[pID] == 0)
                cnt += solve1(nums, j, i + 1, state | (1 << j));
            cnt %= 1000000007;
        }
        table[pID + 1][state] = cnt;
        return table[pID + 1][state];
    }

    int specialPerm(vector<int> &nums)
    {

        // long long int cnt=0;
        // sort(begin(nums),end(nums));
        // const int mod=1e9+7;
        // do{
        //     bool ok=true;
        //     for(int i=0;i<n-1;i++){
        //         if(nums[i]%nums[i+1]!=0 and nums[i+1]%nums[i]!=0){
        //             ok=false;
        //             break;
        //         }
        //     }
        //     if(ok) cnt=(cnt+1LL)%mod;
        // }while(next_permutation(nums.begin(),nums.end()));
        // return (int)cnt;

        //         vector<vector<int>>arr;
        //         do{arr.push_back(nums);
        //         }while(perms(nums));
        //         int cnt=0;
        //         for(vector<int>&a:arr){
        //             bool ok=true;
        //             for (int i = 0; i < a.size() - 1; i++) {
        //                 if (a[i] % a[i + 1] != 0 && a[i + 1] % a[i] != 0) {ok=false;break;}
        //             }
        //             if(ok){cnt++;cnt%=mod;}
        //         }
        //         return cnt;

        table.resize(20, vector<int>((1 << 14) + 5, -1));
        return solve1(nums, -1, 0, 0);
    }
};

class Solution
{
public:
    unsigned long long int solve(vector<int> &cost, vector<int> &time, int i, int tm, vector<vector<int>> &dp)
    {
        if (i == cost.size())
        {
            return (tm >= 0) ? 0 : 1e15;
        }
        if (tm >= 500)
        {
            tm = 500;
        }
        if (dp[i][tm + 500] != -1)
        {
            return dp[i][tm + 500];
        }
        unsigned long long int cst = solve(cost, time, i + 1, tm + time[i], dp) + cost[i];
        unsigned long long int cst2 = solve(cost, time, i + 1, tm - 1, dp);
        cst = min(cst, cst2);
        dp[i][tm + 500] = cst;
        return cst;
    }

    bool cmp(pair<int, int> &num1, pair<int, int> &num2)
    {
        if (num1.first == num2.first)
            return num1.second > num2.second;
        return num1.first < num2.first;
    }

    int paintWalls(vector<int> &cost, vector<int> &time)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        vector<pair<int, int>> nums;
        for (int i = 0; i < cost.size(); i++)
            nums.push_back({cost[i], time[i]});
        sort(begin(nums), end(nums), cmp);
        for (int i = 0; i < cost.size(); i++)
        {
            int a = nums[i].first;
            int b = nums[i].second;
            cost[i] = a;
            time[i] = b;
        }
        vector<vector<int>> dp(cost.size() + 5, vector<int>(1024, -1));
        return solve(cost, time, 0, 0, dp);
    }
};

long long solve(vector<int> &nums)
{
    long long int cnt = 0;
    int n = nums.size();
    int t = 0;
    int f = 0;
    for (int i = 0; i < 32; i++)
    {
        t = 0, f = 0;
        for (int j = 0; j < n; j++)
        {
            if (nums[j] % 2 == 0)
            {
                t++;
            }
            else
            {
                f++;
            }
            nums[j] /= 2;
        }
        cnt += (t * f * (pow(2, i)));
    }
    return cnt;
}

long long contributions(int n, vector<int> &arr)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int> ans[3];
    for (int i = 0; i < n; i++)
    {
        ans[arr[i] % 3].push_back(arr[i]);
    }
    long long int cnt = 0;
    for (int i = 0; i < 3; i++)
    {
        cnt += solve(ans[i]);
    }
    return cnt;
}

// int secretcode(vector<int> &a)
// {
//     int n = a.size();
//     for (int i = 0; i <= n - 3; i++)
//     {
//         if ((a[i] + a[i + 1] + a[i + 2]) % 10 == 0)
//             return 1;
//     }
//     return 0;
// }

// int directedSoldiers(int n, vector<int> &a)
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     int right = 0;
//     int cnt = 0;

//     for (int i = 0; i < n; i++)
//     {
//         if (a[i] == 1)
//         {
//             right++;
//         }
//         else if (right > 0)
//         {
//             cnt++;
//             right--;
//         }
//     }

//     return cnt;
// }

long long superMovement(int n, vector<int> &a, int k)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long cnt = 0;
    int prev = 0;
    vector<long long int> res(k - 1, INT_MAX);
    for (int i = 0; i < n - 1; i++)
    {
        if (prev == k - 1)
        {
            prev = 0;
            continue;
        }
        long long int steps = abs(a[i] - a[i + 1]);
        res[prev] = min(res[prev], steps);
        prev++;
    }
    for (auto it : res)
    {
        cnt += it;
    }
    return cnt;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << superMovement(n, a, k) << endl;
    return 0;
}