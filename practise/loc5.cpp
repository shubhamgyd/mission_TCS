#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        string odd = "";
        string even = "";
        for (auto it : str)
        {
            int num = (it - '0');
            if (num % 2 == 0)
            {
                even.push_back(it);
            }
            else
            {
                odd.push_back(it);
            }
        }
        string ans = odd + even;
        cout << ans << endl;
    }
    return 0;
}