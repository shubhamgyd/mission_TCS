/*
wo strings word1 and word2 are considered almost equivalent if the differences between the frequencies of each letter from 'a' to 'z' between word1 and word2 is at most 3.

Given two strings word1 and word2, each of length n, return true if word1 and word2 are almost equivalent, or false otherwise.

The frequency of a letter x is the number of times it occurs in the string.



Example 1:

Input: word1 = "aaaa", word2 = "bccb"
Output: false
Explanation: There are 4 'a's in "aaaa" but 0 'a's in "bccb".
The difference is 4, which is more than the allowed 3.
Example 2:

Input: word1 = "abcdeef", word2 = "abaaacc"
Output: true
Explanation: The differences between the frequencies of each letter in word1 and word2 are at most 3:
- 'a' appears 1 time in word1 and 4 times in word2. The difference is 3.
- 'b' appears 1 time in word1 and 1 time in word2. The difference is 0.
- 'c' appears 1 time in word1 and 2 times in word2. The difference is 1.
- 'd' appears 1 time in word1 and 0 times in word2. The difference is 1.
- 'e' appears 2 times in word1 and 0 times in word2. The difference is 2.
- 'f' appears 1 time in word1 and 0 times in word2. The difference is 1.
Example 3:

Input: word1 = "cccddabba", word2 = "babababab"
Output: true
Explanation: The differences between the frequencies of each letter in word1 and word2 are at most 3:
- 'a' appears 2 times in word1 and 4 times in word2. The difference is 2.
- 'b' appears 2 times in word1 and 5 times in word2. The difference is 3.
- 'c' appears 3 times in word1 and 0 times in word2. The difference is 3.
- 'd' appears 2 times in word1 and 0 times in word2. The difference is 2.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkAlmostEquivalent(string str1, string str2)
    {
        unordered_map<char, int> mp1, mp2;
        for (char ch : str1)
        {
            mp1[ch]++;
        }
        for (char ch : str2)
        {
            mp2[ch]++;
        }
        for (auto it : mp1)
        {
            char ch = it.first;
            int f = it.second;
            int diff = abs(f - mp2[ch]);
            if (diff > 3)
            {
                return 0;
            }
        }
        for (auto it : mp2)
        {
            char ch = it.first;
            int f = it.second;
            int diff = abs(f - mp1[ch]);
            if (diff > 3)
            {
                return 0;
            }
        }
        return 1;
    }
};

int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    // Solution 1: Brute Force
    // sort both string and check
    // Time Complexity :O(nlogn)

    // Solution 2: Hash Map
    unordered_map<char, int> mp1, mp2;
    for (char ch : str1)
    {
        mp1[ch]++;
    }
    for (char ch : str2)
    {
        mp2[ch]++;
    }
    for (auto it : mp1)
    {
        char ch = it.first;
        int f = it.second;
        if (mp2.find(ch) == mp2.end())
        {
            cout << "No\n";
            return 0;
        }
        else
        {
            int diff = abs(f - mp2[ch]);
            if (diff > 3)
            {
                cout << "No\n";
                return 0;
            }
        }
    }
    cout << "Yes\n";
    return 0;
}