#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int n = str.length();
    int cnt = 0;
    int i = 0;
    while (i < n)
    {
        if (str[i] != '0')
        {
            break;
        }
        i++;
    }
    while (i < n)
    {
        if (str[i] == '0')
        {
            cnt++;
        }
        i++;
    }
    cout << cnt << endl;
    return 0;
}