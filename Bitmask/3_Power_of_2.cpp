#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x;
    cin >> x;
    // if 0 is not edge case
    bool ok = (x & (x - 1)) == 0;

    // 0 can never be the power of 2;
    ok = (x != 0 and !(x & (x - 1)));
    return 0;
}