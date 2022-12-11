/*
Given List of String represnting each order, from 2 customers, and each character in the order
representing item, find if orders were similar.
Conditions for being similar, should be same in length and number of distinct characters should
not be more than 3.

Example - Input :
x : ["nnbnnb", "ammxdf"]
y : ["bbncbb", "aecxdf"]

Output : ["YES", "NO"]

x[0] is similar to y[0] as both same in length and
x[0] has 4 "n", y[0] has 1 "n", so delta is 3,
x[0] has 2 "b", y[0] has 2 "b", so delta is 2,
x[0] has 0 "c", y[0] has 1 "c", so delta is 1

***Personal note - You would better understand this, if you sort both strings,
then difference is only in 3 letters, not more than 3, hence both strings are similar
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> x(n), y(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    for (int j = 0; j < n; j++)
    {
        cin >> y[j];
    }
    for (int i = 0; i < n; i++)
    {
        int l1 = x[i].length();
        int l2 = y[i].length();
        if (l1 != l2)
        {
            cout << "NO\n";
        }
        else
        {
            int hash1[26];
            int hash2[26];
            memset(hash1, 0, sizeof(hash1));
            memset(hash2, 0, sizeof(hash2));
            for (auto it : x[i])
            {
                hash1[(it - 'a')]++;
            }
            for (auto it : y[i])
            {
                hash2[(it - 'a')]++;
            }
            int dis1 = 0;
            int dis2 = 0;
            for (int j = 0; j < 26; j++)
            {
                if (hash1[j])
                    dis1++;
            }
            for (int j = 0; j < 26; j++)
            {
                if (hash2[j])
                    dis2++;
            }
            bool ok = true;
            for (int j = 0; j < 26; j++)
            {
                if ((abs(hash1[j] - hash2[j]) > 3))
                {
                    ok = false;
                    break;
                }
            }
            if (dis1 > 3 or dis2 > 3)
            {
                ok = false;
            }
            if (ok)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
}