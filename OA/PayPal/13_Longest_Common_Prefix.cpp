/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
*/

#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    if (strs.size() == 0)
    {
        return "";
    }
    if (strs.size() == 1)
    {
        return strs[0];
    }
    sort(strs.begin(), strs.end());
    int end = min(strs[0].size(), strs[strs.size() - 1].size());
    int i = 0;
    string start = strs[0], last = strs[strs.size() - 1];
    while (i < end && start[i] == last[i])
    {
        i++;
    }
    return start.substr(0, i);
}