#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        vector<pair<int, int>> nums(10);
        for (int i = 0; i < 10; i++)
        {
            cin >> nums[i].first >> nums[i].second;
        }
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        for (auto it : nums)
        {
            pq.push({it.first + it.second, {it.first, it.second}});
        }
        int totalIcereams = 0;
        while (!pq.empty() and a and b)
        {
            int mnA = pq.top().second.first;
            int mnB = pq.top().second.second;
            pq.pop();
            int mn = min(mnA, mnB);
            int res = min(a / mn, b / mn);
            totalIcereams += res;
            a -= res;
            b -= res;
        }
        cout << totalIcereams << endl;
    }
    return 0;
}