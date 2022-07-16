/*
You are given a license key represented as a string s that consists of only alphanumeric characters and dashes. The string is separated into n + 1 groups by n dashes. You are also given an integer k.

We want to reformat the string s such that each group contains exactly k characters, except for the first group, which could be shorter than k but still must contain at least one character. Furthermore, there must be a dash inserted between two groups, and you should convert all lowercase letters to uppercase.

Return the reformatted license key.



Example 1:

Input: s = "5F3Z-2e-9-w", k = 4
Output: "5F3Z-2E9W"
Explanation: The string s has been split into two parts, each part has 4 characters.
Note that the two extra dashes are not needed and can be removed.
*/

#include <bits/stdc++.h>
using namespace std;

string licenseKeyFormatting(string S, int K)
{
    string res;
    for (auto i = S.rbegin(); i < S.rend(); i++)
        if (*i != '-')
        { // ignore '-' in original string
            if (res.size() % (K + 1) == K)
                res += '-'; // every (K+1)th char is '-' from tail
            res += toupper(*i);
        }

    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    string str;
    cin >> str;
    int k;
    cin >> k;
    int cnt = 0;
    int n = str.length();
    string ans = "";
    for (int i = n - 1; i >= 0; i--)
    {
        if (str[i] != '-')
        {
            cnt++;
            ans.push_back(toupper(str[i]));
        }
        if (cnt == k)
        {
            ans.push_back('-');
            cnt = 0;
        }
    }
    reverse(ans.begin(), ans.end());
    if (ans[0] == '-')
        ans.erase(ans.begin() + 0);
    cout << ans << endl;
    return 0;
}