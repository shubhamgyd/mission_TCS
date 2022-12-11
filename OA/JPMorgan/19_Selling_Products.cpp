/*
The salesperson can remove as many mitems from the Determine the minimum number
 of different IDs the bag contain performing, most, m deletions

Example

Solve question

Two possible actions

Remove with ID= and final will contain item

and the final will contain item ids' [1, 1, 2]

The minimum number of distinct IDs is 2.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int ids[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> ids[i];
    }
    int m;
    cin >> m;
    unordered_map<int, int> mp;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; ++i)
    {
        ++mp[ids[i]];
    }
    for (auto it : mp)
    {
        pq.push(it.second);
    }
    int cnt = 0;
    while (!pq.empty() and m > 0)
    {
        m -= pq.top();
        if (m >= 0)
        {
            pq.pop();
        }
    }
    cout << pq.size() << endl;
}