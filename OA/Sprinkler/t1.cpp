#include <bits/stdc++.h>
using namespace std;

int thirdSmallestElement(int array_length, vector<int> &arr)
{
    sort(begin(arr), end(arr));
    return arr[2];
}

int scoreString(const string &str)
{
    int n = str.length();
    int score = 0;

    vector<int> prefixScore(n, 0);

    for (int i = 2; i < n; ++i)
    {
        if (str[i] == str[i - 3] && str[i - 1] == str[i - 2])
        {
            prefixScore[i] = prefixScore[i - 2] + 5;
        }
        if (i >= 3 && str[i] == str[i - 4] && str[i - 1] == str[i - 3])
        {
            prefixScore[i] = max(prefixScore[i], prefixScore[i - 3] + 10);
        }
        score += prefixScore[i];
    }

    return score;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> nums(n);
    long long int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        sum += nums[i];
    }
    long long int res = sum * n;
    cout << res << endl;
    return 0;
}