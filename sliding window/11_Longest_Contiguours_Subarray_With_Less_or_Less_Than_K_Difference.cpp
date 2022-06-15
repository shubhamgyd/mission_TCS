#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> res(n);
    for (int i = 0; i < n; i++)
    {
        cin >> res[i];
    }
    int i = 0;
    int j = 0;
    map<int, int> mp;
    int ans = 0;
    while (j < n)
    {
        mp[res[j]]++;
        auto it=mp.begin();
        auto it1=mp.end();
        it1--;
        int mx = it1->first;
        int mn = it->first;
        if (mx - mn <= k)
        {
            int range = j - i + 1;
            ans+=range;
        }
        else
        {
            while (i < j)
            {
                mp[res[i]]--;
                if (mp[res[i]] == 0)
                {
                    mp.erase(res[i]);
                }
                i++;
                auto it=mp.begin();
                auto it1=mp.end();
                it1--;
                int mx = it1->first;
                int mn = it->first;
                if (mx - mn <= k)
                {
                    int range=j-i+1;
                    ans+=range;
                }
            }
        }
        j++;
    }
    cout << ans << endl;
    return 0;
}