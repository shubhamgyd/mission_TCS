#include <bits/stdc++.h>
using namespace std;

int countBoxes(string digits, vector<string> passwords)
{
    int openBoxes = 0;
    bool flag = true;
    array<int, 10> digitsFreq;
    for (auto &digit : digits)
    {
        digitsFreq[digit - '0']++;
    }
    for (auto &password : passwords)
    {
        if (password.length() > digits.length())
        {
            continue;
        }
        array<int, 10> passwordFreq;
        for (auto &ch : password)
        {
            passwordFreq[ch - '0']++;
        }
        flag = true;
        for (int i = 0; i <= 9; i++)
        {
            if (digitsFreq[i] < passwordFreq[i])
            {
                flag = false;
                break;
            }
        }
        if (flag)
            openBoxes++;
    }
    return openBoxes;
}