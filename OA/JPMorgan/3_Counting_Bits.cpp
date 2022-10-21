#include <bits/stdc++.h>
using namespace std;

vector<int> CountingBits(int n)
{
    vector<int> vec;
    vector<int> res;
    int ctr;
    while (n > 0)
    {
        if (n % 2 == 1)
        {
            ctr++;
        }
        vec.push_back(n % 2);
        n = n / 2;
    }
    reverse(vec.begin(), vec.end());
    res.push_back(ctr);

    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == 1)
        {
            res.push_back(i + 1);
        }
    }
    return res;
}