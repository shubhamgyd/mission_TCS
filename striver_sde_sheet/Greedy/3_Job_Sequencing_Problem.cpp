/*
Problem Statement: You are given a set of N jobs where each job comes with a deadline and profit. The profit can only be earned upon completing the job within its deadline. Find the number of jobs done and the maximum profit that can be obtained. Each job takes a single unit of time and only one job can be performed at a time.

Examples

Example 1:

Input: N = 4, Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}

Output: 2 60

Explanation: The 3rd job with a deadline 1 is performed during the first unit of time .The 1st job is performed during the second unit of time as its deadline is 4.
Profit = 40 + 20 = 60
*/

#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int>&a,vector<int>&b)
{
    return (a[2]>b[2]);
}


int main()
{
    int n;
    cin >> n;
    vector<vector<int>> res;
    for (int i = 0; i < n; i++)
    {
        int id, deadline, profit;
        cin >> id >> deadline >> profit;
        res.push_back({id, deadline, profit});
    }
    //     Approach:  The strategy to maximize profit should be to pick up jobs that offer higher profits. Hence we should sort the jobs in descending order of profit. Now say if a job has a deadline of 4 we can perform it anytime between day 1-4, but it is preferable to perform the job on its last day. This leaves enough empty slots on the previous days to perform other jobs.

    // Basic Outline of the approach:-

    // Sort the jobs in descending order of profit.
    // If the maximum deadline is x, make an array of size x .Each array index is set to -1 initially as no jobs have been performed yet.
    // For every job check if it can be performed on its last day.
    // If possible mark that index with the job id and add the profit to our answer.
    // If not possible, loop through the previous indexes until an empty slot is found.
    sort(res.begin(),res.end(),cmp);
    int count=0;
    int profit=0;
    int mx=0;
    for(auto it:res)
    {
        mx=max(mx,it[1]);
    }
    int slot[mx+1];
    memset(slot,-1,sizeof(slot));
    for(int i=0;i<n;i++)
    {
        for(int j=res[i][1];j>0;j--)
        {
            if(slot[j]==-1)
            {
                slot[j]=i;
                count++;
                profit+=res[i][2];
                break;
            }
        }
    }
    cout<<"Job Count: "<<count<<endl;
    cout<<"Profit: "<<profit<<endl;
    return 0;
}

// Time Complexity: O(N log N) + O(N*M).
// O(N log N ) for sorting the jobs in decreasing order of profit. O(N*M) since we are iterating through all N jobs and for every job we are checking from the last deadline, say M deadlines in the worst case.
// Space Complexity: O(M) for an array that keeps track on which day which job is performed if M is the maximum deadline available.