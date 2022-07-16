/*
You are given an array of strings arr. A string s is formed by the concatenation of a
subsequence of arr that has unique characters.

Return the maximum possible length of s.

A subsequence is an array that can be derived from another array by deleting some or
 no elements without changing the order of the remaining elements.



Example 1:

Input: arr = ["un","iq","ue"]
Output: 4
Explanation: All the valid concatenations are:
- ""
- "un"
- "iq"
- "ue"
- "uniq" ("un" + "iq")
- "ique" ("iq" + "ue")
Maximum length is 4.
Example 2:

Input: arr = ["cha","r","act","ers"]
Output: 6
Explanation: Possible longest valid concatenations are "chaers" ("cha" + "ers") and
"acters" ("act" + "ers").
Example 3:

Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
Output: 26
Explanation: The only string in arr has all 26 characters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int ans = 0;
    static bool duplicates(string s)
    {
        set<char> st(s.begin(), s.end());
        return st.size() != s.length();
    }
    void solve(string str, int ind, vector<string> &arr, int n)
    {
        int size = str.length();
        ans = max(ans, size);
        for (int i = ind; i < n; i++)
        {
            string curr_s = str + arr[i];
            if (!duplicates(curr_s))
            {
                solve(curr_s, i + 1, arr, n);
            }
        }
    }

public:
    int maxLength(vector<string> &arr)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int n = arr.size();
        solve("", 0, arr, n);
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<string> str(n);
    for (int i = 0; i < n; i++)
    {
        cin >> str[i];
    }
    int len = 0;
    string s = "";
    
    cout << len << endl;
}