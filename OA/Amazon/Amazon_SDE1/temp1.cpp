#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<int, int> mp;
    vector<pair<int, char>> res(n);
    for (int i = 0; i < n; i++)
    {
        int id;
        char ch;
        cin >> id >> ch;
        mp[id] = i;
        res[i] = {id, ch};
    }
    vector<pair<int, char>> temp = res;
    sort(begin(temp), end(temp));
    string ans = "";
    int i = 0;
    bool isCheck = false;
    map<int, vector<string>> pq;
    while (i < n)
    {
        if (temp[i].second == '-' and !isCheck)
        {
            isCheck = true;
            i++;
        }
        else
        {
            if (isCheck)
            {
                int tot = 0;
                int j = i;
                string ans = "";
                while (j < n and temp[j].second != '-')
                {
                    ans.push_back(temp[j].second);
                    tot += abs(j - mp[temp[j].first]);
                    j++;
                }
                if (temp[j].second == '-')
                {
                    isCheck = false;
                    pq[tot].push_back(ans);
                }
                i = j;
            }
            else
            {
                i++;
            }
        }
    }
    bool ok = false;
    if (pq.find(0) != pq.end())
    {
        ok = true;
        for (auto it : pq[0])
        {
            cout << it << endl;
        }
    }
    if (!ok)
    {
        cout << pq.begin()->second[0] << endl;
    }
    return 0;
}