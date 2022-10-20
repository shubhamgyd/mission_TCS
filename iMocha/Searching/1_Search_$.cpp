#include <bits/stdc++.h>
using namespace std;

int solve(string str)
{
    map<char, int> mp;
    for (auto it : str)
    {
        mp[it]++;
    }
    if (mp.find('0') == mp.end() or mp.find('1') == mp.end() or mp.find('2') == mp.end())
    {
        return 0;
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string str;
    cin >> str;
    if (str.length() == n)
        cout << "N" << endl;
    int ans = solve(str);
    cout << ans << endl;
    return 0;
}