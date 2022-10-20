/*
Given an array of words and a string of characters, chars, return the sum of the lengths of words that can be formed using only the chars.
Note: Each character within chars can only be used once.

Ex: Given the following words and chars…

words = ["abc", "cab"], chars = "bac", return 6 ("abc"'s length + "cab"'s length).
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
    }
    string chars;
    cin >> chars;
    sort(begin(chars), end(chars));
    int len = 0;
    for (auto it : words)
    {
        sort(begin(it), end(it));
        if (it == chars)
            len += it.length();
    }
    cout << len << endl;
    return 0;
}