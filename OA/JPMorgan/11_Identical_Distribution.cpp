#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<string> vec)
{
    vector<int> res(vec.size());
    for (int j = 0; j < vec.size(); j++)
    {
        int ctr = 0;
        string s = vec[j];
        for (int i = 1; i < s.length();)
        {
            if (s[i] == s[i - 1])
            {
                ctr++;
                i += 2;
            }
            else
            {
                i++;
            }
        }
        res[j] = ctr;
    }
    return res;
}