// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     string str;
//     cin >> str;
//     map<char, int> mp;
//     for (auto &i : str)
//     {
//         mp[i]++;
//     }
//     int mx = 0;
//     for (auto &it : mp)
//     {
//         if (it.second > mx)
//         {
//             mx = it.second;
//         }
//     }
//     map<char, int> occurs;
//     for (auto &it : mp)
//     {
//         if (it.second == mx)
//         {
//             occurs[it.first]++;
//         }
//     }
//     int n = str.length();
//     for (int i = 0; i < n; i++)
//     {
//         if (occurs.find(str[i]) != occurs.end())
//         {
//             cout << str[i] << endl;
//             break;
//         }
//     }

//     int count[256] = {0};

//     int len = strlen(str);
//     int max = 0;
//     char result;
//     for (int i = 0; i < len; i++)
//     {
//         count[str[i]]++;
//         if (max < count[str[i]])
//         {
//             max = count[str[i]];
//             result = str[i];
//         }
//     }

//     return result;
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string w;
    cin >> w;
    int vow = 0, cnt = 0, m[123] = {};
    string vowels("aeiou");
    for (int i = 0, j = 0, k = 0; i < w.size(); ++i)
    {
        if (vowels.find(w[i]) != string::npos)
        {
            vow += ++m[w[i]] == 1;
            for (; vow == 5; ++k)
            {
                vow -= --m[w[k]] == 0;
            }
            cnt += k - j;
        }
        else
        {
            m['a'] = m['e'] = m['i'] = m['o'] = m['u'] = vow = 0;
            j = k = i + 1;
        }
    }
    cout << cnt << endl;
    return 0;
}
