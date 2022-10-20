#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int lim = n * 2;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < lim; j++)
        {
            cout << "* ";
        }
        lim -= 2;
        if (i != n - 1)
        {
            cout << endl;
        }
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < lim; j++)
        {
            cout << "* ";
        }
        lim += 2;
        cout << endl;
    }
    return 0;
}