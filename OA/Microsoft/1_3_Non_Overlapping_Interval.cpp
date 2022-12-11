/*
Three new health care buildings are to be built in HackerLand. They will be built on land with plots
numbered consecutively starting from 1. There are two integer arrays starting, ending, each of size n,
that represent= n intervals where the ith interval is [starting[], ending[i]]. Determine the number
of ways three non overlapping intervals can be selected from

the nintervals.

Note:

An interval is defined as [where it contains every integer between /tor

•Two intervals [7] and [2] (121 overlap if there is an integer that is contained in both of them.
For example, [2. 51. [3, 8) overlap because 3. 4. 5. are common to both, whereas [15], [8, 9] do
non-overlapping

interval sets must be distinct. At least one Interval must be different for two sets to be distinct.
For example interval sets [[1, 2] [S 41 and [[3 41 21 sbare the same intervals in a different priser
so they are not
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> intervals(n);
    for (int i = 0; i < n; i++)
    {
        cin >> intervals[i].first >> intervals[i].second;
    }
    sort(begin(intervals), end(intervals), [](pair<int, int> &a, pair<int, int> &b)
         {
        if(a.first==b.first){
            return a.second<b.second;
        }
        else return a.first<b.first; });
}