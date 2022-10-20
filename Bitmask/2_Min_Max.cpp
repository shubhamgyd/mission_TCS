#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;
    // If x is minimum
    int r = y ^ ((x ^ y) & -(x < y));

    // if y is maximum
    int r1 = x ^ ((x ^ y) & -(x < y));
    return 0;
}