/*
Adding two large numbers represented by string having commas. Comma is separator for thousand, millions, billions and so on.
e.g. Input:
num1 = "123,456,788.00"
num2 = "1"

Output: "123,456,789.00"

Note Number might be 20 or 30 digits long.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    bool f1 = false, f2 = false;
    for (char ch : str1)
    {
        if (ch == '.')
        {
            f1 = true;
        }
    }
    for (char ch : str2)
    {
        if (ch == '.')
        {
            f2 = true;
        }
    }
    if (f1 and f2)
    {
        string ans = "";
        int i = str1.length() - 1;
        int j = str2.length() - 1;
        int carry = 0;
        while (i >= 0 and j >= 0)
        {
            if (str1[i] == ',' and str2[j] == ',')
            {
                i--;
                j--;
                continue;
            }
            else if (str1[i] == ',')
            {
                ans.push_back(',');
                i--;
            }
            else if (str2[j] == ',')
            {
                ans.push_back(',');
                j--;
            }
            int num = (str1[i] - '0') + (str2[j] - '0') + carry;
            carry = num % 10;
            int rem = num / 10;
            char ch = rem + '0';
            ans.push_back(ch);
            i--;
            j--;
        }
        if (carry)
        {
            char ch = carry + '0';
            ans.push_back(ch);
        }
        cout << ans << endl;
    }
    else
    {
        string ans = "";
        int i = str1.length() - 1;
        int j = str2.length() - 1;
        if (f1)
        {
            while (i >= 0 and str1[i] != '.')
            {
                ans.push_back(str1[i]);
                i--;
            }
            ans.push_back('.');
        }
    }
}