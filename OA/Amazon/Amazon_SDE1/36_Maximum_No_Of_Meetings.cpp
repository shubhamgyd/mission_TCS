/*
This was asked during an interview to calculate the maximum number of meetings that can be 
held based on given 2 arrays.

Size of arrays is from 1 to 50, and the values in the array are from 1 to 1000 max.

I have an array that represents starting time for meetings - [1,3,3,5,7]. Another array that 
represents the time taken for the above meeting - [2,2,1,2,1]

As per the above data, the first meeting starts at 1 and continues for 2hrs. so it covers from 
1hr to 3hrs as meeting duration is 2hrs. The second and third meeting starts at 3 and they
 continue for 2hrs or 1hrs. so they cover 3 to 5 for 2nd meeting, 3 to 4 for the third meeting. 
 The fourth meething starts at 5 and continues for 2hrs. So it covers 5 to 7 as duration is 2hrs 
 The last meeting starts at 7 and continues for 1hr.

The second and third are occurring at same time, so we just need to pick only one such that 
we can arrange maximum number of meetings.

For the given above sample data we can arrange 4 meetings.

Another example:

starting time for meetings - [1,3,5]. Time taken for meetings - [2,2,2].

Here none of the meetings can conflict so maximum we can arrange 3 meetings.
*/


#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>>meetings(n);
    for(int i=0;i<n;i++)
    {
        cin>>meetings[i].first>>meetings[i].second;
    }
    sort(meetings.begin(),meetings.end(),[](pair<int,int>&a,pair<int,int>&b){
        return a.second<b.second;
    });
    int cnt=0;
    int prevEnd=INT_MIN;
    for(auto it:meetings)
    {
        if(it.first>=prevEnd)
        {
            cnt++;
            prevEnd=it.second;
        }
    }
    cout<<cnt<<endl;
}

/*
Sorting all the intervals by their ending times will take O(n log n) time. When we are scanning
intervals, we need to check whether an interval conflicts with some interval that has already been
scheduled. An important observation is that: If an interval intersects some of previously scheduled
intervals, it must intersect the last scheduled interval. That is because the last scheduled interval
has the largest ending time among all the scheduled intervals. Thus, at each step when we reach
a new interval, we only need to check whether it conflicts the last scheduled interval. This process
only takes O(n) time. In a word, this algorithm runs in O(n log n) time
*/