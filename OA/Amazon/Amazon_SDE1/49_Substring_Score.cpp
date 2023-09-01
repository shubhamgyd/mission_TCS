/*
You are given a string S of length N, which contains only lowercase alphabets from 'a' to 'z'

Let's define the score of a string as xor of the occurrence of each character in the string

You are required to handle two types of queries:

1L R. You need to answer the score of the substring of S from

L to R

• 2 X Y: Update the character at position X to y 'a' to 'z alphabet from

ENG
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;
    unordered_map<char, int> mp;
    for (auto it : str)
    {
        mp[it]++;
    }
    int q;
    cin >> q;
    while (q--)
    {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1)
        {
        }
        else
        {
                }
    }
}