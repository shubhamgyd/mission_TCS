#include <bits/stdc++.h>
using namespace std;

int main()
{
    unsigned int x, y;
    cin >> x >> y;
    // Comnmnpute x%y;
    unsigned int mask = (1U << y);
    unsigned int res = (x & (mask - 1));
    cout << res << endl;
    return 0;
}