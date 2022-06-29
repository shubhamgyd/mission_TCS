

#include <bits/stdc++.h>
using namespace std;

int mxLength(vector<int> &nums)
{
    set<int> s;
    for (auto a : nums)
    {
        if (s.find(a) != s.end())
            continue;
        s.insert(a);
        auto it = s.upper_bound(a);
        if (it != s.end())
            s.erase(it);
    }
    return s.size();
}

int lengthOfLIS(vector<int> &nums)
{
    vector<int> res;
    for (int i = 0; i < nums.size(); i++)
    {
        auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
        if (it == res.end())
            res.push_back(nums[i]);
        else
            *it = nums[i];
    }
    return res.size();
}

int lis(int arr[], int n)
{
    int lis[n];

    lis[0] = 1;

    // Compute optimized LIS values in
    // bottom up manner
    for (int i = 1; i < n; i++)
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
    }

    // Return maximum value in lis[]
    return *max_element(lis, lis + n);
}

// Printing Longest Increasing Subsequence
void printSubsequence(int arr[], int n)
{
    vector<int> dp(n, 1);
    int hash[n];
    for(int i=0;i<n;i++) hash[i]=i;
    for (int i = 1; i < n; i++)
    {
        hash[i] = i;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] and dp[j] + 1 > dp[i])
            {
                dp[i] = dp[j] + 1;
                hash[i] = j;
            }
        }
    }
    int mx = 0;
    int ind = 0;
    for (int i = 0; i < n; i++)
    {
       
        if (dp[i] > mx)
        {
            mx = dp[i];
            ind = i;
        }
    }
    
    vector<int> res;
    res.push_back(arr[ind]);
    while (hash[ind] != ind)
    {
        ind = hash[ind];
        res.push_back(arr[ind]);
    }
    reverse(res.begin(), res.end());
    for (auto it : res)
    {
        cout << it << " ";
    }
}
int main()
{
    int arr[3] = {1, 2, 2};
    printSubsequence(arr, 3);
}