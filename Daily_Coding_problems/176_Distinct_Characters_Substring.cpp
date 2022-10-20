/*
Given a string, s, return the total number of substrings that only contain one distinct
character.

Ex: Given the following string s…

s = "aabbc", return 7. ("a", "aa", "a", "b", "bb", "b", "c").
Ex: Given the following string s…

s = "aaa", return 6.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int n = str.length();
    int i = 0;
    int ans = 0;
    while (i < n)
    {
        int j = i;
        int cnt = 0;
        while (j < n and str[i] == str[j])
        {
            cnt++;
            j++;
        }
        ans += (cnt * (cnt + 1)) / 2;
        i = j;
    }
    cout << ans << endl;
    return 0;
}