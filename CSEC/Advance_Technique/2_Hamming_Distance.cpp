// https://en.wikipedia.org/wiki/Hamming_distance

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> res(n);
    for (int i = 0; i < n; i++)
    {
        cin >> res[i];
    }
    int mn = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        string str = res[i];
        for (int j = i + 1; j < n; j++)
        {
            string s = res[j];
            int diff = 0;
            for (int k = 0; k < s.length(); k++)
            {
                if (str[k] != s[k])
                {
                    diff++;
                }
            }
            mn = min(mn, diff);
        }
    }
    cout << mn << endl;
}