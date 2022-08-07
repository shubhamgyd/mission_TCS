#include <bits/stdc++.h>
using namespace std;

int main()
{
    int candies, n;
    cin >> candies >> n;
    vector<int> res(n);
    for (int i = 0; candies > 0; ++i)
    {
        res[i % n] += min(candies, i + 1);
        candies -= i + 1;
    }
    for (auto it : res)
    {
        cout << it << " ";
    }
    cout << endl;
}