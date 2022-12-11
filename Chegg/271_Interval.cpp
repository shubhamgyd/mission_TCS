#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    return a.second < b.second;
}

int main()
{
    // given intervals
    vector<pair<int, int>> jobs;
    // push all jobs into list of vectors where start time and end time is stored
    jobs.push_back({0, 3});
    jobs.push_back({2, 5});
    jobs.push_back({4, 7});
    // sort jobs according to the end time of each job
    sort(jobs.begin(), jobs.end(), cmp);
    // to get final non-overlapping jobs
    vector<pair<int, int>> ans;
    // push first job into ans
    ans.push_back(jobs[0]);
    // Iterate from 1 to n
    for (int i = 1; i < jobs.size(); i++)
    {
        // if last push job finish time is strictly less than the current start time
        // then append current job into list
        if (ans.back().second < jobs[i].first)
        {
            ans.push_back({jobs[i]});
        }
    }
    // print size of non-verlapping jobs
    cout << ans.size() << endl;
    // print valid jobs
    for (auto it : ans)
    {
        cout << it.first << " " << it.second << endl;
    }
}