/*
You are given a string that represents time in the format hh:mm. Some of the digits are
blank (represented by ?). Fill in ? such that the time represented by this string is the maximum possible. Maximum time: 23:59, minimum time: 00:00. You can assume that input string is always valid.

Example 1:

Input: "?4:5?"
Output: "14:59"
Example 2:

Input: "23:5?"
Output: "23:59"
Example 3:

Input: "2?:22"
Output: "23:22"
Example 4:

Input: "0?:??"
Output: "09:59"
Example 5:

Input: "??:??"
Output: "23:59"
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;
    if (str[0] == '?')
    {
        if (str[1] == '?')
        {
            str[0] = '2';
            str[1] = '3';
        }
        else
        {
            str[0] = (str[1] > '3' ? '1' : '2');
        }
    }
    if (str[1] == '?')
    {
        str[1] = (str[0] <= '1' ? '9' : '3');
    }

    if (str[3] == '?')
        str[3] = '5';
    if (str[4] == '?')
        str[4] = '9';
    cout << str << endl;
}