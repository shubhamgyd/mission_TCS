/*
Problem Statement: There is one meeting room in a firm. You are given two arrays, start and end each of size N.For an index ‘i’, start[i] denotes the starting time of the ith meeting while end[i]  will denote the ending time of the ith meeting. Find the maximum number of meetings that can be accommodated if only one meeting can happen in the room at a  particular time. Print the order in which these meetings will be performed.

Example:

Input:  N = 6,  start[] = {1,3,0,5,8,5}, end[] =  {2,4,5,7,9,9}

Output: 1 2 4 5

Explanation: See the figure for a better understanding.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    pair<int, int> time[n];
    for (int i = 0; i < n; i++)
    {
        cin >> time[i].first >> time[i].second;
    }

    // Approach:
    // To proceed we need a vector of three quantities: the starting time, ending time, meeting number. Sort this data structure in ascending order of end time.

    // We need a variable to store the answer. Initially, the answer is 1 because the first meeting can always be performed. Make another variable, say limit that keeps track of the ending time of the meeting that was last performed. Initially set limit as the end time of the first meeting.

    // Start iterating from the second meeting. At every position we have two possibilities:-

    // If the start time of a meeting is  strictly greater than limit we can perform the meeting. Update the answer.Our new limit is the ending time of the current meeting  since it was last performed.Also update limit.
    //  If the start time is less than or equal to limit  ,skip and move ahead.


    multimap<pair<int,int>,int>mp;
    for(int i=0;i<n;i++)
    {
        if(time[i].first<time[i].second)
        {
            mp.insert({{time[i].second,i+1},time[i].first});
        }
    }
    int end=0;
    vector<int>ans;
    for(auto it:mp)
    {
        if(it.second>end)
        {
            ans.push_back(it.first.second);
            end=it.first.first;
        }
    }
    cout<<"Meetings: "<<endl;
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    return 0;
}

// Time Complexity: O(n) to iterate through every position and insert them in a data structure. O(n log n)  to sort the data structure in ascending order of end time. O(n)  to iterate through the positions and check which meeting can be performed.
// Overall : O(n) +O(n log n) + O(n) ~O(n log n)
// Space Complexity: O(n)  since we used an additional data structure for storing the start time, end time, and meeting no.