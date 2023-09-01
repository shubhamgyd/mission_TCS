#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    string str;
    cin >> str;
    char ch;
    cin >> ch;
    int cnt = 0;
    for (char it : str)
    {
        if (tolower(it) == tolower(ch))
        {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}