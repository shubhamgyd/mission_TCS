#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    unordered_map<string, int> mp;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        if (mp.find(str) != mp.end())
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
        mp[str]++;
    }
    return 0;
}