#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int ones = __builtin_popcount(n);
    vector<int> ans;
    ans.push_back(ones);
    string str = "";
    for (int i = 31; i >= 0; i--)
    {
        int k = n >> i;
        if (k & 1)
            str.push_back('1');
        else
            str.push_back('0');
    }
    int i = 0;
    int len = str.length();
    int ind = -1;
    while (i < len)
    {
        if (str[i] == '1' and ind == -1)
        {
            ans.push_back(1);
            ind = 2;
            break;
        }
        i++;
    }
    i++;
    while (i < len)
    {
        if (str[i] == '1')
        {
            ans.push_back(ind);
        }
        ind++;
        i++;
    }
    for (auto it : ans)
    {
        cout << it << endl;
    }
    return 0;
}