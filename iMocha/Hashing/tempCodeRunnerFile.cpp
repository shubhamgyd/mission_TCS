#include <bits/stdc++.h>
using namespace std;

int minParentheses(string p)
{
    int bal = 0;
    int ans = 0;

    for (int i = 0; i < p.length(); ++i)
    {
        bal += p[i] == '(' ? 1 : -1;
        if (bal == -1)
        {
            ans += 1;
            bal += 1;
        }
    }

    return bal + ans;
}

int solve(string str)
{
    int matched = 0;
    int cnt = 0;
    for (int i = 0; i < str.length(); i++)
    {
        matched += (str[i] == '(' ? 1 : -1);
        if (matched == -1)
        {
            cnt += 1;
            matched += 1;
        }
    }
    return cnt + matched;
}
int find_mistake(int *nums, int nums_length)
{
    int miss = 0;
    int db = 0;
    map<int, int> mp;
    for (int i = 0; i < nums_length; i++)
    {
        mp[nums[i]]++;
    }
    for (int i = 1; i <= nums_length; i++)
    {
        if (mp.find(i) == mp.end())
        {
            miss = i;
        }
        else
        {
            if (mp[i] == 2)
            {
                db = i;
            }
        }
    }
    return miss + db;
}

int ascii_deletion_distance(string str1, string str2)
{
    map<char, int> mp, mp1;
    for (auto it : str1)
    {
        mp[it]++;
    }
    for (auto it : str2)
    {
        mp1[it]++;
    }
    int dis = 0;
    for (auto it : str1)
    {
        if (mp1.find(it) == mp1.end())
        {
            dis += int(it);
        }
    }
    for (auto it : str2)
    {
        if (mp.find(it) == mp.end())
        {
            dis += int(it);
        }
    }
    return dis;
}

int main()
{

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << find_mistake(arr, n) << endl;
    return 0;
}
