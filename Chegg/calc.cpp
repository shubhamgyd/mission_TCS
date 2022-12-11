#include <bits/stdc++.h>
using namespace std;

char lostCharNW(string stringSent, string stringRec)
{
    map<char, int> mp;
    int n = stringSent.length();
    for (int i = 0; i < n; i++)
    {
        mp[stringSent[i]]++;
    }
    n = stringRec.length();
    char ch;
    for (int i = 0; i < n; i++)
    {
        if (mp.find(stringRec[i]) != mp.end())
        {
            mp[stringRec[i]]--;
            if (mp[stringRec[i]] == 0)
            {
                mp.erase(stringRec[i]);
            }
        }
    }
    ch = mp.begin()->first;
    return ch;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string a, b;
    cin >> a >> b;
    cout << lostCharNW(a, b) << endl;
    return 0;
}