#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    string str;
    getline(cin, str);
    int cnt = 0;
    priority_queue<string> pq;
    int i = 0;
    int n = str.length();
    while (i < n)
    {
        if (str[i] == ' ' or (str[i] >= 'a' and str[i] <= 'z') or (str[i] >= 'A' and str[i] <= 'Z'))
        {
            i++;
            continue;
        }
        int j = i;
        string s = "";
        bool ok = true;
        while (j < n and str[j] >= '0' and str[j] <= '9')
        {
            if (str[j] == '9')
            {
                ok = false;
            }
            else
            {
                s += str[j];
            }
            j++;
        }
        if (ok)
        {
            pq.push(s);
        }
        i = j;
    }
    if (!pq.empty())
    {
        cout << pq.top() << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}