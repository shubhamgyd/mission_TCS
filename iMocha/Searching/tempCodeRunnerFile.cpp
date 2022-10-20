#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int n = str.length();
    for (int i = n - 1; i >= 0; i--)
    {
        char ch = str[i];
        int ind = n - i - 1;
        int charInd = (ch - 'a');
        int resInd = ind + charInd;
        resInd %= 26;
        char newChar = (resInd + 'a');
        str[i] = newChar;
    }
    cout << str << endl;
    return 0;
}