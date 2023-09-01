/*

You are given a string word and an array of strings forbidden.

A string is called valid if none of its substrings are present in forbidden.

Return the length of the longest valid substring of the string word.

A substring is a contiguous sequence of characters in a string, possibly empty.



Example 1:

Input: word = "cbaaaabc", forbidden = ["aaa","cb"]
Output: 4
Explanation: There are 11 valid substrings in word: "c", "b", "a", "ba", "aa", "bc", "baa", "aab", "ab", "abc"and "aabc". The length of the longest valid substring is 4.
It can be shown that all other substrings contain either "aaa" or "cb" as a substring.
Example 2:

Input: word = "leetcode", forbidden = ["de","le","e"]
Output: 4
Explanation: There are 11 valid substrings in word: "l", "t", "c", "o", "d", "tc", "co", "od", "tco", "cod", and "tcod". The length of the longest valid substring is 4.
It can be shown that all other substrings contain either "de", "le", or "e" as a substring.
*/

#include <bits/stdc++.h>
using namespace std;

// Intuition
// (1) Put all the forbidden strings in the hashmap.
// (2) For each i from n - 1 to 0 (in reverse order).
// (3) Check whether we have fobidden word by enumberating or the lengths from 1 to max_length_of_forbidden_word strting at i. Keep the valid right position.
// The key point is if [i..x] is invalid then [(i - 1)..x] is invalid too.

// Complexity
// Time complexity:
// O(n * max_length_of_forbidden_words ^ 2) the square is because hashmap is not free. It needs O(length) to calculate the hash value and find.

// Space complexity:
// O(sum of forbidden words length)

int solve(string word, vector<string> &forbidden)
{
    unordered_set<string> st;
    int len = 0;
    for (string str : forbidden)
    {
        st.insert(str);
        len = max(len, (int)str.length());
    }
    int n = word.length();
    int r = 0;
    for (int i = n - 1, right = n; right > r and i >= 0; i--)
    {
        string temp = "";
        int cnt = 0;
        for (int j = i; j < right and j - i < len; j++)
        {
            temp.push_back(word[j]);
            if (st.count(temp))
            {
                right = j;
                break;
            }
        }
        r = max(r, right - i);
    }
    return r;
}

int main()
{
    string word;
    cin >> word;
    int n;
    cin >> n;
    vector<string> forbidden(n);
    for (int i = 0; i < n; i++)
    {
        cin >> forbidden[i];
    }
    // Solution 1: Brute Force
    // Generate all possible substring and check valid one

    // Solution 2:
    cout << solve(word, forbidden) << endl;
}