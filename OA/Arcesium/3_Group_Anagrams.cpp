/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.



Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]
*/

#include <bits/stdc++.h>
using namespace std;

// Use an unordered_map to group the strings by their sorted counterparts.
// Use the sorted string as the key and all anagram strings as the value.

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mp;
        for (string s : strs)
        {
            string t = s;
            sort(t.begin(), t.end());
            mp[t].push_back(s);
        }
        vector<vector<string>> anagrams;
        for (auto p : mp)
        {
            anagrams.push_back(p.second);
        }
        return anagrams;
    }
};
// Moreover, since the string only contains lower - case alphabets, we can sort them using
// counting sort to improve the time complexity.

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mp;
        for (string s : strs)
        {
            mp[strSort(s)].push_back(s);
        }
        vector<vector<string>> anagrams;
        for (auto p : mp)
        {
            anagrams.push_back(p.second);
        }
        return anagrams;
    }

private:
    string strSort(string s)
    {
        int counter[26] = {0};
        for (char c : s)
        {
            counter[c - 'a']++;
        }
        string t;
        for (int c = 0; c < 26; c++)
        {
            t += string(counter[c], c + 'a');
        }
        return t;
    }
};