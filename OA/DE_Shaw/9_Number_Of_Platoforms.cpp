/*
Your friend Alex sends you the position of engine and rear coach of various trains present at a railway station. With the information you receive, can you compute the number of platforms of the railway station, given that the station is working at the top of its capacity, utilizing every available platform?

Function Description:
Complete the computePlatforms function in the editor below. It has the following parameters -
• An integer array named enginePositions representing the position of engine of various trains.
• An integer array named rearCoachPositions representing the position of rear coach of various trains.

You need to return an integer denoting the number of platforms of the railway station.

Constraints:
• 1<= |trains| <=1e5
• 1<= enginePositions <=1e9
• 1<= rearCoachPositions <=1e9

Input Format For Custom Testing:
The first line contains an integer, n, denoting the number of elements in enginePositions.
Each line i of the n subsequent lines (where 0<=i<=n) contains an integer describing enginePositionsi.
The next line contains an integer, denoting the number of elements in rearCoachPositions.
Each line j of the n subsequent lines (where 0<=i<=n) contains an integer describing rearCoachPositionsj.

Sample Input 0:
2
1
2
2
2
3

Sample Output 0:
2

Explanation 0:
There are two trains with
• Engines at 1st and 2nd positions : Rear coaches at 2nd and 3rd positions.
• The trains cannot be at the same platform since in that case the rear coach of first train and engine Of second train clash at position 2.
So, the answer is 2.

Sample Input 1:
2
1
3
2
2
4

Sample Output 1:
1

Explanation 1:
There are two trains with
• Engines at 1st and 3rd positions : Rear coaches at 2nd and 4th positions.
• The trains can be at the same platform with first train from 1-2 positions followed by the next train covering 3-4 positions.
So, the answer is 1.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> engine(n);
    for (int i = 0; i < n; i++)
    {
        cin >> engine[i];
    }
    int m;
    cin >> m;
    vector<int> coaches(m);
    for (int i = 0; i < m; i++)
    {
        cin >> coaches[i];
    }
    vector<pair<int, int>> interval;
    for (int i = 0; i < n; i++)
    {
        interval.push_back({engine[i], coaches[i]});
    }
    sort(begin(interval), end(interval));
    int cnt = 1;
    priority_queue<int> pq;
    pq.push(interval[0].second);
    for (int i = 1; i < n; i++)
    {
        if (interval[i].first <= pq.top())
        {
            cnt++;
        }
        else
        {
            pq.pop();
        }
        pq.push(interval[i].second);
    }
    cout << cnt << endl;
    return 0;
}