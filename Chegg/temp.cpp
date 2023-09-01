#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, d;
    cin >> n >> d;
    map<pair<string, string>, vector<int>> mp;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        string A, B;
        int ti;
        cin >> A >> B >> ti;
        mp[{A, B}].push_back(ti);
    }
    map<pair<string, string>, bool> visited;
    for (auto it : mp)
    {
        pair<string, string> p = {it.first.second, it.first.first};
        pair<string, string> p0 = {it.first.first, it.first.second};
        if (mp.find(p) != mp.end() and !visited[p] and !visited[p0])
        {
            visited[p] = true;
            visited[p0] = true;
            for (int num : it.second)
            {
                int start = num;
                for (int end : mp[p])
                {
                    if (end - start > 0 and end - start <= d)
                    {
                        ++cnt;
                    }
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;
}