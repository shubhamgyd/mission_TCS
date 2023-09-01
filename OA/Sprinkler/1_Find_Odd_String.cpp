/*
Find the odd one string of given set of strings
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> res(n);
    for (int i = 0; i < n; i++)
    {
        cin >> res[i];
    }
    map<string, vector<vector<int>>> mp;
    for (string str : res)
    {
        int prevDiff = 0, nextDiff = 0;
    }
    for (auto it : mp)
    {
        if (it.second.size() == 1)
        {
            cout << it.first << endl;
            return 0;
        }
    }
}