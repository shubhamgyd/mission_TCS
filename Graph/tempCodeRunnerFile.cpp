#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int p = log2(n) + 1;
        int X = n + 1;
        for (int i = 0; i < p; i++)
        {
            int count = 0;
            if (n & (1 << i))
            {
                count++;
            }
            if (count > (n / 2))
            {

                X += (1 << i);
            }
        }
        cout<<(n^X)<<endl;
    }
    return 0;
}