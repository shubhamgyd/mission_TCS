/*
Implement an efficient string matching algorithm.

That is, given a string of length N and a pattern of length k, write a program that searches for the pattern in the string with less than O(N * k) worst-case time complexity.

If the pattern is found, return the start index of its location. If not, return False.
*/

// KMP Algorithm

#include <bits/stdc++.h>
using namespace std;

// In this problem we are going to search the pattern in the given string by using KMP  Algorithm

void ComputeArray(string pat, int lps[], int m)
{
    // Length of the previous longest prefix suffix
    int len = 0;

    // lps[0] is always 0
    lps[0] = 0;

    int i = 1;
    while (i < m)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else // pat[i]!=pat[j]
        {
            if (len != 0)
            {
                len = lps[len - 1];
                // Also, note that we do not increment
                // i here
            }
            else
            {
                lps[i] = 0;
                i += 1;
            }
        }
    }
}

void KMPSearch(string txt, string pat)
{
    int n = txt.length();
    int m = pat.length();

    int lps[m];
    ComputeArray(pat, lps, m);
    for (int i = 0; i < m; i++)
    {
        cout << lps[i] << " ";
    }
    cout << endl;
    int i = 0;
    int j = 0;
    while (i < n)
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }
        if (j == m)
        {
            cout << "Pattern matched at the index: " << i - j << endl;
            j = lps[j - 1];
        }
        // mismatch after j matches
        else if (i < n && pat[j] != txt[i])
        {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}

int main()
{
    string txt = "heavymetalisheavymetal";
    string pat = "metal";
    KMPSearch(txt, pat);
}
