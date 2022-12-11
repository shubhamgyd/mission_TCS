/*
Given two strings, one is a subsequence if all of the elements of the first string occur in the
same order within the second string. They do not have to be contiguous in the second string,
but order must be maintained. For example, given the string 'I like cheese', the words Cr', 'cheese')
are one possible subsequence of that string. Words are space delimited.

Given two strings, s and t, where t is a subsequence of s, report the words of s, missing in
t (case sensitive), in the order they are missing.



Example


S='I like cheese'


t='like'

Test R

Then 'like' is the subsequence, and ['I', 'cheese'] is the list of missing words, in order.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s, t;
    getline(cin, s);
    getline(cin, t);
    unordered_map<string, int> mp;
    stringstream ss(s);
    string word;
    while (ss >> word)
    {
        mp[word]++;
    }
    stringstream ss1(t);
    while (ss1 >> word)
    {
        mp[word]--;
        if (mp[word] == 0)
        {
            mp.erase(word);
        }
    }
    stringstream newS(s);
    while (newS >> word)
    {
        if (mp.find(word) != mp.end())
        {
            cout << word << endl;
        }
    }
    return 0;
}