#include <bits/stdc++.h>
using namespace std;

void DFS(int i, int j, char ch, int len, vector<string> &ans)
{
    for (int k = j; k < j + len; k++)
    {
        ans[i][k] = ch;
    }

    for (int k = j; k < j + len; k++)
    {
        ans[i + len - 1][k] = ch;
    }
    for (int k = i + 1; k < i + len - 1; k++)
    {
        ans[k][j] = ch;
        ans[k][j + len - 1] = ch;
    }
}

int main()
{
    int n;
    cin >> n;
    int len = 2 * n;
    string str = string(2 * n, '*');
    vector<string> ans;
    for (int i = 0; i < 2 * n; i++)
    {
        ans.push_back(str);
    }
    int i = 0;
    int j = 0;
    for (char ch = ('A' + n - 1); ch >= 'A'; ch--)
    {
        DFS(i, j, ch, len, ans);
        len -= 2;
        i++;
        j++;
    }
    for (auto it : ans)
    {
        cout << it << endl;
    }
    return 0;
}