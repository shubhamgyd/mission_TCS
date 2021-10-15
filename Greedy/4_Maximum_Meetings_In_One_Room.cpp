/*
There is one meeting room in a firm. There are N meetings in the form of (S[i], F[i]) where S[i] is the start time of meeting i and F[i] is finish time of meeting i. The task is to find the maximum number of meetings that can be accommodated in the meeting room. Print all meeting numbers

Examples: 

Input : s[] = {1, 3, 0, 5, 8, 5}, f[] = {2, 4, 6, 7, 9, 9} 
Output : 1 2 4 5 
First meeting [1, 2] 
Second meeting [3, 4] 
Fourth meeting [5, 7] 
Fifth meeting [8, 9]

Input : s[] = {75250, 50074, 43659, 8931, 11273, 27545, 50879, 77924}, 
f[] = {112960, 114515, 81825, 93424, 54316, 35533, 73383, 160252 } 
Output : 6 7 1 

*/

#include<bits/stdc++.h>
using namespace std;

struct Meet
{
    int start;
    int end;
    int pos;
};

bool cmp(struct Meet a,struct Meet b)
{
    return a.end<b.end;
}

void MaxMeet(int s[],int f[],int n)
{
    struct Meet meet[n];
    for(int i=0;i<n;i++)
    {
        meet[i].start=s[i];
        meet[i].end=f[i];
        meet[i].pos=i+1;
    }

    sort(meet,meet+n,cmp);
    vector<int>position;
    // Adding fist meet
    position.push_back(meet[0].pos);

    // Time limit of first meet
    int limit=meet[0].end;

    for(int i=1;i<n;i++)
    {
        // If start time of next meeting is greater than equal to the previous meeting
        // then we can count this meeting 
        if(meet[i].start>=limit)
        {
            // Update time limit
            limit=meet[i].end;

            // Push selected meeting in vector
            position.push_back(meet[i].pos);
        }
    }

    for(auto it:position)
    {
        cout<<it<<" ";
    }


}

int main()
{
    // strt time
    int s[] = { 1, 3, 0, 5, 8, 5 };
     
    // Finish time
    int f[] = { 2, 4, 6, 7, 9, 9 };
    int n=sizeof(s)/sizeof(s[0]);
    MaxMeet(s,f,n);
    return 0;
}