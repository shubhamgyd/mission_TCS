/*
You are given an integer n in base 10, write an integer in base 9 representation
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string ans = "";
    while (n)
    {
        char ch = ((n % 9) + '0');
        n /= 9;
        ans.push_back(ch);
    }
    reverse(begin(ans), end(ans));
    cout << ans << endl;
    return 0;
}