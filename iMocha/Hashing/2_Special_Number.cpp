#include <bits/stdc++.h>
using namespace std;

string updateString(string str)
{
    unordered_map<char, char> mp;
    mp['1'] = '!';
    mp['2'] = '@';
    mp['3'] = '#';
    mp['4'] = '$';
    mp['5'] = '%';
    mp['6'] = '^';
    mp['7'] = '&';
    mp['8'] = '*';
    mp['9'] = '?';
    mp['0'] = '+';
    mp[' '] = '-';
    for (int i = 0; i < str.length(); i++)
    {
        str[i] = mp[str[i]];
    }
    return str;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string str;
    getline(cin, str);
    cout << str.length() << endl;
    string ans = updateString(str);
    cout << ans << endl;
    return 0;
}