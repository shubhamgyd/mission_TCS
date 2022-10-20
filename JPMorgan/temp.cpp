#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> markets(m);
    for (int i = 0; i < m; i++)
    {
        cin >> markets[i];
    }
    vector<vector<int>> res(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> res[i][j];
        }
    }
    vector<int> adj[n];

    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;

// int passes(char *input1)
// {
//     int n = strlen(input1);
//     int cnt = 0;
//     int i = 0;
//     while (i < n - 1)
//     {
//         int steps = 0;
//         if (input1[i] == 'A')
//         {
//             i += 2;
//         }
//         else if (input1[i] == 'B')
//         {
//             i--;
//         }
//         cnt++;
//         if (i >= n - 1)
//             break;
//     }
//     return cnt;
// }

// int main()
// {
//     char str[] = "AABAAA";
//     cout << passes(str);
//     // string str;
//     // cin >> str;
//     // int n = str.size();
//     // int cnt = 0;
//     // int i = 0;
//     // while (i < n - 1)
//     // {
//     //     int steps = 0;
//     //     if (str[i] == 'A')
//     //     {
//     //         i += 2;
//     //     }
//     //     else if (str[i] == 'B')
//     //     {
//     //         i--;
//     //     }
//     //     cnt++;
//     //     if (i >= n - 1)
//     //         break;
//     // }
//     // cout << cnt << endl;
//     return 0;
// }