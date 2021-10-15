#include<bits/stdc++.h>
using namespace std;

/*
https://leetcode.com/problems/maximum-profit-in-job-scheduling/discuss/409188/C%2B%2B-with-picture
Algorithm
1.Use a map to store job start times and the maximum profit (zero, initially).
2.Use an unordered map to store start time and job information.
    We will use this unordered map to look-up jobs by their start time.
3.Since times in the map are sorted, process each time point right to left:
    a.Lookup job information in the unordered map by the start time.
    b.Set the maximum profit as the greater of:
        i.Running maximum profit.
        ii.Job profit plus maximum profit at the end of the job.
    c.Update the running maximum profit.
4.Return the running maximum profit.


Instead of using a hash map to store job information, we could pack it to the same map, 
like map<int, pair<int, vector<pair<int, int>>>> jobs;. It would probably be a good idea 
to define some struct for the value type, or readability would suffer.
*/

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        map<int,int>times;
        unordered_map<int,vector<pair<int,int>>>jobs;
        for(int i=0;i<startTime.size();i++)
        {
            times[startTime[i]]=0;
            jobs[startTime[i]].push_back({endTime[i],profit[i]});
        }
        int max_profit=0;
        for(auto it=rbegin(times);it!=rend(times);++it)
        {
            for(auto job:jobs[it->first])
            {
                auto it=times.lower_bound(job.first);
                max_profit=max(max_profit,(it==end(times)?0:it->second)+job.second);
            }
            it->second=max_profit;
        }
        return max_profit;
    }
};