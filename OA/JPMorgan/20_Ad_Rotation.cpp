/*
An e-commerce advertisements the ads are stored in structure they are displayed or not based
on value bit position number. The sequence of ads being displayed at this can represented
as a binary where 1 means the displayed and means is hidden. The ads should rotate,
 on the next page load, ads that are displayed now are hidden and vice versa.

Given base integer representing the current representation. Starting position of
highest order bit, negate that all lower order from to 0. Return base representation the result.

Example: 10-30

3010-000111102

111102 preceding zeros discarded.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string str = "";
    while (n)
    {
        if (n & 1)
            str += '1';
        else
            str += '0';
        n >>= 1;
    }
    // cout << str << endl;
    reverse(begin(str), end(str));
    for (int i = 0; i < str.length(); ++i)
    {
        if (str[i] == '0')
            str[i] = '1';
        else
            str[i] = '0';
    }
    int num = stoi(str, 0, 2);
    cout << num << endl;
    return 0;
}