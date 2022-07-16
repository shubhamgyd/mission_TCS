#include <bits/stdc++.h>
using namespace std;

int countPt(int r, int p, int i, int j)
{
    if (i * p > j)
        return 0;
    else if (r == 0)
        return 1;
    return countPt(r - 1, p, i + 1, j) + countPt(r - 1, p, i, j + 1);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int r, p;
        cin >> r >> p;
        int temp = countPt(r, p, 0, 0);
    }
}