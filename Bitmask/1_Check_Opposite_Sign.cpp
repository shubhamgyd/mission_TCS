#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;
    bool ok = ((x ^ y) < 0);
    cout << ok << endl;
    return 0;
}