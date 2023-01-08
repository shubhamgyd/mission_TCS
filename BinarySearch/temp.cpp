#include <bits/stdc++.h>
using namespace std;
void ComputeArray(string pat, int lps[], int m)
{
    int len = 0;

    lps[0] = 0;

    int i = 1;
    while (i < m)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i += 1;
            }
        }
    }
}

int KMPSearch(string txt, string pat)
{
    int n = txt.length();
    int m = pat.length();
    int ans = 0;
    int lps[m];
    ComputeArray(pat, lps, m);
    int i = 0;
    int j = 0;
    while (i < n)
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }
        if (j == m)
        {
            j = lps[j - 1];
            ans++;
        }
        else if (i < n && pat[j] != txt[i])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    return ans;
}

int solution(vector<int> &numbers, vector<int> &pattern)
{
    int n = numbers.size();
    int m = pattern.size();
    vector<int> ans;
    for (int i = 1; i < n; i++)
    {
        if (numbers[i] > numbers[i - 1])
        {
            ans.push_back(1);
        }
        else if (numbers[i] == numbers[i - 1])
        {
            ans.push_back(0);
        }
        else
        {
            ans.push_back(-1);
        }
    }
    string txt = "";
    for (auto it : ans)
    {
        txt += to_string(it);
    }
    string pat = "";
    for (auto it : pattern)
    {
        pat += to_string(it);
    }
    return KMPSearch(txt, pat);
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int m;
    cin >> m;
    vector<int> patt(m);
    for (int i = 0; i < m; i++)
    {
        cin >> patt[i];
    }
    cout << solution(nums, patt) << endl;
    return 0;
}