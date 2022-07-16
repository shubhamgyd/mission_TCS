/*
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane
and an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance
(i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique
(except for the order that it is in).
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; i++)
    {
        cin >> points[i].first >> points[i].second;
    }
    int k;
    cin >> k;

    // Using Brute Force
    vector<pair<int, pair<int, int>>> dist;
    for (int i = 0; i < n; i++)
    {
        int x = points[i].first;
        int y = points[i].second;
        int dis = x * x + y * y;
        dist.push_back({dis, {x, y}});
    }
    sort(dist.begin(), dist.end());
    for (int i = 0; i < k; i++)
    {
        cout << "[" << dist[i].second.first << " " << dist[i].second.second << "],";
    }
    cout << endl;
    // T:O(nlogn+ n)
    // S:O(n)

    // Using priority_queue
    vector<vector<int>> vs;
    priority_queue<pair<int, pair<int, int>>> pq;
    // int n=points.size();
    for (int i = 0; i < n; i++)
    {
        pq.push({points[i].first * points[i].first + points[i].second * points[i].second, {points[i].first, points[i].second}});
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    // cout<<"K closest element to the origin are: "<<endl;
    while (!pq.empty())
    {
        // cout<<pq.top().second.first<<" "<<pq.top().second.second<<endl;
        vs.push_back({pq.top().second.first, pq.top().second.second});
        pq.pop();
    }
    for (auto it : vs)
    {
        cout << "[" << it[0] << " " << it[1] << ",]";
    }
    cout << endl;
    // T:O(nlgon)
    // S:O(k)
}