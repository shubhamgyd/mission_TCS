#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int n = str.length();
    unordered_map<char, int> mp;
    for (auto it : str)
    {
        mp[it]++;
    }
    string ans = "";
    int i = 0;
    unordered_map<char, bool> visited;
    while (i < n)
    {
        if (!visited[str[i]])
        {
            visited[str[i]] = true;
            int freq = mp[str[i]];
            ans.push_back(str[i]);
            ans += to_string(freq);
            int j = i;
            while (j < n and str[i] == str[j])
            {
                j++;
            }
            i = j;
        }
        else
        {
            i++;
        }
    }
    cout << ans << endl;
    return 0;
}